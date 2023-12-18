#include <stdio.h>
#include <stdlib.h>
struct Customer
{
    int id;
    int age;
    struct Customer* next;
};
struct Queue
        {
            struct Customer* front;
            struct Customer* rear;
        };
struct Customer* createCustomer(int id,int age)
        {
            struct Customer* newCustomer = (struct Customer*)malloc(sizeof(struct Customer));
            if (newCustomer == NULL)
            {
                printf(("memory is empty!!"));
                exit(EXIT_FAILURE);
            }
            newCustomer->id = id;
            newCustomer->age = age;
            newCustomer->next = NULL;
            return newCustomer;
        }
struct Queue* createQueue()
        {
            struct Queue* newQueue = (struct Queue*) malloc(sizeof (struct Queue));
            if ( newQueue == NULL)
            {
                printf("Memory is empty!!");
                exit(EXIT_FAILURE);
            }
            newQueue->front = newQueue->rear = NULL;
            return newQueue;
        }
void enqueue(struct Queue* queue,int id,int age)
{
            struct Customer* newCustomer = createCustomer(id,age);
            if (id == 3 || (id == 2 && queue->front == NULL))
            {
                newCustomer->next = queue->front;
                queue->front = newCustomer;
                if(queue->rear == NULL)
                {
                    queue->rear = newCustomer;
                }
                else {
                    if (queue->rear != NULL) {
                        queue->rear->next = newCustomer;
                    }
                    queue->rear = newCustomer;
                    if(queue->front == NULL)
                    {
                        queue->front = newCustomer;
                    }
                }
            }
}
struct Customer* dequeue(struct Queue* queue)
{
    if(queue ->front == NULL)
    {
        printf("kuyruk bos!!");
        return NULL;
    }
    struct Customer* dequeuedCustomer = queue->front;
    queue->front = queue->front->next;3
    if(queue->front == NULL)
    {
        queue->rear = NULL;
    }
    return dequeuedCustomer;
}
void displayQueue(struct Queue* queue)
{
    if(queue ->front == NULL)
    {
        printf("kuyruk bos!!");
        return;
    }
    struct Customer* current = queue->front;
    printf("Kuyruk:");
    while(current != NULL)
    {
        printf("(ID: %d, Yas: %d) -> ",current->id,current->age);
        current = current->next;
    }
    printf("NULL\n");
}
int main()
{
    struct Queue* bankQueue = createQueue();
    int choice,id,age;
    while(1 == 1){
        printf("*****MENU*****\n");
        printf("1- Kisi Ekle\n");
        printf("2- Kisi Isle\n");
        printf("3- Kuyruk Goruntule\n");
        printf("0- Cıkıs\n");
        scanf("%d",&choice);
        switch(choice)
    {
        case 1:
            printf("ID:");
            scanf("%d",&id);
            printf("Age:");
            scanf("%d",&age);
            enqueue(bankQueue,id,age);
            break;
        case 2:
            dequeue(bankQueue);
            break;
        case 3:
            displayQueue(bankQueue);
            break;
        case 0:
            return 0;
            break;
        default:
            printf("invalid value!!");
            break;
    }}
    return 0;
}