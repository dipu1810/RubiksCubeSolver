//
// Created by Mayukh on 25-06-2024.
//
#include<bits/stdc++.h>
#include "RubiksCube.h"
#include "RubiksCube3darr.cpp"
using namespace std;
#ifndef IDDFSSOLVER_H
#define IDDFSSOLVER_H



class IDDFSSolver {
    RubiksCube3darr rb,rb1;
    int maxdepth;
public:
    IDDFSSolver(RubiksCube3darr rbx,int n) {
        rb=rbx;
        rb1=rbx;
        maxdepth=n;
    }
    vector<RubiksCube::MOVE>moves;

    bool iddfs() {
        for(int i=0;i<=maxdepth;i++) {

            moves.clear();

            if(dfs(rb,0,i)) {
                rb=rb1;
                return true;
            }

        }
        rb=rb1;
        return false;
    }
    bool dfs(RubiksCube3darr&rb,int curdepth,int maxdepth) {
        if(curdepth>maxdepth)return false;



        if(rb.isSolved()){rb1=rb;return true;}
        for(int i=0;i<18;i++) {
            rb.move(RubiksCube::MOVE(i));
            moves.push_back(RubiksCube::MOVE(i));


                if(dfs(rb,curdepth+1,maxdepth))return true;

            rb.invert(RubiksCube::MOVE(i));
            moves.pop_back();
        }
        return false;

    }

};



#endif //IDDFSSOLVER_H
