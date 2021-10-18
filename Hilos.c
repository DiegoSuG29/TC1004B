#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 1000
int saldo;
pthread_mutex_t saldoLock = PTHREAD_MUTEX_INITIALIZER;

void * suma100(void *arg){  //Pasar direccion
    //char *c =(char *)arg; 
    //printf("Hola desde un hilo %s \n",c);
    int lsaldo;
    pthread_mutex_lock(&saldoLock); //Bloquea
    //Region critica
    lsaldo = saldo;
    lsaldo += 100;
    saldo = lsaldo;
    pthread_mutex_unlock(&saldoLock); //Desbloquea
    pthread_exit(NULL);
}

int main(){
    pthread_t threads[NUM_THREADS]; //Guarda los hilos 
    saldo = 0;
    char *s = "Soy un argumento";
    for(int i = 0; i < NUM_THREADS; i++){
        pthread_create(&threads[i],NULL,suma100,NULL);
    }
    for(int i = 0; i < NUM_THREADS; i++){
        pthread_join(threads[i],NULL);
    }
    printf("Saldo final es %d\n",saldo);
    pthread_exit(NULL);
}