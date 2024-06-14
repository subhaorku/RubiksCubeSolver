#include<bits/stdc++.h>
#include "../Model/RubiksCube.h"

#ifndef RUBIKS_CUBE_SOLVER_DFSSOLVER_H
#define RUBIKS_CUBE_SOLVER_DFSSOLVER_H

/*
 * TypeName T : RubiksCube Representation used (3d Array. 1d Array , Bitboard)
 * TypeName H : Corresponding Hash Function
 * This defines a template class DFSSolver which can work with different types of Rubik's Cube representations (T) and corresponding hash functions (H).
 */

template<typename  T,typename H>

class DFSSOLVER {
private:

    vector<RubiksCube::MOVE>moves; //vector to store sequence of moves performed to solve the given rubiksCube
    int max_search_depth; //maximum depth for dfs search after which dfs will give up


    // DFS CODE to find the solution (helper function)

    bool dfs(int dep) {
        if(rubiksCube.isSolved()) return true; //Base Case
        if(dep > max_search_depth) return false; // if curr depth exceeds max search depth then return false

        //Loop over all the 18 diff states u can visit from the curr state

        for(int i=0;i<18;i++)
        {
            rubiksCube.move(RubiksCube::MOVE(i)); //perform a move out of 18 diff operations
            moves.push_back(RubiksCube::MOVE(i)); //Add the move to the sequence
            if(dfs(dep+1)) return  true; // Recursively Call dfs with increased depth
            moves.pop_back();//Backtrack : Remove the last move since it didnt reach the solved state
            rubiksCube.invert(RubiksCube::MOVE(i)); // Invert the move to restore the cube's state

        }
        return false;//if no solution is found at this depth value 'dep'
    }

public:
    T rubiksCube; // This is an instance of the Rubik's Cube, represented by the template type T. It stores the current state of the cube that the solver will work on.


    // The constructor initializes the rubiksCube instance and the max_search_depth
    /*
     * Parameters:
     * T _rubiksCube: The initial state of the Rubik's Cube.
     * int _max_search_depth: The maximum depth for the DFS search. It defaults to 8 if not provided.
     * Inside the constructor, the initial Rubik's Cube state and the maximum search depth are assigned to the corresponding member variables.
     */
    DFSSOLVER(T _rubiksCube, int _max_search_depth=8)
    {
        rubiksCube = _rubiksCube;
        max_search_depth=_max_search_depth;
    }

   /*
    * solve method
    */
    vector<RubiksCube::MOVE> solve(){
        dfs(1);//start off with depth =1 i.e. the root node / curr state
        return moves;
    }

};
#endif // RUBIKS_CUBE_SOLVER_DFSSOLVER_H