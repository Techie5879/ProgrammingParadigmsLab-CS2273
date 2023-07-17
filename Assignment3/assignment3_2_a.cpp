// Aritra Bandyopadhyay 2021CSB107
// Assignment3_2 Stack Class

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
    int stack_size;
    cout << "Initialize a stack: " << endl;
    cout << "Enter size: ";
    cin >> stack_size;
    MyStack stack(stack_size);
    // Stack is initialized upto here
    int switcher;
    while (true) {
        cout << "\nPress 0 to display all operations\n";
        cout << "\nEnter an operation: ";

        cin >> switcher;

        switch(switcher)
        {
            case 0:
                cout << "Press 1 to Push an Integer to the Stack\n";
                cout << "Press 2 to Pop an Integer from the Stack\n";
                cout << "Press 3 get Max Size of Stack\n";
                cout << "Press 4 get Current Size of Stack\n";
                cout << "Press 5 to check if Stack is Empty\n";
                cout << "Press 6 to Display the Stack contents\n";
                cout << "Press 7 to Exit\n";
                break;
            case 1:
            {
                cout << "\nEnter integer to be pushed to stack: ";
                int data;
                cin >> data;
                if (!stack.push(data)) {
                    cout << "Stack Overflow" << endl;
                }
                else {
                    cout << data << " successfully pushed to stack" << endl;
                }
                break;
            }
            case 2:
            {
                int popped = stack.pop();
                if (popped == -1) cout << "Stack Underflow" << endl;
                else {
                    cout << popped << " popped from Stack" << endl;
                }
                break;
            }
            case 3:
                cout << "Max size of stack is: " << stack.MaxSize() << endl;
                break;
            case 4:
                cout << "Current size of stack is: " << stack.CurrentSize() << endl;
                break;
            case 5:
                if(stack.isEmpty()) cout << "Stack is empty" << endl;
                else cout << "Stack isn't empty" << endl;
                break;
            case 6:
                stack.Display();
                break;
            case 7:
                stack.~MyStack();
                cout << "Deleted Stack" << endl << "Exiting..." << endl;
                exit(0);
                break;
 
        }
    }
}
