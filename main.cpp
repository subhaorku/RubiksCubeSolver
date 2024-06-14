#include<bits/stdc++.h>
#include "Model/RubiksCube3DArray.cpp"
#include "Model/RubiksCube1DArray.cpp"
#include "Solver/DFSSolver.h"
#include "Solver/BFSSolver.h"
#include "Solver/IDDFSSolver.h"
using namespace std;

int main() {
//    RubiksCube3dArray object3DArray;
//    RubiksCube1dArray object1DArray;
//    object3DArray.print();
//    if (object3DArray.isSolved()) cout << "SOLVED\n\n";
//    else cout << "NOT SOLVED\n\n";
//
//        if (object1DArray.isSolved()) cout << "SOLVED\n\n";
//    else cout << "NOT SOLVED\n\n";
//
//    object3DArray.u();
//    object1DArray.u();
//    object3DArray.print();
//    object1DArray.print();
//    if (object3DArray.isSolved()) cout << "SOLVED\n\n";
//    else cout << "NOT SOLVED\n\n";
//
//    if (object1DArray.isSolved()) cout << "SOLVED\n\n";
//    else cout << "NOT SOLVED\n\n";
//    object3DArray.l();
//    object1DArray.l();
//    object3DArray.print();
//    object1DArray.print();
//    if (object3DArray.isSolved()) cout << "SOLVED\n\n";
//    else cout << "NOT SOLVED\n\n";
//
//    if (object1DArray.isSolved()) cout << "SOLVED\n\n";
//    else cout << "NOT SOLVED\n\n";
//    object3DArray.lPrime();
//    object1DArray.lPrime();
//    object3DArray.print();
//    object1DArray.print();
//    if (object3DArray.isSolved()) cout << "SOLVED\n\n";
//    else cout << "NOT SOLVED\n\n";
//
//    if (object1DArray.isSolved()) cout << "SOLVED\n\n";
//    else cout << "NOT SOLVED\n\n";
//
//    object3DArray.uPrime();
//    object1DArray.uPrime();
//    object3DArray.print();
//    object1DArray.print();
//    if (object3DArray.isSolved()) cout << "SOLVED\n\n";
//    else cout << "NOT SOLVED\n\n";
//
//    if (object1DArray.isSolved()) cout << "SOLVED\n\n";
//    else cout << "NOT SOLVED\n\n";

// DFS Solver Testing-----------------------------------------------------------------------------------------------------------
//RubiksCube3dArray cube;
//cube.print();
//vector<RubiksCube::MOVE> shuffle_moves = cube.randomShuffleCube(6);
//for (auto move : shuffle_moves) cout<< cube.getMove(move)<<" ";
//cout<<"\n\n";
//cube.print();
//
//DFSSOLVER<RubiksCube3dArray,Hash3d> DFSSolver(cube,8);
//vector<RubiksCube::MOVE> solve_moves = DFSSolver.solve();
//
//for(auto move:solve_moves) cout<<cube.getMove(move)<<" ";
//cout<<"\n";
//DFSSolver.rubiksCube.print();



// BFS Solver Testing-----------------------------------------------------------------------------------------------------------
//RubiksCube3dArray object3DArray;
//object3DArray.print();
//vector<RubiksCube::MOVE> shuffle_moves = object3DArray.randomShuffleCube(6);
//for (auto move : shuffle_moves) cout<< object3DArray.getMove(move)<<" ";
//cout<<"\n\n";
//object3DArray.print();
//
//BFSSolver<RubiksCube3dArray,Hash3d> bfsSolver(object3DArray);
//vector<RubiksCube::MOVE> solve_moves = bfsSolver.solve();
//
//for(auto move:solve_moves) cout<<object3DArray.getMove(move)<<" ";
//cout<<"\n";
//bfsSolver.rubiksCube.print();


// IDDFS Solver Testing-----------------------------------------------------------------------------------------------------------

//RubiksCube3dArray cube;
//cube.print();
//vector<RubiksCube::MOVE> shuffle_moves = cube.randomShuffleCube(6);
//for (auto move : shuffle_moves) cout<< cube.getMove(move)<<" ";
//cout<<"\n\n";
//cube.print();
//
//    IDDFSSolver<RubiksCube3dArray,Hash3d> IDDFSSolver(cube,8);
//vector<RubiksCube::MOVE> solve_moves = IDDFSSolver.solve();
//
//for(auto move:solve_moves) cout<<cube.getMove(move)<<" ";
//cout<<"\n";
//IDDFSSolver.rubiksCube.print();

return 0;
}
