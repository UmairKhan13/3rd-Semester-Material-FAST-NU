#include<iostream>
using namespace std;

void insertionSort(int array[], int n)
{
    for(int i = 1 ; i < n ; i++)
    {
        int temp = array[i];
        int j = i;
        for ( ; j > 0 && array[j-1] > temp; j--)
        {
            array[j]  = array[j-1];
        }
        
        array[j] = temp;
    }

    for(int i = 0 ;i < n ; i ++)
    cout<<array[i]<<" , ";
}

int main()
{
    int arr[5] = {4,9,1,0,5};
    insertionSort(arr, 5);
}