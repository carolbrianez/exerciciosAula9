# Aula 9: Pilha, Passagem de Argumentos e Exercícios em C

## Sumário
1. [Pilha](#pilha)
   1. [Pilha de funções](#pilha-de-funções)
   2. [Stack Overflow](#stack-overflow)
2. [Passagem de argumentos](#passagem-de-argumentos)
   1. [Por valor](#por-valor)
   2. [Usando variáveis locais com nomes iguais](#usando-variáveis-locais-com-nomes-iguais)
   3. [Por referência](#por-referência)
   4. [Exercícios](#exercícios)

---

## Pilha

Uma pilha (stack) funciona como uma pilha de pratos:
- Colocar um prato: `push`
- Retirar um prato: `pop`
- Último a entrar é o primeiro a sair: **LIFO** (last-in, first-out)

### Pilha de funções

- A pilha armazena cada função chamada, junto com suas variáveis locais.
- Quando a função termina, ela é retirada da pilha e suas variáveis são destruídas.

Exemplo:

```c
#include <stdio.h>

int operacao(int, int);

int multi(int);

int main(void) {
  int a = 10;
  int b = 20;

  printf("Resultado: b*b - a*a = %d", operacao(a, b));
  return 0;
}

int operacao(int x, int y) {
  return multi(y) - multi(x);
}

int multi(int z) {
  return z * z;
}
```

Fluxo de execução:
1. `main()` chama `operacao(10, 20)`.
2. `operacao()` chama `multi(20)` e `multi(10)`.
3. Quando `multi()` termina, ele retorna o valor para `operacao()`.
4. Por fim, `operacao()` retorna o resultado para `main()`.

---

### Stack Overflow

Se houver muitas chamadas de funções e a pilha consumir mais memória do que disponível, ocorrerá um erro de stack overflow.

---

## Passagem de argumentos

- **Por valor:** Uma cópia do valor é usada, e alterações na função não afetam o valor original.
- **Por referência:** O endereço da variável é passado, permitindo que a função altere o valor original.

### Por valor

As alterações feitas dentro da função não afetam o valor original fora dela.

Exemplo:

```c
#include <stdio.h>

void soma(int x) {
  x += 2;
}

int main(void) {
  int a = 5;
  soma(a);
  printf("Valor de a: %d\n", a); // a ainda será 5
  return 0;
}
```

---

### Usando variáveis locais com nomes iguais

Mesmo que duas funções usem variáveis com os mesmos nomes, elas são independentes, pois cada função tem seu próprio escopo.

---

### Por referência

Ao passar o endereço de uma variável para a função (com `&`), a função pode alterar o valor da variável original.

Exemplo:

```c
#include <stdio.h>

void soma2(int *x) {
  *x += 2;
}

int main(void) {
  int a = 5;
  soma2(&a);
  printf("Valor de a: %d\n", a); // a será 7
  return 0;
}
```

---

## Exercícios

### Exercício 1

Altere o programa abaixo para que `multi3` receba o endereço de `x` e não retorne nada (`void`):

```c
#include <stdio.h>

int multi3(int y);

int main(void) {
  int x = 5;
  printf("X antes: %d\n", x);

  int resultado = multi3(x);
  printf("Resultado: %d\n", resultado);

  printf("X depois: %d\n", x);
  return 0;
}

int multi3(int y) {
  return 3 * y;
}
```

---

### Exercício 2

Crie um programa em C que:
1. Recebe um número inteiro.
2. Armazena o número na variável `numero`.
3. Imprime o número recebido.
4. Usa uma função chamada `subtrai3()` que recebe o valor do número e retorna `numero - 3`.
5. Imprime o valor retornado por `subtrai3()` e o valor atual de `numero`.

Exemplo de saída:

```
Digite um numero: 7
Recebido: 7
Resultado: 4
Atual: 7
```

---

### Exercício 3

Altere o programa anterior para usar passagem por referência, de modo que `subtrai3()` receba o endereço de `numero`.

Exemplo de saída:

```
Digite um numero: 7
Recebido: 7
Resultado: 4
Atual: 4
```

---
