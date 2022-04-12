#include<iostream>
using namespace std;

void mergeTwoArrays(int a[] , int b[] , int n , int m )
{
    int i = 0 , j  = 0 , k = 0;
    int temp[n + m ];
    while( i < n && j < m)
    {
        if(a[i] < b[j])
        {
            temp[k++] = a[i++];
        }
        else
        {
            temp[k++] = b[j++];
        }
        
    }
    while(j < m )
    temp[k++] = b[j++];

    while (i < n)
    temp[k++] = a[i++];
   
    for(int i =  0 ; i <  sizeof(temp)/sizeof(temp[0]) ; i++)
    cout<<temp[i]<<" ";
}

int main()
{
	
	int arr1[] = {54,62,78,89 ,500};
    int arr2[] = {1,3,4,6,8};
	
	mergeTwoArrays(arr1, arr2 ,  sizeof(arr1)/sizeof(arr1[0]) , sizeof(arr2)/sizeof(arr2[0]));
	
}