#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	if (shmget(100, 20 * sizeof(int), IPC_CREAT|IPC_EXCL|0666) == -1) {
		perror("Erro no shmget");
		exit(0);
	}

	if (shmget(200, 4 * sizeof(int), IPC_CREAT|IPC_EXCL|0666) == -1) {
		perror("Erro no shmget");
		exit(0);
	}
}
