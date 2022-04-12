#include<iostream>

using namespace std;

void selectionSort(int array[] , int n)
{
    for (int i = 0 ; i < n; i++)
    {
        int min = i;

        for (int j = i+1; j < n; j++)
        {
            if(array[j] < array[min])
            min = j;
        }
        
        int temp = array[min];
        array[min] = array[i];
        array[i] = temp;
    }

    for(int i = 0 ;i < n ; i ++)
    cout<<array[i]<<" , ";
    
}

int main()
{
    int arr[5] = {4,9,1,0,5};
    selectionSort(arr, 5);
}