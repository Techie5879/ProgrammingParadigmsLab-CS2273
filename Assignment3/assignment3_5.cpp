// Aritra Bandyopadhyay 2021CSB107
// Assignment3_5 Adding polynomials

#include <iostream>
using namespace std;

class Node {
    public:
        int coefficient;
        int exponent;
        Node *next;

        Node(int coefficient, int exponent) {
            this->coefficient = coefficient;
            this->exponent = exponent;
            this->next = NULL;
        }
};

class LinkedList {
    public:
        Node *head;
        LinkedList() {
            head = NULL;
        }
        void addTerm(int coefficient, int exponent) {
            Node *newTerm = new Node(coefficient, exponent);
            if (head == NULL) {
                head = newTerm;
                return;
            }
            Node *current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newTerm;
        }
};


LinkedList addPolynomials(LinkedList first, LinkedList second) {
    LinkedList result;

    Node *firstNode = first.head;
    Node *secondNode = second.head;

    while (firstNode != NULL && secondNode != NULL) {
        if (firstNode->exponent > secondNode->exponent) {
            result.addTerm(firstNode->coefficient, firstNode->exponent);
            firstNode = firstNode->next;
        } 
        else if (firstNode->exponent < secondNode->exponent) {
            result.addTerm(secondNode->coefficient, secondNode->exponent);
            secondNode = secondNode->next;
        } 
        else {
            result.addTerm(firstNode->coefficient + secondNode->coefficient, firstNode->exponent);
            firstNode = firstNode->next;
            secondNode = secondNode->next;
        }
    }

    while (firstNode != NULL) {
        result.addTerm(firstNode->coefficient, firstNode->exponent);
        firstNode = firstNode->next;
    }

    while (secondNode != NULL) {
        result.addTerm(secondNode->coefficient, secondNode->exponent);
        secondNode = secondNode->next;
    }
    return result;
}

int main() {
    LinkedList first;
    LinkedList second;
    int coeff, exp;
    while(true) {
        cout << "For first polynomial (Enter 0 for coeff to break):" << endl;
        cout << "Enter coefficient: ";
        cin >> coeff;
        if (coeff == 0) break;
        cout << "Enter exponent: ";
        cin >> exp;
        first.addTerm(coeff, exp);
    }
    cout << endl;
    while(true) {
        cout << "For second polynomial (Enter 0 for coeff to break):" << endl;
        cout << "Enter coefficient: ";
        cin >> coeff;
        if (coeff == 0) break;
        cout << "Enter exponent: ";
        cin >> exp;
        second.addTerm(coeff, exp);
    }

    Node *current = first.head;
    cout << "First polynomial: ";
    while (current->next != NULL) {
        cout << current->coefficient << "x^" << current->exponent << " + ";
        current = current->next;
    }
    cout << current->coefficient << "x^" << current->exponent << "\n";

    current = second.head;
    cout << "Second polynomial: ";
    while (current->next != NULL) {
        cout << current->coefficient << "x^" << current->exponent << " + ";
        current = current->next;
    }
    cout << current->coefficient << "x^" << current->exponent << "\n";

    LinkedList result = addPolynomials(first, second);

    current = result.head;
    cout << "Result: ";
    while (current->next != NULL) {
        cout << current->coefficient << "x^" << current->exponent << " + ";
        current = current->next;
    }
    cout << current->coefficient << "x^" << current->exponent << "\n";

    return 0;
}
