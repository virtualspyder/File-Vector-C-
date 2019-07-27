#ifndef PERSON_H__
#define PERSON_H__

// Some standard headers
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

class Person
{
private : 
	string firstName;
	string lastName;
	char gender;
	int birthYear;
	int birthMonth;
	int birthDay;

public : 
	Person(string personFirstName, string personLastName, char personGender, int personBirthYear, int personBirthMonth, int personBirthDay);

	string findName(string lname) const;

	string getFirstName() const;
	string getLastName() const;
	char getGender() const;

	int getBirthYear() const;
	int getBirthMonth() const;
	int getBirthDay() const;

	void setName(string personFirstName, string personLastName);

	void setFirstName(string name);
	void setLastName(string name);
	void setGender(char gender);

	void setBirthYear(int year);
	void setBirthMonth(int month);
	void setBirthDay(int day);
};

#endif // PERSON_H__
