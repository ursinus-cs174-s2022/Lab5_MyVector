#include <stdio.h>
#include <vector>
#include <iostream>
#include <time.h> 
#include <sstream>
#include <string>
#include <algorithm>
#include "myvector.h"
using namespace std;

/**
 * @brief Compare a regular stl vector to one of our custom vectors
 * 
 * @param arr Instance of a regular stl vector
 * @param myarr Instance of on of our own vector objects
 * @return true if the vectors have the same elements
 * @return false if the vectors difffer anywhere
 */
bool listsEqual(vector<int>& arr, myvector<int>& myarr) {
    bool equal = (int)arr.size() == myarr.size();
    for (size_t i = 0; i < arr.size() && (int)i < myarr.size() && equal; i++) {
        int i1 = arr.at(i);
        int i2 = myarr.at(i);
        if (i1 != i2) {
            equal = false;
        }
    }
    return equal;
}

/**
 * @brief Print out the elements of an stl vector formatted exactly
 * as the elements of our custom vector are formatted
 * 
 * @param arr STL Vector to print out
 */
void printVector(vector<int>& arr) {
    cout << "[";
    for (size_t k = 0; k < arr.size(); k++) {
        cout << arr.at(k);
        if (k < arr.size()-1) {
            cout << ", ";
        }
    }
    cout << "]\n";
}

/**
 * @brief Remove the first instance of a particular element from 
 *        an STL vector if that element exists
 * 
 * @param arr STL vector
 * @param item Element to remove
 */
void removeVectorItem(vector<int>& arr, int item) {
    vector<int>::iterator it = arr.begin();
    bool found = false;
    while (!found && it != arr.end()) {
        if (*it == item) {
            found = true;
            arr.erase(it);
        }
        else {
            it++;
        }
    }
}


void doTest(int numOps, int seed) {
    vector<int> arr;
    myvector<int> myarr;
    srand(seed);
    for (int i = 0; i < numOps; i++) {
        string operation = "no operation";
        int op = rand() % 100;
        if (op < 50) {
            int x = rand() % numOps;
            arr.push_back(x);
            myarr.push_back(x);
            stringstream stream;
            stream << "push_back(" << x << ")";
            operation = stream.str();
        }
        else if (op < 80 && arr.size() > 0) {
            int x = rand() % numOps;
            int index = rand() % arr.size();
            arr.insert(arr.begin() + index, x);
            myarr.insert(index, x);
            stringstream stream;
            stream << "insert(" << index << ", " << x << ")";
            operation = stream.str();
        }
        else if (op < 90 && arr.size() > 0) {
            int x = rand() % numOps;
            int index = rand() % arr.size();
            arr[index] = x;
            myarr.set(index, x);
            stringstream stream;
            stream << "set(" << index << ", " << x << ")";
            operation = stream.str();
        }
        else if (op < 95 && arr.size() > 0) {
            int index = rand() % arr.size();
            arr.erase(arr.begin() + index);
            myarr.remove(index);
            stringstream stream;
            stream << "remove(" << index << ")";
            operation = stream.str();
        }
        else if (op < 98 && arr.size() > 0) {
            int value = arr.at(rand() % arr.size());
            removeVectorItem(arr, value);
            myarr.removeItem(value);
            stringstream stream;
            stream << "removeItem(" << value << ")";
            operation = stream.str();
        }
        cout << operation << "\n";
        if ((int)arr.size() != myarr.size()) {
            cout << "Vector:    ";
            printVector(arr);
            cout << "My Vector: " << myarr.toString() << "\n";
            cout << "Arrays do not have the same size after a " << operation;
            cout << "\n Ground truth size " << arr.size() <<  ", my size " << myarr.size() << "\n";
            return;
        }
        
        if (!listsEqual(arr, myarr)) {
            cout << "Vector:    ";
            printVector(arr);
            cout << "My Vector: " << myarr.toString() << "\n";
            cout << "Arrays not equal after a " << operation << "\n";
            return;
        }
    }
}


int main(int argc, char** argv) {
    if (argc < 3) {
        cout << "Usage: ./tester <number of operations> <seed>\n";
        return 1;
    }
    int numOps = atoi(argv[1]);
    int seed = atoi(argv[2]);
    doTest(numOps, seed);
    return 0;
}

