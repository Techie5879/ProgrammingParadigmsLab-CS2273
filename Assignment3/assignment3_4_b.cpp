// Aritra Bandyopadhyay 2021CSB107
// Assignment3_4 Stack + overloading

#include <iostream>
using namespace std;


class MyStack {
    private:
        int *arr;
        int top;
        int max_size;
        static int stack_count;
        static const int MAX_STACKS = 10;
    public:
        MyStack(int maxSize) {
            if (stack_count >= MAX_STACKS) {
                cout << "Maximum limit of " << MAX_STACKS << " stacks reached" << endl;
                return;
            }
            max_size = maxSize;
            arr = new int[max_size];
            top = -1;
            stack_count++;
        }
        static int GetStackCount() {
            return stack_count;
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
        friend MyStack operator+(const MyStack &s1, const MyStack &s2) {
            MyStack new_stack(s1.max_size + s2.max_size);
            for (int i = 0; i <= s1.top; i++) {
                new_stack.push(s1.arr[i]);
            }
            for (int i = 0; i <= s2.top; i++) {
                new_stack.push(s2.arr[i]);
            }
            return new_stack;
        }
        ~MyStack() {
            delete [] arr;
        }
};

int MyStack::stack_count = 0;

int main() {
    MyStack aStackA(5), aStackB(3);
    for (int i = 1; i <= 5; i++) {
        aStackA.push(i);
    }
    for (int i = 1; i <= 3; i++) {
        aStackB.push(i);
    }
    cout << "Stack A: " << endl;
    aStackA.Display();
    cout << "Stack B: " << endl;
    aStackB.Display();
    MyStack aStackC = aStackA + aStackB;
    cout << "Stack C: " << endl;
    aStackC.Display();
    return 0;
}

