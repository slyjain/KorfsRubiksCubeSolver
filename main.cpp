#include <bits/stdc++.h>
// #include "RubiksCube.h"
// #include "RubiksCube3d.cpp"
// #include "RubiksCube1D.cpp"
// #include "RubiksCubeBitBoard.h"
// #include "./Solver/DFS.h"
// #include "./Solver/IDDFS.h"
#include "./Solver/IDAstarSolver.h"
#include "PatternDatabase/CornerDBMaker.h"
using namespace std;

int main()
{
    RubiksCubeBitBoard cube;
    string fileName="/home/heisenberg/CLionProjects/KorfsRubiksCubeSolver/Database.txt";
//        CornerDBMaker dbMaker(fileName, 0x99);
//    dbMaker.bfsAndStore();
   vector<RubiksCube::MOVE>movesMade= cube.randomShuffle(5);
   for(auto x:movesMade){
    cout<<cube.getMoveLetter(x)<<" ";
   }
   cout<<"\n";
    IDAstarSolver<RubiksCubeBitBoard,HashBitBoard>idaStar(cube);
    vector<RubiksCube::MOVE>allMoves=idaStar.solve();
    for(auto x:allMoves){
        cout<<cube.getMoveLetter(x)<<" ";
    }
    cout<<"\n";

    return 0;
}
