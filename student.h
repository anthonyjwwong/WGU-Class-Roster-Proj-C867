#pragma once
#include <string>
#include "degree.h"

using namespace std;

class Student {
public:
	const static int arrSizeDays = 3;
private:
	/*
	 * Variables required for student class.
	 */
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int numOfDaysComplete[arrSizeDays];
	DegreeProgram degreeProgram;
public:

	/*
	 * Getter
	 */
	string getID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();                              
	int* getNumOfDays();
	DegreeProgram getDegreeProgram();

	/*
	 * Setter
	 */
	void setID(string ID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAdress(string email);
	void setAge(int age);
	void setNumOfDays(int numOfDays[]);
	void setDegreeProgram(DegreeProgram degProgram);

	/*
	 * Constructor& Destructor
	 */

	Student() { //Default Consturctor
		this->studentID = "";
		this->firstName = "";
		this->lastName = "";
		this->emailAddress = "";
		this->age = 0;
		for (int i = 0; i < arrSizeDays; i++) {
			this->numOfDaysComplete[i] = 0;
		}
		this->degreeProgram = DegreeProgram::SOFTWARE;
	};

	Student(string id, string firstName, string lastName, string email, int age, int numOfDays[], DegreeProgram degProgram);
	
	~Student(); // destructor

	/*
	 * Print method
	 */
	void print();
};

