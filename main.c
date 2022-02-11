#include <stdio.h>
typedef int costo;
//{tv,decoder,smartphone,earphones,smartwatch,laptop,computer,mouse,keyboard,speaker,monitor,ram,gpu,motherboard,cpu,tower,fan,psu,hd,ssd};
struct oggetto
{
    int prod_cod;
    char *name;
    char *spec;
    int qty_stored;
    costo euro;
}obj;
typedef struct oggetto Oggetto;

Oggetto merce[20]=
        {
        00001,"Samsung","Tv 55 pollici 8K",1,570,
        00002,"Edison","Decoder DVB-T2",1,20,
        00003,"IPhone","PRO MAX",1,1250,
        00004,"AirPods","Chip H1",
        };

int main()
{
}
