#include <iostream>
#include <iostream>
#include <stdlib.h> 
#include <stdio.h>
#include <time.h>
#include <string.h>
using namespace std;

void eratostenes(bool arr[], int size)
{
	for (int i = 2; i < size; i++)
	{
		if (arr[i])
		{
			for (int j = 2; i * j < size; j++)
			{
				arr[i * j] = false;
			}
		}
	}
}

void trunctRight(bool arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i])
		{
			for (int j = i; j != 0; j /= 10)
			{
				if (!arr[j])
				{
					arr[i] = false;
				}
			}
		}
	}
}

int main()
{
	int size = 100000000;
	bool* arr = new bool[size];

	for (int i = 0; i < size; i++)
	{
		arr[i] = true;
	}

	arr[0] = arr[1] = false;

	eratostenes(arr, size);
	trunctRight(arr, size);
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i]) {
			cout << i << endl;
			sum++;
		}
	}
	cout << endl << "There are excatly " << sum << " right truncatable primes in base 10." << endl;

	return 0;
}