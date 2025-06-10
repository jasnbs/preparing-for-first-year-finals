#include <stdio.h>
#include <stdlib.h>
typedef struct complex{
    double re;
    double im;
}COMPLEX;
typedef struct mat { 
COMPLEX el[100][100]; 
int n, m; 
} MAT; 
MAT * ucitaj(){
    MAT * matrica=(MAT *)malloc(sizeof(MAT));
    if(matrica==NULL)
       return NULL;
    printf("insert matrix dimesions");
    scanf("%d %d",&matrica->n, &matrica->m);
    printf("insert matrix elements(complex number real and imaginational part)");
    for(int i=0;i<matrica->n;i++){
        for(int j=0;j<matrica->m;j++){
            scanf("%lf %lf", &matrica->el[i][j].re,&matrica->el[i][j].im);
        }
    }
    return matrica;
}
COMPLEX multiply_c(COMPLEX a, COMPLEX b){
    COMPLEX result;
    result.re=a.re * b.re - a.im * b.im;
    result.im=a.re * b.im + a.im * b.re;
    return result;
}
MAT* multiply_m(const MAT *a, const MAT * b){
    if(a->m!=b->n){
        return NULL;
    }
    MAT * product=(MAT*)malloc(sizeof(MAT));
    if(product==NULL)
        return NULL;
    product->n=a->n;
    product->m=b->m;
    for(int i=0;i<a->n;i++){
       for(int j=0;j<b->m;j++){
        product->el[i][j].re=0;
        product->el[i][j].im=0;
        for(int k=0;k<a->m;k++){
            COMPLEX p=multiply_c(a->el[i][k],b->el[k][j]);
            product->el[i][j].re+=p.re;
            product->el[i][j].im+=p.im;
        }
    }
}
  return product;
}
void print_matrix(const MAT *m){
    if(m==NULL){
        printf("matrix je NULL\n");
        return;}
    for(int i=0;i<m->n;i++){
        for(int j=0; j<m->m;j++){
            printf("(%lf + %lf)",m->el[i][j].re, m->el[i][j].im);
        }
        printf("\n");
    }
}
int main(){
    printf("matrix 1\n");
    MAT * mat1=ucitaj();
    printf("matrix 2\n");
    MAT * mat2=ucitaj();
    if(mat1 && mat2){
        MAT *result=multiply_m(mat1,mat2);
        if(result){
            printf("result of multiplication\n");
            print_matrix(result);
            free(result);
        }else{printf("matrices cannot be multiplicated");}
        free(mat1);
        free(mat2);
    }else{printf("trouble reading matrices");}
    return 0;
}