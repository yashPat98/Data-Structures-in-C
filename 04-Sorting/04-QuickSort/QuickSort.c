//headers
#include <stdio.h>
#include <stdlib.h>

//main() - entry point function
int main(void)
{
    //function prototypes
    void QuickSort(int *, int, int);

    //variable declarations
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
        printf("Memory Allocation failed !! Exiting Now...\n");
        exit(0);
    }

    printf("Enter the elements : \n");
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
    QuickSort(iArray, 0, size - 1);

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


//QuickSort() -  sorts array in ascending order
void QuickSort(int arr[], int left, int right)
{
    //function declaration
    void swap(int arr[], int i, int j);

    //variable declaration
    int i, last;

    if(left >= right)       //do nothing if array contains fewer elements than 2
        return ;

    swap(arr, left, (left + right) / 2);
    last = left;

    for(i = left + 1; i <= right; i++)
        if(arr[i] < arr[left])
            swap(arr, ++last, i);

    swap(arr, left, last);
    QuickSort(arr, left, last - 1);
    QuickSort(arr, last + 1, right);
}

void swap(int arr[], int i, int j)
{
    //variable declaration
    int temp;

    //code
    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

