// Student List Program
// Created by: Arjun Pai
// Description: This program allows you to manage a list of students.
// You can add, print, or delete students.
// Credits: Ram Pai for explaining stcmp and hlping with debugging and Canvas tutorials

#include <iostream>
#include <cstring>

using namespace std;

 int MAX_STUDENTS = 100;

struct Student { //initilize variables
    char firstName[50];
    char lastName[50];
    int studentId;
    float GPA;
    bool isDeleted;
};

void addStudent(Student students[], int& numStudents) {
  if (numStudents < MAX_STUDENTS) {//information adding to student
        cout << "Enter first name: ";
        cin >> students[numStudents].firstName; //user input of name
        cout << "Enter last name: ";
        cin >> students[numStudents].lastName; //user input of last name 
        cout << "Enter student ID: ";
        cin >> students[numStudents].studentId;//user input of id
        cout << "Enter GPA: ";
        cin >> students[numStudents].GPA;// user input of GPA
        students[numStudents].isDeleted = false;
        numStudents++;
    } else {
        cout << "Maximum number of students reached." << endl;
    }
}

void printStudents(Student students[], int numStudents) {//print data function
    cout << "List of students:" << endl;
    for (int i = 0; i < numStudents; ++i) {
      if (!students[i].isDeleted) {//data printing
            cout << "Student ID: " << students[i].studentId << endl;
            cout << "First Name: " << students[i].firstName << endl;
            cout << "Last Name: " << students[i].lastName << endl;
            cout << "GPA: " << students[i].GPA << endl;
            cout << "-------------------" << endl;//seperator 
        }
    }
}
    void deleteStudent(Student students[], int numStudents, int studentIdToDelete) {//student deletion function
      for (int i = 0; i < numStudents; ++i) {//run through students
        if (students[i].studentId == studentIdToDelete) {
	  students[i].isDeleted = true;//delete
	  cout << "Student with ID " << studentIdToDelete << " deleted." << endl;//tell user it deleted
            return;
        }
    }
    cout << "Student with ID " << studentIdToDelete << " not found." << endl;
}

    int main() {//main
    Student studentList[MAX_STUDENTS];
    int numStudents = 0;
    char command[10];

    cout << "Welcome to the Student List Program!" << endl;

    while (true) {
        cout << "Enter a command (ADD, PRINT, DELETE, QUIT): ";
        cin >> command;
	//run thrugh all commands and do the one the user wanted and inputted
        if (strcmp(command, "ADD") == 0) {
            addStudent(studentList, numStudents);
        } else if (strcmp(command, "PRINT") == 0) {
            printStudents(studentList, numStudents);
        } else if (strcmp(command, "DELETE") == 0) {
           int studentIdToDelete;
            cout << "Enter student ID to delete: ";
            cin >> studentIdToDelete;
            deleteStudent(studentList, numStudents, studentIdToDelete);
        } else if (strcmp(command, "QUIT") == 0) {//break out of program
            break;
       } else {
            cout << "Invalid command. Please try again." << endl;
        }  }

    return 0;
}
