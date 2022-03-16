#include <iostream>
#include "myvector.h"

using namespace std;

int main() {
    myvector<float> arr;
    for (int i = 0; i < 15; i++) {
        arr.push_back(i);
    }
    arr.insert(1, 100);
    arr.insert(5, 60);
    cout << arr.toString() << "\n";
}