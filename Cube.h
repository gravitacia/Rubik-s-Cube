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

    void PrintingCube();
    void PrintingCubeInFile();
    bool validCube();
    void generateCube();
    void getFileCube();
    vector<vector<char>> scramblingCube(string str);


};


#endif //MAIN_CPP_CUBE_H
