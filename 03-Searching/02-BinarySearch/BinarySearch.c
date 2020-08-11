#include <stdio.h>

#define SIZE 10

int main(void)
{
    //function prototypes
    void InsertEntry(int*,int);
    int BinarySearch(int[], int);
    void Display(int[], int);

    //variable declaration
    int Records[SIZE];
    int rPtr = 0;
    int choice, data, kIndex;

    //code
    do
    {   
        printf("\n\n");
        printf("Selct from below Menu :- \n");
        printf("1->Insert Entry in Record Table\n");
        printf("2->Search For Entry in Record Table\n");
        printf("3->Display Record Table\n");
        printf("4->Exit\n");
        printf("Enter Your Choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                if(rPtr < SIZE)
                {
                    printf("\n\n");
                    printf("Enter the data to be inserted in Record Table : ");
                    scanf("%d", &data);
                    InsertEntry(&Records[rPtr], data);
                    rPtr++;
                }
                else
                {
                    printf("\n\n");
                    printf("Record Table Full. Data Cannot be Inserted\n");
                }
                break;
            case 2:
                printf("Enter Key to be searched : ");
                scanf("%d", &data);
                kIndex = BinarySearch(Records, data);
                if(kIndex != -1)
                {
                    printf("The key is present in Record table at Entry %d.\n", (kIndex + 1));
                }
                else
                {
                    printf("\n\n");
                    printf("The Key is not present in Record Table!!!\n\n");
                }
                break;
            case 3:
                Display(Records, rPtr);
                break;
            case 4:
                printf("\n\n");
                break;
            default:
                printf("\n\n");
                printf("Please Enter a Valid choice!!\n");
                break;
        }

    }while(choice != 4);

    return (0);
}

void InsertEntry(int* arr_element, int data)
{
    *arr_element = data;
}

int BinarySearch(int arr[], int key)
{
    //variable declaration
    int left = 0;
    int right = SIZE - 1;
    int mid;

    //code
    while(left <= right)
    {
        mid = (left + right)/2;
        if(key == arr[mid])
            return (mid);
        else if(key < arr[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }

    return (-1);
}

void Display(int rTable[], int iPtr)
{
    int i;

    //code
    printf("\n\n");
    printf("***** Record Table *****\n\n");
    for(i = 0; i < iPtr; i++)
        printf("  Entry %d = %d\n", (i + 1), rTable[i]);
    
    printf("\n***** End ******");
}
