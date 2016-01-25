// Adam Allard
// Course Project
// This implementation file manages dvds from the DVD class. implements addDVD, deleteDVD, and updateDVD methods

#include "DVD_Manager.h"

// used to add a DVD object
void DVD_Manager::addDVD(DVD &movie)
{
	string inputS;
	int inputI;

	cout << endl << "What is the DVD title? ";
	cin.ignore();
	getline(cin, inputS);
	movie.setTitle(inputS);
	

	cout << "How long is the movie (in minutes)? ";
	cin >> inputI;
	movie.setMovieLength(inputI);

	cout << "What year did the movie come out? ";
	cin >> inputI;
	movie.setYear(inputI);

	cout << "Who is the first main actor? ";
	cin.ignore();
	getline(cin, inputS);
	movie.setActor1(inputS);

	cout << "Who is the next main actor? ";
	getline(cin, inputS);
	movie.setActor2(inputS);
}

// used to delete a DVD object. (sets all attributes to zero, or (empty) for the title)
void DVD_Manager::deleteDVD(DVD &movie)
{
	movie.setTitle("(empty)");
	movie.setMovieLength(0);
	movie.setYear(0);
	movie.setActor1("");
	movie.setActor2("");
}

// used to update an exsisting DVD object
void DVD_Manager::updateDVD(DVD &movie)
{
	string inputS;
	int inputI;

	cout << "What would you like to update?" << endl
		<< "Title" << endl << "Movie Length" << endl << "Year" << endl << "Actor 1" << endl << "Actor 2" << endl
		<< "Type your selection: ";
	getline(cin, inputS);

	if (inputS == "Title" || inputS == "title" || inputS == "TITLE")
	{
		cout << endl << "What is the new DVD title? ";
		getline(cin, inputS);
		movie.setTitle(inputS);
	}

	else if (inputS == "Movie Length" || inputS == "movie length" || inputS == "MOVIE LENGTH")
	{
		cout << "How long is the new movie (in minutes)? ";
		cin >> inputI;
		movie.setMovieLength(inputI);
	}

	else if (inputS == "Year" || inputS == "year" || inputS == "YEAR")
	{
		cout << "What year did the new movie come out? ";
		cin >> inputI;
		movie.setYear(inputI);
	}

	else if (inputS == "Actor 1" || inputS == "actor 1" || inputS == "ACTOR 1")
	{
		cout << "Who is the new first main actor? ";
		getline(cin, inputS);
		movie.setActor1(inputS);
	}

	else if (inputS == "Actor 2" || inputS == "actor 2" || inputS == "ACTOR 2")
	{
		cout << "Who is the new second main actor? ";
		getline(cin, inputS);
		movie.setActor2(inputS);
	}

	else
		cout << "That was not a valid option." << endl;
}

