#include <stdio.h>
#include <math.h>
int prost(int broj){
    if(broj<=1) return 0;
    if(broj==2)return 1;
    if(broj%2==0)return 0;
    for(int i=3;i<=sqrt(broj);i+=2){
        if(broj%i==0)return 0;
    }
    return 1;
}
int medjuprost(int broj){
    if(broj<2) return 0;
    int prethodni=2;
    int trenutni;
    for(trenutni=3;trenutni<=2 * broj; trenutni++){
        if(prost(trenutni)){
            if((trenutni+prethodni)/2==broj) return 1;
        }
        prethodni=trenutni;
    }return 0;
}
int main(){
    int n;
    printf("unesite broj:");
    scanf("%d", &n);
    if(medjuprost(n)){
        printf("DA\n");
    } else{
        printf("NE\n");
    }

return 0;
    
}