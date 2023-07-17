// Aritra Bandyopadhyay 2021CSB107
// Assignent_2_1 Stack

#include <iostream>
using namespace std;

// Constant int used here (used in the initializeStack function)
const int MAX_SIZE = 10;

typedef struct stack {
    int top;
    int max_size;
    int *arr;
}
MyStack;

bool initializeStack(MyStack &s, int stacksize) {
    s.top = -1;

    if (stacksize <= 0) {
        stacksize = MAX_SIZE;
        cout << "Using DEFAULT const value (10) as invalid input provided" << endl;
    }
    s.max_size = stacksize;
    
    s.arr = new int[stacksize];
    if (s.arr == nullptr)
        return false;

    return true;
}

bool push(MyStack &s, int data) {
    if (s.top >= s.max_size - 1) 
        return false;

    s.arr[++s.top] = data;
    
    return true;
}

int pop(MyStack &s) {
    if (s.top == -1) { // underflow
        return -1;
    }
    int popper = s.arr[s.top--];
    return popper;
}

// Inline functions used here
inline int getMaxSize(MyStack &s) {
    return s.max_size;
}

inline int getCurrentSize(MyStack &s) {
    return s.top + 1;
}

inline bool isEmpty(MyStack &s) {
    return s.top == -1;
}

int main() {
    MyStack stack;

    int switcher;
    while (true) {
        cout << "\nPress 0 to display all operations\n";
        cout << "\nEnter an operation: ";

        cin >> switcher;

        switch(switcher)
        {
            case 0:
                cout << "\nPress 1 to initialize a stack\n";
                cout << "Press 2 to Push an Integer to the Stack\n";
                cout << "Press 3 to Pop an Integer from the Stack\n";
                cout << "Press 4 get Max Size of Stack\n";
                cout << "Press 5 get Current Size of Stack\n";
                cout << "Press 6 to check if Stack is empty\n";
                cout << "Press 7 to EXIT\n";
                break;
            case 1:
            {
                cout << "\nEnter size of stack to be initialized: ";
                int size;
                cin >> size;
                if (!initializeStack(stack, size)) {
                    cout << "Memory allotment error" << endl;
                    exit(1);
                }
                cout << "Stack initialized with size " << stack.max_size << endl;
                break;
            }
            case 2:
            {
                cout << "\nEnter integer to be pushed to stack: ";
                int data;
                cin >> data;
                if (!push(stack, data)) {
                    cout << "Stack Overflow" << endl;
                }
                else {
                    cout << data << " successfully pushed to stack" << endl;
                }
                break;
            }
            case 3:
            {
                int popped = pop(stack);
                if (popped == -1) cout << "Stack Underflow" << endl;
                else {
                    cout << popped << " popped from Stack" << endl;
                }
                break;
            }
            case 4:
                cout << "Max size of stack is: " << getMaxSize(stack) << endl;
                break;
            case 5:
                cout << "Current size of stack is: " << getCurrentSize(stack) << endl;
                break;
            case 6:
                if(isEmpty(stack)) cout << "Stack is empty" << endl;
                else cout << "Stack isn't empty" << endl;
                break;
            case 7:
                delete[] stack.arr;
                cout << "Deleted Stack" << endl << "Exiting..." << endl;
                exit(0);
                break;
        }
    }


}