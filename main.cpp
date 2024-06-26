//
// Created by Mayukh on 26-06-2024.
//
#include<bits/stdc++.h>

#include "BFSSolver.h"

#include "CornerPatternDatabase.h"
using namespace std;
int main() {




    RubiksCube3darr cube;
     cube.randomShuffleCube(5);
    cube.print();
    BFSSolver solver(cube);

    solver.bfs();
    for(auto c:solver.moves)cout<<cube.getMove(c)<<" ";



    cout << "\n";



    return 0;

    return 0;
}
