#include<iostream>
using namespace std;

void swap(int *a , int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void combSort(int *arr , int n )
{
	int step = n , j , k ;
	
	while((step = int(step/1.3)) > 1)
	{
		
		for(j  =  n -1 ; j >= step ; j--)
		{
			k = j-step;	
			if(arr[k] > arr[j])
			swap(&arr[k] , &arr[j]);
		}
	}
	
	bool flag = true;
	
	for( int i = 0 ; i < n -1 && flag ; i++)
	{
		for(int j = i +1  , flag = false ; j < n - i -1 ; j++)
		{
			if(arr[j-1] > arr[j])
			{
				swap(arr[j-1] , arr[j]);
				flag = true;	
			}
			
		}
	}
}

int main()
{
	
	int arr[] = {5,62,1,14,500,1,7,9,6,3,0};
	
	combSort(arr,sizeof(arr)/sizeof(arr[0]));
	
	for(int i = 0 ; i < sizeof(arr)/sizeof(arr[0]) ; i++)
	cout<<arr[i]<<" ";
}


