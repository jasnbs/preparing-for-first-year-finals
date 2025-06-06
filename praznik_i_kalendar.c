#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct praznik{
    int dan,mjesec,godina;
    char naziv[256];
}PRAZNIK;
typedef struct kalendar{
    PRAZNIK praznici[100];
    int n;
}KALENDAR;
PRAZNIK * kopija (const PRAZNIK * p){
    PRAZNIK * novi=(PRAZNIK *)malloc(sizeof(PRAZNIK));
    if(novi==NULL) return NULL;
    novi->dan=p->dan;
    novi->mjesec=p->mjesec;
    novi->godina=p->godina;
    strcpy(novi->naziv,p->naziv);
    return novi;
}
PRAZNIK **mjesec(KALENDAR * k, int mjesec, int godina){
    int broj_praznika=0;
    for(int i=0;i<k->n;i++){
        if(k->praznici[i].mjesec==mjesec && k->praznici[i].godina==godina){
            broj_praznika++;
        }
    }
    PRAZNIK **rezultat=(PRAZNIK **)malloc(broj_praznika * sizeof(PRAZNIK));
    if(rezultat==NULL)return NULL;
    int index=0;
    for(int i=0;i<k->n;i++){
        if(k->praznici[i].mjesec==mjesec && k->praznici[i].godina==godina){
            rezultat[index] = kopija(&k->praznici[i]);
            if(rezultat[index] == NULL) {
                for(int j = 0; j < index; j++) {
                    free(rezultat[j]);
                }
                free(rezultat);
                return NULL;
            }
            index++;
        }
    }
    return rezultat;
}
void ispisi(KALENDAR * k,int godina){
    printf("praznici u %d. godini:\n",godina);
    for(int i=0;i<k->n;i++){
        if(k->praznici[i].godina==godina){
            printf(" %d. %d. %d. -%s\n",k->praznici[i].dan,k->praznici[i].mjesec,k->praznici[i].godina,k->praznici[i].naziv);
        }
    }
}
int main(){
    KALENDAR k;
    k.n=0;
    int tekuca_godina=2025;
     k.praznici[k.n].dan = 1;
    k.praznici[k.n].mjesec = 5;
    k.praznici[k.n].godina = tekuca_godina;
    strcpy(k.praznici[k.n].naziv, "Medjunarodni praznik rada (drugi dan)");
    
    k.n++;
    k.praznici[k.n].dan = 2;
    k.praznici[k.n].mjesec = 5;
    k.praznici[k.n].godina = tekuca_godina;
    strcpy(k.praznici[k.n].naziv, "Medjunarodni praznik rada (drugi dan)");
    k.n++;
     k.praznici[k.n].dan = 9;
    k.praznici[k.n].mjesec = 5;
    k.praznici[k.n].godina= tekuca_godina;
    strcpy(k.praznici[k.n].naziv, "Dan pobede nad fasizmom");
    k.n++;
    PRAZNIK** peti_mjesec=mjesec(&k,5,tekuca_godina);
    printf("praznici u 5 mjesecu % godine:\n", tekuca_godina);\
    if(peti_mjesec!=NULL){
        for(int i=0; i<3;i++){
            if(peti_mjesec[i]!=NULL){
                printf("  -%s\n",  peti_mjesec[i]->naziv);
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        free(peti_mjesec[i]);
    }
    free(peti_mjesec);
    ispisi(&k, tekuca_godina);
    return 0;
}