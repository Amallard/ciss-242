// Adam Allard
// Course Project - DVD Collection
// This program keeps track of a user's DVD collection. It makes use of the DVD class to create the DVDs, and 
// the DVD_Manager class to manage the DVD's. It allows a user to add, delete, and update
// up to 5 DVDs. Welcome to the future. 

#include <iostream>
#include <string>
#include "DVD_Manager.h"
#include "DVD.h"
using namespace std;

void displayMenu(DVD[]);
void addDVD(DVD[]);
void deleteDVD(DVD[]);
void updateDVD(DVD[]);
void showDVDs(DVD[]);

int main()
{
	DVD myDVDs[5];

	displayMenu(myDVDs);

	cout << endl;
	system("pause");
	return 0;
}

// this function displays the menu and prompts the user to enter a menu selection, upon which will call the selected option
void displayMenu(DVD movies[])
{
	short option;
	// draw line across terminal
	for (int i = 0; i < 80; i++)
		cout << char(196);

	cout << "DVD Collection Menu" << endl;
	// draw line across terminal
	for (int i = 0; i < 80; i++)
		cout << char(196);

	// menu options
	cout << "1. Add DVD" << endl
		 << "2. Delete DVD" << endl
		 << "3. Update DVD" << endl
		 << "4. Show all DVDs" << endl
		 << "5. Exit" << endl;
	cout << "What would you like to do: ";
	cin >> option;
	cout << endl;

	// validate user entry
	while (option != 1 && option != 2 && option != 3 && option != 4 && option != 5)
	{
		cout << "Invalid menu seletion."		<< endl
			 << "Please enter a number 1 - 5."	<< endl
			 << "What would you like to do: ";
		cin >> option;

	}

	// call respective function from user's choice
	switch (option)
	{
	case 1:
		addDVD(movies);
		break;
	case 2:
		deleteDVD(movies);
		break;
	case 3:
		updateDVD(movies);
		break;
	case 4:
		showDVDs(movies);
		break;
	case 5:
		std::exit;
	}
}

// this function adds a DVD to the selection. if a space is open (the title is empty), it creates the DVD 
// in the first empty spot
void addDVD(DVD movies[])
{
	DVD_Manager manage;
	
	for (int i = 0; i < 5; i++)
	{
		if (movies[i].getTitle() == "(empty)")
		{
			manage.addDVD(movies[i]);
			break;
		}
	}

	displayMenu(movies);
}

// this function deletes a DVD. it prompts the user to enter a DVD they wish to delete, then calls the 
// DVD_Manager class to delete the DVD
void deleteDVD(DVD movies[])
{
	DVD_Manager manage;
	string input;

	cout << "What DVD would you like to delete? ";
	cin.ignore();
	getline(cin, input);
	for (int i = 0; i < 5; i++)
	{
		if (input == movies[i].getTitle())
		{
			manage.deleteDVD(movies[i]);
			break;
		}
	}

	displayMenu(movies);
}

// this function updates a user defined DVD by calling the DVD_Manager object 
void updateDVD(DVD movies[])
{
	DVD_Manager manage;
	string input;

	cout << "What DVD would you like to update? ";
	cin.ignore();
	getline(cin, input);
	for (int i = 0; i < 5; i++)
	{
		if (input == movies[i].getTitle())
		{
			manage.updateDVD(movies[i]);
			break;
		}
	}
	displayMenu(movies);
}

// this function displays the DVD collection list
void showDVDs(DVD movies[])
{
	for (int i = 0; i < 5; i++)
	{
		cout << "Title:  " << movies[i].getTitle() << endl;
		cout << "Length: " << movies[i].getMovieLength() << " minutes" << endl;
		cout << "Year:   " << movies[i].getYear() << endl;
		cout << "Actor:  " << movies[i].getActor1() << endl;
		cout << "Actor:  " << movies[i].getActor2() << endl << endl;
	}

	displayMenu(movies);
}