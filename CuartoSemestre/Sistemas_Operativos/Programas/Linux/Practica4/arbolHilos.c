#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>

int mails = 0;
pthread_mutex_t mutex;

void* routine(){
	for (int i = 0; i < 10000000; i++){
		pthread_mutex_lock(&mutex);
		mails++;
		pthread_mutex_unlock(&mutex);
	}
}

int main(int argc, char const *argv[])
{

		pid_t pid1;
		pthread_t th[1200];
		int i,j,k;
		pthread_mutex_init(&mutex, NULL);

	if((pid1 = fork()) == 0){
		printf("soy el proceso hijo\n");
		for (j = 0; j < 15; ++j)
		{
			if (pthread_create(th + j, NULL, &routine, NULL) != 0)
			{
				perror("fallo creacion de hilo");
				return 1;
			}
			printf("primer nivel, hilo %d creado\n", j);
			for (i = 0; i < 10; ++i)
			{
				if (pthread_create(th + i, NULL, &routine, NULL) != 0)
				{
					perror("fallo creacion de hilo");
					return 1;
				}
				printf("---segundo nivel, hilo %d creado\n", i);
				for (k = 0; k < 5; ++k)
				{
					if (pthread_create(th + k, NULL, &routine, NULL) != 0)
					{
						perror("fallo creacion de hilo");
						return 1;
					}
					printf("-----Tercer nivel, hilo %d creado - Practica 4\n", k);
				}
			}
		}
		for(i = 0; i < 15; i++){
			if(pthread_join(th[i],NULL) != 0){
				return 2;
			}
			printf("primer nivel, hilo %d finalizo\n", i);
		}
		pthread_mutex_destroy(&mutex);
	}
	return 0;
}