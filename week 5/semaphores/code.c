#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define BUFFER_SIZE 5

sem_t full, empty;
int x = 0;
int buffer[BUFFER_SIZE];
int count = 0;

void wait_sem() {
    if (count == 0) {
        printf("Buffer is empty!\n");
        return;
    }
    count--;
}

void signal_sem() {
    if (count == BUFFER_SIZE) {
        printf("Buffer is full!\n");
        return;
    }
    count++;
}

void producer() {
    if (count == BUFFER_SIZE) {
        printf("Buffer is full!\n");
        return;
    }
    signal_sem();
    x++;
    printf("Producer has produced: Item %d\n", x);
}

void consumer() {
    if (count == 0) {
        printf("Buffer is empty!\n");
        return;
    }
    printf("Consumer has consumed: Item %d\n", x);
    x--;
    wait_sem();
}

int main() {
    int choice;
    sem_init(&full, 0, 0);
    sem_init(&empty, 0, BUFFER_SIZE);
    printf("\nEnter 1.Producer 2.Consumer 3.Exit\n");
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                producer();
                break;
            case 2:
                consumer();
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    
    sem_destroy(&full);
    sem_destroy(&empty);
    return 0;
}
