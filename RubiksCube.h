//
// Created by Mayukh on 24-06-2024.
//

#ifndef RUBIKSCUBE_H
#define RUBIKSCUBE_H


#include<bits/stdc++.h>
using namespace std;
class RubiksCube {
public:
    enum class FACE {
        UP,
        DOWN,
        LEFT,
        RIGHT,
        FRONT,
        BACK
    };
    enum class COLOR {
        WHITE,
        YELLOW,
        GREEN,
        BLUE,
        RED,
        ORANGE
    };
    enum class MOVE {
        L, LPRIME, L2,
        R, RPRIME, R2,
        U, UPRIME, U2,
        D, DPRIME, D2,
        F, FPRIME, F2,
        B, BPRIME, B2
    };


    virtual char getColorLetter(COLOR color);
    // This method will return the colour of the face when facing towards the screen at row and column indices(0-indesxed)
    virtual COLOR getColor(FACE face, unsigned row, unsigned col) const = 0;
    //This method will return true if the rubiks cube is solved
    virtual bool isSolved() const = 0;
    //This method will display the move in string format
    string getMove(MOVE ind) const;

    /* This method will print the rubiks cube in planar format when its 6 faces are taken out as cross section of cube
     * The arrangement is
     *      U
     *    L F R B
     *      D
     * Colour wise of centre it is
     *      W
     *    G R B O
     *      Y
    */
    void print()const;
    // Shuffle Cube randomly n times
    RubiksCube& randomShuffleCube(unsigned int n);
    // Moves on cube
    RubiksCube& move(MOVE ind);
    RubiksCube& invert(MOVE ind);

    virtual RubiksCube& u() = 0;
    virtual RubiksCube& uPrime() = 0;
    virtual RubiksCube& u2() = 0;

    virtual RubiksCube& l() = 0;
    virtual RubiksCube& lPrime() = 0;
    virtual RubiksCube& l2() = 0;

    virtual RubiksCube& f() = 0;
    virtual RubiksCube& fPrime() = 0;
    virtual RubiksCube& f2() = 0;

    virtual RubiksCube& r() = 0;
    virtual RubiksCube& rPrime() = 0;
    virtual RubiksCube& r2() = 0;

    virtual RubiksCube& b() = 0;
    virtual RubiksCube& bPrime() = 0;
    virtual RubiksCube& b2() = 0;

    virtual RubiksCube& d() = 0;
    virtual RubiksCube& dPrime() = 0;
    virtual RubiksCube& d2() = 0;
};






#endif //RUBIKSCUBE_H
