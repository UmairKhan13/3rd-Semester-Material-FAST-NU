#include<iostream>
#include<math.h>
using namespace std;
void swap(int *a , int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void shellSort(int *arr , int n)
{
    int gap = floor(n/2);

    while( gap >0 )
    {
        for(int i = 0 ; gap + i < n ; i++)
        {
            int temp = arr[i];
            int j = i;
            for (; j > 0 && arr[gap + j] < temp ; j--)
                swap(&arr[j] , &arr[j + gap]);
            arr[j] = temp ; 
        }
        gap = floor(gap/2);
    }
}

int main()
{
	
	int arr[] = {5,62,1,14,500,1,7,9,6,3,0};
	
	shellSort(arr,sizeof(arr)/sizeof(arr[0]));
	
	for(int i = 0 ; i < sizeof(arr)/sizeof(arr[0]) ; i++)
	cout<<arr[i]<<" ";
}
