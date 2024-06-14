#include "RubiksCube.h"
class RubiksCube3dArray : public RubiksCube     //class RubiksCube3Darray is inherited from RubiksCube class so that it can inherit all public and protected members of RubiksCube
{
private:
// This method 'rotateFace' is not needed by the external world , we need it to rotate it internally
    void rotateFace(int ind) // parameter 'ind' is the face which is to be rotated
    {
        char temp_arr[3][3]= {};
        for(int i=0;i<3;i++) {
            for (int j = 0; j < 3; j++) {
                temp_arr[i][j] = cube[ind][i][j];
            }
        }
        /*
         * These four loops perform a 90-degree clockwise rotation of the face. Here's how it works:
         *  The first loop assigns the left column of temp_arr to the top row of cube[ind].
         *  The second loop assigns the top row of temp_arr to the right column of cube[ind].
         *  The third loop assigns the right column of temp_arr to the bottom row of cube[ind].
         *   The fourth loop assigns the bottom row of temp_arr to the left column of cube[ind].
         */
        for (int i = 0; i < 3; i++) cube[ind][0][i] = temp_arr[2 - i][0];
        for (int i = 0; i < 3; i++) cube[ind][i][2] = temp_arr[0][i];
        for (int i = 0; i < 3; i++) cube[ind][2][2 - i] = temp_arr[i][2];
        for (int i = 0; i < 3; i++) cube[ind][2 - i][0] = temp_arr[2][2 - i];
    }
public:
    char cube[6][3][3]={}; //declaration of a public member variable 'cube'
/*
 * constructor of the RubiksCube3dArray class
 * The purpose of this constructor is to initialize the Rubik's Cube to a solved state.
 */
    RubiksCube3dArray(){
        for (int i = 0; i < 6; i++) { //for 6 diff colors
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++)
                    cube[i][j][k] = getColorLetter(COLOR(i));
                // COLOR(i): Converts the face index i to the corresponding COLOR enum value.
            }
        }
    }

    COLOR getColor(FACE face, unsigned row, unsigned col) const override {
        /*
         * The override keyword indicates that this function is intended to override a virtual function in a base class. It tells the compiler to check that the function is indeed overriding a base class function. If it is not, the compiler will generate an error.
         * The const keyword at the end of the function declaration means that the function is a constant member function
         * and will not alter the state of the RubiksCube3dArray object.
         */
        char color = cube[int(face)][row][col];
        switch (color) {
            case 'B':
                return COLOR::BLUE;
            case 'R':
                return COLOR::RED;
            case 'G':
                return COLOR::GREEN;
            case 'O':
                return COLOR::ORANGE;
            case 'Y':
                return COLOR::YELLOW;
            default:
                return COLOR::WHITE;
        }
    }

    bool isSolved() const override {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if (this->cube[i][j][k] == getColorLetter(COLOR(i))) continue;
                    // cube is a member variable of the RubiksCube3dArray class. The this-> is used to explicitly refer to the member variable cube of the current instance of the class.
                    return false;
                }
            }
        }
        return true;
    }
    RubiksCube &u() override {
        this->rotateFace(0);
        /*
         *This line calls the rotateFace function on the upper face of the cube, which is indexed as 0.
         * The rotateFace function performs a 90-degree clockwise rotation of the specified face.
         */
        // A temporary array temp_arr is used to store the edge values of the adjacent faces before they are overwritten.
        char temp_arr[3] = {};
        // These loops shift the edge values of the adjacent faces to their new positions after the upper face rotation.
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[4][0][2 - i];
        for (int i = 0; i < 3; i++) cube[4][0][2 - i] = cube[1][0][2 - i];
        for (int i = 0; i < 3; i++) cube[1][0][2 - i] = cube[2][0][2 - i];
        for (int i = 0; i < 3; i++) cube[2][0][2 - i] = cube[3][0][2 - i];
        for (int i = 0; i < 3; i++) cube[3][0][2 - i] = temp_arr[i];

        // This allows for method chaining. The function returns a reference to the current object after performing the rotation.
        return *this;
    }

    RubiksCube &uPrime() override {
        this->u();
        this->u();
        this->u();

        return *this;
    }

    RubiksCube &u2() override {
        this->u();
        this->u();

        return *this;
    }

    RubiksCube &l() override {
        this->rotateFace(1);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[0][i][0];
        for (int i = 0; i < 3; i++) cube[0][i][0] = cube[4][2 - i][2];
        for (int i = 0; i < 3; i++) cube[4][2 - i][2] = cube[5][i][0];
        for (int i = 0; i < 3; i++) cube[5][i][0] = cube[2][i][0];
        for (int i = 0; i < 3; i++) cube[2][i][0] = temp_arr[i];

        return *this;
    }

    RubiksCube &lPrime() override {
        this->l();
        this->l();
        this->l();

        return *this;
    }

    RubiksCube &l2() override {
        this->l();
        this->l();

        return *this;
    }

    RubiksCube &f() override {
        this->rotateFace(2);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[0][2][i];
        for (int i = 0; i < 3; i++) cube[0][2][i] = cube[1][2 - i][2];
        for (int i = 0; i < 3; i++) cube[1][2 - i][2] = cube[5][0][2 - i];
        for (int i = 0; i < 3; i++) cube[5][0][2 - i] = cube[3][i][0];
        for (int i = 0; i < 3; i++) cube[3][i][0] = temp_arr[i];

        return *this;
    }

    RubiksCube &fPrime() override {
        this->f();
        this->f();
        this->f();

        return *this;
    }

    RubiksCube &f2() override {
        this->f();
        this->f();

        return *this;
    }

    RubiksCube &r() override {
        this->rotateFace(3);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[0][2 - i][2];
        for (int i = 0; i < 3; i++) cube[0][2 - i][2] = cube[2][2 - i][2];
        for (int i = 0; i < 3; i++) cube[2][2 - i][2] = cube[5][2 - i][2];
        for (int i = 0; i < 3; i++) cube[5][2 - i][2] = cube[4][i][0];
        for (int i = 0; i < 3; i++) cube[4][i][0] = temp_arr[i];

        return *this;
    }

    RubiksCube &rPrime() override {
        this->r();
        this->r();
        this->r();

        return *this;
    }

    RubiksCube &r2() override {
        this->r();
        this->r();

        return *this;
    }

    RubiksCube &b() override {
        this->rotateFace(4);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[0][0][2 - i];
        for (int i = 0; i < 3; i++) cube[0][0][2 - i] = cube[3][2 - i][2];
        for (int i = 0; i < 3; i++) cube[3][2 - i][2] = cube[5][2][i];
        for (int i = 0; i < 3; i++) cube[5][2][i] = cube[1][i][0];
        for (int i = 0; i < 3; i++) cube[1][i][0] = temp_arr[i];

        return *this;
    }

    RubiksCube &bPrime() override {
        this->b();
        this->b();
        this->b();

        return *this;
    }

    RubiksCube &b2() override {
        this->b();
        this->b();

        return *this;
    }

    RubiksCube &d() override {
        this->rotateFace(5);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[2][2][i];
        for (int i = 0; i < 3; i++) cube[2][2][i] = cube[1][2][i];
        for (int i = 0; i < 3; i++) cube[1][2][i] = cube[4][2][i];
        for (int i = 0; i < 3; i++) cube[4][2][i] = cube[3][2][i];
        for (int i = 0; i < 3; i++) cube[3][2][i] = temp_arr[i];

        return *this;
    }

    RubiksCube &dPrime() override {
        this->d();
        this->d();
        this->d();

        return *this;
    }

    RubiksCube &d2() override {
        this->d();
        this->d();

        return *this;
    }
/*
 *This is an overload of the == operator for the RubiksCube3dArray class.
 *It takes a const reference to another RubiksCube3dArray object (r1) as its parameter.
 *The const at the end of the function declaration indicates that this function does not modify the state of the object it is called on.
 */
    bool operator==(const RubiksCube3dArray &r1) const{
        for(int i=0;i<6;i++)
        {
            for(int j=0;j<3;j++)
            {
                for(int k=0;k<3;k++) {
                    if (cube[i][j][k] != r1.cube[i][j][k]) return false;
                    // r1.cube[i][j][k]: Accesses the element at position (i, j, k) in the cube array of r1.
                    // cube[i][j][k]: Accesses the element at position (i, j, k) in the cube array of the current object.
                }
            }
        }
       return true;
    }
    // This operator overload makes it convenient to compare Rubik's Cube objects for equality.




/*
 * This is an overload of the assignment operator (=) for the RubiksCube3dArray class.
 * It takes a const reference to another RubiksCube3dArray object (r1) as its parameter.
 * The return type is a reference to the current object (RubiksCube3dArray &), which allows for assignment chaining.
 */
    RubiksCube3dArray &operator= (const RubiksCube3dArray &r1) {
        for(int i=0;i<6;i++) {
            for(int j=0;j<3;j++) {
                for(int k=0;k<3;k++) {
                    cube[i][j][k]=r1.cube[i][j][k];
                }
            }
        }
        return *this;
        // After all cells have been assigned, the function returns a reference to the current object (*this).
    }

};
//Hash3d struct defines custom hash function for 'RubiksCube3dArray' objects as keys in hash-based containers like std::unordered_map or std::unordered_set

struct  Hash3d {

       /*
        *  operator overload
        *   we are defining function call operator () for Hash3d struct
        *   size_t is the hashed value of the rubiks cube obj
        */
        size_t operator() (const RubiksCube3dArray &r1) const {
           string str = "";
           for (int i = 0; i < 6; i++) {
               for (int j = 0; j < 3; j++) {
                   for (int k = 0; k < 3; k++)
                       str += r1.cube[i][j][k];
               }
           }

           return hash<string>()(str); // This line creates hashed value of string str
           // str is passed to functor(function object) to get the hash value




           /*   A functor, short for function object, is an object that can be called as if it were a function. In C++, a functor is typically implemented by defining the operator() in a class or struct. This allows an instance of the class or struct to be used in a function call context.
            *  Characteristics of Functors:
            *   State: Functors can maintain state because they are objects.
            *   Operator Overloading: They overload the operator().
            *   Flexibility: They can have member variables and methods, offering more flexibility than regular functions.
            */
       }
    };

