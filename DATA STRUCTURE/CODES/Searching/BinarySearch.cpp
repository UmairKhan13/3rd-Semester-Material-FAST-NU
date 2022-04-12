#include<iostream>
using namespace std;

int binarySearch(int array[] , int tail , int head , int key)
{
    if(tail <= head)
    {
        int mid = (tail + head )/2;
        if(array[mid] == key)
        return array[mid];
        if(array[mid] > key)
        binarySearch(array , tail , mid - 1 , key);
        if(array[mid] < key)
        binarySearch(array , mid + 1 , head , key);
    }
    return -1;
}

int main()
{
    int array[] = {4,6,2,5,7,3};
    int value = binarySearch(array , 0 , 6 , 1);
    cout<<value;
}