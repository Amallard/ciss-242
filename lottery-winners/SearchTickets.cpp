#include <iostream>
using namespace std;

int linearSearch(int[], int, int);
void sortArray(int[], int);
int binarySearch(int[], int, int);


int main() 
{
	const int SIZE = 10;
	int luckyNums[SIZE] = { 13579, 62483, 26791, 77777, 26792,
		79422, 33445, 85647, 55555, 93212 };
	int winningNum, results;

	cout << "Enter in this week's winning number: ";
	cin >> winningNum;

	cout << endl << "Checking your tickets using a linear search..." << endl;
	results = linearSearch(luckyNums, SIZE, winningNum);
	if (results == -1)
	{ 
		cout << "Sorry, you did not win. Let's try a binary search just to make sure." << endl;
	}
	else
	{
		cout << "Your ticket " << luckyNums[results] << " won!" << endl;
	}

	cout << "Checking your tickets using a binary search..." << endl;
	sortArray(luckyNums, SIZE);
	results = binarySearch(luckyNums, SIZE, winningNum);
	if (results == -1)
	{
		cout << "Sorry, you still did not win. Better luck next week." << endl;
	}
	else
	{
		cout << "Your ticket " << luckyNums[results] << " still won!" << endl;
	}
	cout << endl;

	system("pause");
	return 0;
}

int linearSearch(int list[], int numElems, int value) 
{
	int index = 0,
		position = -1;
	bool found = false;

	while (index < numElems && !found)
	{
		if (list[index] == value)
		{
			found = true;
			position = index;
		}
		index++;
	}
	return position;
}

void sortArray(int list[], int size)
{
	bool swap;
	int temp;

	do
	{
		swap = false;
		for (int count = 0; count < (size - 1); count++)
		{
			if (list[count] > list[count + 1])
			{
				temp = list[count];
				list[count] = list[count + 1];
				list[count + 1] = temp;
				swap = true;
			}
		}
	} while (swap);
}

int binarySearch(int list[], int size, int value)
{
	int first = 0,
		last = size - 1,
		middle,
		position = -1;
	bool found = false;

	while (!found && first <= last)
	{
		middle = (first + last) / 2;
		if (list[middle] == value)
		{
			found = true;
			position = middle;
		}
		else if (list[middle] > value)
		{
			last = middle - 1;
		}
		else
			first = middle + 1;
	}
	return position;
}