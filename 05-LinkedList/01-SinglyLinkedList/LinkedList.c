#include <stdio.h>

struct NODE
{
    int iNum;
    struct NODE *next;
};

int main(void)
{
    //function prototypes
    void CreateList(struct NODE **);
    void InsertLast(struct NODE *);
    void InsertFirst(struct NODE **);
    void InsertAt(struct NODE *, int);
    void DisplayList(struct NODE *);
    void DeleteList(struct NODE *);
    void DeleteFirst(struct NODE **);
    void DeleteLast(struct NODE **);
    void DeleteAt(struct NODE **, int);

    //variable declaration
    struct NODE *head = NULL;
    int choice, position;

    //code
    do
    {
        printf("\n\n");
        printf("List Menu : \n");
        printf("1->Create List\n");
        printf("2->Insert Node at last\n");
        printf("3->Insert Node at first\n");
        printf("4->Insert Node at user defined position\n");
        printf("5->Delete from first position\n");
        printf("6->Delete from last position\n");
        printf("7->Delete from user defined position\n");
        printf("8->Display List\n");
        printf("9->Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                CreateList(&head);
                break;

            case 2:
                InsertLast(head);
                break;

            case 3:
                InsertFirst(&head);
                break;

            case 4:
                printf("\n");
                printf("Insert data at position : ");
                scanf("%d", &position);
                if(position <= 1)
                {
                    printf("Invalid Position ! use Insert first for 1st position...\n");
                }    
                else
                {
                    InsertAt(head, position);
                }
                break;

            case 5:
                DeleteFirst(&head);
                break;

            case 6:
                DeleteLast(&head);
                break;

            case 7:
                printf("\n");
                printf("Insert data at position : ");
                scanf("%d", &position);
                DeleteAt(&head, position);
                break;

            case 8:
                DisplayList(head);
                break;

            case 9:
                printf("\nExiting Now...");
                DeleteList(head);
                head = NULL;
                break;

            default:
                printf("\n");
                printf("Enter a valid choice.\n");
                break;
        }

    }while(choice != 9);

    return (0);
}

void CreateList(struct NODE **head)
{
    //variable declaration
    struct NODE *ptr = NULL;

    if(*head == NULL)
    {
        //allocate memory for new node
        ptr = (struct NODE *)malloc(sizeof(struct NODE));
        if(ptr == NULL)
        {
            printf("\nMemory allocation faied. Exiting now...\n\n");
            return ;
        }
        else
        {
            printf("\nSuccessfully created list.\n\n");
        }
        

        printf("\n\n");
        printf("Enter data to be inserted at first node : ");
        scanf("%d", &(ptr->iNum));

        ptr->next = NULL;

        *head = ptr;
    }
    else
    {
        printf("\n\nList is already created !\n");
        return ;
    }   

    ptr = NULL;
}

void InsertLast(struct NODE *ptr)
{
    struct NODE *temp = NULL;

    //code
    if(ptr == NULL)
    {
        printf("\n\nThe List is not created ! Insert failed...\n");
        return ;
    }
    else
    {
        while(ptr->next != NULL)
        {
            ptr = ptr->next;
        }

        temp = (struct NODE *)malloc(sizeof(struct NODE));

        printf("\n");
        printf("Enter the data to be inserted : ");
        scanf("%d", &(temp->iNum));

        temp->next = NULL;

        ptr->next = temp;
    }
    
    ptr = NULL;
}

void InsertFirst(struct NODE **head)
{
    //variable declaration
    struct NODE *temp = NULL;

    if(*head == NULL)
    {
        printf("\n\nThe List is not created ! Insert failed...\n");
        return ;
    }
    else
    {
        //allocate memory for new node
        temp = (struct NODE *)malloc(sizeof(struct NODE));
        if(temp == NULL)
        {
            printf("\nMemory allocation failed ! Exiting Now...\n");
            return ;
        }

        printf("\n");
        printf("Enter the data to be inserted : ");
        scanf("%d", &(temp->iNum));

        temp->next = *head;
        *head = temp;
    }
    
    temp = NULL;
}

void InsertAt(struct NODE *ptr, int pos)
{
    //variable declaration
    struct NODE *temp = NULL;

    //code
    if(ptr == NULL)
    {
        printf("\n\nThe List is not created ! Insert failed...\n");
        return ;
    }
    else
    {
        for(int i = 1; i < pos - 1; i++)
        {
            if(ptr->next == NULL)
                break;

            ptr = ptr->next;
        }

        temp = (struct NODE *)malloc(sizeof(struct NODE));
        if(temp == NULL)
        {                        
            printf("\nMemory allocation failed ! Exiting Now...\n");
            return ;
        }

        printf("\n");
        printf("Insert data to be Inserted : ");
        scanf("%d", &(temp->iNum));

        if(ptr->next == NULL)
        {
            ptr->next = temp;
            temp->next = NULL;
        }
        else
        {
            temp->next = ptr->next;
            ptr->next = temp;
        }   
    }

    temp = NULL;
}


void DisplayList(struct NODE *ptr)
{
    if(ptr == NULL)
    {
        printf("List is not created. Nothing to display...\n");
        return ;
    }

    printf("\n\nList : \n");
    while(ptr->next != NULL)
    {
        printf("%d -> ", ptr->iNum);
        ptr = ptr->next;
    }

    printf("%d -> NULL", ptr->iNum);
    printf("\n");
}


void DeleteList(struct NODE *ptr)
{
    //variable declaration
    struct NODE *temp = NULL;

    //code
    if(ptr == NULL)
    {
        printf("\n");
        printf("List is empty.\n");
        return ;
    }

    while(ptr->next != NULL)
    {
        temp = ptr->next;
        free(ptr);
        ptr = temp;
    }
    
    if(ptr)
    {
        free(ptr);
        ptr = NULL;
        temp = NULL;
    }

    printf("\n\n");
    printf("Memory freed successfully.\n");
}


void DeleteFirst(struct NODE **head)
{
    //variable declaration
    struct NODE *temp = NULL;

    //code
    if(*head == NULL)
    {
        printf("\n");
        printf("List is not created.\n");
    }
    else
    {
        temp = *head;
        *head = (*head)->next;

        printf("\nElement %d is deleted.\n", temp->iNum);
        temp->next = NULL;
        free(temp);
        temp = NULL;
    }
}

void DeleteLast(struct NODE **head)
{
    //variable declaration
    struct NODE *temp = NULL;
    struct NODE *ptr = NULL;

    //code
    ptr = *head;
    if(ptr == NULL)
    {
        printf("\n");
        printf("List is not created.\n");
    }
    else
    {
        if(ptr->next == NULL)
        {
            printf("\n");
            printf("Element %d is deleted .\n", ptr->iNum);
            free(ptr);
            (*head) = NULL;
            ptr = NULL;
            temp = NULL;

            return;
        }

        while(ptr->next != NULL)
        {
            temp = ptr;
            ptr = ptr->next;
        }

        if(ptr)
        {
            printf("\n");
            printf("Element %d is deleted .\n", ptr->iNum);
            free(ptr);        
        }

        if(temp)
            temp->next = NULL;
    }
    
    ptr = NULL;
    temp = NULL;
}

void DeleteAt(struct NODE **head, int pos)
{
    //variable declaration
    struct NODE *temp = NULL;
    struct NODE *ptr = NULL;

    //code
    ptr = *head;
    if(ptr == NULL)
    {
        printf("\n");
        printf("List is not created.\n");
    }
    else
    {
        if(ptr->next == NULL)
        {
            free(ptr);
            *head = NULL;
            ptr = NULL;

            return;
        }

        if(pos == 1)
        {
            *head = ptr->next;

            ptr->next = NULL;
            free(ptr);
            return;
        }

        for(int i = 1; i < pos - 1; i++)
        {
            if(ptr->next == NULL)
                break;

            temp = ptr;
            ptr = ptr->next;
        }

        if(ptr->next != NULL)
        {
            temp = ptr->next;
            ptr->next = temp->next;
            free(temp);
        }
        else
        {
            temp->next = NULL;
            free(ptr);
        }
    }

    ptr = NULL;
    temp = NULL;
}
