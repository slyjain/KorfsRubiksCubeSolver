#include <bits/stdc++.h>
#include "RubiksCube.h"
#include "RubiksCube3d.cpp"
#include "RubiksCube1D.cpp"
using namespace std;

int main() {
    RubiksCube1D a;
    a.print();
    // a.F();
    // a.print();
    // a.FPRIME();
    // a.print();
    // a.F2();
    // a.print();
    // a.D();
    // a.print();
    // a.UPRIME();
    // a.print();
    // a.U2();
    // // a.U2();
    // a.print();
    // a.D();
    // a.print();
    // a.D();
    // a.print();
    // a.D2();
    // a.print();
    // a.DPRIME();
    // a.print();
    // a.D();
    // a.print();
      // a.B();
    // a.print();
    // a.BPRIME();
    // a.print();
    // a.B2();
    // a.print();
    // a.R();
    // a.print();
    // a.RPRIME();
    // a.print();
    // a.L();
    // a.print();
    // a.L();
    // a.print();
    // a.L();
    // a.print();
    // a.L();
    // a.print();
    // a.L2();
    // a.print();
    // a.L2();
    // a.print();
    // vector<RubiksCube::MOVE>moves_made=a.randomShuffle(5);
    a.U();
    a.print();
    cout<<"Is this Rubiks Cube solved: "<<a.isSolved(a)<<"\n";
    // for(auto it=moves_made.rbegin();it!=moves_made.rend();it++){
    //   a.invert(*it);
    //   // cout<<static_cast<int>(*it)<<"\n";
    // }
    a.BPRIME();
    a.print();
    cout<<"Is this Rubiks Cube solved: "<<a.isSolved(a)<<"\n";
    
    return 0;
}
