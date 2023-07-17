// Aritra Bandyopadhyay 2021CSB107
// Assignment3_2 Stack Class Multiple stack

#include <iostream>
using namespace std;

class MyStack {
    private:
        int *arr;
        int top;
        int max_size;
    public:
        MyStack(int maxSize) {
            max_size = maxSize;
            arr = new int[max_size];
            top = -1;
        }
        bool isEmpty() {
            return top == -1;
        }
        bool push(int data) {
            if (top >= max_size - 1) 
                return false;
            arr[++top] = data;
            return true;
        }
        int pop() {
            if (isEmpty()) {
                return -1;
            }
            return arr[top--];
        }
        int MaxSize() {
            return max_size;
        }
        int CurrentSize() {
            return top + 1;
        }
        void Display() {
            if(isEmpty()) {
                cout << "Stack is empty" << endl;
                return;
            }
            cout << endl;
            for (int i = CurrentSize() - 1; i >= 0; i--) {
                cout << arr[i] << endl;
            }
            return;
        }
        ~MyStack() {
            delete [] arr;
        }
};

int main() {
    MyStack stack1(5);
    MyStack stack2(4);
    MyStack stack3(2);
    MyStack stack4(3);

    stack1.push(1);
    stack1.push(4);
    stack1.push(2);

    stack2.push(34);
    stack2.push(4);

    stack3.push(50);
    stack3.push(53);
    stack3.push(37);
    stack3.push(6);
    stack3.push(71);

    // stack4 is empty
    cout << "stack1 max size: " << stack1.MaxSize() << endl;
    cout << "stack2 max size: " << stack2.MaxSize() << endl;
    cout << "stack3 max size: " << stack3.MaxSize() << endl;
    cout << "stack4 max size: " << stack4.MaxSize() << endl << endl;

    cout << "stack1 current size: " << stack1.CurrentSize() << endl;
    cout << "stack2 current size: " << stack2.CurrentSize() << endl;
    cout << "stack3 current size: " << stack3.CurrentSize() << endl;
    cout << "stack4 current size: " << stack4.CurrentSize() << endl << endl;


    stack1.isEmpty() ? cout << "Stack1 is Empty" << endl : cout << "Stack1 isn't Empty" << endl;
    stack2.isEmpty() ? cout << "Stack2 is Empty" << endl : cout << "Stack2 isn't Empty" << endl;
    stack3.isEmpty() ? cout << "Stack3 is Empty" << endl : cout << "Stack3 isn't Empty" << endl;
    stack4.isEmpty() ? cout << "Stack4 is Empty" << endl : cout << "Stack4 isn't Empty" << endl;
    
}