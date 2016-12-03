// You are given a map in form of a two-dimensional integer grid where 1 represents land 
// and 0 represents water. Grid cells are connected horizontally/vertically (not diagonally). 

// The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells). 
// The island doesn't have "lakes" (water inside that isn't connected to the water around the island). 
// One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. 
// Determine the perimeter of the island.

// Example:

// [[0,1,0,0],
//  [1,1,1,0],
//  [0,1,0,0],
//  [1,1,0,0]]

// Answer: 16

/*
 * 计算1所在方块组成的区域的周长
 *
 * 思路：因为1所在方块是连在一块的。所以可以用方块数*4 - 内部的边*2来得到边长
 */

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int result = 0;
        int repeat = 0;
        for(size_t i = 0; i < grid.size(); ++i) {
            for(size_t j = 0; j < grid[i].size(); ++j) {
                if(grid[i][j] == 1) {
                    result++;
                    if(i != 0 && grid[i-1][j] == 1)
                        repeat++;
                    if(j != 0 && grid[i][j-1] == 1)
                        repeat++;
                }
            }
        }
        return result*4 - repeat*2;
    }
};