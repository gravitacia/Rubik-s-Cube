/// Header Files
#include "Cube.h"
#include <fstream>

using namespace std;


void Cube::PrintingCube(vector<vector<char>> vec)
{
    /// печатаем белую сторону
    cout << endl;
    int cnt = 0;
    cout << "\t           ---------" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "\t           ";
        cout << "| ";
        for (int j = 0; j < 3; j++)
        {
            cout << vec[0][cnt] << " ";
            cnt++;
        }
        cout << "|" << endl;
    }
    cout << "\t           ---------" << endl;

    /// Печать красной, синей, оранжевой, и зеленой сторон
    cout << "\t --------- --------- --------- ---------" << endl;
    for (int j = 0; j < 9; j += 3)
    {
        cout << "\t | " << vec[2][j] << " " << vec[2][j + 1] << " " << vec[2][j + 2] << " | ";
        cout << "| " << vec[1][j] << " " << vec[1][j + 1] << " " << vec[1][j + 2] << " | ";
        cout << "| " << vec[4][j] << " " << vec[4][j + 1] << " " << vec[4][j + 2] << " | ";
        cout << "| " << vec[3][j] << " " << vec[3][j + 1] << " " << vec[3][j + 2] << " | ";
        cout << endl;
    }
    cout << "\t --------- --------- --------- ---------" << endl;

    /// печатаем желтую сторону
    cnt = 0;
    cout << "\t           ---------" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "\t           ";
        cout << "| ";
        for (int j = 0; j < 3; j++)
        {
            cout << vec[5][cnt] << " ";
            cnt++;
        }
        cout << "|" << endl;
    }
    cout << "\t           ---------" << endl;
    cout << endl;

}


void Cube::PrintingCubeInFile(vector<vector<char>> vec)
{
    ofstream fout;
    fout.open("solved.txt", ios_base::out | ios_base::app);
    /// Printing WHITE Layer...
    fout << endl;
    int cnt = 0;
    fout << "\t           ---------" << endl;
    for (int i = 0; i < 3; i++)
    {
        fout << "\t           ";
        fout << "| ";
        for (int j = 0; j < 3; j++)
        {
            fout << vec[0][cnt] << " ";
            cnt++;
        }
        fout << "|" << endl;
    }
    fout << "\t           ---------" << endl;

    /// Printing RED, BLUE, ORANGE and GREEN Layer...
    fout << "\t --------- --------- --------- ---------" << endl;
    for (int j = 0; j < 9; j += 3)
    {
        fout << "\t | " << vec[2][j] << " " << vec[2][j + 1] << " " << vec[2][j + 2] << " | ";
        fout << "| " << vec[1][j] << " " << vec[1][j + 1] << " " << vec[1][j + 2] << " | ";
        fout << "| " << vec[4][j] << " " << vec[4][j + 1] << " " << vec[4][j + 2] << " | ";
        fout << "| " << vec[3][j] << " " << vec[3][j + 1] << " " << vec[3][j + 2] << " | ";
        fout << endl;
    }
    fout << "\t --------- --------- --------- ---------" << endl;

    /// Printing YELLOW Layer...
    cnt = 0;
    fout << "\t           ---------" << endl;
    for (int i = 0; i < 3; i++)
    {
        fout << "\t           ";
        fout << "| ";
        for (int j = 0; j < 3; j++)
        {
            fout << vec[5][cnt] << " ";
            cnt++;
        }
        fout << "|" << endl;
    }
    fout << "\t           ---------" << endl;
    fout << endl;

}



bool Cube::validCube(vector<vector<char>> validVec){
    char color[6] = {'W', 'B', 'R', 'G', 'O', 'Y'};
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 9; j++) {
            if (validVec[i][j] != color[i]) return false;
        }
    }
    return true;
}


void Cube::generateCube(vector<vector<char>> &vec){
    string commands;
    int a;
    a = rand() % 15 + 5;
    char com[12] = {'A','B','C','D','E','F','G','H','I','J','K','L'};
    for (int i = 0; i<a; i++){
        int choise = rand() % 12;
        commands += com[choise];
    }
    cout << commands << endl;
    vec = scramblingCube(commands, vec);
    antiScrambleCommand(commands);
}

//delete this method
void Cube::solvingCube(vector<vector<char>> vec) {
    SolvingByAlgorithm(vec);
}

void Cube::getFileCube(vector<vector<char>> &fileVec) {

    char fileColour;
    int stroka = 0;
    int stolb = 0;

    ifstream fin("C:\\Users\\kosar\\CLionProjects\\Rubik\\cmake-build-debug\\cube.txt");

    if (!fin.is_open()) {
        cout << "Cant open file";
    } else {
        while (fin.get(fileColour)) {
            fileVec[stolb][stroka] = fileColour;
            if (stroka <= 7) stroka++;
            else {
                stroka = 0;
                stolb++;
            }
            if (stolb == 5 && stroka == 9){
                break;
            }
        }
    }
}