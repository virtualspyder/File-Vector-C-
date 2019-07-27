#include "Person.h"

Person::Person(string personFirstName, string personLastName, char personGender, int personBirthYear, int personBirthMonth, int personBirthDay) : 
	firstName(personFirstName), 
	lastName(personLastName), 
	gender(personGender), 
	birthYear(personBirthYear), 
	birthMonth(personBirthMonth), 
	birthDay(personBirthDay)
	{
	}

string Person::findName(string lname) const
{
	if(lastName == lname) return lname; 

	return "";
}

string Person::getFirstName() const
{
	return firstName;
}

string Person::getLastName() const
{
	return lastName;
}

char Person::getGender() const
{
	return gender;
}

int Person::getBirthYear() const
{
	return birthYear;
}

int Person::getBirthMonth() const
{
	return birthMonth;
}

int Person::getBirthDay() const
{
	return birthDay;
}

void Person::setFirstName(string name)
{
	firstName = name;
}

void Person::setLastName(string name)
{
	lastName = name;
}

void Person::setGender(char personGender)
{
	gender = personGender;
}

void Person::setBirthYear(int year)
{
	birthYear = year;
}

void Person::setBirthMonth(int month)
{
	birthMonth = month;
}

void Person::setBirthDay(int day)
{
	birthDay = day;
}

void Person::setName(string personFirstName, string personLastName)
{
	setFirstName(personFirstName);
	setLastName(personLastName);
}
