// Adam Allard
// Week 5 Assignment 2
// This program reads and prints a joke and its punch line
//   from two different files. 

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void displayAllLines(ifstream &infile);
void displayLastLine(ifstream &infile);

int main()
{
	// open files
	ifstream joke("C:\\Users\\Dan\\Desktop\\joke.txt", ios::in);
	ifstream punchline("C:\\Users\\Dan\\Desktop\\punchline.txt", ios::in);


	// if the files open, call funtions with files as arguments
	if (joke)
		displayAllLines(joke);
	else 
		cout << "ERROR: Cannot open file." << endl;

	if (punchline)
		displayLastLine(punchline);
	else
		cout << "ERROR: Cannot open file." << endl;
	

	// close files
	joke.close();
	punchline.close();

	cout << endl;
	system("pause");
	return 0;
}

// this function reads the contents of a file passed to it
void displayAllLines(ifstream &infile)
{
	string line;

	getline(infile, line);

	while (infile)
	{
		cout << line << endl;
		getline(infile, line);
	}
}

// this function goes to the end of a file passed to it. then moves back one character
//   at a time until it finds a newline character ('\n')
//   once the newline char is found it prints the line after it. 
void displayLastLine(ifstream &infile)
{
	string line;
	char ch;		// to mark the current character
	long pos = -1;	// position index to move backwards on the last line

	// go to end of file
	infile.seekg(0L, ios::end);
	// move back one character
	infile.seekg(pos, ios::cur);
	// get character at current position and store it in ch
	infile.get(ch);
	
	// if current character is not a newline char, move back one position and check again
	while (ch != '\n')
	{
		pos--;
		infile.seekg(pos, ios::cur);
		infile.get(ch);
	}

	// once a newline character is found, read the next line.
	getline(infile, line);

	if (infile)
		cout << line << endl;
}