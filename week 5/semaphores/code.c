#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define BUFFER_SIZE 5

sem_t full, empty;
pthread_mutex_t mutex;
int x = 0;
int buffer[BUFFER_SIZE];
int count = 0;

void wait_sem()
{
    pthread_mutex_lock(&mutex);
    if (count == 0)
    {
        printf("Buffer is empty!\n");
        pthread_mutex_unlock(&mutex);
        return;
    }
    count--;
    pthread_mutex_unlock(&mutex);
}

void signal_sem()
{
    pthread_mutex_lock(&mutex);
    if (count == BUFFER_SIZE)
    {
        printf("Buffer is full!\n");
        pthread_mutex_unlock(&mutex);
        return;
    }
    count++;
    pthread_mutex_unlock(&mutex);
}

void producer()
{
    if (count == BUFFER_SIZE)
    {
        printf("Buffer is full!\n");
        return;
    }
    signal_sem();
    x++;
    printf("Producer has produced: Item %d\n", x);
}

void consumer()
{
    if (count == 0)
    {
        printf("Buffer is empty!\n");
        return;
    }
    printf("Consumer has consumed: Item %d\n", x);
    x--;
    wait_sem();
}

int main()
{
    int choice;
    sem_init(&full, 0, 0);
    sem_init(&empty, 0, BUFFER_SIZE);
    pthread_mutex_init(&mutex, NULL);
    
    printf("\nEnter 1.Producer 2.Consumer 3.Exit\n");
    while (1)
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice)
        {
            case 1:
                producer();
                break;
            case 2:
                consumer();
                break;
            case 3:
                pthread_mutex_destroy(&mutex);
                sem_destroy(&full);
                sem_destroy(&empty);
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}
