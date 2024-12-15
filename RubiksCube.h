//
// Created by heisenberg on 12/13/24.
//

#ifndef RUBIKSCUBE_H
#define RUBIKSCUBE_H

#include<bits/stdc++.h>
using namespace std;

class RubiksCube {
public:
    enum class FACE {
        UP,
        LEFT,
        FRONT,
        RIGHT,
        BACK,
        DOWN
    };
    enum class COLOR {
        WHITE,
        GREEN,
        RED,
        BLUE,
        ORANGE,
        YELLOW
    };
    enum class MOVE {
        U,U2,UPRIME,
        L,L2,LPRIME,
        F,F2,FPRIME,
        R,R2,RPRIME,
        B,B2,BPRIME,
        D,D2,DPRIME
    };
    virtual COLOR getColor(FACE face,unsigned row,unsigned col)const=0;
    char getColorLetter(COLOR color);
    void printColor(char c);
    void print();
    RubiksCube& move(MOVE move);
    RubiksCube& invert(MOVE move);
    vector<MOVE> randomShuffle(int times);
    bool isSolved(RubiksCube& c);
    virtual RubiksCube& U() = 0;       // Up clockwise
    virtual RubiksCube& UPRIME() = 0;   // Up counterclockwise
    virtual RubiksCube& U2() = 0;       // Up 180 degrees

    virtual RubiksCube& D() = 0;       // Down clockwise
    virtual RubiksCube& DPRIME() = 0;   // Down counterclockwise
    virtual RubiksCube& D2() = 0;       // Down 180 degrees

    virtual RubiksCube& L() = 0;       // Left clockwise
    virtual RubiksCube& LPRIME() = 0;  // Left counterclockwise
    virtual RubiksCube& L2() = 0;      // Left 180 degrees

    virtual RubiksCube& R() = 0;       // Right clockwise
    virtual RubiksCube& RPRIME() = 0;  // Right counterclockwise
    virtual RubiksCube& R2() = 0;      // Right 180 degrees

    virtual RubiksCube& F() = 0;       // Front clockwise
    virtual RubiksCube& FPRIME() = 0;  // Front counterclockwise
    virtual RubiksCube& F2() = 0;      // Front 180 degrees

    virtual RubiksCube& B() = 0;       // Back clockwise
    virtual RubiksCube& BPRIME() = 0;  // Back counterclockwise
    virtual RubiksCube& B2() = 0;      // Back 180 degrees

};



#endif RUBIKSCUBE_H
