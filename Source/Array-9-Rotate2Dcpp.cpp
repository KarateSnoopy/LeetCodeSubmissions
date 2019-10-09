// LeetCode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

void Rotate4(vector<vector<int>>& q,
    int x1, int y1,
    int x2, int y2,
    int x3, int y3,
    int x4, int y4
    )
{
    int temp = q[x1][y1];
    q[x1][y1] = q[x4][y4];
    q[x4][y4] = q[x3][y3];
    q[x3][y3] = q[x2][y2];
    q[x2][y2] = temp;
}

void rotate(vector<vector<int>>& q)
{
    std::cout << "Width: " << q.size() << " ";
    std::cout << "Height: " << q[0].size() << "\n";

    for( int x = 0; x<q.size(); x++ )
    {
        for( int y = 0; y<q[0].size(); y++ )
        {
            std::cout << q[x][y] << ",";
        }
        std::cout << "\n";
    }
    std::cout << "\n";

    //q[0][0]; // corner1  
    //q[0][q[0].size() - 1]; // corner2
    //q[q.size() - 1][q[0].size() - 1]; // corner3
    //q[q.size()-1][0]; // corner4

    int startW = 0;
    int startH = 0;

    int numOfRings = (((int)q[0].size()+1) / 2);
    int h = (int)q.size() - 1;
    int w = (int)q[0].size() - 1;
    for (int ringIndex = 0; ringIndex < numOfRings; ringIndex++)
    {
        for( int i=0; i<h; i++ )
        {
            std::cout << i << std::endl;
            Rotate4(q,
                startH+0, startW+i,
                startH+i, startW+w,
                startH+h, startW+w-i,
                startH+h-i, startW+0
            );
        }

        startH++;
        startW++;

        h -= 2;
        w -= 2;
    }

    for (int x = 0; x < q.size(); x++)
    {
        for (int y = 0; y < q[0].size(); y++)
        {
            std::cout << q[x][y] << ",";
        }
        std::cout << "\n";
    }
    std::cout << "\n";

}

bool VerifyResults9( vector<vector<int>> input, vector<vector<int>> output )
{
    rotate(input);

    for(size_t i=0; i<output.size(); i++)
    {
        for (size_t j = 0; j < output[i].size(); j++)
        {
            if( input[i][j] != output[i][j] ) return false;
        }
    }

    return true;
}

void TestArray9()
{
    bool failed = false;
    if (!VerifyResults9(
        {{1, 2, 3}, {4,5,6}, {7,8,9} }, 
        {{7, 4, 1}, {8,5,2}, {9,6,3} }
    )) failed = true;

    if (!VerifyResults9(
        { {1, 2, 3, 4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16} },
        { {13,9,5,1}, {14,10,6,2}, {15,11,7,3}, {16,12,8,4} }
    )) failed = true;

    if (!VerifyResults9(
        { {1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}, {16, 17, 18, 19, 20}, {21, 22, 23, 24, 25} },
        { {1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}, {16, 17, 18, 19, 20}, {21, 22, 23, 24, 25} }
    )) failed = true;

    if (failed) 
        std::cout << "Failure!";
    else
        std::cout << "Success!";
}


