#include <stdio.h>//Libreria standard del C I/O.
#include <stdlib.h>//Libreria usata per la generazione di numeri pseudocasuali.
#include <time.h> //Libreria usata per inizializzare il seme per la generazione di numeri pseudocasuali.
#define False 0//Ri-definizione del valore 0 con False.
#define True 1//Ri-definizione del valore 1 con True.

typedef int costo;
struct oggetto
{
    int prod_cod;
    char *name;
    char *spec;
    int qty_stored;
    costo euro;
};//Struct per contenere i tipi di dati del mio magazzino.
typedef struct oggetto Oggetto;//La Struct oggetto viene passata alla variabile STRUCT Oggetto.
struct giorno
{
    Oggetto g1[20];
    Oggetto g2[20];
    Oggetto g3[20];
    Oggetto g4[20];
    Oggetto g5[20];
    Oggetto g6[20];
    Oggetto g7[20];
    Oggetto g8[20];
    Oggetto g9[20];
    Oggetto g10[20];

};//Struct giorno di Struct di Oggetto.
void in_scorta(Oggetto merce[20]);//Funzione che visualizza la disponibilità e l'indisponibilità della merce in magazzino.
void sel_giorno(Oggetto merce[20]);//Funzione che permette di scegliere il giorno interessato in un periodo di 10 giorni.
void acquisti(Oggetto merce[20]);/*Funzione che simula una lista di prodotti acquistati e nello stesso momento generando
* numeri casuali effettua l'acquisto facendo la differenza tra quantità disponibile e il numero casuale.*/

void main()
{
    srand((unsigned int) time(0));
    Oggetto merce[20]=
            {
                    {1,"Samsung","Tv 55 pollici 8K",100,570},
                    {2,"Edison","Decoder DVB-T2",100,20},
                    {3,"IPhone 13 PRO MAX","512gb,6gb ram",100,1250},
                    {4,"AirPods","Chip H1",100,250},
                    {5,"Apple Watch 7","Res 396×484 pixel",100,400},
                    {6,"Huawei Matebook 13","Ryzen 7 3700U,16gb ram",100,750},
                    {7,"HP Omen 25L","10th Gen Intel Core i5,NVIDIA GeForce GTX 1650",100,800},
                    {8,"Razer Orochi","4000DPI",100,75},
                    {9,"Logitech G810 Orion Spectrum","Romer-G Switch,Rgb",100,100},
                    {10,"Creative Pebble v3","Bluetooth",100,40},
                    {11,"Xiaomi Mi 34 Curved","3440x1440 144hz 1ms",100,470},
                    {12,"Kingston Hyper X Predator","32gb 4x4 3600mhz CL17",100,250},
                    {13,"ASUS RTX 3080 TUF","10GB VRAM",100,2500},
                    {14,"MSI B500 Mortar","AM4 chipset",100,140},
                    {15,"AMD Ryzen 5600X","6/12 Thread,4.65GHZ",100,370},
                    {16,"Deepcool Macube 110","Micro-Atx",100,70},
                    {17,"Deepcool RM120","120mm RGB",100,50},
                    {18,"Corsair RM750X","750W",100,170},
                    {19,"Western Digital","1Tb storage",100,50},
                    {20,"Samsung 980 Pro","SSD 1TB",100,250}};
    int sel;
    printf("\n\n-Benvenuto in SAP Enterprise Resource Planning-\n-------------ELECTRONICS WAREHOUSE-------------\n"
           "\n-Qui potrai visualizzare lo stock ed il venduto giornaliero e dei 10 giorni successivi.\n");//L'uso del nome 'SAP' e il suo marchio registrato sono utilizzati solo per scopi dimostrativi a fini didattici.

           do
           {
               printf("\n///////////////////////////////////////////////////////////////////////////////////////\n"
                      "\n\n0.Seleziona il giorno.\n1.Esci.\n\nScelta n:");
               scanf("%d",&sel);

               switch (sel)
               {
                   case 0:sel_giorno(merce);break;
                   case 1:printf("\nChiusura in corso...\n");break;
                   default:printf("\nErrore.\n");break;
               }
           }
           while(sel!=1);

}/*Main in cui vengono dichiarati i valori e le informazioni delle variabili della struct.*/

void in_scorta(Oggetto merce[20])
{
    int i;
    int nr;
    int x=False;
    printf("\n///////////////////////////////////////////////////////////////////////////////////////\n");

    for(i=0;i<4;i++)
    {
        nr=rand()%20;
        if(merce[nr].qty_stored >= 1)
        {
            printf("\n|Prod_cod:%d|--|%s|--|Spec: %s|--|Qty: %d|--|Prezzo: %d Euro|\n",merce[nr].prod_cod,merce[nr].name,merce[nr].spec,merce[nr].qty_stored,merce[nr].euro);
        }
    }

    for(i=0;i<20;i++)
    {
        if(merce[i].qty_stored == 0)
        {
            x=True;
        }
        else
            x=False;
    }

    if(x==True)
        printf("\n\n//////////Siamo in attesa di restock, il magazzino e' completamente vuoto!!!///////////\n\n");
}

void sel_giorno(Oggetto merce[20])
{
    int giorno,operazione;
    printf("\n///////////////////////////////////////////////////////////////////////////////////////\n"
           "\nSelezionare un giorno da 0=1 Febbraio 2022 al 9=10 Febbraio 2022:\n\nScelta n:");
    scanf("%d",&giorno);
    switch(giorno)
    {
        case 0:{printf("\n///////////////////////////////////////////////////////////////////////////////////////\n"
                      "\n1 Febbraio 2022\n\n0.Scorte\n1.Vendite.\n\nScelta n:");
            scanf("%d",&operazione);
            switch (operazione)
            {
                case 0:in_scorta(merce);break;
                case 1:acquisti(merce);break;
                default:printf("Errore!!!");break;
            }}break;
        case 1:{printf("\n///////////////////////////////////////////////////////////////////////////////////////\n"
                      "\n2 Febbraio 2022\n\n0.Scorte\n1.Vendite.\n\nScelta n:");
            scanf("%d",&operazione);
            switch (operazione)
            {
                case 0:in_scorta(merce);break;
                case 1:acquisti(merce);break;
                default:printf("Errore!!!");break;
            }}break;
        case 2:{printf("\n///////////////////////////////////////////////////////////////////////////////////////\n"
                      "\n3 Febbraio 2022\n\n0.Scorte\n1.Vendite.\n\nScelta n:");
            scanf("%d",&operazione);
            switch (operazione)
            {
                case 0:in_scorta(merce);break;
                case 1:acquisti(merce);break;
                default:printf("Errore!!!");break;
            }}break;
        case 3:{printf("\n///////////////////////////////////////////////////////////////////////////////////////\n"
                      "\n4 Febbraio 2022\n\n0.Scorte\n1.Vendite.\n\nScelta n:");
            scanf("%d",&operazione);
            switch (operazione)
            {
                case 0:in_scorta(merce);break;
                case 1:acquisti(merce);break;
                default:printf("Errore!!!");break;
            }}break;
        case 4:{printf("\n///////////////////////////////////////////////////////////////////////////////////////\n"
                      "\n5 Febbraio 2022\n\n0.Scorte\n1.Vendite.\n\nScelta n:");
            scanf("%d",&operazione);
            switch (operazione)
            {
                case 0:in_scorta(merce);break;
                case 1:acquisti(merce);break;
                default:printf("Errore!!!");break;
            }}break;
        case 5:{printf("\n///////////////////////////////////////////////////////////////////////////////////////\n"
                      "\n6 Febbraio 2022\n\n0.Scorte\n1.Vendite.\n\nScelta n:");
            scanf("%d",&operazione);
            switch (operazione)
            {
                case 0:in_scorta(merce);break;
                case 1:acquisti(merce);break;
                default:printf("Errore!!!");break;
            }}break;
        case 6:{printf("\n///////////////////////////////////////////////////////////////////////////////////////\n"
                      "\n7 Febbraio 2022\n\n0.Scorte\n1.Vendite.\n\nScelta n:");
            scanf("%d",&operazione);
            switch (operazione)
            {
                case 0:in_scorta(merce);break;
                case 1:acquisti(merce);break;
                default:printf("Errore!!!");break;
            }}break;
        case 7:{printf("\n///////////////////////////////////////////////////////////////////////////////////////\n"
                      "\n8 Febbraio 2022\n\n0.Scorte\n1.Vendite.\n\nScelta n:");
            scanf("%d",&operazione);
            switch (operazione)
            {
                case 0:in_scorta(merce);break;
                case 1:acquisti(merce);break;
                default:printf("Errore!!!");break;
            }}break;
        case 8:{printf("\n///////////////////////////////////////////////////////////////////////////////////////\n"
                      "\n9 Febbraio 2022\n\n0.Scorte\n1.Vendite.\n\nScelta n:");
            scanf("%d",&operazione);
            switch (operazione)
            {
                case 0:in_scorta(merce);break;
                case 1:acquisti(merce);break;
                default:printf("Errore!!!");break;
            }}break;
        case 9:{printf("\n///////////////////////////////////////////////////////////////////////////////////////\n"
                      "\n10 Febbraio 2022\n\n0.Scorte\n1.Vendite.\n\nScelta n:");
            scanf("%d",&operazione);
            switch (operazione)
            {
                case 0:in_scorta(merce);break;
                case 1:acquisti(merce);break;
                default:printf("Errore!!!");break;
            }}break;
        default:
            printf("ERRORE!!!");break;
    }
}

void acquisti(Oggetto merce[20])
{
    int i=0;
    int ar;
    int guadagni_parz;
    int venduti;

    while(merce[i].qty_stored >= 0 && i<=19)
        {
            ar=rand()%20;
            if(merce[i].qty_stored >=1 && merce[i].qty_stored>=ar && ar!=0)
            {
                merce[i].qty_stored = merce[i].qty_stored-ar;
                guadagni_parz=(ar*(merce[i].euro));
                venduti=ar;
                printf("\n|Prod_cod: %d|--|%s|--|Qty: %d|--|Prezzo: %d euro|--|Venduti: %d|--|Guadagno: %d Euro|\n",merce[i].prod_cod,merce[i].name,merce[i].qty_stored,merce[i].euro,venduti,guadagni_parz);
                i++;
            }
            else
                i++;
        }
}