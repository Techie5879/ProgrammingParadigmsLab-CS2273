// Aritra Bandyopadhyay 2021CSB107
// Assignment3_6 Set Class implementation

#include <bits/stdc++.h>
using namespace std;

class Set {
    public:
        vector<int> elements;
        // Constructor
        Set(vector<int> e) {
            elements = e;
            sort(elements.begin(), elements.end());
        }

        // Union of two sets
        Set Union(Set set2) {
            vector<int> unionElements;
            int i = 0, j = 0;
            while (i < elements.size() && j < set2.elements.size()) {
                if (elements[i] < set2.elements[j]) {
                    unionElements.push_back(elements[i++]);
                } else if (elements[i] > set2.elements[j]) {
                    unionElements.push_back(set2.elements[j++]);
                } else {
                    unionElements.push_back(elements[i++]);
                    j++;
                }
            }
            while (i < elements.size()) {
                unionElements.push_back(elements[i++]);
            }
            while (j < set2.elements.size()) {
                unionElements.push_back(set2.elements[j++]);
            }
            return Set(unionElements);
        }

        // Intersection of two sets
        Set Intersection(Set set2) {
            vector<int> intersectionElements;
            int i = 0, j = 0;
            while (i < elements.size() && j < set2.elements.size()) {
                if (elements[i] < set2.elements[j]) {
                    i++;
                } 
                else if (elements[i] > set2.elements[j]) {
                    j++;
                } 
                else {
                    intersectionElements.push_back(elements[i++]);
                    j++;
                }
            }
            return Set(intersectionElements);
        }

        // Complement of a set
        Set Complement(vector<int> universalSet) {
            vector<int> complementElements;
            int i = 0, j = 0;
            while (i < elements.size() && j < universalSet.size()) {
                if (elements[i] < universalSet[j]) {
                    i++;
                } else if (elements[i] > universalSet[j]) {
                    complementElements.push_back(universalSet[j++]);
                } else {
                    i++;
                    j++;
                }
            }
            while (j < universalSet.size()) {
                complementElements.push_back(universalSet[j++]);
            }
            return Set(complementElements);
        }

        // Set difference
        Set SetDifference(Set set2) {
            return Intersection(set2.Complement(elements));
        }

        // Test equal sets
        bool TestEqualSets(Set set2) {
            if (elements.size() != set2.elements.size()) {
                return false;
            }
            for (int i = 0; i < elements.size(); i++) {
                if (elements[i] != set2.elements[i]) {
                    return false;
                }
            }
            return true;
        }

// Print Cartesian product
        vector<pair<int, int>> CartesianProduct(Set set2) {
            vector<pair<int, int>> product;

            for (int i = 0; i < elements.size(); i++) {
                for (int j = 0; j < set2.elements.size(); j++) {
                    product.push_back(make_pair(elements[i], set2.elements[j]));
                }
            }
            return product;
        }

// Display power set
        void DisplayPowerSet(vector<int> subset, int index) {
            if (index == elements.size()) {
                cout << "{";
                for (int i = 0; i < subset.size(); i++) {
                    cout << subset[i];
                    if (i != subset.size() - 1) {
                        cout << ", ";
                    }
                }
                cout << "}" << endl;
                return;
            }
            DisplayPowerSet(subset, index + 1);
            subset.push_back(elements[index]);
            DisplayPowerSet(subset, index + 1);
            subset.pop_back();
        }

// Test if a set is distinct
        bool TestDistinct() {
            for (int i = 0; i < elements.size() - 1; i++) {
                if (elements[i] == elements[i + 1]) {
                    return false;
                }
            }
            return true;
        }

// Find mean, variance, standard deviation, and median
        void NumericData() {
            if (elements.empty()) {
                cout << "Set is empty" << endl;
                return;
            }
            int sum = 0;
            for (int i = 0; i < elements.size(); i++) {
                sum += elements[i];
            }
            int mean = sum / elements.size();
            cout << "Mean: " << mean << endl;
            int variance = 0;
            for (int i = 0; i < elements.size(); i++) {
                variance += pow(elements[i] - mean, 2);
            }
            variance /= elements.size();
            cout << "Variance: " << variance << endl;

            int standardDeviation = sqrt(variance);
            cout << "Standard deviation: " << standardDeviation << endl;

            int median;
            if (elements.size() % 2 == 0) {
                median = (elements[elements.size() / 2 - 1] + elements[elements.size() / 2]) / 2;
            } else {
                median = elements[elements.size() / 2];
            }
            cout << "Median: " << median << endl;
        }
        void PrintSet() {
            cout << "{";
            for (int i = 0; i < elements.size(); i++) {
                cout << elements[i];
                if (i != elements.size() - 1) {
                    cout << ", ";
                }
            }
            cout << "}" << endl;
        }
};

int main() {
    vector<int> elements1 = {1, 2, 3, 4};
    vector<int> elements2 = {3, 3, 4, 5, 6};
    vector<int> universalSet = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Set set1(elements1);
    Set set2(elements2);

    cout << "Set 1: ";
    set1.PrintSet();
    cout << "Set 2: ";
    set2.PrintSet();

// Union
    cout << "Union: ";
    set1.Union(set2).PrintSet();

// Intersection
    cout << "Intersection: ";
    set1.Intersection(set2).PrintSet();

// Complement
    cout << "Complement of Set 1: ";
    set1.Complement(universalSet).PrintSet();
    cout << "Complement of Set 2: ";
    set2.Complement(universalSet).PrintSet();

// Set difference
    cout << "Set difference of Set 1 and Set 2: ";
    set1.SetDifference(set2).PrintSet();

// Test equal sets
    if (set1.TestEqualSets(set2)) {
        cout << "Set 1 and Set 2 are equal" << endl;
    } else {
        cout << "Set 1 and Set 2 are not equal" << endl;
    }

// Print Cartesian product
    cout << "Cartesian product of Set 1 and Set 2: " << endl;
    vector<pair<int, int>> product = set1.CartesianProduct(set2);
    cout << "{ ";
    for (int i = 0; i < product.size(); i++) {
        if (i == product.size() - 1) cout << "(" << product[i].first << ", " << product[i].second << ")";
        else cout << "(" << product[i].first << ", " << product[i].second << ")" << ", ";

    }
    cout << " }";
    cout << endl;

// Display power set
    cout << "Power Set of Set 1: " << endl;
    set1.DisplayPowerSet({}, 0);

// Test if a set is distinct
    if (set1.TestDistinct()) {
        cout << "Set 1 is distinct" << endl;
    } else {
        cout << "Set 1 is not distinct" << endl;
    }
    if (set2.TestDistinct()) {
        cout << "Set 2 is distinct" << endl;
    } else {
        cout << "Set 2 is not distinct" << endl;
    }

// Find mean, variance, standard deviation, and median
    cout << "Numeric data of Set 1: " << endl;
    set1.NumericData();

    return 0;
}