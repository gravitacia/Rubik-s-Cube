#ifndef MAIN_CPP_CUBE_H
#define MAIN_CPP_CUBE_H

#include <vector>
#include <iostream>
#include <fstream>
#include "SolvingAlgorithm.h"
using namespace std;


class Cube : public SolvingAlgorithm
{
protected:
    vector<vector<char>> cubeVec;
    char color[6] = {'W', 'B', 'R', 'G', 'O', 'Y'};

public:
    Cube(){
        vector<vector<char>> vec1(6, vector<char>(9));
        cubeVec = vec1;
        vec1.clear();

        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 9; j++) {
                char ch = color[i];
                cubeVec[i][j] = ch;
            }
        }
    }
    vector<vector<char>> getCube()
    {
        return cubeVec;
    }

    void PrintingCube(vector<vector<char>> V);
    void PrintingCubeInFile(vector<vector<char>> V);
    bool validCube(vector<vector<char>> V);
    void generateCube(vector<vector<char>> &V);
    void getFileCube(vector<vector<char>> &V);
    void solvingCube(vector<vector<char>> V);

    Cube(vector<vector<char>> vector);
};


#endif //MAIN_CPP_CUBE_H
