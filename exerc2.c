#include <stdio.h>

void subtrai3(int *valor, int *resultado) {
    *resultado = *valor - 3;
}

int main() {
    int numero = 7; 
    int resultado;

    printf("digite um numero: %d\n", numero);
    printf("recebido: %d\n", numero);

    subtrai3(&numero, &resultado);

    printf("resultado: %d\n", resultado);
    printf("atual: %d\n", numero);

    return 0;
}