// Adam Allard
// Week 4 Assignment 2
// This program holds and displays data about soccer players on a team. 
// it will show the players' names, numbers, and how many points they scored.
// it will also provide the total points on team and who on the team made the most points 

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Player {
	string name;
	int number,
		points;
};

void getPlayerInfo(Player&);
void showInfo(Player);
int getTotalPoints(Player[], int);
void showHighest(Player[], int);

int main()
{
	const int SIZE = 3;
	Player team[SIZE];
	for (int index = 0; index < SIZE; index++)
	{
		cout << "PLAYER #" << index + 1 << endl;
		cout << "---------" << endl;
		getPlayerInfo(team[index]);
	}

	cout << setw(20) << left << "NAME" << setw(10) << left << "NUMBER"
		<< setw(10) << left << "POINTS SCORED" << endl;
	for (int index = 0; index < SIZE; index++)
	{
		showInfo(team[index]);
	}

	cout << "TOTAL POINTS: " << getTotalPoints(team, SIZE) << endl;

	showHighest(team, SIZE);

	cout << endl;
	system("pause");
	return 0;
}

// this function prompts user to enter info about each player on team
void getPlayerInfo(Player& p)
{
	cout << "Player name: ";
	getline(cin, p.name);
	cout << "Player's number: ";
	cin >> p.number;
	while (p.number < 0)
	{
		cout << "Player's number cannot be negative. Try again." << endl;
		cout << "Player's number: ";
		cin >> p.number;
	}
	cout << "Points scored: ";
	cin >> p.points;
	while (p.points < 0)
	{
		cout << "Player's points cannot be negative. Try again." << endl;
		cout << "Player's points: ";
		cin >> p.points;
	}
	cout << endl;
	cin.ignore();
}

// this function displays the player info about each player on team
void showInfo(Player p)
{
	cout << setw(23) << p.name << setw(9) << left << p.number
		<< setw(13) << left << p.points << endl;
}

// this function adds up and returns the total points on team
int getTotalPoints(Player team[], int size)
{
	int total = 0;
	for (int index = 0; index < size; index++)
	{
		total += team[index].points;
	}
	return total;
}

// this function displays the player in team with the most points 
void showHighest(Player team[], int size)
{
	int highest = team[0].points;
	int index = 0;
	for (int count = 1; count < size; count++)
	{
		if (team[count].points > highest)
		{
			highest = team[count].points;
			index = count;
		}
	}
	cout << "The player who scored the most points is: " << team[index].name;
}