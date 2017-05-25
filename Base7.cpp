/**
 * 10进制转7进制
 **/

#include <memory>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string convertToBase7(int num)
    {
        if(num >= 0)
        {
            int res = convert10ToN(num, 7);
            return to_string(res);
        }
        else
        {
            int res = convert10ToN(-num, 7);
            return "-" + to_string(res);
        }

    }

private:
    int convert10ToN(int num, const int N)
    {
        vector<int> res;
        int remain = 0;
        while(num >= N)
        {
            remain = num % N;
            res.push_back(remain);
            num = num / N;
        }
        res.push_back(num);
        std::reverse(res.begin(), res.end());
        
        int result = 0;
        for(auto i : res)
            result = result * 10 + i;
        return result;
    }
};