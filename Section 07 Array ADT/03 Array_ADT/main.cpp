#include <iostream>

using namespace std;

struct Array_ADT
{
    int *A;
    int size;
    int length;
};

void display(Array_ADT arr)
{
    cout << "Display() array\n" << flush;
    for (int i=0;i<arr.length;i++) {
        cout << " " << arr.A[i];
    }
    cout << endl;
}

void append(Array_ADT &arr, int x)
{
    if(arr.length < arr.size) // check if array has free index locations
    {
        arr.A[arr.length] = x; //value appended at end of array sucessfully.
        arr.length++; // number of elements in array increased.
    }
}

int main()
{
    Array_ADT myarr; unsigned maxSizeofArray;
    cout << "Enter max size of array" << endl;
    cin >> maxSizeofArray;

    // create array in heap of size "maxSizeofArray".
    myarr.A = new int[maxSizeofArray];

    //set a length of array or number of elements.
    cout << "Enter length of array: "; cin >> myarr.length;

    // initialize array
    cout << endl;
    for (int i =0;i<myarr.length;i++)
    {
        cout << "index " << i << " :" ;
        cin >> myarr.A[i];
    }

//    // display array ADT elements
//    display(myarr);

    //append an element in ADT.
    append(myarr,8);

    display(myarr);


    return 0;
}
