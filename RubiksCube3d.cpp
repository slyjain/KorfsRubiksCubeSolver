//
// Created by heisenberg on 12/13/24.
//
#include "RubiksCube.h"
#include<bits/stdc++.h>
using namespace std;
class RubiksCube3d :public RubiksCube{
    char cube[6][3][3]{};
    void rotateFace(FACE f) {
        int temp[3][3]{};
        int fR = static_cast<int>(f);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                temp[i][j] = cube[fR][i][j];
            }
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cube[fR][j][2 - i] = temp[i][j];
            }
        }
    }
    void rotateFace(int f) {
        int temp[3][3]{};
        int fR = f;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                temp[i][j] = cube[fR][i][j];
            }
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cube[fR][j][2 - i] = temp[i][j];
            }
        }
    }
public:
    RubiksCube3d() {
        for(int i=0;i<6;i++) {
            for(int j=0;j<3;j++) {
                for(int k=0;k<3;k++) {
                    cube[i][j][k]=getColorLetter(COLOR(i));
                }
            }
        }
    }
    COLOR getColor(FACE face, unsigned row, unsigned col) const override {
        char c=cube[(int(face))][row][col];
        switch(c) {
            case 'W': return COLOR::WHITE;
            case 'G': return COLOR::GREEN;
            case 'R': return COLOR::RED;
            case 'B': return COLOR::BLUE;
            case 'O': return COLOR::ORANGE;
            case 'Y': return COLOR::YELLOW;
        }
    };
    RubiksCube& F() override {
         cout << "Rotating Front face clockwise" << std::endl;
        rotateFace(FACE::FRONT);
        int temp[3]{};
            for(int i=0;i<3;i++) {
                temp[i]=cube[3][i][0];
            }
        for(int i=0;i<3;i++) {
            cube[3][i][0]=cube[0][2][i];
        }
        for(int i=0;i<3;i++) {
            cube[0][2][i]=cube[1][2-i][2];
        }
        for(int i=0;i<3;i++) {
            cube[1][2-i][2]=cube[5][0][2-i];
        }
        for(int i=0;i<3;i++) {
            cube[5][0][2-i]=temp[i];
        }
        return *this;

    };
    RubiksCube& FPRIME() override {
        cout << "Rotating Front face anti-clockwise" << std::endl;
        rotateFace(FACE::FRONT);
        int temp[3]{};
        for(int i=0;i<3;i++) {
            temp[i]=cube[3][i][0];
        }
        for(int i=0;i<3;i++) {
            cube[3][i][0]=cube[0][2][i];
        }
        for(int i=0;i<3;i++) {
            cube[0][2][i]=cube[1][2-i][2];
        }
        for(int i=0;i<3;i++) {
            cube[1][2-i][2]=cube[5][0][2-i];
        }
        for(int i=0;i<3;i++) {
            cube[5][0][2-i]=temp[i];
        }
        rotateFace(FACE::FRONT);
        // int temp[3]{};
        for(int i=0;i<3;i++) {
            temp[i]=cube[3][i][0];
        }
        for(int i=0;i<3;i++) {
            cube[3][i][0]=cube[0][2][i];
        }
        for(int i=0;i<3;i++) {
            cube[0][2][i]=cube[1][2-i][2];
        }
        for(int i=0;i<3;i++) {
            cube[1][2-i][2]=cube[5][0][2-i];
        }
        for(int i=0;i<3;i++) {
            cube[5][0][2-i]=temp[i];
        }
        rotateFace(FACE::FRONT);
        // int temp[3]{};
        for(int i=0;i<3;i++) {
            temp[i]=cube[3][i][0];
        }
        for(int i=0;i<3;i++) {
            cube[3][i][0]=cube[0][2][i];
        }
        for(int i=0;i<3;i++) {
            cube[0][2][i]=cube[1][2-i][2];
        }
        for(int i=0;i<3;i++) {
            cube[1][2-i][2]=cube[5][0][2-i];
        }
        for(int i=0;i<3;i++) {
            cube[5][0][2-i]=temp[i];
        }
        return *this;

    };
    RubiksCube& F2() override {
        cout << "Rotating Front face clockwise 2 times " << std::endl;
        rotateFace(FACE::FRONT);
        int temp[3]{};
        for(int i=0;i<3;i++) {
            temp[i]=cube[3][i][0];
        }
        for(int i=0;i<3;i++) {
            cube[3][i][0]=cube[0][2][i];
        }
        for(int i=0;i<3;i++) {
            cube[0][2][i]=cube[1][2-i][2];
        }
        for(int i=0;i<3;i++) {
            cube[1][2-i][2]=cube[5][0][2-i];
        }
        for(int i=0;i<3;i++) {
            cube[5][0][2-i]=temp[i];
        }
        rotateFace(FACE::FRONT);
        // int temp[3]{};
        for(int i=0;i<3;i++) {
            temp[i]=cube[3][i][0];
        }
        for(int i=0;i<3;i++) {
            cube[3][i][0]=cube[0][2][i];
        }
        for(int i=0;i<3;i++) {
            cube[0][2][i]=cube[1][2-i][2];
        }
        for(int i=0;i<3;i++) {
            cube[1][2-i][2]=cube[5][0][2-i];
        }
        for(int i=0;i<3;i++) {
            cube[5][0][2-i]=temp[i];
        }
        return *this;
    };
    RubiksCube& U() override {
        cout << "Rotating UP face clockwise" << std::endl;
        rotateFace(FACE::UP);
        int temp[3]{};
        for(int i=0;i<3;i++) {
            temp[i]=cube[1][0][i];
        }
        for(int i=0;i<3;i++) {
            cube[1][0][i]=cube[2][0][i];
        }
        for(int i=0;i<3;i++) {
            cube[2][0][i]=cube[3][0][i];
        }
        for(int i=0;i<3;i++) {
            cube[3][0][i]=cube[4][0][i];
        }
        for(int i=0;i<3;i++) {
            cube[4][0][i]=temp[i];
        }
        return *this;
    };
    RubiksCube& U2() override {
        cout << "Rotating UP face clockwise for 2 times" << std::endl;
        // rotateFace(FACE::FRONT);
        rotateFace(FACE::UP);
        int temp[3]{};
        for(int i=0;i<3;i++) {
            temp[i]=cube[1][0][i];
        }
        for(int i=0;i<3;i++) {
            cube[1][0][i]=cube[2][0][i];
        }
        for(int i=0;i<3;i++) {
            cube[2][0][i]=cube[3][0][i];
        }
        for(int i=0;i<3;i++) {
            cube[3][0][i]=cube[4][0][i];
        }
        for(int i=0;i<3;i++) {
            cube[4][0][i]=temp[i];
        }
        rotateFace(FACE::UP);
        // int temp[3]{};
        for(int i=0;i<3;i++) {
            temp[i]=cube[1][0][i];
        }
        for(int i=0;i<3;i++) {
            cube[1][0][i]=cube[2][0][i];
        }
        for(int i=0;i<3;i++) {
            cube[2][0][i]=cube[3][0][i];
        }
        for(int i=0;i<3;i++) {
            cube[3][0][i]=cube[4][0][i];
        }
        for(int i=0;i<3;i++) {
            cube[4][0][i]=temp[i];
        }
        return *this;
    };
    RubiksCube& UPRIME() override {
        cout << "Rotating UP face ANTI-clockwise" << std::endl;
        // rotateFace(FACE::FRONT);
        rotateFace(FACE::UP);
        int temp[3]{};
        for(int i=0;i<3;i++) {
            temp[i]=cube[1][0][i];
        }
        for(int i=0;i<3;i++) {
            cube[1][0][i]=cube[2][0][i];
        }
        for(int i=0;i<3;i++) {
            cube[2][0][i]=cube[3][0][i];
        }
        for(int i=0;i<3;i++) {
            cube[3][0][i]=cube[4][0][i];
        }
        for(int i=0;i<3;i++) {
            cube[4][0][i]=temp[i];
        }
        rotateFace(FACE::UP);
        // int temp[3]{};
        for(int i=0;i<3;i++) {
            temp[i]=cube[1][0][i];
        }
        for(int i=0;i<3;i++) {
            cube[1][0][i]=cube[2][0][i];
        }
        for(int i=0;i<3;i++) {
            cube[2][0][i]=cube[3][0][i];
        }
        for(int i=0;i<3;i++) {
            cube[3][0][i]=cube[4][0][i];
        }
        for(int i=0;i<3;i++) {
            cube[4][0][i]=temp[i];
        }
        rotateFace(FACE::UP);
        // int temp[3]{};
        for(int i=0;i<3;i++) {
            temp[i]=cube[1][0][i];
        }
        for(int i=0;i<3;i++) {
            cube[1][0][i]=cube[2][0][i];
        }
        for(int i=0;i<3;i++) {
            cube[2][0][i]=cube[3][0][i];
        }
        for(int i=0;i<3;i++) {
            cube[3][0][i]=cube[4][0][i];
        }
        for(int i=0;i<3;i++) {
            cube[4][0][i]=temp[i];
        }
        return *this;
    };
    RubiksCube& DPRIME() override {
        cout << "Rotating DOWN face Anti -clockwise" << std::endl;
        rotateFace(FACE::DOWN);
        // rotateFace(FACE::UP);
        int temp[3]{};
        for(int i=0;i<3;i++) {
            temp[i]=cube[1][2][i];
        }
        for(int i=0;i<3;i++) {
            cube[1][2][i]=cube[2][2][i];
        }
        for(int i=0;i<3;i++) {
            cube[2][2][i]=cube[3][2][i];
        }
        for(int i=0;i<3;i++) {
            cube[3][2][i]=cube[4][2][i];
        }
        for(int i=0;i<3;i++) {
            cube[4][2][i]=temp[i];
        }
        return *this;
    };
    RubiksCube& D2() override {
        cout << "Rotating DOWN face 2 times clockwise" << std::endl;
        rotateFace(FACE::DOWN);
        // rotateFace(FACE::UP);
        int temp[3]{};
        for(int i=0;i<3;i++) {
            temp[i]=cube[1][2][i];
        }
        for(int i=0;i<3;i++) {
            cube[1][2][i]=cube[2][2][i];
        }
        for(int i=0;i<3;i++) {
            cube[2][2][i]=cube[3][2][i];
        }
        for(int i=0;i<3;i++) {
            cube[3][2][i]=cube[4][2][i];
        }
        for(int i=0;i<3;i++) {
            cube[4][2][i]=temp[i];
        }
        rotateFace(FACE::DOWN);
        // int temp[3]{};
        for(int i=0;i<3;i++) {
            temp[i]=cube[1][2][i];
        }
        for(int i=0;i<3;i++) {
            cube[1][2][i]=cube[2][2][i];
        }
        for(int i=0;i<3;i++) {
            cube[2][2][i]=cube[3][2][i];
        }
        for(int i=0;i<3;i++) {
            cube[3][2][i]=cube[4][2][i];
        }
        for(int i=0;i<3;i++) {
            cube[4][2][i]=temp[i];
        }
        return *this;
    };
    RubiksCube& D() override {
        cout << "Rotating DOWN face clockwise" << std::endl;
        rotateFace(FACE::DOWN);
        // rotateFace(FACE::UP);
        int temp[3]{};
        for(int i=0;i<3;i++) {
            temp[i]=cube[1][2][i];
        }
        for(int i=0;i<3;i++) {
            cube[1][2][i]=cube[2][2][i];
        }
        for(int i=0;i<3;i++) {
            cube[2][2][i]=cube[3][2][i];
        }
        for(int i=0;i<3;i++) {
            cube[3][2][i]=cube[4][2][i];
        }
        for(int i=0;i<3;i++) {
            cube[4][2][i]=temp[i];
        }
        rotateFace(FACE::DOWN);
        // int temp[3]{};
        for(int i=0;i<3;i++) {
            temp[i]=cube[1][2][i];
        }
        for(int i=0;i<3;i++) {
            cube[1][2][i]=cube[2][2][i];
        }
        for(int i=0;i<3;i++) {
            cube[2][2][i]=cube[3][2][i];
        }
        for(int i=0;i<3;i++) {
            cube[3][2][i]=cube[4][2][i];
        }
        for(int i=0;i<3;i++) {
            cube[4][2][i]=temp[i];
        }
        rotateFace(FACE::DOWN);
        // int temp[3]{};
        for(int i=0;i<3;i++) {
            temp[i]=cube[1][2][i];
        }
        for(int i=0;i<3;i++) {
            cube[1][2][i]=cube[2][2][i];
        }
        for(int i=0;i<3;i++) {
            cube[2][2][i]=cube[3][2][i];
        }
        for(int i=0;i<3;i++) {
            cube[3][2][i]=cube[4][2][i];
        }
        for(int i=0;i<3;i++) {
            cube[4][2][i]=temp[i];
        }
        return *this;
    };
    RubiksCube& B() override {
        cout << "Rotating BACK face clockwise" << std::endl;
        int temp[3]{};
        rotateFace(FACE::BACK);
        
        for(int i=0;i<3;i++) {
            temp[i]=cube[0][0][i];
        }
        for(int i=0;i<3;i++) {
            cube[0][0][i]=cube[3][i][2];
        }
        for(int i=0;i<3;i++) {
            cube[3][i][2]=cube[5][2][2-i];
        }
        for(int i=0;i<3;i++) {
            cube[5][2][2-i]=cube[1][2-i][0];
        }
        for(int i=0;i<3;i++) {
            cube[1][2-i][0]=temp[i];
        }
        return *this;
    };
    RubiksCube& B2() override {
        cout << "Rotating BACk face 2 times clockwise" << std::endl;
        // rotateFace(FACE::FRONT);
        int temp[3]{};
        rotateFace(FACE::BACK);
        
        for(int i=0;i<3;i++) {
            temp[i]=cube[0][0][i];
        }
        for(int i=0;i<3;i++) {
            cube[0][0][i]=cube[3][i][2];
        }
        for(int i=0;i<3;i++) {
            cube[3][i][2]=cube[5][2][2-i];
        }
        for(int i=0;i<3;i++) {
            cube[5][2][2-i]=cube[1][2-i][0];
        }
        for(int i=0;i<3;i++) {
            cube[1][2-i][0]=temp[i];
        }
        rotateFace(FACE::BACK);
        
        for(int i=0;i<3;i++) {
            temp[i]=cube[0][0][i];
        }
        for(int i=0;i<3;i++) {
            cube[0][0][i]=cube[3][i][2];
        }
        for(int i=0;i<3;i++) {
            cube[3][i][2]=cube[5][2][2-i];
        }
        for(int i=0;i<3;i++) {
            cube[5][2][2-i]=cube[1][2-i][0];
        }
        for(int i=0;i<3;i++) {
            cube[1][2-i][0]=temp[i];
        }
        return *this;
    };
    RubiksCube& BPRIME() override {
        cout << "Rotating BACK face ANTI-clockwise" << std::endl;
        // rotateFace(FACE::FRONT);
        int temp[3]{};
        rotateFace(FACE::BACK);
        
        for(int i=0;i<3;i++) {
            temp[i]=cube[0][0][i];
        }
        for(int i=0;i<3;i++) {
            cube[0][0][i]=cube[3][i][2];
        }
        for(int i=0;i<3;i++) {
            cube[3][i][2]=cube[5][2][2-i];
        }
        for(int i=0;i<3;i++) {
            cube[5][2][2-i]=cube[1][2-i][0];
        }
        for(int i=0;i<3;i++) {
            cube[1][2-i][0]=temp[i];
        }
        rotateFace(FACE::BACK);
        
        for(int i=0;i<3;i++) {
            temp[i]=cube[0][0][i];
        }
        for(int i=0;i<3;i++) {
            cube[0][0][i]=cube[3][i][2];
        }
        for(int i=0;i<3;i++) {
            cube[3][i][2]=cube[5][2][2-i];
        }
        for(int i=0;i<3;i++) {
            cube[5][2][2-i]=cube[1][2-i][0];
        }
        for(int i=0;i<3;i++) {
            cube[1][2-i][0]=temp[i];
        }
        rotateFace(FACE::BACK);
        
        for(int i=0;i<3;i++) {
            temp[i]=cube[0][0][i];
        }
        for(int i=0;i<3;i++) {
            cube[0][0][i]=cube[3][i][2];
        }
        for(int i=0;i<3;i++) {
            cube[3][i][2]=cube[5][2][2-i];
        }
        for(int i=0;i<3;i++) {
            cube[5][2][2-i]=cube[1][2-i][0];
        }
        for(int i=0;i<3;i++) {
            cube[1][2-i][0]=temp[i];
        } 
        return *this;
    };
    RubiksCube& R() override {
        cout << "Rotating RIGHT face clockwise" << std::endl;
        int temp[3]{};
        
        
        rotateFace(FACE::RIGHT);
        
        for(int i=0;i<3;i++){
            temp[i]=cube[0][i][2];
        }
        for(int i=0;i<3;i++){
            cube[0][i][2]=cube[2][i][2];
        }
        for(int i=0;i<3;i++){
            cube[2][i][2]=cube[5][i][2];
        }
        for(int i=0;i<3;i++){
            cube[5][i][2]=cube[4][2-i][0];
        }
        for(int i=0;i<3;i++){
            cube[4][2-i][0]=temp[i];
        }
        return *this;
    };
    RubiksCube& R2()override{
        cout << "Rotating RIGHT face clockwise" << std::endl;
        int temp[3]{};
        
        
        rotateFace(FACE::RIGHT);
        
        for(int i=0;i<3;i++){
            temp[i]=cube[0][i][2];
        }
        for(int i=0;i<3;i++){
            cube[0][i][2]=cube[2][i][2];
        }
        for(int i=0;i<3;i++){
            cube[2][i][2]=cube[5][i][2];
        }
        for(int i=0;i<3;i++){
            cube[5][i][2]=cube[4][2-i][0];
        }
        for(int i=0;i<3;i++){
            cube[4][2-i][0]=temp[i];
        }
         rotateFace(FACE::RIGHT);
        
        for(int i=0;i<3;i++){
            temp[i]=cube[0][i][2];
        }
        for(int i=0;i<3;i++){
            cube[0][i][2]=cube[2][i][2];
        }
        for(int i=0;i<3;i++){
            cube[2][i][2]=cube[5][i][2];
        }
        for(int i=0;i<3;i++){
            cube[5][i][2]=cube[4][2-i][0];
        }
        for(int i=0;i<3;i++){
            cube[4][2-i][0]=temp[i];
        }
        return *this;
    }
    RubiksCube& RPRIME() override {
        cout << "Rotating RIGHT face ANTI-clockwise" << std::endl;
        // rotateFace(FACE::FRONT);
        int temp[3]{};
        rotateFace(FACE::RIGHT);
        
        for(int i=0;i<3;i++){
            temp[i]=cube[0][i][2];
        }
        for(int i=0;i<3;i++){
            cube[0][i][2]=cube[2][i][2];
        }
        for(int i=0;i<3;i++){
            cube[2][i][2]=cube[5][i][2];
        }
        for(int i=0;i<3;i++){
            cube[5][i][2]=cube[4][2-i][0];
        }
        for(int i=0;i<3;i++){
            cube[4][2-i][0]=temp[i];
        }
        rotateFace(FACE::RIGHT);
        
        for(int i=0;i<3;i++){
            temp[i]=cube[0][i][2];
        }
        for(int i=0;i<3;i++){
            cube[0][i][2]=cube[2][i][2];
        }
        for(int i=0;i<3;i++){
            cube[2][i][2]=cube[5][i][2];
        }
        for(int i=0;i<3;i++){
            cube[5][i][2]=cube[4][2-i][0];
        }
        for(int i=0;i<3;i++){
            cube[4][2-i][0]=temp[i];
        }
        rotateFace(FACE::RIGHT);
        
        for(int i=0;i<3;i++){
            temp[i]=cube[0][i][2];
        }
        for(int i=0;i<3;i++){
            cube[0][i][2]=cube[2][i][2];
        }
        for(int i=0;i<3;i++){
            cube[2][i][2]=cube[5][i][2];
        }
        for(int i=0;i<3;i++){
            cube[5][i][2]=cube[4][2-i][0];
        }
        for(int i=0;i<3;i++){
            cube[4][2-i][0]=temp[i];
        }
        return *this;
    };
    RubiksCube& L() override {
        cout << "Rotating Left face clockwise" << std::endl;
        int temp[3]{};
        rotateFace(FACE::LEFT);

        for(int i=0;i<3;i++){
            temp[i]=cube[5][i][0];
        }
        for(int i=0;i<3;i++){
            cube[5][i][0]=cube[2][i][0];
        }
        for(int i=0;i<3;i++){
            cube[2][i][0]=cube[0][i][0];
        }
        for(int i=0;i<3;i++){
            cube[0][i][0]=cube[4][2-i][2];
        }
        for(int i=0;i<3;i++){
            cube[4][2-i][2]=temp[i];
        }
        return *this;
        
    };
    RubiksCube& L2() override {
        cout << "Rotating LEFT face clockwise 2 Times" << std::endl;
        int temp[3]{};
      rotateFace(FACE::LEFT);

        for(int i=0;i<3;i++){
            temp[i]=cube[5][i][0];
        }
        for(int i=0;i<3;i++){
            cube[5][i][0]=cube[2][i][0];
        }
        for(int i=0;i<3;i++){
            cube[2][i][0]=cube[0][i][0];
        }
        for(int i=0;i<3;i++){
            cube[0][i][0]=cube[4][2-i][2];
        }
        for(int i=0;i<3;i++){
            cube[4][2-i][2]=temp[i];
        }
        rotateFace(FACE::LEFT);

        for(int i=0;i<3;i++){
            temp[i]=cube[5][i][0];
        }
        for(int i=0;i<3;i++){
            cube[5][i][0]=cube[2][i][0];
        }
        for(int i=0;i<3;i++){
            cube[2][i][0]=cube[0][i][0];
        }
        for(int i=0;i<3;i++){
            cube[0][i][0]=cube[4][2-i][2];
        }
        for(int i=0;i<3;i++){
            cube[4][2-i][2]=temp[i];
        }
        return *this;
    };
    RubiksCube& LPRIME() override {
        cout << "Rotating LEFT face ANTI-clockwise" << std::endl;
        // rotateFace(FACE::FRONT);
        int temp[3]{};
        rotateFace(FACE::LEFT);

        for(int i=0;i<3;i++){
            temp[i]=cube[5][i][0];
        }
        for(int i=0;i<3;i++){
            cube[5][i][0]=cube[2][i][0];
        }
        for(int i=0;i<3;i++){
            cube[2][i][0]=cube[0][i][0];
        }
        for(int i=0;i<3;i++){
            cube[0][i][0]=cube[4][2-i][2];
        }
        for(int i=0;i<3;i++){
            cube[4][2-i][2]=temp[i];
        }
        rotateFace(FACE::LEFT);

        for(int i=0;i<3;i++){
            temp[i]=cube[5][i][0];
        }
        for(int i=0;i<3;i++){
            cube[5][i][0]=cube[2][i][0];
        }
        for(int i=0;i<3;i++){
            cube[2][i][0]=cube[0][i][0];
        }
        for(int i=0;i<3;i++){
            cube[0][i][0]=cube[4][2-i][2];
        }
        for(int i=0;i<3;i++){
            cube[4][2-i][2]=temp[i];
        }
        rotateFace(FACE::LEFT);

        for(int i=0;i<3;i++){
            temp[i]=cube[5][i][0];
        }
        for(int i=0;i<3;i++){
            cube[5][i][0]=cube[2][i][0];
        }
        for(int i=0;i<3;i++){
            cube[2][i][0]=cube[0][i][0];
        }
        for(int i=0;i<3;i++){
            cube[0][i][0]=cube[4][2-i][2];
        }
        for(int i=0;i<3;i++){
            cube[4][2-i][2]=temp[i];
        }
        return *this;
    };
};