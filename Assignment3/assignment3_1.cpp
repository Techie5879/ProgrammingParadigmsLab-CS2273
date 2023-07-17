// Aritra Bandyopadhyay 2021CSB107
// Assignment 3_1 Student info
#include <iostream>
using namespace std;

const int MAX_STUDENTS = 20;

class Student {
    private:
        string name;
        int age;
        string dept;
        int year;
    public:
        void ReadStudentData() {
            cout << "Enter name of Student: ";
            cin >> name;
            cout << "Enter age: ";
            cin >> age;
            cout << "Enter Department: ";
            cin >> dept;
            cout << "Enter Year: ";
            cin >> year;
        }
        void PrintStudentData() {
            cout << "Name: " << name << endl;
            cout << "Age: " << age << endl;
            cout << "Department: " << dept << endl;
            cout << "Year: " << year << endl;
        }
};

int main() {
    Student stdreg[MAX_STUDENTS];
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    if (n > MAX_STUDENTS) {
        cout << "Too many records! Exiting...\n";
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        cout << endl << "Enter information for student " << i + 1 << ":" << endl;
        stdreg[i].ReadStudentData();
    }

    cout << endl;

    int key;
    while (true) {
        cout << "Enter Student number to display details, (0 to print all, -1 to break): ";
        cin >> key;
        if (key == -1) {
            cout << endl << "Exiting..." << endl;
            break;
        }
        else if (key == 0) {
            for (int i = 0; i < n; i++) {
                stdreg[i].PrintStudentData();
                cout << endl;
            }
        }
        else if (key > n) {
            cout << "Invalid" << endl;
            break;
        }
        else {
            stdreg[key - 1].PrintStudentData();
            cout << endl;
        }
        
    }
}