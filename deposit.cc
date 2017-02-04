/* EXERCISE 1 
 * Simple example to demonstrate race conditions when shared variable is not
 * protected by mutual exclusion.
 */

#include <stdio.h>
#include <pthread.h>

static volatile int balance = 0; 

void *deposit(void *arg) {
    char *name = (char*) arg;
    int amt = 1000000;
    for (int i = 0; i < amt; i++) {
        balance += 1;
    }
    printf("%s deposited $%d.\n", name, amt);
    return NULL;
}

int main() {
    pthread_t p1, p2;
    printf("Initial balance = $%d \n", balance);
    pthread_create(&p1, NULL, deposit, (void *)"Susan");
    pthread_create(&p2, NULL, deposit, (void *) "Amy");
    // wait for threads to finish
    pthread_join(p1, NULL);
    pthread_join(p2, NULL);
    printf("Final balance = $%d \n", balance);
    return 0;
}
