//
// Created by Mayukh on 25-06-2024.
//
#include<bits/stdc++.h>
#include "RubiksCube.h"
#include "RubiksCube3darr.cpp"
using namespace std;

#ifndef BFSSOLVER_H
#define BFSSOLVER_H



class BFSSolver {
     RubiksCube3darr rb;
     RubiksCube3darr rb1;
public:
     BFSSolver(RubiksCube3darr rbx) {
          rb=rbx;
          rb1=rbx;
     }

     vector<RubiksCube::MOVE>moves;
public:
     unordered_map<RubiksCube3darr,bool,Hash3d>visited;
     // unordered_map<RubiksCube3darr,bool,Hash3d>og;
     unordered_map<RubiksCube3darr,RubiksCube::MOVE,Hash3d>moveset;

     void bfs() {

          queue<RubiksCube3darr>q;
          visited[rb]=true;


          q.push(rb);
          while(!q.empty()) {
               auto node=q.front();
               q.pop();

               if(node.isSolved()) {
                    rb1=node;
                    break;
               }
               for(int i=0;i<18;i++) {
                    node.move(RubiksCube::MOVE(i));
                    if(!visited[node]) {
                         visited[node]=true;
                         moveset[node]=RubiksCube::MOVE(i);
                         q.push(node);
                    }
                    node.invert(RubiksCube::MOVE(i));
               }
          }
          rb1.print();
          while(!(rb1==rb)) {
               moves.push_back(moveset[rb1]);
               rb1.invert(moveset[rb1]);

          }
          reverse(moves.begin(),moves.end());



     }






};


#endif //BFSSOLVER_H
