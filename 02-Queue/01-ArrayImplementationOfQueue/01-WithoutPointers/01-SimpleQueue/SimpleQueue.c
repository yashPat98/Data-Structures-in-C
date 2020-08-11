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
                Insert(data);             
                break;
            case 2:
                Remove();
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
    if(MyQueue.rear < (MAXQUEUE - 1))
    {
        MyQueue.rear++;
        MyQueue.items[MyQueue.rear] = data;
    }
    else
    {
        printf("The Queue is Full!!!\n\n");
    }
    
}

int Remove(void)
{
    //variable declaration
    int data;

    //code
    if(MyQueue.rear < MyQueue.front)
    {
        printf("The Queue is Empty!!!\n\n");
        return (-1);
    }
    else
    {    
        data = MyQueue.items[MyQueue.front];
        MyQueue.front++;
        printf("The Data %d is removed from Queue!!\n\n", data);
    }

    return (data);
}

void Display(void)
{
    //code
    printf("***** Queue *****\n");
    for(int i = MyQueue.front; i <= MyQueue.rear; i++)
        printf("\t%d \n", MyQueue.items[i]);

}
