// Aritra Bandyopadhyay 2021CSB107
// Assignment 4_2
#include <iostream>
#include <string>
using namespace std;

// Base class Person
class Person {
protected:
    string name;
    int age;
    char gender;
public:
    Person() {}
    Person(string n, int a, char g) : name(n), age(a), gender(g) {}
    // virtual function, can be overridden for every derived class
    virtual void displayProfile() {}
};

// Derived class Student
class Student : public Person {
protected:
    string dept;
    int year;
public:
    Student() {}
    Student(string n, int a, char g, string d, int y) : Person(n, a, g), dept(d), year(y) {}
    void displayProfile() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Gender: " << gender << endl;
        cout << "Department: " << dept << endl;
        cout << "Year: " << year << endl;
    }
};

// Derived class Clerk
class Clerk : public Person {
protected:
    int workload;
    int salary;
public:
    Clerk() {}
    Clerk(string n, int a, char g, int w, int s) : Person(n, a, g), workload(w), salary(s) {}
    void displayProfile() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Gender: " << gender << endl;
        cout << "Workload: " << workload << endl;
        cout << "Salary: " << salary << endl;
    }
};

// Derived class Professor
class Professor : public Person {
protected:
    string dept;
    int courseload;
    int salary;
public:
    Professor() {}
    Professor(string n, int a, char g, string d, int c, int s) : Person(n, a, g), dept(d), courseload(c), salary(s) {}
    void displayProfile() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Gender: " << gender << endl;
        cout << "Department: " << dept << endl;
        cout << "Course load: " << courseload << endl;
        cout << "Salary: " << salary << endl;
    }
};

int main() {
    // create a Student object
    Student s("John", 20, 'M', "Computer Science", 3);

    // display the student's profile
    cout << "Student Profile:" << endl;
    s.displayProfile();
    cout << endl;

    // create a Clerk object
    Clerk c("Jane", 30, 'F', 40, 50000);

    // display the clerk's profile
    cout << "Clerk Profile:" << endl;
    c.displayProfile();
    cout << endl;

    // create a Professor object
    Professor p("David", 45, 'M', "Mathematics", 4, 100000);

    // display the professor's profile
    cout << "Professor Profile:" << endl;
    p.displayProfile();
    cout << endl;

    return 0;
}
