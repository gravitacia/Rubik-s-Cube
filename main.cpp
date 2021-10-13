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
    srand (time(NULL));

    char color[6] = {'W', 'B', 'R', 'G', 'O', 'Y'};
    /// вектор для чтения кубика из файла и случайной генерации
    vector<vector<char>> fileCube(6, vector<char>(9));
    vector<vector<char>> genCube(6, vector<char>(9));

    char ans = 'y';

    while (ans == 'y' || ans == 'Y')
    {
        Cube cube;

        cout << "Choose import reference " << endl;
        cout << "Type F for file or type C for console:" << endl;

        char answer;
        cin >> answer;

        if (answer == 'C' || answer == 'c') {
            cout << "Choose type of cube" << endl;
            cout << "Type S for scrambling solved cube or G for random generation:" << endl;

            cin >> answer;

            if (answer == 'G' || answer == 'g') {

                for (int i = 0; i < 6; i++) {
                    for (int j = 0; j < 9; j++) {
                        char ch = color[i];
                        genCube[i][j] = ch;
                    }
                }

                cube.generateCube(genCube);

                cout << "Generated cube is" << endl;
                cube.printingCube(genCube);

                cout << "Do you want to scramble this cube more?(y/n)" << endl;
                cin >> answer;
                if (answer == 'y' || answer == 'Y'){
                    scrambleCommand();
                    string str;
                    cin >> str;
                    genCube = cube.scramblingCube(str, genCube);
                }


                cout << "Choose output reference: " << endl;
                cout << "Type C for console or type F for file:" << endl;
                cin >> answer;

                if (answer == 'C' || answer == 'c') {

                    cout << " Solving Rubik's Cube..... " << endl;
                    cube.solvingCube(genCube);
                    cout << endl;

                    cout << endl;
                    cout << " Solved Rubik's cube is..... " << endl;
                    cube.PrintingCube(genCube);
                } else {
                    cube.solvingCube(cube.getCube());
                    cube.PrintingCubeInFile(cube.getCube());
                }
            }

            else if (answer == 'S' || answer == 's'){

                scrambleCommand();
                string str;
                cin >> str;
                //cube = cube.scramblingCube(str, cube.getCube());
                cube.antiScrambleCommand(str);

                cout << "Choose output reference: " << endl;
                cout << "Type C for console or type F for file:" << endl;
                cin >> answer;

                if (answer == 'C' || answer == 'c'){

                    cout << endl;
                    cout << " Scrambled Cube is....." << endl;
                    cube.PrintingCube(cube.getCube());

                    cout << " Solving Rubik's Cube..... " << endl;
                    cube.solvingCube(cube.getCube());
                    cout << endl;
                }

                else{
                    cube.solvingCube(genCube);
                    cube.PrintingCubeInFile(genCube);
                }
            }
        }

        else if (answer == 'F' || answer == 'f') {

            cube.getFileCube(fileCube);
            if (!cube.validColors(fileCube))
                continue;


            cout << "Choose output reference: " << endl;
            cout << "Type C for console or type F for file:" << endl;
            cin >> answer;

            if (answer == 'C' || answer == 'c'){

                cout << endl;
                cout << " Scrambled Cube is....." << endl;
                cube.PrintingCube(fileCube);

                cout << " Solving Rubik's Cube..... " << endl;
                cube.solvingCube(fileCube);
                cout << endl;
            }
            else{
                cube.solvingCube(fileCube);
                cube.PrintingCubeInFile(fileCube);
            }

        }
        else cout << "Exeption" << endl;



        cout << " Want to Solve again? (y/n): ";
        cin >> ans;
    }

    return 0;
}
