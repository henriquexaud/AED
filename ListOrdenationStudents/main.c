#include <stdio.h>
#include <string.h>

void ordemAlfabetica(char nomes[][21], int n) {
  int i, j;
  char aux[21];
  for (i = 0; i < n - 1; i++) {
    for (j = i + 1; j < n; j++) {
      if (strcmp(nomes[i], nomes[j]) > 0) {
        strcpy(aux, nomes[i]);
        strcpy(nomes[i], nomes[j]);
        strcpy(nomes[j], aux);
      }
    }
  }
}

int main() {
  int n, k;
  char nomes[100][21];
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%s", nomes[i]);
  }
  ordemAlfabetica(nomes, n);
  printf("%s\n", nomes[k - 1]);
  return 0;
}