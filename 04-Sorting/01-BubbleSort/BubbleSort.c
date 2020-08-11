#include <stdio.h>
#include <stdlib.h>

enum
{
    FALSE,
    TRUE
};

int main(void)
{
    //function prototype
    void BubbleSort(int*, int);

    //variable declaration
    int *iArray = NULL;
    int size, i;

    //code
    printf("\n");
    printf("Enter the number of elements to sort : ");
    scanf("%d", &size);

    iArray = (int *)malloc(size * sizeof(int));
    if(iArray == NULL)
    {
        printf("Memory allocation failed !! Exiting Now...\n");
        exit(0);
    }

    printf("\n");
    printf("Enter the elements to sort : \n");
    for(i = 0; i < size; i++)
    {
        printf("Element %d : ", i + 1);
        scanf("%d", (iArray + i));
    }

    //display unsorted array
    printf("\n\n");
    printf("Unsorted Array : \n");
    for(i = 0; i < size; i++)
    {
        printf("iArray[%d] = %d\n", i, iArray[i]);
    }

    //sort the array
    BubbleSort(iArray, size);

    //display sorted array
    printf("\n\n");
    printf("Sorted Array : \n");
    for(i = 0; i < size; i++)
    {
        printf("iArray[%d] = %d\n", i, iArray[i]);
    }


    //freeing memory
    if(iArray)
    {
        free(iArray);
        iArray = NULL;
    }

    return (0);
}

void BubbleSort(int arr[], int size)
{
    //variable declaration
    int pass, i, j, temp;
    int swap = TRUE;

    //code
    for(pass = 0; pass < size - 1 && swap == TRUE; pass++)
    {
        swap = FALSE;
        printf("\n\n");
        printf("Pass %d : \n", pass + 1);
        for(j = 0; j < size - pass - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                swap = TRUE;
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }

        for(i = 0; i < size; i++)
        {
            printf("%d\t", arr[i]);
        }
    }

}