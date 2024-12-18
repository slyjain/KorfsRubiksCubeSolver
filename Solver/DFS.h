//
// Created by heisenberg on 12/16/24.
//
#include<bits/stdc++.h>
#include "../RubiksCube.h"
#ifndef DFS_H
#define DFS_H


template<typename T,typename H>
class DFS {
    vector<RubiksCube::MOVE>moves;
    int maxSearchDepth;
    bool dfs(int depth) {
        if(rubiksCube.isSolved(rubiksCube))return true;
        if(depth>maxSearchDepth)return false;   
        for(int i=0;i<18;i++) {
            rubiksCube.move(RubiksCube::MOVE(i));
            moves.push_back(RubiksCube::MOVE(i));
            if(dfs(depth+1))return true;
            moves.pop_back();
            rubiksCube.invert(RubiksCube::MOVE(i));
        }
        return false;
    }
public:
    T rubiksCube;
    DFS(T rubiksCube_,int maxSearchDepth_=8) {
        rubiksCube=rubiksCube_;
        maxSearchDepth=maxSearchDepth_;
    }
    vector<RubiksCube::MOVE>solve() {
        dfs(1);
        return moves;
    }
};



#endif //DFS_H
