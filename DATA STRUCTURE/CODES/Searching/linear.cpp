#include<iostream>
using namespace std;

int linearSearch(int array[] , int n , int key)
{
    for (int i = 0 ; i < n ; i ++)
    if(array[i] == key) return array[i]  ;
    return -1;
}

int main()
{
    int array[] = {4,6,2,5,7,3};
    int value = linearSearch(array , 6 , 5);
    cout<<value;
}
