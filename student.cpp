
#include "student.h"
#include <iostream>

using namespace std;

/*
 * Getter Methods
 */
string Student::getID() {
	return this->studentID;
}

string Student::getFirstName() {
	return this->firstName;
}

string Student::getLastName() {
	return this->lastName;
}
string Student::getEmailAddress() {
	return this->emailAddress;
}

int Student::getAge() {
	return this->age;
}

int* Student::getNumOfDays() {
	return this->numOfDaysComplete;
}

DegreeProgram Student::getDegreeProgram() {
	return this->degreeProgram;
}

/*
 * Setter Methods
 */
void Student::setID(string ID) {
	this->studentID = ID;
}

void Student::setFirstName(string firstName) {
	this->firstName = firstName;
}

void Student::setLastName(string lastName) {
	this->lastName = lastName;
}

void Student::setEmailAdress(string email) {
	this->emailAddress = email;
}

void Student::setAge(int age) {
	this->age = age;
}

void Student::setNumOfDays(int numOfDays[]) {
	for (int i = 0; i < arrSizeDays; i++) {
		numOfDaysComplete[i] = numOfDays[i];
	}
}

void Student::setDegreeProgram(DegreeProgram degProgram) {
	this->degreeProgram = degProgram;
}

/*
 * Constructor / Destructor
 */
Student::Student(string id, string firstName, string lastName, string email, int age, int numOfDays[], DegreeProgram degProgram) {
	setID(id);
	setFirstName(firstName);
	setLastName(lastName);
	setEmailAdress(email);
	setAge(age);
	setNumOfDays(numOfDays);
	setDegreeProgram(degProgram);
}

Student::~Student() {};

/*
 * Print Method
 */
void Student::print() {
	cout << getID() << '\t';
	cout << getFirstName() << '\t';
	cout << getLastName() << '\t';
	cout << getEmailAddress() << '\t';
	cout << getAge() << '\t';
	cout << getNumOfDays()[0] << '\t';
	cout << getNumOfDays()[1] << '\t';
	cout << getNumOfDays()[2] << '\t';

	if (getDegreeProgram() == DegreeProgram::SECURITY) {
		cout << "SECURITY";
	}
	else if (getDegreeProgram() == DegreeProgram::SOFTWARE) {
		cout << "SOFTWARE";
	}
	else if (getDegreeProgram() == DegreeProgram::NETWORK) {
		cout << "NETWORK";
	}
	cout << endl;


}