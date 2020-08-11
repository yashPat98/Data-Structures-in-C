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
} MyQueue;          //declaraing struct variable

//Entry Point Function
int main(void)
{
    //function prototypes
    void Insert(int);
    int Remove(void);
    void Display(void);

    //variable declaration
    int choice, data;

    //code
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
                Insert(data);             
                break;
            case 2:
                data = Remove();
                if(data != 0)
                {
                    printf("The data %d is Removed from Queue.\n\n", data);
                }
                break;
            case 3:
                Display();
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


void Insert(int data)
{
    //code
    if(MyQueue.rear == (MAXQUEUE - 1))
        MyQueue.rear = 0;
    else
        MyQueue.rear++;

    if(MyQueue.rear == MyQueue.front)
    {
        MyQueue.rear--;
        printf("The Queue is Full. Data Cannot be inserted!!!\n\n");
        return;
    }

    MyQueue.items[MyQueue.rear] = data;
}

int Remove(void)
{
    //function prototype
    int IsEmpty(void);

    //variable declaration
    int data;

    //code
    if(IsEmpty())
    {
        printf("The Queue is Empty!!!\n\n");
        return (0);
    }

    if(MyQueue.front == (MAXQUEUE - 1))
        MyQueue.front = 0;
    else
        MyQueue.front++;

    data = MyQueue.items[MyQueue.front];
    MyQueue.items[MyQueue.front] = 0;

    return (data);
}

int IsEmpty(void)
{
    if(MyQueue.front == MyQueue.rear)
        return (TRUE);
    else
        return (FALSE);
}

void Display(void)
{
    //code
    printf("***** Queue *****\n");
    for(int i = 0; i < MAXQUEUE; i++)
    {
        printf("\t%d ", MyQueue.items[i]);
        if(i == MyQueue.front)
            printf("Front\n");
        else if(i == MyQueue.rear || MyQueue.rear == -1)
            printf("Rear\n");
        else
            printf("\n");
    }
}
