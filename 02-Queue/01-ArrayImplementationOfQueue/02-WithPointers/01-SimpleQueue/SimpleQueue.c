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
    int choice, data;
    struct QUEUE MyQueue;

    //code
    MyQueue.front = 0;
    MyQueue.rear  = -1;
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
                Remove(&MyQueue);
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
    if(q->rear < (MAXQUEUE - 1))
    {
        q->rear++;
        q->items[q->rear] = data;
    }
    else
    {
        printf("The Queue is Full!!!\n\n");
    }
    
}

int Remove(struct QUEUE *q)
{
    //variable declaration
    int data;

    //code
    if(q->rear < q->front)
    {
        printf("The Queue is Empty!!!\n\n");
        return (-1);
    }
    else
    {    
        data = q->items[q->front];
        q->front++;
        printf("The Data %d is removed from Queue!!\n\n", data);
    }

    return (data);
}

void Display(struct QUEUE *q)
{
    //code
    printf("***** Queue *****\n");
    for(int i = q->front; i <= q->rear; i++)
        printf("\t%d \n", q->items[i]);

}
