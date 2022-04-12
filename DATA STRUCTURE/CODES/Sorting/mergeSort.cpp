#include<iostream>

using namespace std;

void copyElements(int *array , int *temp , int startTemp , int startArray , int NumOfElements )
{
    while(NumOfElements > 0)
    {
        array[startArray++] = temp[startTemp++];
        NumOfElements--;
    }
}

void merge(int *array , int start, int mid , int end)
{
    if(array[mid-1] <= array[mid])
    return;
    int i = start;
    int j  = mid;
    int tempIndex = 0;
    int temp[end - start];

    while(i < mid && j < end)
    {
        temp[tempIndex++] = array[i]<=array[j] ? array[i++] : array[j++];
    }
    while(j < end)
    temp[tempIndex++] = array[j++];

    while(i < mid)
    temp[tempIndex++] = array[i++];

    copyElements(array , temp , 0 , start , tempIndex);
}

void MergeSort(int array[], int start , int end)
{
    if(end- start < 2)
    return;
    int mid = (start + end)/2;

    MergeSort(array , start , mid);
    MergeSort(array ,mid , end );

    merge(array , start , mid , end);

}

int main()
{
   int arr[] = {5,62,1,14,500,1,7,9,6,3,0};
	
	MergeSort(arr,0,sizeof(arr)/sizeof(arr[0]));

    for(int i = 0 ; i < sizeof(arr)/sizeof(arr[0]) ; i++)
	cout<<arr[i]<<" ";
}
