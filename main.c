#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TRUE 1
#define FALSE 0
enum giorno {g1,g2,g3,g4,g5,g6,g7,g8,g9};
typedef float costo;
struct oggetto
{
    int prod_cod;
    char *name;
    char *spec;
    int qty_stored;
    costo euro;
};
typedef struct oggetto Oggetto;
void in_scorta(Oggetto merce[20]);
void sel_giorno(enum giorno giorno);
void acquisti(Oggetto merce[20]);

void main()
{
    srand((unsigned int) time(0));
    Oggetto merce[20]=
            {
                    {1,"Samsung","Tv 55 pollici 8K",100,570.0F},
                    {2,"Edison","Decoder DVB-T2",100,20.0F},
                    {3,"IPhone","PRO MAX",100,1250.0F},
                    {4,"AirPods","Chip H1",100,250.0F},
                    {5,"Apple Watch","Serie 7",100,400.0F},
                    {6,"Huawei Matebook 13","Ryzen 7 3700U,16gb ram",100,750.0F},
                    {7,"HP Omen 25L","10th Gen Intel Core i5,NVIDIA GeForce GTX 1650",100,800.0F},
                    {8,"Razer Orochi","4000DPI",100,75.0F},
                    {9,"Logitech G810 Orion Spectrum","Romer-G Switch,Rgb",100,100.0F},
                    {10,"Creative Pebble v3","Bluetooth",100,40.0F},
                    {11,"Xiaomi Mi 34 Curved","3440x1440 144hz 1ms",100,470.0F},
                    {12,"Hyper X Predator","32gb 4x4 3600mhz CL17",100,250.0F},
                    {13,"ASUS RTX 3080 TUF","10GB VRAM",100,2500.0F},
                    {14,"MSI B500 Mortar","AM4 chipset",100,140.0F},
                    {15,"Ryzen 5600X","4.65GHZ",100,370.0F},
                    {16,"Deepcool Macube 110","Micro-Atx",100,70.0F},
                    {17,"Deepcool RM120","120mm RGB",100,50.0F},
                    {18,"Corsair RM750X","750W",100,170.0F},
                    {19,"Western Digital 1tb","1Tb storage",100,50.0F},
                    {20,"Samsung 980 Pro","SSD 1TB",100,250.0F}};
    int sel;
    printf("\n\n-Benvenuto in SAP Enterprise Resource Planning-\n-------------ELECTRONICS WAREHOUSE-------------\n");  //L'uso del nome 'SAP' e il suo marchio registrato sono utilizzati solo per scopi dimostrativi a fini didattici.
    printf("\n-Qui potrai visualizzare lo stock ed il venduto giornaliero e dei 10 giorni successivi.\n");

    do
    {
        printf("\n///////////////////////////////////////////////////////////////////////////////////////\n");
        printf("\nDigita il numero corrispondente all'operazione da effettuare.");
        printf("\n\n0.Visualizza le Scorte.\n1.Visualizza il venduto.\n2.Seleziona il giorno.\n3.Esci.\n\nScelta n:");
        scanf("%d",&sel);

        switch (sel)
        {
            case 0:in_scorta(merce);break;
            case 1:acquisti(merce);break;
            case 2:sel_giorno;break;
            case 3:printf("\nChiusura in corso...\n");break;
            default:printf("\nErrore.\n");break;
        }
    }
    while(sel!=3);

}
void in_scorta(Oggetto merce[20])
{
    int i;
    int nr;
    int terminato=FALSE;
    printf("\n///////////////////////////////////////////////////////////////////////////////////////\n");

    {
        for(i=0;i<4;i++)
        {
            nr=rand()%20;
            if(merce[nr].qty_stored >=1)
                printf("\n|Codice:%d|--|Merce: %s|--|Spec: %s|--|Qty: %d|--|Prezzo: %f euro|\n",merce[nr].prod_cod,merce[nr].name,merce[nr].spec,merce[nr].qty_stored,merce[nr].euro);
        }
    }

    for(i=0;i<19;i++)
    {
        if(merce[i].qty_stored==0)
            terminato=TRUE;
        else
            terminato=FALSE;
    }

    if(terminato==TRUE)
        printf("\n\n/////////////Siamo in attesa di restock, il magazzino e' completamente vuoto!!!//////////////\n\n");
}

void sel_giorno(enum giorno giorno)
{

}
void acquisti(Oggetto merce[20])
{
    int i=0;
    int ar;
    float guadagni=0.0F;

    while(merce[i].qty_stored >= 0 && i<=19)
        {
            ar=rand()%20;
            if(merce[i].qty_stored<ar && merce[i].qty_stored>0 )
            {
                printf("\n|Codice:%2d|--|Merce: %s|--|Qty: %d|--|Prezzo: %f euro|\n",merce[i].prod_cod,merce[i].name,merce[i].qty_stored,merce[i].euro);
                i++;
            }
            else if(merce[i].qty_stored==0)
            {
                printf("\n|Codice:%2d|--|Merce: %s| QUESTO PRODOTTO E' TERMINATO!\n",merce[i].prod_cod,merce[i].name,merce[i].qty_stored,merce[i].euro);
                i++;
            }
            else
            {
                merce[i].qty_stored = (merce[i].qty_stored)-ar;
                if(merce[i].qty_stored>0)
                {
                    printf("\n|Codice:%2d|--|Merce: %s|--|Qty: %d|--|Prezzo: %f euro|\n",merce[i].prod_cod,merce[i].name,merce[i].qty_stored,merce[i].euro);
                    guadagni=guadagni+(float)ar*merce->euro;
                    i++;
                }
            }
        }
    printf("\nGuadagni: %f euro\n",guadagni);
    }