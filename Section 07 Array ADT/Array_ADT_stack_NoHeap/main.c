#include<stdio.h>
struct Array
{
    int A[10];
    int size;
    int length;
};

void Display(struct Array arr)
{
    int i;
    printf("\nElements are\n");
    for(i=0;i<arr.length;i++)
        printf("%d ",arr.A[i]);
    printf("\n");
}

/*Append element at the end of list
* Complexity: O(1)
*/

void Append(struct Array *arr,int x)
{
    if(arr->length<arr->size)
        arr->A[arr->length++]=x;
}

/*Insert element at an index location
 * Complexity:
 * Best Case -> O(1) . Insert at the end of array
 * Worst Case -> O(n). Insert at the beginning of array
*/
void Insert(struct Array *arr,int index,int x)
{
    int i;

    if(index>=0 && index <=arr->length)
    {
        for(i=arr->length;i>index;i--)
            arr->A[i]=arr->A[i-1];
        arr->A[index]=x;
        arr->length++;
    }
    else {
        printf("\nInvalid index passed.\n");
    }

}
/* delete element given by its index number
 * Complexity:
 * Best Case -> O(1). Delete the last element of array. No shifting of elements required.
 * Worst Case -> O(n). Delete the first (zeroth) element of array. Shift all the elements to left side.
*/
void deleteElementAtIndex(struct Array *arr,int index)
{
 int deletedValue=0 ,i =0;
        if(index>=0 && index<arr->length)
        {
            deletedValue = arr->A[index];
            for (i=index;i<arr->length-1;i++) // loop to shift elements. starting from deleted index to end of array.
            {
                arr->A[i] = arr->A[i+1];
            }
            arr->length--; //an element is deleted. Length of array is reduced.
            printf("\nValue %d deleted from array.\n",deletedValue);
        }
        else
            //index is invalid
            printf("\nIndex invalid!\n");

}

int main()
{
    struct Array arr1={{2,3,4,5,6,7},10,6};
    Display(arr1);
//    Append(&arr1,10);
//    Insert(&arr1,0,12);
    deleteElementAtIndex(&arr1,2);
    Display(arr1);
    return 0;
}
