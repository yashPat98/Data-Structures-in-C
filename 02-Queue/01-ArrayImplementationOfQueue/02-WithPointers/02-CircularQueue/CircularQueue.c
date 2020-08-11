#include <stdio.h>

#define MAXQUEUE 5

enum
{
    FALSE,
    TRUE
}; 

struct QUEUE
{
    int items[MAXQUEUE];
    int front, rear;
};          

//Entry Point Function
int main(void)
{
    //function prototypes
    void Insert(struct QUEUE *, int);
    int Remove(struct QUEUE *);
    void Display(struct QUEUE *);

    //variable declaration
    int i, choice, data;
    struct QUEUE MyQueue;

    //code
    for(i = 0; i < MAXQUEUE; i++)
        MyQueue.items[i] = 0;

    MyQueue.front = MAXQUEUE - 1;
    MyQueue.rear  = MAXQUEUE - 1;

    do
    {
        printf("\n\n");
        printf("Queue Menu : \n");
        printf("1->Insert element into Queue.\n");
        printf("2->Remove element from Queue.\n");
        printf("3->Display Queue.\n");
        printf("4->Exit.\n");
        printf("Select from above menu : ");
        scanf("%d", &choice);

        printf("\n\n");
        switch(choice)
        {
            case 1:
                printf("Enter the data to be Inserted : ");
                scanf("%d", &data);
                Insert(&MyQueue, data);             
                break;
            case 2:
                data = Remove(&MyQueue);
                if(data != 0)
                {
                    printf("The data %d is Removed from Queue.\n\n", data);
                }
                break;
            case 3:
                Display(&MyQueue);
                break;
            case 4:
                printf("Exiting From Queue Menu\n\n");
                break;
            default:
                printf("Please enter valid choice !!!");
                break;
        }
        
    }while(choice != 4);

    return (0);
}


void Insert(struct QUEUE *q, int data)
{
    //code
    if(q->rear == (MAXQUEUE - 1))
        q->rear = 0;
    else
        q->rear++;

    if(q->rear == q->front)
    {
        q->rear--;
        printf("The Queue is Full. Data Cannot be inserted!!!\n\n");
        return;
    }

    q->items[q->rear] = data;
}

int Remove(struct QUEUE *q)
{
    //function prototype
    int IsEmpty(struct QUEUE *);

    //variable declaration
    int data;

    //code
    if(IsEmpty(q))
    {
        printf("The Queue is Empty!!!\n\n");
        return (0);
    }

    if(q->front == (MAXQUEUE - 1))
        q->front = 0;
    else
        q->front++;

    data = q->items[q->front];
    q->items[q->front] = 0;

    return (data);
}

int IsEmpty(struct QUEUE *q)
{
    if(q->front == q->rear)
        return (TRUE);
    else
        return (FALSE);
}

void Display(struct QUEUE *q)
{
    //code
    printf("***** Queue *****\n");
    for(int i = 0; i < MAXQUEUE; i++)
    {
        printf("\t%d ", q->items[i]);
        if(i == q->front)
            printf("Front\n");
        else if(i == q->rear || q->rear == -1)
            printf("Rear\n");
        else
            printf("\n");
    }
}
