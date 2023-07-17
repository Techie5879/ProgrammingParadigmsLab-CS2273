// Aritra Bandyopadhyay 2021CSB107
// Assignment2_5 Generic Stack

#include <iostream>
using namespace std;

// Constant int used here (used in the initializeStack function)
const int MAX_SIZE = 10;

// using this struct to push and pop from stack to show it accepts struct
typedef struct Person {
    string name;
    int age;
}
Person;


template <typename T>
struct MyStack {
    int top;
    int max_size;
    T *arr;
};

template <typename T>
bool initializeStack(MyStack<T> &s, int stacksize) {
    s.top = -1;
    if (stacksize <= 0) {
        stacksize = MAX_SIZE;
        cout << "Using DEFAULT const value (10) as invalid input provided" << endl;
    }
    s.max_size = stacksize;
    
    s.arr = new T[stacksize];
    if (s.arr == nullptr)
        return false;

    return true;
}

template <typename T>
bool push(MyStack<T> &s, T data) {
    if (s.top >= s.max_size - 1) 
        return false;

    s.arr[++s.top] = data;
    
    return true;
}

template <typename T>
T pop(MyStack<T> &s) {
    if (s.top == -1) { // underflow
        return T();
    }
    T popper = s.arr[s.top--];
    return popper;
}

// Inline functions used here
template <typename T>
inline int getMaxSize(MyStack<T> &s) {
    return s.max_size;
}

template <typename T>
inline int getCurrentSize(MyStack<T> &s) {
    return s.top + 1;
}

template <typename T>
inline bool isEmpty(MyStack<T> &s) {
    return s.top == -1;
}

int main() {
    MyStack<int> intStack;
    MyStack<float> floatStack;
    MyStack<double> doubleStack;
    MyStack<short> shortStack;
    MyStack<Person> personStack;
    
    

    int switcher;
    while (true) {
        cout << "\nPress 0 to display all operations\n";
        cout << "\nEnter an operation: ";
        cin >> switcher;

        switch(switcher)
        {
            case 0:
                cout << "\nPress 1 to initialize stacks\n";
                cout << "Press 2 to Push an Integer to the Stack\n";
                cout << "Press 3 to Pop an Integer from the Stack\n";
                cout << "Press 4 to Push a Float to the Stack\n";
                cout << "Press 5 to Pop a Float from the Stack\n";
                cout << "Press 6 to Push a Double to the Stack\n";
                cout << "Press 7 to Pop a Double from the Stack\n";
                cout << "Press 8 to Push a Short to the Stack\n";
                cout << "Press 9 to Pop a Short from the Stack\n";
                cout << "Press 10 to Push a Struct to the Stack\n";
                cout << "Press 11 to Pop a Struct from the Stack\n";
                cout << "Press 12 get Max Size of Stack\n";
                cout << "Press 13 get Current Size of Stack\n";
                cout << "Press 14 to check if Stack is empty\n";
                cout << "Press 15 to EXIT\n";
                break;
            case 1:
            {
                cout << "\nEnter size of stack to be initialized: ";
                int size;
                cin >> size;
                if (!initializeStack(intStack, size)) {
                    cout << "intStack Memory allotment error" << endl;
                    exit(1);
                }
                if (!initializeStack(floatStack, size)) {
                    cout << "floatStack Memory allotment error" << endl;
                    exit(1);
                }
                if (!initializeStack(doubleStack, size)) {
                    cout << "doubleStack Memory allotment error" << endl;
                    exit(1);
                }
                if (!initializeStack(shortStack, size)) {
                    cout << "shortStack Memory allotment error" << endl;
                    exit(1);
                }
                if (!initializeStack(personStack, size)) {
                    cout << "personStack Memory allotment error" << endl;
                    exit(1);
                }
                cout << "\nintStack initialized with size " << intStack.max_size << endl;
                cout << "floatStack initialized with size " << floatStack.max_size << endl;
                cout << "doubleStack initialized with size " << doubleStack.max_size << endl;
                cout << "shortStack initialized with size " << shortStack.max_size << endl;
                cout << "personStack initialized with size " << personStack.max_size << endl;
                break;
            }
            case 2:
            {
                int intvalue;
                cout << "\nEnter an integer to push to the stack: ";
                cin >> intvalue;
                if (!push(intStack, intvalue)) cout << "Stack Overflow" << endl;
                else cout << "Integer " << intvalue << " pushed to stack" << endl;
                break;
            }
            case 3:
            {
                if (isEmpty(intStack)) cout << "Stack Underflow" << endl;
                else {
                    int intpopped = pop(intStack);
                    cout << intpopped << " popped from Stack" << endl;
                }
                break;
            }
            case 4:
            {
                float floatvalue;
                cout << "\nEnter a float to push to the stack: ";
                cin >> floatvalue;
                if (!push(floatStack, floatvalue)) cout << "Stack Overflow" << endl;
                else cout << "Float " << floatvalue << " pushed to stack" << endl;
                break;
            }
            case 5:
            {
                if (isEmpty(floatStack)) cout << "Stack Underflow" << endl;
                else {
                    float floatpopped = pop(floatStack);
                    cout << floatpopped << " popped from Stack" << endl;
                }
                break;
            }
            case 6:
            {
                double doublevalue;
                cout << "\nEnter a double to push to the stack: ";
                cin >> doublevalue;
                if (!push(doubleStack, doublevalue)) cout << "Stack Overflow" << endl;
                else cout << "Double " << doublevalue << " pushed to stack" << endl;
                break;
            }
            case 7:
            {
                if (isEmpty(doubleStack)) cout << "Stack Underflow" << endl;
                else {
                    double doublepopped = pop(doubleStack);
                    cout << doublepopped << " popped from Stack" << endl;
                }
                break;
            }
            case 8:
            {
                short shortvalue;
                cout << "\nEnter a short to push to the stack: ";
                cin >> shortvalue;
                if (!push(shortStack, shortvalue)) cout << "Stack Overflow" << endl;
                else cout << "Short " << shortvalue << " pushed to stack" << endl;
                break;
            }
            case 9:
            {
                if (isEmpty(shortStack)) cout << "Stack Underflow" << endl;
                else {
                    short shortpopped = pop(shortStack);
                    cout << shortpopped << " popped from Stack" << endl;
                }
                break;
            }
            case 10:
            {
                Person person;
                cout << "\nEnter name of person: ";
                cin >> person.name;
                cout << "\nEnter age of person: ";
                cin >> person.age;
                if (!push(personStack, person)) cout << "Stack Overflow" << endl;
                else cout << "Person with Name: " << person.name << " and Age: " << person.age << " pushed to Stack" << endl;
                break;
            }
            case 11:
            {

                if (isEmpty(personStack)) cout << "Stack Underflow" << endl;
                else {
                    Person personpopped = pop(personStack);
                    cout << "Popped from Stack:" << endl;
                    cout << "Name: " << personpopped.name << " Age: " << personpopped.age << endl;
                }
                break;
            }
            case 12:
                cout << "Max size of intStack is: " << getMaxSize(intStack) << endl;
                cout << "Max size of floatStack is: " << getMaxSize(floatStack) << endl;
                cout << "Max size of doubleStack is: " << getMaxSize(doubleStack) << endl;
                cout << "Max size of shortStack is: " << getMaxSize(shortStack) << endl;
                cout << "Max size of personStack is: " << getMaxSize(personStack) << endl;
                break;
            case 13:
                cout << "Current size of intStack is: " << getCurrentSize(intStack) << endl;
                cout << "Current size of floatStack is: " << getCurrentSize(floatStack) << endl;
                cout << "Current size of doubleStack is: " << getCurrentSize(doubleStack) << endl;
                cout << "Current size of shortStack is: " << getCurrentSize(shortStack) << endl;
                cout << "Current size of personStack is: " << getCurrentSize(personStack) << endl;
                break;
            case 14:
            {
                cout << "Enter the type of stack to check for empty: ";
                string type;
                cin >> type;
                if (type == "int") {
                    if (isEmpty(intStack)) {
                        cout << "The intStack is empty" << endl;
                    } 
                    else {
                        cout << "The intStack is not empty" << endl;
                    }
                }
                if (type == "float") {
                    if (isEmpty(floatStack)) {
                        cout << "The float stack is empty" << endl;
                    } 
                    else {
                        cout << "The float stack is not empty" << endl;
                    }
                }
                if (type == "double") {
                    if (isEmpty(doubleStack)) {
                        cout << "The double stack is empty" << endl;
                    } else {
                        cout << "The double stack is not empty" << endl;
                    }
                }
                if (type == "short") {
                    if (isEmpty(shortStack)) {
                        cout << "The short stack is empty" << endl;
                    } else {
                        cout << "The short stack is not empty" << endl;
                    }
                }
                if (type == "struct") {
                    if (isEmpty(personStack)) {
                        cout << "The struct stack is empty" << endl;
                    } else {
                        cout << "The struct stack is not empty" << endl;
                    }
                }
                break;
            }
            case 15:
            {
                cout << "Exiting program\n";
                delete [] intStack.arr;
                delete [] floatStack.arr;
                delete [] doubleStack.arr;
                delete [] shortStack.arr;
                delete [] personStack.arr;
                exit(0);
            }
        }
    }
}
