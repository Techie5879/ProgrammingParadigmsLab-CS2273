// Aritra Bandyopadhyay 2021CSB107
// Generic stack
#include <iostream>
using namespace std;

typedef struct Person {
    string name;
    int age;
}
Person;

template<typename T>
class MyStack {
    private:
        T *arr;
        int top;
        int max_size;
    public:
        MyStack(int maxSize) {
            max_size = maxSize;
            arr = new T[max_size];
            top = -1;
        }
        bool isEmpty() {
            return top == -1;
        }
        bool push(T data) {
            if (top >= max_size - 1) 
                return false;
            arr[++top] = data;
            return true;
        }
        T pop() {
            if (isEmpty()) {
                return T();
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
        void DisplayStruct() {
            if(isEmpty()) {
                cout << "Stack is empty" << endl;
                return;
            }
            cout << endl;
            for (int i = CurrentSize() - 1; i >= 0; i--) {
                cout << arr[i].name << endl;
                cout << arr[i].age << endl;
            }
            return;
            
        }
};


int main() {
    MyStack<int> intStack(5);
    intStack.push(1);
    intStack.push(2);
    intStack.push(3);
    intStack.push(4);

    cout << "Int stack: " << endl;
    intStack.Display();

    MyStack<short> shortStack(5);
    shortStack.push(11);
    shortStack.push(22);
    shortStack.push(33);

    cout << "Short stack: " << endl;
    shortStack.Display();

    MyStack<float> floatStack(5);
    floatStack.push(1.1);
    floatStack.push(2.2);
    floatStack.push(3.3);

    cout << "Float stack: " << endl;
    floatStack.Display();

    MyStack<double> doubleStack(5);
    doubleStack.push(1.11);
    doubleStack.push(2.22);
    doubleStack.push(3.33);

    cout << "Double stack: " << endl;
    doubleStack.Display();

    MyStack<Person> personStack(3);
    Person p1;
    Person p2;
    Person p3;
    p1.name = "John Doe";
    p1.age = 30;
    personStack.push(p1);

    p2.name = "Jane Doe";
    p2.age = 25;
    personStack.push(p2);

    p3.name = "Jim Smith";
    p3.age = 35;
    personStack.push(p3);

    cout << "Person stack: " << endl;
    personStack.DisplayStruct();

    return 0;
}