#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	int* numeros;
	int *soma;
	int id_mem_numeros, id_mem_soma, aux = 1, pos, vlr;
	char aux_sobrepor;
	if ((id_mem_numeros = shmget(100, 20 * sizeof(int), 0666)) == -1) {
		perror("Erro no shmget 100");
		exit(0);
	}
	if ((id_mem_soma = shmget(200, 4 * sizeof(int), 0666)) == -1) {
		perror("Erro no shmget 200");
		exit(0);
	}
	numeros = (int*)shmat(id_mem_numeros, 0, 0);
	soma = shmat(id_mem_soma, 0, 0);
	
	while (aux > 0) {
		printf("\nEscolha uma das opções: \n1-Inserir ou Alterar\n2-Imprimir Números\n3-Calcular Soma\n4-Imprimir Soma\n0-Sair\n");
		scanf("%d", &aux);

		if (aux == 1) {
			printf("\nEm que posição deseja armazenar o valor?\n");
			scanf("%d", &pos);
			printf("\nQual o valor deseja armazenar?\n");
			scanf("%d", &vlr);
			if (numeros[pos] > 0) {
				printf("\nJá existe o valor: %d na posição solicitada, deseja realmente alterar? Y ou N\n", numeros[pos]);
				scanf("%s", &aux_sobrepor);
				if (aux_sobrepor == 'Y')
					numeros[pos] = vlr;
				printf("Teste1");
				aux = 15;
			} else
				numeros[pos] = vlr;
		} else if (aux == 2) {
			for (int i = 0; i < 5; i++)
				printf("\nNúmero %d: %d\n", (i + 1), numeros[i]);
		} else if (aux == 3) {
			for (int i = 0; i < 5; i++)
				*soma = numeros[i] + *soma;
		} else if (aux == 4)
			printf("Soma: %d", *soma);
	}
}
