#include<iostream>
#include<conio.h>
using namespace std;

int maxNum(int *array  , int n )
{
    int max = array[0];

    for(int i = 1 ; i < n; i++)
    {
        if(array[i] > max)
        max = array[i];
    }

    return max;
}

void countingSort(int *array , int n )
{
    // int n = sizeof(array)/sizeof(array[0]);
    int max = maxNum(array , n);
    int countArray[max] = {0};

    for(int i = 0 ; i < n ; i ++)
    countArray[ array[i] ]++;

    int k = 0 ;
    for(int i = 0 ; i <= max ; i++)
    {
        int temp = countArray[i];
        for(int j = 0 ; j < temp; j++)
        {
            array[k++] = i;
        }
    }

    for(int j = 0 ; j < n ; j++)
    cout<<array[j]<<" ";

}

int main()
{
   int arr[] = {5,62,1,14,500,1,9,9,6,3,0};
	
	countingSort(arr ,11 );

    // for(int i = 0 ; i < sizeof(arr)/sizeof(arr[0]) ; i++)
	// cout<<arr[i]<<" ";
}
