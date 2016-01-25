/*
* Adam Allard
* This program creates an array of ints, sends it to a function that creates  
* a new array twice the size of the passed array, and fills second half of the  
* array with 0. the new array is then passed to a function that displays the array.
* 
* I hope I did this correctly, because this seemed too easy.
*/

#include <iostream>

using namespace std;

// function prototypes 
int* expandArray(int[], int);
void showArray(int[], int);

int main() {
	const int SIZE = 5;
	int smallArray[SIZE] = { 1, 2, 3, 4, 5 };

	int* bigArray = expandArray(smallArray, SIZE);

	showArray(bigArray, (SIZE * 2));

	system("pause");
	return 0;
}

// this function accepts an array, and creates a new array twice the size filling
// the first half of the new array with the contents of the passed array. the function
// returns a pointer to the new function
int* expandArray(int array[], int size)
{
	int* newArray = nullptr;
	newArray = new int[(size * 2)];
	
	// fill first half of newArray with contents from passed array.
	for (int index = 0; index < (size); index++)
	{
		newArray[index] = array[index];
	}
	// fill the rest of the array with 0's.
	for (int index = size; index < (size * 2); index++)
	{
		newArray[index] = 0;
	}

	return newArray;
}

// this function shows the array it's passed
void showArray(int array[], int size)
{
	for (int index = 0; index < size; index++)
	{
		cout << array[index] << " ";
	}
	cout << endl;
}