/* Adam Allard
*  This program will verify a password a user enters in meets the minimum requirements:
*  6 characters long, 1 uppercase letter, 1 lowercase letter, and 1 digit
*/

#include <iostream>
#include <string>
using namespace std;

bool validatePassword(string);

int main() 
{
	string password;

	cout << "Passwords must contain at least: " << endl
		<< "* 6 characters" << endl << "* 1 uppercase letter" << endl
		<< "* 1 lowercase letter" << endl << "* 1 digit" << endl
		<< "Please enter your password: ";

	cin >> password;
	cout << endl;

	// if the password doesn't meet the criteria, keep prompting user for a new password
	while (!validatePassword(password))
	{
		cout << "Please enter your new password: ";
		cin >> password;
		cout << endl;
	}

	cout << "Password accepted." << endl << endl;

	system("pause");
	return 0;
}

/* 
this function accepts a string and validates that it meets the minimum requirements of a password
- 6 characters
- 1 uppercase letter
- 1 lowercase letter
- 1 digit
*/
bool validatePassword(string passWord) {
	bool status = false; // return value and overall test
	bool upper  = false, // test for uppercase letter
		 lower  = false, // test for lowercase letter
		 digit  = false, // test for digit
		 length = false; // test for length

	for (int index = 0; index < passWord.length(); index++)
	
		// test password for min. requirements 
	{
		if (isupper(passWord.at(index)))
			upper = true;
		if (islower(passWord.at(index)))
			lower = true;
		if (isdigit(passWord.at(index)))
			digit = true;
		if (passWord.length() > 5)
			length = true;
	}

	// tell user why password isn't accepted
	if (!upper)
		cout << "Passwords must contain at least 1 uppercase letter." << endl;
	if (!lower)
		cout << "Passwords must contain at least 1 lowercase letter." << endl;
	if (!digit)
		cout << "Passwords must contain at least 1 digit." << endl;
	if (!length)
		cout << "Passwords must have at least 6 characters." << endl;
    
	// if all requirement are met, pass function as true
	if ((length) && (upper) && (lower) && (digit))
		status = true;

	return status;
}