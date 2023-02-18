#pragma once

#include "student.h"



class Roster {
	public: 
		const static int numOfStudents = 5;
		Student* classRosterArray[numOfStudents] = { nullptr, nullptr, nullptr,nullptr,nullptr };
	private:
		int index = 0;
		int size = sizeof(classRosterArray) / sizeof(classRosterArray[0]);
	public:
		/*
		 * All the required methods/functions in Part E.
		 */
		~Roster();
		void parse(string row);
		void add(string id, string firstName, string lastName, string email, int age, int numOfDays1, int numOfDays2, int numOfDays3, DegreeProgram degProgram);
		void printAll();
		void remove(string ID);
		void printAverageDaysInCourse(string studentID);
		void printInvalidEmails();
		void printByDegreeProgram(DegreeProgram degreeProgram);
};

