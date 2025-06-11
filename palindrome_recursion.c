#include <stdio.h>
#include <string.h>
int palindrome(char *string, int i, int j){
    if(i>=j){
        return 1;
    }
    if(string[i]!=string[j]){
        return 0;
    }
    return palindrome(string,i+1,j-1);
}
int main(){
    char str[]="anavolimilovana";
    int lenght=strlen(str);
    if(palindrome(str,0,lenght-1)){
        printf("string is palindrome");
    }else{
        printf("string is not palindrome");
    }
    return 0;
}