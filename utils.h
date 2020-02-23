#pragma once

#include <vector>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

void printVec(const std::vector<int> &vec);

void printMat(const std::vector<std::vector<int>> &mat);