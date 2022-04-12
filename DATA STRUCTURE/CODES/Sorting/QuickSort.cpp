#include<iostream>
using namespace std;

int Partition(int *array , int i , int j)
{
    int pivot = array[i];
    while (i < j)
    {
        while(i < j && array[--j] >= pivot );
        if(i < j)
        array[i] = array[j];

        while(i < j && array[++i] <= pivot);
        if(i < j)
        array[j]= array[i];
    }

    array[j] = pivot;

    return j;
    
}

void QuickSort(int *array , int start , int end)
{
    if(end-start < 2)
    return;

    int pivotIndex = Partition(array , start , end);
    QuickSort(array , start , pivotIndex);
    QuickSort(array , pivotIndex+1 , end);

}


int main()
{
   int arr[] = {5,62,1,14,500,1,7,9,6,3,0};
	
	QuickSort(arr,0,sizeof(arr)/sizeof(arr[0]));

    for(int i = 0 ; i < sizeof(arr)/sizeof(arr[0]) ; i++)
	cout<<arr[i]<<" ";
}
