#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    //function prototype
    void SelectionSort(int*, int);

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
    SelectionSort(iArray, size);

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

void SelectionSort(int arr[], int size)
{
    //code
    int i, index, j, large, last;
    int k = 1;

    //code
    for(last = size - 1; last > 0; last--)
    {
        large = arr[0];
        index = 0;
        
        printf("\n\n");
        printf("Pass %d : \n", k++);
        for(j = 1; j <= last; j++)
        {
            if(arr[j] > large)
            {
                large = arr[j];
                index = j;
            }

        }
        arr[index] = arr[last];
        arr[last] = large;

        for(i = 0; i < size; i++)
        {
            printf("%d\t", arr[i]);
        }
    }
}