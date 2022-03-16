#include <iostream>
#include "myvector.h"

using namespace std;

int main() {
    myvector<float> arr;
    for (int i = 0; i < 15; i++) {
        arr.add(i);
    }
    arr.add(1, 100);
    arr.add(5, 60);
    cout << arr.toString() << "\n";
}