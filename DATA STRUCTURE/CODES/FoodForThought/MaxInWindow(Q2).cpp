#include<iostream>
#include "ArrayException.h"
using namespace std;

int main()
{
	int n, k;
	int *ptrArray;
	int *WindowElement;
	cout << "Enter size of array: ";
	cin >> n;
	cout << "Enter size of window: ";
	cin >> k;

	ptrArray = new int[n];
	WindowElement = new int[n - (k - 1)];

	cout << "Enter element:" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> ptrArray[i];
	}

	for (int i = 0; i < n-(k-1); i++)
	{
		int max = ptrArray[i];

		for (int j = i; j < k; j++)
		{
			if (ptrArray[j]> max)
			{
				max = ptrArray[j];
			}
		}

		WindowElement[i] = max;
	}

	cout << endl;

	for (int i = 0; i < n - (k - 1); i++)
	{
		cout << WindowElement[i]<<",";
	}
}