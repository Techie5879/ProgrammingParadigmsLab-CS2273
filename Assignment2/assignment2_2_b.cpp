// Aritra Bandyopadhyay 2021CSB107
// Assignent_2_1 Stack (Showing multiple stacks can be instantiated together and can coexist)

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
        // cout << "Using DEFAULT const value (10) as invalid input provided" << endl;
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
    
    MyStack stack1, stack2, stack3, stack4;

    // Initialize stack1 with a stack size of 5
    initializeStack(stack1, 5);

    // Initialize stack2 with a stack size of 7
    initializeStack(stack2, 7);

    // Initialize stack3 with the default stack size (10)
    initializeStack(stack3, 0);

    // Initialize stack4 with size 12
    initializeStack(stack4, 12);

    push(stack1, 1);
    push(stack1, 4);
    push(stack1, 2);

    push(stack2, 34);
    push(stack2, 4);

    push(stack3, 50);
    push(stack3, 53);
    push(stack3, 37);
    push(stack3, 6);
    push(stack3, 71);

    // stack4 is empty

    cout << "stack1 max size: " << getMaxSize(stack1) << endl;
    cout << "stack2 max size: " << getMaxSize(stack2) << endl;
    cout << "stack3 max size: " << getMaxSize(stack3) << endl;
    cout << "stack4 max size: " << getMaxSize(stack4) << endl << endl;

    cout << "stack1 current size: " << getCurrentSize(stack1) << endl;
    cout << "stack2 current size: " << getCurrentSize(stack2) << endl;
    cout << "stack3 current size: " << getCurrentSize(stack3) << endl;
    cout << "stack4 current size: " << getCurrentSize(stack4) << endl << endl;


    isEmpty(stack1) ? cout << "Stack1 is Empty" << endl : cout << "Stack1 isn't Empty" << endl;
    isEmpty(stack2) ? cout << "Stack2 is Empty" << endl : cout << "Stack2 isn't Empty" << endl;
    isEmpty(stack3) ? cout << "Stack3 is Empty" << endl : cout << "Stack3 isn't Empty" << endl;
    isEmpty(stack4) ? cout << "Stack4 is Empty" << endl : cout << "Stack4 isn't Empty" << endl;

}