// Aritra Bandyopadhyay 2021CSB107
// Assignent_2_3 Generic Swap

#include <iostream>
#include <iomanip>

using namespace std;

typedef struct struct1
{
    int data1;
    int data2;

}struct1;


template <typename T> 
void swapper(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}


int main() {
    //Demonstrating the common swapper functions for all datatypes
    int x, y;
    cout << "\nEnter the first int value: ";
    cin >> x;
    cout << "\nEnter the second int value: ";
    cin >> y;
    cout << endl << "Before swapping:" << endl;
    cout << "x: " << x << " y: " << y << endl;
    swapper(x, y);
    cout << "After swapping:" << endl;
    cout << "x: " << x << " y: " << y << endl;

    short a, b;
    cout << "\nEnter the first short value: ";
    cin >> a;
    cout << "\nEnter the second short value: ";
    cin >> b;
    cout << endl << "Before swapping:" << endl;
    cout << "a: " << a << " b: " << b << endl;
    swapper(a, b);
    cout << "After swapping:" << endl;
    cout << "a: " << a << " b: " << b << endl;

    float p, q;
    cout << "\nEnter the first float value: ";
    cin >> p;
    cout << "\nEnter the second float value: ";
    cin >> q;
    cout << endl << "Before swapping:" << endl;
    cout << setprecision(4) << "p: " << p << " q: " << q << endl;
    swapper(p, q);
    cout << "After swapping:" << endl;
    cout << setprecision(4) << "p: " << p << " q: " << q << endl;


    double r, s;
    cout << "\nEnter the first double value: ";
    cin >> r;
    cout << "\nEnter the second double value: ";
    cin >> s;
    cout << endl << "Before swapping:" << endl;
    cout << setprecision(6) << "r: " << r << " s: " << s << endl;
    swapper(r, s);
    cout << "After swapping:" << endl;
    cout << setprecision(6) << "r: " << r << " s: " << s << endl;


    // Making a struct that represents (x,y) coordinates
    struct Point {
        int x;
        int y;
    };

    struct Point pt1, pt2;
    cout << "\nEnter the x coordinate of the first point: ";
    cin >> pt1.x;
    cout << "\nEnter the y coordinate of the first point: ";
    cin >> pt1.y;
    cout << "\nEnter the x coordinate of the second point: ";
    cin >> pt2.x;
    cout << "\nEnter the y coordinate of the second point: ";
    cin >> pt2.y;

    cout << endl << "Before swapping:" << endl;
    cout << "pt1.x: " << pt1.x << " pt1.y: " << pt1.y << endl;
    cout << "pt2.x: " << pt2.x << " pt2.y: " << pt2.y << endl;
    swapper(pt1, pt2);
    cout << "After swapping:" << endl;
    cout << "pt1.x: " << pt1.x << " pt1.y: " << pt1.y << endl;
    cout << "pt2.x: " << pt2.x << " pt2.y: " << pt2.y << endl;    
    return 0;
}


