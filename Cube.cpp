#include "Cube.h"
#include <fstream>

using namespace std;


void Cube::PrintingCube()
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
            cout << this->cubeVec[0][cnt] << " ";
            cnt++;
        }
        cout << "|" << endl;
    }
    cout << "\t           ---------" << endl;

    /// Печать красной, синей, оранжевой, и зеленой сторон
    cout << "\t --------- --------- --------- ---------" << endl;
    for (int j = 0; j < 9; j += 3)
    {
        cout << "\t | " << cubeVec[2][j] << " " << cubeVec[2][j + 1] << " " << cubeVec[2][j + 2] << " | ";
        cout << "| " << cubeVec[1][j] << " " << cubeVec[1][j + 1] << " " << cubeVec[1][j + 2] << " | ";
        cout << "| " << cubeVec[4][j] << " " << cubeVec[4][j + 1] << " " << cubeVec[4][j + 2] << " | ";
        cout << "| " << cubeVec[3][j] << " " << cubeVec[3][j + 1] << " " << cubeVec[3][j + 2] << " | ";
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
            cout << cubeVec[5][cnt] << " ";
            cnt++;
        }
        cout << "|" << endl;
    }
    cout << "\t           ---------" << endl;
    cout << endl;

}


void Cube::PrintingCubeInFile()
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
            fout << cubeVec[0][cnt] << " ";
            cnt++;
        }
        fout << "|" << endl;
    }
    fout << "\t           ---------" << endl;

    /// Printing RED, BLUE, ORANGE and GREEN Layer...
    fout << "\t --------- --------- --------- ---------" << endl;
    for (int j = 0; j < 9; j += 3)
    {
        fout << "\t | " << cubeVec[2][j] << " " << cubeVec[2][j + 1] << " " << cubeVec[2][j + 2] << " | ";
        fout << "| " << cubeVec[1][j] << " " << cubeVec[1][j + 1] << " " << cubeVec[1][j + 2] << " | ";
        fout << "| " << cubeVec[4][j] << " " << cubeVec[4][j + 1] << " " << cubeVec[4][j + 2] << " | ";
        fout << "| " << cubeVec[3][j] << " " << cubeVec[3][j + 1] << " " << cubeVec[3][j + 2] << " | ";
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
            fout << cubeVec[5][cnt] << " ";
            cnt++;
        }
        fout << "|" << endl;
    }
    fout << "\t           ---------" << endl;
    fout << endl;

}



bool Cube::validCube(){
    char color[6] = {'W', 'B', 'R', 'G', 'O', 'Y'};
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 9; j++) {
            if (cubeVec[i][j] != color[i]) return false;
        }
    }
    return true;
}


void Cube::generateCube(){
    string commands;
    int a;
    a = rand() % 5 + 4;
    char com[12] = {'A','B','C','D','E','F','G','H','I','J','K','L'};
    for (int i = 0; i<a; i++){
        int choise = rand() % 12;
        commands += com[choise];
    }
    cout << commands << endl;
    cubeVec = scramblingCube(commands);
    antiScrambleCommand(commands);
}

void Cube::getFileCube() {

    char fileColour;
    int stroka = 0;
    int stolb = 0;

    ifstream fin("C:\\Users\\kosar\\CLionProjects\\rubiksCube\\cmake-build-debug\\cube.txt");

    if (!fin.is_open()) {
        cout << "Cant open file";
    } else {
        while (fin.get(fileColour)) {
            cubeVec[stolb][stroka] = fileColour;
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

vector<vector<char>> Cube::scramblingCube(string str){
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str.at(i);
        if (islower(ch))
        {
            ch = toupper(ch);
        }
        if (ch == 'A' || ch == 'M' || ch == 'Y')
        {
            cubeVec = Blue_Right_Clock(cubeVec);
        }
        else if (ch == 'B' || ch == 'N' || ch == 'Z')
        {
            cubeVec = Blue_Right_Anti_Clock(cubeVec);
        }
        else if (ch == 'C' || ch == 'O')
        {
            cubeVec = Blue_Left_Clock(cubeVec);
        }
        else if (ch == 'D' || ch == 'P')
        {
            cubeVec = Blue_Left_Anti_Clock(cubeVec);
        }
        else if (ch == 'E' || ch == 'Q')
        {
            cubeVec = Blue_Up_Clock(cubeVec);
        }
        else if (ch == 'F' || ch == 'R')
        {
            cubeVec = Blue_Up_Anti_Clock(cubeVec);
        }
        else if (ch == 'G' || ch == 'S')
        {
            cubeVec = Blue_Down_Clock(cubeVec);
        }
        else if (ch == 'H' || ch == 'T')
        {
            cubeVec = Blue_Down_Anti_Clock(cubeVec);
        }
        else if (ch == 'I' || ch == 'U')
        {
            cubeVec = Blue_Front_Clock(cubeVec);
        }
        else if (ch == 'J' || ch == 'V')
        {
            cubeVec = Blue_Front_Anti_Clock(cubeVec);
        }
        else if (ch == 'K' || ch == 'W')
        {
            cubeVec = Blue_Back_Clock(cubeVec);
        }
        else if (ch == 'L' || ch == 'X')
        {
            cubeVec = Blue_Back_Anti_Clock(cubeVec);
        }
    }
    return cubeVec;
}