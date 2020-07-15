#include "utils.h"
#include <iostream>

void printVec(const std::vector<int> &vec)
{
    for (int i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

void printMat(const std::vector<std::vector<int>> &mat)
{
    for (int i = 0; i < mat.size(); ++i)
    {
        for (int j = 0; j < mat[i].size(); ++j)
        {
            std::cout << mat[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << std::endl;
}
