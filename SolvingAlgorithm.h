//
// Created by kosar on 12.10.2021.
//

#ifndef MAIN_CPP_SOLVINGALGORITHM_H
#define MAIN_CPP_SOLVINGALGORITHM_H


#include <vector>
#include <iostream>
#include <fstream>
using namespace std;


class SolvingAlgorithm {
public:

    void printingCube(vector<vector<char>> vec);
    void printingCubeInFile(vector<vector<char>> vec);
    bool validColors(vector<vector<char>> vec);
    void antiScrambleCommand(string str);



/// Solution
    vector<vector<char>> SolvingByAlgorithm(vector<vector<char>> vec);


/// Rotation of Side Clockwise
    vector<char> rotate_clock(vector<char> vec);

/// Rotation of Side Anti-Clockwise
    vector<char> rotate_anti_clock(vector<char> vec);


/// RED Moves
    vector<vector<char>> Red_Right_Clock(vector<vector<char>> vec);
    vector<vector<char>> Red_Right_Anti_Clock(vector<vector<char>> vec);
    vector<vector<char>> Red_Left_Clock(vector<vector<char>> vec);
    vector<vector<char>> Red_Left_Anti_Clock(vector<vector<char>> vec);
    vector<vector<char>> Red_Up_Clock(vector<vector<char>> vec);
    vector<vector<char>> Red_Up_Anti_Clock(vector<vector<char>> vec);
    vector<vector<char>> Red_Down_Clock(vector<vector<char>> vec);
    vector<vector<char>> Red_Down_Anti_Clock(vector<vector<char>> vec);
    vector<vector<char>> Red_Front_Clock(vector<vector<char>> vec);
    vector<vector<char>> Red_Front_Anti_Clock(vector<vector<char>> vec);
    vector<vector<char>> Red_Back_Clock(vector<vector<char>> vec);
    vector<vector<char>> Red_Back_Anti_Clock(vector<vector<char>> vec);


/// BLUE Moves
    vector<vector<char>> Blue_Right_Clock(vector<vector<char>> vec);
    vector<vector<char>> Blue_Right_Anti_Clock(vector<vector<char>> vec);
    vector<vector<char>> Blue_Left_Clock(vector<vector<char>> vec);
    vector<vector<char>> Blue_Left_Anti_Clock(vector<vector<char>> vec);
    vector<vector<char>> Blue_Up_Clock(vector<vector<char>> vec);
    vector<vector<char>> Blue_Up_Anti_Clock(vector<vector<char>> vec);
    vector<vector<char>> Blue_Down_Clock(vector<vector<char>> vec);
    vector<vector<char>> Blue_Down_Anti_Clock(vector<vector<char>> vec);
    vector<vector<char>> Blue_Front_Clock(vector<vector<char>> vec);
    vector<vector<char>> Blue_Front_Anti_Clock(vector<vector<char>> vec);
    vector<vector<char>> Blue_Back_Clock(vector<vector<char>> vec);
    vector<vector<char>> Blue_Back_Anti_Clock(vector<vector<char>> vec);


/// ORANGE Moves
    vector<vector<char>> Orange_Right_Clock(vector<vector<char>> vec);
    vector<vector<char>> Orange_Right_Anti_Clock(vector<vector<char>> vec);
    vector<vector<char>> Orange_Left_Clock(vector<vector<char>> vec);
    vector<vector<char>> Orange_Left_Anti_Clock(vector<vector<char>> vec);
    vector<vector<char>> Orange_Up_Clock(vector<vector<char>> vec);
    vector<vector<char>> Orange_Up_Anti_Clock(vector<vector<char>> vec);
    vector<vector<char>> Orange_Down_Clock(vector<vector<char>> vec);
    vector<vector<char>> Orange_Down_Anti_Clock(vector<vector<char>> vec);
    vector<vector<char>> Orange_Front_Clock(vector<vector<char>> vec);
    vector<vector<char>> Orange_Front_Anti_Clock(vector<vector<char>> vec);
    vector<vector<char>> Orange_Back_Clock(vector<vector<char>> vec);
    vector<vector<char>> Orange_Back_Anti_Clock(vector<vector<char>> vec);


/// GREEN Moves
    vector<vector<char>> Green_Right_Clock(vector<vector<char>> vec);
    vector<vector<char>> Green_Right_Anti_Clock(vector<vector<char>> vec);
    vector<vector<char>> Green_Left_Clock(vector<vector<char>> vec);
    vector<vector<char>> Green_Left_Anti_Clock(vector<vector<char>> vec);
    vector<vector<char>> Green_Up_Clock(vector<vector<char>> vec);
    vector<vector<char>> Green_Up_Anti_Clock(vector<vector<char>> vec);
    vector<vector<char>> Green_Down_Clock(vector<vector<char>> vec);
    vector<vector<char>> Green_Down_Anti_Clock(vector<vector<char>> vec);
    vector<vector<char>> Green_Front_Clock(vector<vector<char>> vec);
    vector<vector<char>> Green_Front_Anti_Clock(vector<vector<char>> vec);
    vector<vector<char>> Green_Back_Clock(vector<vector<char>> vec);
    vector<vector<char>> Green_Back_Anti_Clock(vector<vector<char>> vec);




};


#endif //MAIN_CPP_SOLVINGALGORITHM_H
