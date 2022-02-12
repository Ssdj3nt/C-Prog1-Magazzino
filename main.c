#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef enum {false,true};
typedef float costo;
enum giorno {g1,g2,g3,g4,g5,g6,g7,g8,g9};
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
void main()
{
    srand((unsigned int)time(0));
    Oggetto merce[20]=
            {
                    {1,"Samsung","Tv 55 pollici 8K",100,570},
                    {2,"Edison","Decoder DVB-T2",100,20},
                    {3,"IPhone","PRO MAX",100,1250},
                    {4,"AirPods","Chip H1",100,250},
                    {5,"Apple Watch","Serie 7",100,400},
                    {6,"Huawei Matebook 13","Ryzen 7 3700U,16gb ram",100,750},
                    {7,"HP Omen 25L","10th Gen Intel® Core™ i5,NVIDIA® GeForce® GTX 1650",100,800},
                    {8,"Razer Orochi","4000DPI",100,75},
                    {9,"Logitech G810 Orion Spectrum","Romer-G Switch,Rgb",100,100},
                    {10,"Creative Pebble v3","Bluetooth",100,40},
                    {11,"Xiaomi Mi 34 Curved","3440x1440 144hz 1ms",100,470},
                    {12,"Hyper X Predator","32gb 4x4 3600mhz CL17",100,250},
                    {13,"ASUS RTX 3080 TUF","10GB VRAM",100,2500},
                    {14,"MSI B500 Mortar","AM4 chipset",100,140},
                    {15,"Ryzen 5600X","4.65GHZ",100,370},
                    {16,"Deepcool Macube 110","Micro-Atx",100,70},
                    {17,"Deepcool RM120","120mm RGB",100,50},
                    {18,"Corsair RM750X","750W",100,170},
                    {19,"Western Digital 1tb","1Tb storage",100,50},
                    {20,"Samsung 980 Pro","SSD 1TB",100,250}};
    int sel;
    printf("\n-Benvenuto nel gestore magazzino.\n");
    printf("\n-Qui potrai visualizzare lo stock ed il venduto giornaliero e dei 10 giorni successivi.\n");
    printf("\n\n");
    printf("\n\n");

    do
    {
        printf("\nDigita il numero corrispondente all'operazione da effettuare.");
        printf("\n0.Visualizza le Scorte\n1.Seleziona giorno\n2.Esci\nScelta n°:");
        scanf("%d",&sel);

        switch (sel)
        {
            case 0:in_scorta(merce);break;
            case 1:sel_giorno;break;
            case 2:printf("\nChiusura in corso...\n");break;
            default:printf("\nErrore.\n");
        }
    }
    while(sel!=2);

}
void in_scorta(Oggetto merce[20])
{
    int i,rn;
    if(merce->qty_stored > 0)
    {
        for(i=0;i<4;i++)
        {
            rn=rand()%20;
            printf("\n|Codice:%2d|--|Merce: %s|--|Spec: %s|--|Qty: %d|--|Prezzo %f|\n",merce[rn].prod_cod,merce[rn].name,merce[rn].spec,merce[rn].qty_stored,merce[rn].euro);
        }
    }
}
void sel_giorno(enum giorno giorno)
{

}
