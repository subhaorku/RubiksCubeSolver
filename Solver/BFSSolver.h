#include<bits/stdc++.h>
#include "../Model/RubiksCube.h"

#ifndef RUBIKS_CUBE_SOLVER_BFSSOLVER_H
#define RUBIKS_CUBE_SOLVER_BFSSOLVER_H

// Typename T: RubiksCube Representation used (3d, 1d, Bitboard)
// Typename H: Corresponding Hash function


template<typename T,typename H>

class BFSSolver {
private:
    vector<RubiksCube::MOVE>moves; // Vector to store the sequence of moves performed to solve the cube
    unordered_map<T,bool,H>visited; // Hash map to keep track of visited states
    unordered_map<T,RubiksCube::MOVE,H> move_done; //  Hash map to store the move that led to each state

    //    move_done[] -> Back-Pointer map as to how we reached that state

    T bfs() {
        queue<T> q;
        q.push(rubiksCube);
        visited[rubiksCube]=true;

        while(!q.empty())
        {
            T node = q.front();
            q.pop();
            if(node.isSolved()){
                return node;
            }
            for(int i=0;i<18;i++)
            {
                auto curr_move = RubiksCube::MOVE(i);
                node.move(curr_move);
                if(!visited[node])
                {
                    visited[node]=true;
                    move_done[node]=curr_move;
                    q.push(node);
                }
                node.invert(curr_move);//restore back to explore the states at same level
            }
        }
        return  rubiksCube;
    }

public:

    T rubiksCube;

    BFSSolver(T _rubiksCube)
    {
        rubiksCube = _rubiksCube;
    }

    // perform BFS and return the vector of moves done to solve the cube

    vector<RubiksCube::MOVE> solve()
    {
        T solved_cube = bfs();
        assert(solved_cube.isSolved());
        T curr_cube = solved_cube;
        while(!(curr_cube == rubiksCube))
        {
            RubiksCube::MOVE curr_move = move_done[curr_cube];
            moves.push_back(curr_move);
           curr_cube.invert(curr_move);
        }
        rubiksCube = solved_cube;
        reverse(moves.begin(),moves.end());
        return moves;
    }
};

#endif //RUBIKS_CUBE_SOLVER_BFSSOLVER_H