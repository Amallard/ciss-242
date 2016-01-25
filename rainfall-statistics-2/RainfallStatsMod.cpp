#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

double getTotal(double[], int);
double getAverage(double[], int);
double getLowest(double[], int, int&);
double getHighest(double[], int, int&);
void sortList(double[], string[], int);

const int MONTHS = 12;
string months[MONTHS] = { "January", "February", "March", "April", "May", "June",
"July", "August", "September", "October", "November", "December" };
double rainFall[12];

int main()
{
	// get the rainfall for the 12 months
	cout << "Enter the rainfall for:" << endl << endl;
	for (int index = 0; index < 12; index++)
	{
		cout << left << setw(10);
		cout << months[index] << ": " << setw(5);
		cin >> rainFall[index];
	}

	int lowestMonth, highestMonth;
	double low, high;

	cout << endl;
	cout << "The total rainfall is " << getTotal(rainFall, MONTHS) << endl;
	cout << "The average rainfall is " << getAverage(rainFall, MONTHS) << endl;

	low = getLowest(rainFall, MONTHS, lowestMonth);
	high = getHighest(rainFall, MONTHS, highestMonth);

	cout << months[lowestMonth] << " has the lowest rainfall at " << low << endl;
	cout << months[highestMonth] << " has the highest rainfall at " << high << endl << endl;

	sortList(rainFall, months, MONTHS);

	system("pause");
	return 0;
}

double getTotal(double rainfall[], int size)
{
	double total = 0;
	for (int index = 0; index < size; index++)
	{
		total += rainfall[index];
	}
	return total;
}

double getAverage(double rainfall[], int months)
{
	double average = getTotal(rainfall, MONTHS) / months;
	return average;
}

double getLowest(double rainfall[], int size, int &lowestIndex)
{
	double lowest = rainfall[0];
	for (int index = 0; index < size; index++)
	{
		if (rainfall[index] <= lowest)
		{
			lowest = rainfall[index];
			lowestIndex = index;
		}
	}
	return lowest;
}
double getHighest(double rainfall[], int size, int &highestIndex)
{
	double highest = rainfall[0];
	for (int index = 0; index < size; index++)
	{
		if (rainfall[index] >= highest)
		{
			highest = rainfall[index];
			highestIndex = index;
		}
	}
	return highest;
} 

void sortList(double rainfall[], string month[], int size)
{
	bool swap;
	int tempCount;
	string tempMonth;

	do
	{
		swap = false;
		for (int count = 0; count < (size - 1); count++)
		{
			if (rainfall[count] < rainfall[count + 1])
			{
				tempCount = rainfall[count];
				tempMonth = month[count];

				rainfall[count] = rainfall[count + 1];
				month[count] = month[count + 1];

				rainfall[count + 1] = tempCount;
				month[count + 1] = tempMonth;

				swap = true;
			}
		}
	} while (swap);

	cout << "Here is the rainfall for all the months, from highest to lowest: " << endl;
	for (int index = 0; index < size; index++)
	{
		cout << left << setw(10);
		cout << month[index] << ": " << setw(5);
		cout << rainfall[index] << endl;
	}
	cout << endl;
}