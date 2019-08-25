#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

class Solution 
{
public:
    unordered_map<char, char> partnership_map{{'(', ')'}, {'[', ']'}, {'{', '}'}};
    stack<char> sk;
    bool isValid(string s) 
    {
        for (auto c : s)
        {
            if (c == '}' or c == ']' or c == ')')
            {
                if (sk.empty())
                {
                    return false;
                }
                else
                {
                    char _c = sk.top();
                    if (partnership_map[_c] == c)
                    {
                        sk.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
            }
            else
            {
                sk.push(c);
            }
        }
        return sk.empty();
    }
};