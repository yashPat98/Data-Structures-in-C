#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    //function prototype
    void InsertionSort(int*, int);

    //variable declaration
    int *iArray = NULL;
    int i, size;

    printf("\n\n");
    printf("Enter the number of elements to sort : ");
    scanf("%d", &size);

    //allocate memory 
    iArray = (int *)malloc(size * sizeof(int));
    if(iArray == NULL)
    {
        printf("\n");
        printf("Memory allocation failed!!! Exiting Now..\n");
        exit(0);
    }

    printf("Enter the elemets : \n");
    for(i = 0; i < size; i++)
    {
        printf("Element %d : ", i + 1);
        scanf("%d", iArray + i);
    }

    //display unsorted array
    printf("\n\n");
    printf("Unsorted array : \n");
    for(i = 0; i < size; i++)
    {
        printf("iArray[%d] = %d\n", i, iArray[i]);
    }

    //sort
    InsertionSort(iArray, size);

    //display sorted array
    printf("\n\n");
    printf("Sorted array : \n");
    for(i = 0; i < size; i++)
    {
        printf("iArray[%d] = %d\n", i, iArray[i]);
    }

    //free the memory
    if(iArray)
    {
        free(iArray);
        iArray = NULL;
    }

    return (0);
}

void InsertionSort(int arr[], int size)
{
    //variable declaration
    int i, j, temp;

    //code
    printf("\n\n");
    for(i = 1; i < size; i++)
    {
        temp = arr[i];
        for(j = i - 1; j >= 0 && temp < arr[j]; j--)
        {
            arr[j + 1] = arr[j];
        }

        arr[j + 1] = temp;

        printf("Iteration %d\n\n", i);
        for(int k = 0; k < size; k++)
        {
            printf("%d\t", arr[k]);
        }

        printf("\n");
    }

}