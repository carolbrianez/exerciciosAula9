#include <stdio.h>

void subtrai3(int* numero) {  
    *numero = *numero - 3;   
}

int main(void) {
    int numero;
    
    printf("digite um numero: ");
    
    scanf("%d", &numero); 
    
    printf("recebido: %d\n", numero);
    
    subtrai3(&numero); 
    
    printf("resultado: %d\n", numero); 
    
    printf("atual: %d\n", numero);
    
    return 0;
}