#include <iostream>
#include <ctime>

class Arr
{
public:
	Arr(int size)
	{
		m_size = size;
		m_array = new int[size];

		for (int i = 0; i < size; i++)
		{
			m_array[i] = rand() % 100;
		}
	};
	~Arr() { delete[] m_array; };

	void print()
	{
		std::cout << "Array [ ";
		for (int i = 0; i < m_size; i++)
		{
			std::cout << m_array[i] << " ";
		}
		std::cout << "]" << std::endl;
	}
	int halfSize() { return m_size / 2; }
	int m_size;
	int* m_array;

private:

};

void bubbleSort(Arr* arr, int &iteration)
{
	//Ќачинаем с конца массива. сравниваем числа с текущим индексом и с индексом текущий - 1.
	//≈сли тек. число меньше, то мен€ем местами.
	//ѕосле каждой итерации минимальный индекс увеличитс€ на 1

	if ((arr->m_array == nullptr) || (arr->m_size == 0))
		return;
	
	for (int i = 0; i < arr->m_size; i++)
	{
		bool isSort = true;
		for (int j = arr->m_size - 1; j > i; j--)
		{
			iteration++;
			if (arr->m_array[j]< arr->m_array[j-1])
			{
				int temp = arr->m_array[j];
				arr->m_array[j] = arr->m_array[j - 1];
				arr->m_array[j - 1] = temp;
				isSort = false;
			}
		}
		if (isSort)
			break;
	}
}

void SelectionSort(Arr* arr, int& iteration)
{
	//«а один проход по массиву находим минимальное число.
	//ћен€ем минимальное число с крайним левым;
	//ѕосле каждой итерации индекс крайне левого числа увеличиваетс€ на 1

	if ((arr->m_array == nullptr) || (arr->m_size == 0))
		return;
	int min = 0;

	for (int i = 0; i < arr->m_size; i++)
	{
		
		min = i;
		for (int j = i; j < arr->m_size; j++)
		{
			iteration++;
			if (arr->m_array[j] < arr->m_array[min])
			{
				min = j;
			}
		}
		if (min != i)
		{
			int temp = arr->m_array[min];
			arr->m_array[min] = arr->m_array[i];
			arr->m_array[i] = temp;
		}
	}
}

void InsertionSort(Arr* arr, int& iteration)
{
	//¬начале крайний левый элемент считаетс€ отсортированным.
	//«атем беретс€ следующий элемент массива после отсортированного. 
	//Ётот элемент сравниваетс€ со всем отсортированными, если он меньше сравниваемого, тогда они мен€ютс€ местами
	//ѕосле того, как элемент встал на свое место в отсортированной части индекс отсортированных элементов увеличиваетс€ на 1

	int AlreadySort = 0;
	for (int i = 1; i < arr->m_size; i++)
	{
		AlreadySort++;
		int current = AlreadySort;
		for (int j = AlreadySort - 1; j >= 0; j--)
		{
			iteration++;
			if (arr->m_array[current] < arr->m_array[j])
			{
				int temp = arr->m_array[current];
				arr->m_array[current] = arr->m_array[j];
				arr->m_array[j] = temp;
				current = j;
			}
		}
		
	}
}


#include <iostream>
using namespace std;
// Swap two elements - Utility function  
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

// partition the array using last element as pivot
int partition(int arr[], int low, int high)
{
	int pivot = arr[high];    // pivot 
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{
		//if current element is smaller than pivot, increment the low element
		//swap elements at i and j
		if (arr[j] <= pivot)
		{
			i++;    // increment index of smaller element 
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

//quicksort algorithm
void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		//partition the array 
		int pivot = partition(arr, low, high);

		//sort the sub arrays independently 
		quickSort(arr, low, pivot - 1);
		quickSort(arr, pivot + 1, high);
	}
}

void displayArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << "\t";

}

//int main()
//{
//	int arr[] = { 12,23,3,43,51,35,19,45 };
//	int n = sizeof(arr) / sizeof(arr[0]);
//	cout << "Input array" << endl;
//	displayArray(arr, n);
//	cout << endl;
//	quickSort(arr, 0, n - 1);
//	cout << "Array sorted with quick sort" << endl;
//	displayArray(arr, n);
//	return 0;
//}

int main()
{
	std::srand(static_cast<unsigned int>(time(0)));

	Arr myArr(4);
	
	myArr.print();
	
	int iteration = 0;

	//InsertionSort(&myArr, iteration);
	quickSort(myArr.m_array, 0, myArr.m_size - 1);

	std::cout << "=============================================================" << std::endl;
	std::cout << "Count of iter = " << iteration << std::endl;

	myArr.print();

	return 0;
}