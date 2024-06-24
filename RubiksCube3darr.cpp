//
// Created by Mayukh on 24-06-2024.
//

#include "RubiksCube.h"
class RubiksCube3darr:public RubiksCube {
    public :
        char cube[6][3][3];
    RubiksCube3darr() {
        for(int i=0;i<6;i++) {
            for(int j=0;j<3;j++) {
                for(int k=0;k<6;k++) {
                    cube[i][j][k]=getColorLetter(COLOR(i));
                }
            }
        }
    }
    void rotate(FACE face) {
        int x=(int)(face);
        char a=cube[x][0][0];
        cube[x][0][0]=cube[x][2][0];
        cube[x][2][0]=cube[x][2][2];
        cube[x][2][2]=cube[x][0][2];
        cube[x][0][2]=a;
        a=cube[x][0][1];cube[x][0][1]=cube[x][1][0];cube[x][1][0]=cube[x][2][1];cube[x][2][1]=cube[x][1][2];cube[x][1][2]=a;


    }
    COLOR getColor(FACE face,unsigned int row,unsigned int col) const override {
        char color=cube[(int)face][row][col];
        switch(color) {
            case 'B':return COLOR::BLUE;
            case 'W':return COLOR::WHITE;
            case 'R':return COLOR::RED;
            case 'Y':return COLOR::YELLOW;
            case 'G':return COLOR::GREEN;
            case 'O':return COLOR::ORANGE;

        }
    }
    bool isSolved() const override {
        int s=1;
        for(int i=0;i<6;i++) {
            for(int j=0;j<3;j++) {
                for(int k=0;k<3;k++)s=s&(cube[i][j][k]==cube[i][1][1]);
            }
        }
        return s;
    }
    RubiksCube &u() override {
        for(int i=0;i<3;i++) {
            char a=getColorLetter(getColor(FACE::FRONT,0,i));
            cube[(int)(FACE::FRONT)][0][i]=getColorLetter(getColor(FACE::RIGHT,0,i));
            cube[(int)(FACE::RIGHT)][0][i]=getColorLetter(getColor(FACE::BACK,0,i));
            cube[(int)(FACE::BACK)][0][i]=getColorLetter(getColor(FACE::LEFT,0,i));
            cube[(int)(FACE::LEFT)][0][i]=a;


        }
        rotate(FACE::UP);
        return *this;
    }
    RubiksCube &d()override {
        for(int i=0;i<3;i++) {
            char a=getColorLetter(getColor(FACE::FRONT,2,i));
            cube[(int)(FACE::FRONT)][2][i]=getColorLetter(getColor(FACE::RIGHT,2,i));
            cube[(int)(FACE::RIGHT)][2][i]=getColorLetter(getColor(FACE::BACK,2,i));
            cube[(int)(FACE::BACK)][2][i]=getColorLetter(getColor(FACE::LEFT,2,i));
            cube[(int)(FACE::LEFT)][2][i]=a;


        }
        for(int i=0;i<3;i++) rotate(FACE::DOWN);
        return *this;
    }
    RubiksCube &r()override {
        string s1="";
        for(int i=0;i<3;i++)s1+=cube[(int)FACE::UP][i][2];
        for(int i=0;i<3;i++)cube[(int)FACE::UP][i][2]=cube[(int)FACE::FRONT][i][2];
        for(int i=0;i<3;i++)cube[(int)FACE::FRONT][i][2]=cube[(int)FACE::DOWN][i][2];
        for(int i=0;i<3;i++)cube[(int)FACE::DOWN][i][2]=cube[(int)FACE::BACK][2-i][0];
        for(int i=0;i<3;i++)cube[(int)FACE::BACK][2-i][0]=s1[i];
        rotate(FACE::RIGHT);
        return *this;


    }
    RubiksCube &l()override {
        string s1="";
        for(int i=0;i<3;i++)s1+=cube[(int)FACE::UP][i][0];
        for(int i=0;i<3;i++)cube[(int)FACE::UP][i][0]=cube[(int)FACE::FRONT][i][0];
        for(int i=0;i<3;i++)cube[(int)FACE::FRONT][i][0]=cube[(int)FACE::DOWN][i][0];
        for(int i=0;i<3;i++)cube[(int)FACE::DOWN][i][0]=cube[(int)FACE::BACK][2-i][2];
        for(int i=0;i<3;i++)cube[(int)FACE::BACK][2-i][2]=s1[i];

        for(int i=0;i<3;i++)rotate(FACE::LEFT);

        return *this;


    }
    RubiksCube &f() override {
        string s1="";
        for(int i=0;i<3;i++)s1+=cube[(int)FACE::UP][2][i];

        for(int i=0;i<3;i++)cube[(int)FACE::UP][2][i]=cube[(int)FACE::LEFT][2-i][2];

        for(int i=0;i<3;i++)cube[(int)FACE::LEFT][i][2]=cube[(int)FACE::DOWN][0][i];

        for(int i=0;i<3;i++)cube[(int)FACE::DOWN][0][i]=cube[(int)FACE::RIGHT][2-i][0];
        for(int i=0;i<3;i++)cube[(int)FACE::RIGHT][i][0]=s1[i];
        rotate(FACE::FRONT);
        return *this;

    }
    RubiksCube &b() override {
        string s1="";
        for(int i=0;i<3;i++)s1+=cube[(int)FACE::UP][0][i];
        for(int i=0;i<3;i++)cube[(int)FACE::UP][0][i]=cube[(int)FACE::LEFT][2-i][0];
        for(int i=0;i<3;i++)cube[(int)FACE::LEFT][i][0]=cube[(int)FACE::DOWN][2][i];
        for(int i=0;i<3;i++)cube[(int)FACE::DOWN][2][i]=cube[(int)FACE::RIGHT][2-i][2];
        for(int i=0;i<3;i++)cube[(int)FACE::RIGHT][i][2]=s1[i];

        for(int i=0;i<3;i++)  rotate(FACE::BACK);
        return *this;
    }
    RubiksCube &u2() override {
        this->u();
        this->u();
        return *this;
    }
    RubiksCube &uPrime() override {
        this->u2();
        this->u();
        return *this;
    }
    RubiksCube &d2() override {
        this->d();
        this->d();
        return *this;
    }
    RubiksCube &dPrime() override {
        this->d2();
        this->d();
        return *this;
    }
    RubiksCube &l2() override {
        this->l();
        this->l();
        return *this;
    }
    RubiksCube &lPrime() override {
        this->l2();
        this->l();
        return *this;
    }
    RubiksCube &r2() override {
        this->r();
        this->r();
        return *this;
    }
    RubiksCube &rPrime() override {
        this->r2();
        this->r();
        return *this;
    }
    RubiksCube &f2() override {
        this->f();
        this->f();
        return *this;
    }
    RubiksCube &fPrime() override {
        this->f2();
        this->f();
        return *this;
    }
    RubiksCube &b2() override {
        this->b();
        this->b();
        return *this;
    }
    RubiksCube &bPrime() override {
        this->b2();
        this->b();
        return *this;
    }











};
