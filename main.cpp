#include <bits/stdc++.h>
#include "RubiksCube.h"
#include "RubiksCube3d.cpp"
#include "RubiksCube1D.cpp"
#include "RubiksCubeBitBoard.cpp"
#include "./Solver/DFS.h"
#include "./Solver/IDDFS.h"
using namespace std;

int main()
{
    RubiksCube3d cube;
    // cube.B().U().B2().;
    vector<RubiksCube::MOVE> rsMoves = cube.randomShuffle(5);
    for (auto x : rsMoves)
    {
        cout << cube.getMoveLetter(x) << " ";
    }
    cout << "\n";
    IDDFS<RubiksCubeBitBoard, HashBitBoard> s(cube, 4);
    // DFSSolver<RubiksCube3d, Hash3D> s(cube, 3);

    vector<RubiksCube::MOVE> moveList = s.solve();
    // cout<<moveList.size();

    for (auto x : moveList)
    {
        // cout<<"here";
        cout << cube.getMoveLetter(x) << " ";
    }

    return 0;
}
