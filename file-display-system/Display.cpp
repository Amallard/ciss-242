// Adam Allard
// Week 5 Assignment 1
// This program asks the user for the name of the file, then displays
//    the content of the file on the screen up to 24 lines. when the 
//    user wants to see more of the file he/she will strike a key and
//    the next 24 lines of the file will be displayed

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	ifstream inputFile;
	string userFile;		// for user to specify name of file 
	string input;			// for data from file
	int count = 0;			// accumulator

	cout << "What is the name of the file? ";
	cin >> userFile;
	
	inputFile.open(userFile, ios::in);

	// if the file opens successfully
	if (inputFile)
	{
		// read one line from the file inputFile
		getline(inputFile, input);
		
		while (inputFile)
		{
			// print the one line from the file inputFile
			cout << input << endl;
			// add one to the count to know how many lines have been printed
			count++;

			// if 24 lines have been printed, pause the program until user strikes a key
			if (count == 24)
			{
				system("pause");
				// reset the count to start over
				count = 0;
			}
			// read the next line from the file inputFile
			getline(inputFile, input);
		}
		inputFile.close();
	}
	// if inputFile fails to open
	else
	{
		cout << "ERROR: Cannot open file " << userFile << endl;
	}

	system("pause");
	return 0;
}