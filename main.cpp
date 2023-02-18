// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "roster.h"


int main()
{

    const string studentData[] =
    {
      "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
      "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
      "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
      "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
      "A5,Anthony,Wong,awong44@wgu.com,30,20,30,40,SOFTWARE"
    };

    /* F1 - Print out personal info */
    std::cout << "C867 - SCRIPTING & PROGRAMMING: APPLICATIONS" << std::endl << "Language: C++" << std::endl;
    std::cout << "Student ID: 010393626" << std::endl << "Name: Anthony Wong" << std::endl;
    std::cout << " " << endl;

    /* F2 - Instance of Roster Class*/
    Roster classRoster;
    
    const static int classRosterSize = 5;

    /* F3 - Add each student to classRoster*/
    for (int i = 0; i < classRosterSize; i++) {
        classRoster.parse(studentData[i]);
    }
    cout << "-- First PrintAll() after classRoster array has been populated --" << endl << endl;
    classRoster.printAll();


    /* F4 - Convert the pseudo code */
    
    //Print invalid email
    cout << "-- printInvalidEmails() --" << endl << endl;
    classRoster.printInvalidEmails();


    //loop through and print average days in course.
    cout << "-- printAverageDaysInCourse() --" << endl << endl;
    for (int i = 0; i < classRosterSize; i++) {
        classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getID());
      
    }
  
    
   //Print by the different degree program
    cout << endl << "-- printByDegreeProgram() --" << endl << endl;

    classRoster.printByDegreeProgram(SECURITY);
   
    classRoster.printByDegreeProgram(NETWORK);

    classRoster.printByDegreeProgram(SOFTWARE);


    //First Remove
    cout << "-- remove(\"A3\")--" << endl << endl;
    classRoster.remove("A3");

    classRoster.printAll();


    //Second remove of the same element -> error message
    cout << "-- remove(\"A3\")-- second time --" << endl << endl;

    classRoster.remove("A3"); 

    cout << endl << "-- printAll() --" << endl << endl;

    classRoster.printAll();


    return 0;
}



