#include <iostream>
#include <cstring> // For C-strings

using namespace std;

// Define the maximum number of students
const int MAX_STUDENTS = 100;

// Define the student struct
struct Student {
    char firstName[50];
    char lastName[50];
    int studentId;
    float GPA;
};

// Function to add a new student to the array by reference
void addStudent(Student students[], int& numStudents) {
    if (numStudents < MAX_STUDENTS) {
        cout << "Enter first name: ";
        cin >> students[numStudents].firstName;
        cout << "Enter last name: ";
        cin >> students[numStudents].lastName;
        cout << "Enter student ID: ";
        cin >> students[numStudents].studentId;
        cout << "Enter GPA: ";
        cin >> students[numStudents].GPA;
        numStudents++; // Increment the number of students
    } else {
        cout << "Maximum number of students reached." << endl;
    }
}

// Function to print all students in the array by value
void printStudents(const Student students[], int numStudents) {
    cout << "List of students:" << endl;
    for (int i = 0; i < numStudents; ++i) {
        cout << "Student ID: " << students[i].studentId << endl;
        cout << "First Name: " << students[i].firstName << endl;
        cout << "Last Name: " << students[i].lastName << endl;
        cout << "GPA: " << students[i].GPA << endl;
        cout << "-------------------" << endl;
    }
}

// Function to delete a student by student ID by reference
void deleteStudent(Student students[], int& numStudents, int studentIdToDelete) {
    for (int i = 0; i < numStudents; ++i) {
        if (students[i].studentId == studentIdToDelete) {
            // Shift elements to fill the gap caused by deletion
            for (int j = i; j < numStudents - 1; ++j) {
                students[j] = students[j + 1];
            }
            numStudents--; // Decrement the number of students
            cout << "Student with ID " << studentIdToDelete << " deleted." << endl;
            return;
        }
    }
    cout << "Student with ID " << studentIdToDelete << " not found." << endl;
}

int main() {
    Student studentList[MAX_STUDENTS]; // Array to store student records
    int numStudents = 0; // Number of students currently in the array
    char command[10];

    cout << "Welcome to the Student Database!" << endl;

    while (true) {
        cout << "Enter a command (ADD, PRINT, DELETE, QUIT): ";
        cin >> command;

        if (strcmp(command, "ADD") == 0) {
            addStudent(studentList, numStudents);
        } else if (strcmp(command, "PRINT") == 0) {
           printStudents(studentList, numStudents);
        } else if (strcmp(command, "DELETE") == 0) {
        int studentIdToDelete;
            cout << "Enter student ID to delete: ";
            cin >> studentIdToDelete;
            deleteStudent(studentList, numStudents, studentIdToDelete);
        } else if (strcmp(command, "QUIT") == 0) {
	  break; // Exit the program
        } else {
            cout << "Invalid command. Please try again." << endl;
        }
    }

    return 0;
}
