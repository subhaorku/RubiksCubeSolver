#include<bits/stdc++.h>
#include "Model/RubiksCube3DArray.cpp"
#include "Model/RubiksCube1DArray.cpp"
#include "Solver/DFSSolver.h"

using namespace std;

int main() {
    RubiksCube3dArray object3DArray;
    RubiksCube1dArray object1DArray;
    object3DArray.print();
    if (object3DArray.isSolved()) cout << "SOLVED\n\n";
    else cout << "NOT SOLVED\n\n";

        if (object1DArray.isSolved()) cout << "SOLVED\n\n";
    else cout << "NOT SOLVED\n\n";

    object3DArray.u();
    object1DArray.u();
    object3DArray.print();
    object1DArray.print();
    if (object3DArray.isSolved()) cout << "SOLVED\n\n";
    else cout << "NOT SOLVED\n\n";

    if (object1DArray.isSolved()) cout << "SOLVED\n\n";
    else cout << "NOT SOLVED\n\n";
    object3DArray.l();
    object1DArray.l();
    object3DArray.print();
    object1DArray.print();
    if (object3DArray.isSolved()) cout << "SOLVED\n\n";
    else cout << "NOT SOLVED\n\n";

    if (object1DArray.isSolved()) cout << "SOLVED\n\n";
    else cout << "NOT SOLVED\n\n";
    object3DArray.lPrime();
    object1DArray.lPrime();
    object3DArray.print();
    object1DArray.print();
    if (object3DArray.isSolved()) cout << "SOLVED\n\n";
    else cout << "NOT SOLVED\n\n";

    if (object1DArray.isSolved()) cout << "SOLVED\n\n";
    else cout << "NOT SOLVED\n\n";

    object3DArray.uPrime();
    object1DArray.uPrime();
    object3DArray.print();
    object1DArray.print();
    if (object3DArray.isSolved()) cout << "SOLVED\n\n";
    else cout << "NOT SOLVED\n\n";

    if (object1DArray.isSolved()) cout << "SOLVED\n\n";
    else cout << "NOT SOLVED\n\n";
    return 0;
}
