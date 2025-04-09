#include <stdio.h>

void multi3(int *y);

int main(void) {
  int x = 5;
  printf("X antes: %d\n", x);

  multi3(&x);

  printf("X depois: %d\n", x);
  return 0;
}

void multi3(int *y) {
  *y = 3 * (*y); 
}