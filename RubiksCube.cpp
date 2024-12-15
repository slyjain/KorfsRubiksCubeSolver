//
// Created by heisenberg on 12/13/24.
//
#include<bits/stdc++.h>
using namespace std;
#include "RubiksCube.h"
char RubiksCube::getColorLetter(COLOR color) {
    switch(color) {
        case COLOR::WHITE:
            return 'W';
        case COLOR::GREEN:
            return 'G';
        case COLOR::RED:
            return 'R';
        case COLOR::BLUE:
            return 'B';
        case COLOR::ORANGE:
            return 'O';
        case COLOR::YELLOW:
            return 'Y';
        default:
            return '?';
    }
}
void RubiksCube::printColor(char color) {
    switch (color) {
        case 'W': std::cout << "\033[38;2;255;255;255mW\033[0m "; break; // Bright White
        case 'G': std::cout << "\033[38;2;0;255;0mG\033[0m "; break;     // Bright Green (Lime Green)
        case 'R': std::cout << "\033[1;31mR\033[0m "; break;     // Bright Red
        case 'B': std::cout << "\033[1;34mB\033[0m "; break;     // Bright Blue
        case 'O': std::cout << "\033[38;2;255;165;0mO\033[0m "; break;   // Bright Orange (RGB: 255, 165, 0)
        case 'Y': std::cout << "\033[38;2;255;255;0mY\033[0m "; break;   // Bright Yellow
        default:  std::cout << "\033[0m? "; break;                // Reset
    }
}
void RubiksCube::print() {
    for(int i=0;i<9;i++) {
        for(int j=0;j<12;j++) {
            if(j>=3&&j<=5&&i>=0&&i<=2) {
                printColor(getColorLetter(getColor(FACE::UP,i-0,j-3)));
                // cout<<i<<","<<j-3;
            }
            else if(i>=3&&i<=5&&j>=0&&j<=2) {
                printColor(getColorLetter(getColor(FACE::LEFT,i-3,j-0)));
                // cout<<i-3<<","<<j;
            }
            else if(i>=3&&i<=5&&j>=3&&j<=5) {
                printColor(getColorLetter(getColor(FACE::FRONT,i-3,j-3)));
                // cout<<i-3<<","<<j-3;
            }
            else if(i>=3&&i<=5&&j>=6&&j<=8) {
                printColor(getColorLetter(getColor(FACE::RIGHT,i-3,j-6)));
                // cout<<i-3<<","<<j-6;
            }
            else if(i>=3&&i<=5&&j>=9&&j<=11) {
                printColor(getColorLetter(getColor(FACE::BACK,i-3,j-9)));
                // cout<<i-3<<","<<j-9;
            }
            else if(j>=3&&j<=5&&i>=6&&i<=8) {
                printColor(getColorLetter(getColor(FACE::DOWN,i-6,j-3)));
                // cout<<i-6<<","<<j-3;
            }else {
                cout<<"  ";
            }

        }
        cout<<"\n";
    }
}
RubiksCube &RubiksCube::move(MOVE ind) {
    switch (ind) {
        case MOVE::U:
            return this->U();
        case MOVE::U2:
            return this->U2();
        case MOVE::UPRIME:
            return this->UPRIME();
        case MOVE::L:
            return this->L();
        case MOVE::L2:
            return this->L2();
        case MOVE::LPRIME:
            return this->LPRIME();
        case MOVE::F:
            return this->F();
        case MOVE::F2:
            return this->F2();
        case MOVE::FPRIME:
            return this->FPRIME();
        case MOVE::R:
            return this->R();
        case MOVE::R2:
            return this->R2();
        case MOVE::RPRIME:
            return this->RPRIME();
        case MOVE::B:
            return this->B();
        case MOVE::B2:
            return this->B2();
        case MOVE::BPRIME:
            return this->BPRIME();
        case MOVE::D:
            return this->D();
        case MOVE::D2:
            return this->D2();
        case MOVE::DPRIME:
            return this->DPRIME();
    }
}
RubiksCube &RubiksCube::invert(MOVE ind) {
    switch (ind) {
        case MOVE::U:
            return this->UPRIME();
        case MOVE::U2:
            return this->U2();
        case MOVE::UPRIME:
            return this->U();
        case MOVE::L:
            return this->LPRIME();
        case MOVE::L2:
            return this->L2();
        case MOVE::LPRIME:
            return this->L();
        case MOVE::F:
            return this->FPRIME();
        case MOVE::F2:
            return this->F2();
        case MOVE::FPRIME:
            return this->F();
        case MOVE::R:
            return this->RPRIME();
        case MOVE::R2:
            return this->R2();
        case MOVE::RPRIME:
            return this->R();
        case MOVE::B:
            return this->BPRIME();
        case MOVE::B2:
            return this->B2();
        case MOVE::BPRIME:
            return this->B();
        case MOVE::D:
            return this->DPRIME();
        case MOVE::D2:
            return this->D2();
        case MOVE::DPRIME:
            return this->D();
    }
}
vector<RubiksCube::MOVE> RubiksCube::randomShuffle(int times){
    srand(time(0));
    vector<MOVE> moves_made;
    for(int i=0;i<times;i++){
        int num=rand()%18;
        moves_made.push_back(static_cast<MOVE>(num));
        this->move(static_cast<MOVE>(num));
    }
    return moves_made;
}
bool RubiksCube::isSolved(RubiksCube& c){
    for(int i=0;i<6;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                if(getColorLetter(c.getColor(FACE(i),j,k))==getColorLetter(COLOR(i)))continue;
                else{return false;}
            }
        }
    }
    return true;
}