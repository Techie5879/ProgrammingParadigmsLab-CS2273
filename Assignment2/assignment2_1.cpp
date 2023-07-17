// Aritra Bandyopadhyay 2021CSB107
// Assignent_2_1 Student Data

#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

typedef struct student {
    string name;
    int age;
    string dept;
    int year;
}
student;

void readStudentData(student &s) {
    cout << "Enter name of Student: ";
    cin >> s.name;
    cout << "Enter age: ";
    cin >> s.age;
    cout << "Enter Department: ";
    cin >> s.dept;
    cout << "Enter Year: ";
    cin >> s.year;

}

void printStudentData(student s) {
    cout << endl;
    cout << "Name: " << s.name << endl;
    cout << "Age: " << s.age << endl;
    cout << "Dept: " << s.dept << endl;
    cout << "Year: " << s.year << endl << endl;
}

int main() {
    student stdreg[MAX_SIZE];
    cout << "Enter number of records to be inserted: ";
    int n;
    cin >> n;
    cout << endl;

    if (n > MAX_SIZE) {
        cout << "Too many records! Exiting...\n";
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        cout << "Enter Student Details for Student " << i + 1 << endl;
        readStudentData(stdreg[i]);
        cout << endl;
    }
    int key;
    while (true) {
        cout << "Enter Student number to display details, 0 to display all, -1 to break: ";
        cin >> key;
        if (key == 0) {
            for (int i = 0; i < n; i++) {
                printStudentData(stdreg[i]);
            }
        }
        else if (key == -1){
            cout << endl << "Exiting..." << endl;
            break;
        }
        else if (key > n) {
            cout << "Invalid" << endl;
            break;
        }
        else printStudentData(stdreg[key - 1]);
    }

}