#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encontraAluno (char *alunos[], int n, int k) {
	int a, b;
	char *aux;

	for (a = 0; a < n - 1; a++) {
		for (b = 0; b < n - 1; b++) {
			if (strcmp(alunos[b + 1], alunos[b] < 0) {
				aux = alunos[b];
				alunos[b] = alunos[b + 1];
				alunos[b + 1] = aux;
			}
		}
	}

	printf("%s\n", alunos[k - 1]);
}

int main() {
	int k, n, i;
	scanf("%d %d", &n, &k);

	char *nomes[n];

	for (i = 0; i < n; i++) {
		nomes[i] = malloc(21 * sizeof(char));
		scanf("%s", nomes[i]);
	}

	encontraAluno(nomes, n, k);

	for (i = 0; i < n; i++) {
		free(nomes[i]);
	}
}