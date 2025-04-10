#include <stdio.h>

void subtrai3(int* numero);

int main(void) {
    int n;
    
    printf("digite um numero: ");
    scanf("%d", &n); 
    
    printf("recebido: %d\n", n);
    
    subtrai3(&n); 
    
    printf("resultado: %d\n", n); 
    return 0;
}

void subtrai3 (int *numero) {
    *numero = *numero - 3;
    printf ("Atual: %d\n", *numero);
}