#include "SolvingAlgorithm.h"
#include "Cube.h"
#include <fstream>
#include <random>
#include <time.h>

using namespace std;

void scrambleCommand(){
    /// Taking Input from the User to Scramble the Cube.....
    cout << " You have to Scramble the Cube, type {A B C D E..... or ABCDE....} from the moves given below: " << endl;
    cout << "  A: Right Clockwise " << endl;
    cout << "  B: Right Anti Clockwise " << endl;
    cout << "  C: Left Clockwise " << endl;
    cout << "  D: Left Anti Clockwise " << endl;
    cout << "  E: Up Clockwise " << endl;
    cout << "  F: Up Anti Clockwise " << endl;
    cout << "  G: Down Clockwise " << endl;
    cout << "  H: Down Anti Clockwise " << endl;
    cout << "  I: Front Clockwise " << endl;
    cout << "  J: Front Anti Clockwise " << endl;
    cout << "  K: Back Clockwise " << endl;
    cout << "  L: Back Anti Clockwise " << endl;
    cout << " Now Enter Sequence to Scramble the Cube: ";
}

int main()
{
    srand(time(NULL));

    char ans = 'y';

    while (ans == 'y' || ans == 'Y')
    {
        Cube cube;

        cout << "Choose import reference " << endl;
        cout << "Type F for file or type C for console:" << endl;
        vector<vector<char>> vec;

        char answer;
        cin >> answer;

        if (answer == 'C' || answer == 'c') {
            cout << "Choose type of cube" << endl;
            cout << "Type S for scrambling solved cube or G for random generation:" << endl;

            cin >> answer;

            if (answer == 'G' || answer == 'g') {

                cube.generateCube();

                cout << "Generated cube is" << endl;
                cube.PrintingCube();

                cout << "Do you want to scramble this cube more?(y/n)" << endl;
                cin >> answer;
                if (answer == 'y' || answer == 'Y'){
                    scrambleCommand();
                    string str;
                    cin >> str;
                    cube.scramblingCube(str);
                }


                cout << "Choose output reference: " << endl;
                cout << "Type C for console or type F for file:" << endl;
                cin >> answer;

                if (answer == 'C' || answer == 'c') {

                    cout << " Solving Rubik's Cube..... " << endl;
                    cube.SolvingByAlgorithm(cube.getCube());
                    cout << endl;

                } else {
                    cube.SolvingByAlgorithm(cube.getCube());
                }
            }

            else if (answer == 'S' || answer == 's'){

                scrambleCommand();
                string str;
                cin >> str;
                cube.scramblingCube(str);
                cube.antiScrambleCommand(str);

                cout << "Choose output reference: " << endl;
                cout << "Type C for console or type F for file:" << endl;
                cin >> answer;

                if (answer == 'C' || answer == 'c'){

                    cout << endl;
                    cout << " Scrambled Cube is....." << endl;
                    cube.PrintingCube();

                    cout << " Solving Rubik's Cube..... " << endl;
                    cube.SolvingByAlgorithm(cube.getCube());
                    cout << endl;
                }

                else{
                    cube.SolvingByAlgorithm(cube.getCube());
                }
            }
        }

        else if (answer == 'F' || answer == 'f') {

            cube.getFileCube();
            if (!cube.validColors(cube.getCube()))
                continue;

            cout << "Cube from file" << endl;
            cube.PrintingCube();

            cout << "Do you want to scramble this cube more?(y/n)" << endl;
            cin >> answer;
            if (answer == 'y' || answer == 'Y'){
                scrambleCommand();
                string str;
                cin >> str;
                cube.scramblingCube(str);
            }

            cout << "Choose output reference: " << endl;
            cout << "Type C for console or type F for file:" << endl;
            cin >> answer;

            if (answer == 'C' || answer == 'c'){

                cout << endl;
                cout << " Scrambled Cube is....." << endl;
                cube.PrintingCube();

                cout << " Solving Rubik's Cube..... " << endl;
                cube.SolvingByAlgorithm(cube.getCube());
                cout << endl;
            }
            else{
                cube.SolvingByAlgorithm(cube.getCube());
            }

        }

        cout << " Want to Solve again? (y/n): ";
        cin >> ans;
    }

    return 0;
}
