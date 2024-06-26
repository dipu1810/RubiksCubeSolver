This project attempts to solve the Rubiks Cube and Perform operations on it

Initially an Object of Rubiks Cube Class had been created. A subclass of it called Rubikscube3darr was then developed which contained the representation of Rubiks Cube in 3d array format

To Make Visualization simple we assumed two things
1)     The faces were visualized as
             Top
         Left Front Right Back
              Down
2) The middle pieces were made constant in each face and only 12 possible moves were operated
   Middle Piece Orientation:
                 W
                G R B O
                  Y
   The moved which was performed were
   L (Front Left Side Upwards)
   R ( Front Right Side Upwards)
   U ( Up Right Side)
   D  ( Down Right Side)
   F ( Front Clockwise)
   B (Back Clockwise)

    Other moves were derivatives of these basic 6 moves.

   Solving:
   I incorporated the states of a rubiks Cube as nodes of a graph and the edges as the moves. This helped us to perfrom BFS DFS and IDDFS on the Rubiks Cube.
   Using IDA* algorithm the solution was further optimized
   
