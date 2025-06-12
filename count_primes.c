#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int isPrime(int num){
    if(num<=1) return 0;
    if(num==2) return 1;
    if(num % 2==0)return 0;
    for(int i=3;i*i<=num;i+=2){
        if(num%i==0)return 0;
    }
    return 1;
}
int countPrimes(int numb){
    numb=abs(numb);
    if(numb<10){
        return isPrime(numb);
    }
    int lastDigit=numb%10;
    int count= isPrime(lastDigit);
    return count + countPrimes(numb/10);
}
int countArrayPrimes(int *arr, int n, int k){
    int total=0;
    for(int i=0;i<n;i++){
        int primesInNumber=countPrimes(arr[i]);
        if(primesInNumber>k){
            total++;
        }
    }
    return total;
}
int main(){
    int number=1234;
    printf("number %d has %d prime digits\n",number,countPrimes(number));
    int arr[]={12,44,33,54};
    int size=sizeof(arr)/sizeof(arr[0]);
    int k=1;
    printf("in array we have %d numbers that have more than %d prime digits",countArrayPrimes(arr,size,k),k);
    return 0;
}