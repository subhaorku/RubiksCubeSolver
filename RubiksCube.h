//headerguards to prevent multiple inclusion of same headerfile
#ifndef RUBIKS_CUBE_SOLVER_RUBIKSCUBE // to check whether the macro 'RUBIKS_CUBE_SOLVER_RUBIKSCUBE' has been defined yet or not
#define RUBIKS_CUBE_SOLVER_RUBIKSCUBE // defines the macro

#include<bits/stdc++.h>
using namespace std;

/*
 * A base class for all Rubik's Cube Model. There are various representations for Rubik's Cube.
 * Each representation has it's own special ways of definitions.
 * This base class provides shared functionality between all the models.
 * There are two reasons why we need this base class :
 * We will write solver for Generic class and it will solve for all the children class.
 * To maintain consistency across the models
 * If the solver is compatible with generic cube model then it will be compatible with all models as these models will be following the blue_print of the generic cube model.
 * We'll benchmark all models and observe which one is better for performance.
 */

class RubiksCube{
public:
    enum class FACE{
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
        L,LPRIME,L2,
        R,RPRIME,R2,
        U,UPRIME,U2,
        D,DPRIME,D2,
        F,FPRIME,F2,
        B,BPRIME,B2
    };

// Enumerations (enums) are a way to define a set of named integer constants, making code more readable and easier to manage.


/*
   * Returns the color of the cell at (row, col) in face.
   * If Rubik's Cube face is pointing at you, then the row numbering starts from the
   * top to bottom, and column numbering starts from the left to right.
   * The rows and columns are 0-indexed.
   * @param Face, row, and column index
   */

virtual COLOR getColor(FACE face , unsigned row , unsigned col) const=0;
//The const keyword at the end of the function declaration indicates that this member function does not modify the state of the object. It can be called on const instances of the class.


/*
    * Returns the first letter of the given COLOR
    * Eg: For COLOR::GREEN, it returns 'G'
    */
static char getColorLetter(COLOR color);


/*
 * Returns true if the Rubik Cube is solved, otherwise returns false.
 */
virtual bool isSolved() const = 0;


/*
 * Returns the move in the string format.
 */
static string getMove(MOVE ind);

/*
  *MOVE::L returns "L"
  *MOVE::LPRIME returns "L'"
  *MOVE::L2 returns "L2"
  */




/*
    * Print the Rubik Cube in Planar format.
    *
    * The cube is laid out as follows.
    *
    * The sides:
    *    U
    *  L F R B
    *    D
    *
    * Color wise:
    *
    *          W W W
    *          W W W
    *          W W W
    *
    *  G G G   R R R   B B B   O O O
    *  G G G   R R R   B B B   O O O
    *  G G G   R R R   B B B   O O O
    *
    *          Y Y Y
    *          Y Y Y
    *          Y Y Y
    *
    * Row and Column Numberings:
    * rx -> row numbering
    * cx -> column numbering
    * bx -> both row and column numbering
    *
    *             b0 c1 c2
    *             r1  .  .
    *             r2  .  .
    *
    *  b0 c1 c2   b0 c1 c2   b0 c1 c2   b0 c1 c2
    *  r1  .  .   r1  .  .   r1  .  .   r1  .  .
    *  r2  .  .   r2  .  .   r2  .  .   r2  .  .
    *
    *             b0 c1 c2
    *             r1  .  .
    *             r2  .  .
    *
    */

void print() const;




/*
 * Randomly Shuffles the cube by performing a specified number of moves and returns the moves performed
 * unsigned int times: The number of random moves to perform on the cube.
 * vector<MOVE>: A vector containing the sequence of moves performed during the shuffle.
 */
vector<MOVE> randomShuffleCube(unsigned int times);



/*
 * Perform moves on the Rubiks Cube
 *  This method performs a specific move on the Rubik's Cube.
 *  RubiksCube&: A reference to the RubiksCube object, allowing for method chaining.
 */
RubiksCube &move(MOVE ind);


/*
 * Invert a move
 */
RubiksCube &invert(MOVE ind);

/*
 * The methods below defines the various rotational moves on the Rubik's Cube.
 * As pure virtual methods, they must be implemented by any derived class.
 */

virtual RubiksCube &f() = 0;

virtual RubiksCube &fPrime() = 0;

virtual RubiksCube &f2() = 0;

virtual RubiksCube &u() = 0;

virtual RubiksCube &uPrime() = 0;

virtual RubiksCube &u2() = 0;

virtual RubiksCube &l() = 0;

virtual RubiksCube &lPrime() = 0;

virtual RubiksCube &l2() = 0;

virtual RubiksCube &r() = 0;

virtual RubiksCube &rPrime() = 0;

virtual RubiksCube &r2() = 0;

virtual RubiksCube &b() = 0;

virtual RubiksCube &bPrime() = 0;

virtual RubiksCube &b2() = 0;

virtual RubiksCube &d() = 0;//90 degrees clockwise.

virtual RubiksCube &dPrime() = 0;// 90 degrees counterclockwise.

virtual RubiksCube &d2() = 0;//180 degrees


/*
 * Returns a string representation of the colors at a specific corner of a Rubiks Cube
 */
string getCornerColorString(uint8_t ind) const;

/*
 * Returns the index of the specific corner
 */
uint8_t getCornerIndex(uint8_t ind) const;

/*
 * Returns the orientation of the specific corner
 */
uint8_t getCornerOrientation(uint8_t ind) const;
};

#endif //RUBIKS_CUBE_SOLVER_RUBIKSCUBE_H
// This line marks the end of the conditional block started by #ifndef