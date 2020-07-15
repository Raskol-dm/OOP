#include <iostream>

#include "MathVector.h"

using namespace std;
using namespace mathvector;

int main() {
    MathVector<int> vec = { 0, 1, 2};  // переменная
    MathVector<int> vec1 = { 3, 4, 5};

    cout << "Tests" <<endl;

    cout << "initial vector" <<endl;
    for (auto el: vec) {
        cout << el << " ";
    }
    cout<< endl;

    cout << "length = " << vec.length() << endl;
    cout << "angle = " << vec.angle(vec1) << endl;
    cout << "ortogonality = " << vec.ortogonality(vec1) << endl;
    cout << "collinearity = " << vec.collinearity(vec1) << endl;

    vec *= 10;

    cout << "changed vector" <<endl;
    for (auto el: vec) {   // по каждому элементу из вектора
        cout << el << " ";
    }
    cout<< endl;

    cout << "Checking for equalling " << vec.equals(vec1) << endl;

    MathVector<double> vec2 = {1.2, 2, 4, 5};

    vec2.normalize();

    cout << "normalized vector" <<endl;
    for (auto el: vec2) {
        cout << el << " ";
    }
    cout<< endl;

    vec.addTo(vec1);

    cout << "added vector" <<endl;
    for (auto el: vec) {
        cout << el << " ";
    }
    cout<< endl;

    return 0;
}
