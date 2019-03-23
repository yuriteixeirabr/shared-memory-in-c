#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	
	if (shmctl(shmget(100, 20 * sizeof(int), 0666), IPC_RMID, NULL) == -1)
		perror("Erro ao excluir a área de memória 100");
	if (shmctl(shmget(200, 4 * sizeof(int), 0666), IPC_RMID, NULL) == -1)
		perror("Erro ao excluir a área de memória 200");
}
