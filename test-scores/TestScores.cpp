/*
* Adam Allard
* This program dynamically allocates an array large enough to hold a user defined 
* number of test scores. the array is then passed to a function that sorts the array
* in ascending order, and then another function to find the average. and finally to 
* a function that displays the sorted list with the average. 
*/

#include <iostream>
#include <iomanip>

using namespace std;

// function prototypes
void getGrades(double*, int);
void displayGrades(double*, int, double);
void sort(double*, int);
double average(double*, int);

int main() {
	double* testScores = nullptr;
	double averageScore;
	int temp;
	int numScores;

	cout << "How many test scores are there? ";
	cin >> temp;
	// validate user entry
	while (temp < 0)
	{
		cout << "Invalid number of scores." << endl;
		cout << "Cannot be negative." << endl;
		cout << "How many test scores are there? ";
		cin >> temp;
	}
	numScores = temp;
	// dynamically allocate array  
	testScores = new double[numScores];

	getGrades(testScores, numScores);
	sort(testScores, numScores);

	averageScore = average(testScores, numScores);

	displayGrades(testScores, numScores, averageScore);

	// free dynamically allocated memory
	delete [] testScores;
	testScores = nullptr;

	system("pause");
	return 0;
}

// this function gets the grades
void getGrades(double* scores, int size) {

	double grade;

	cout << endl << "Enter the grades below." << endl;
	for (int count = 0; count < size; count++)
	{
		cout << "Score of Test " << (count + 1) << ": ";
		cin >> grade;
		while (grade < 0)
		{
			cout << "Invalid test score." << endl;
			cout << "Score cannot be negative." << endl;
			cout << "Score of Test " << (count + 1) << ": ";
			cin >> grade;
		}
		scores[count] = grade;
	}
}

// this function displays the grades
void displayGrades(double* score, int size, double avg) {

	cout << setprecision(2) << fixed << endl;

	cout << "Score" << endl;
	// this is to attempt the underline under Score as shown in the expected output in syllabus
	for (int i = 0; i < 5; i++)
	   cout << char(196);
	cout << endl;

	for (int index = 0; index < size; index++)
	{
		cout << score[index] << endl;
	}
	
	cout  << "Average Score: " << avg << endl << endl;
}

// this function sorts the array in accending order
void sort(double* score, int size) {
	int startScan,
		minIndex;
	double minValue;
	for (startScan = 0; startScan < (size - 1); startScan++)
	{
		minIndex = startScan;
		minValue = score[startScan];
		for (int index = startScan + 1; index < size; index++)
		{
			if (score[index] < minValue)
			{
				minValue = score[index];
				minIndex = index;
			}
		}
		score[minIndex] = score[startScan];
		score[startScan] = minValue;
	}
}

// this function gets the average score of the grades
double average(double* score, int numScores) {
	double avg,
		   total = 0;
	for (int index = 0; index < numScores; index++)
	{
		total += score[index];
	}

	avg = total / numScores;

	return avg;
}