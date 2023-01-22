#include <iostream>

using namespace std;

template <class T>
int IndexOf(T arr[], int size, T value);

template <class T>
void Sort(T arr[], int size);

template <class T>
void FillArray(T arr[], int size);

template <class T>
void PrintArray(T arr[], int size);

int main()
{
	setlocale(0, "");
	srand(time(NULL));

	const int size{ 10 };
	int arr[size]{};

	FillArray(arr, size);
	PrintArray(arr, size);
	Sort(arr, size);
	PrintArray(arr, size);

	cout << IndexOf(arr, size, 10) << endl;
}

template<class T>
int IndexOf(T arr[], int size, T value)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == value)
			return arr[i];
	}

	return -1;
}

template<class T>
void Sort(T arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		auto swapValue = arr[i];
		auto swapIndex = i;

		for (int j = i + 1; j < size; j++)
		{
			if (swapValue > arr[j])
			{
				swapValue = arr[j];
				swapIndex = j;
			}
		}

		if (swapIndex == i)
			continue;

		auto tmp = arr[i];
		arr[i] = swapValue;
		arr[swapIndex] = tmp;
	}
}

template<class T>
void FillArray(T arr[], int size)
{
	for (int i = 0; i < size; i++)
		arr[i] = rand() % 100;
}

template<class T>
void PrintArray(T arr[], int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << ' ';

	cout << endl;
}