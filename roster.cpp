#include <iostream>
#include <regex>

#include "roster.h"

using namespace std;


/*
 * Parse method using delimiter as taught in WGU
 */
void Roster::parse(string row) {
	size_t rhs = row.find(",");
	string id = row.substr(0, rhs);

	size_t lhs = rhs + 1;
	rhs = row.find(",", lhs);
	string firstName = row.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	string lastName = row.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	string email = row.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	int age = stoi(row.substr(lhs, rhs - lhs));

	int arr[3];

	for (int i = 0; i < 3; i++) {
		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		arr[i] = stoi(row.substr(lhs, rhs - lhs));
	}

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	string degreeProg = row.substr(lhs, rhs - lhs);

	DegreeProgram degree = DegreeProgram::SOFTWARE;

	if (degreeProg == "SOFTWARE") {
		degree = DegreeProgram::SOFTWARE;
	} 
	else if (degreeProg == "SECURITY") {
		degree = DegreeProgram::SECURITY;
	}
	else if (degreeProg == "NETWORK") {
		degree = DegreeProgram::NETWORK;
	}

	
	add(id, firstName, lastName, email, age, arr[0], arr[1], arr[2], degree);
}

/*
 * Add Method
 */
 void Roster::add(string id, string firstName, string lastName,
	 string email, int age, int numOfDays1, int numOfDays2, int numOfDays3,
	 DegreeProgram degProgram) {

	 int numOfDays[] = { numOfDays1, numOfDays2, numOfDays3 };
		
	 classRosterArray[index++] = new Student(id, firstName, lastName, email, age, numOfDays, degProgram);
 }


 /*
  * Print Method
  */
 void Roster::printAll() {
	 for (int i = 0; i < size; i++) {
		 this->classRosterArray[i]->print();
		
	 }
	 cout << " " << endl;
 }

 /*
  * Remove method by student ID
  */
 void Roster::remove(string studentID) {
	 
	 
	 int currentIndex = -1;

	 for (int i = 0; i < size; i++) {
		 if (classRosterArray[i]->getID() == studentID) {
			 currentIndex = i;
		 }
	 }

	
	
	if (currentIndex == -1) {
		cout << "Sorry, the ID you have entered is invalid." << endl;
	}
	else if (currentIndex >= 0) {

		for (int i = currentIndex; i < size; i++) {
			classRosterArray[i] = classRosterArray[i + 1];
		};
		size--;
	}
}
	

 /*
  * Average Days left in course method for individual student
  */
 void Roster::printAverageDaysInCourse(string studentID) {

		int currentIndex= -1;
		int avgDays = 0;
		int day1, day2, day3;

	 
	 for (int i = 0; i < size; i++) {
		 if (classRosterArray[i]->getID() == studentID) {
			 currentIndex = i;
		 }
	 }

	 
	 day1 = classRosterArray[currentIndex]->getNumOfDays()[0];
	 day2 = classRosterArray[currentIndex]->getNumOfDays()[1];
	 day3 = classRosterArray[currentIndex]->getNumOfDays()[2];

	 avgDays = (day1 + day2 + day3) / 3;

	 cout << "Student ID: " << classRosterArray[currentIndex]->getID() << " average days in course " << avgDays << " days" << endl;
	
}
	


 /*
  * Check invalid Emails method using Regex.
  */
 void Roster::printInvalidEmails() {

	 string emailTemp;
	 const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");

	 for (int i = 0; i < Roster::size; i++) {
		 emailTemp = classRosterArray[i]->getEmailAddress();
		 if (!regex_match(emailTemp, pattern)) {
			 cout << classRosterArray[i]->getEmailAddress() << " is not a valid email" << endl;
		  }
	 }
	 cout << " " << endl;

 }


 /*
  * Sort students by their degreeprogram method.
  */
 void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	 for (int i = 0; i < size; i++) {
		 if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
			 classRosterArray[i]->print();
		 }
	 }
	 cout << " " << endl;
 }


/*
 * Destructor
 */
Roster::~Roster() {
	for (int i = 0; i < numOfStudents; i++) {
		
		cout << "destructor is called" << endl;
		delete classRosterArray[i];
	}
 } 