#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        unordered_map<char, vector<char>> number_letter_map;
        number_letter_map['2'] = vector<char>{'a', 'b', 'c'};
        number_letter_map['3'] = vector<char>{'d', 'e', 'f'};
        number_letter_map['4'] = vector<char>{'g', 'h', 'i'};
        number_letter_map['5'] = vector<char>{'j', 'k', 'l'};
        number_letter_map['6'] = vector<char>{'m', 'n', 'o'};
        number_letter_map['7'] = vector<char>{'p', 'q', 'r', 's'};
        number_letter_map['8'] = vector<char>{'t', 'u', 'v'};
        number_letter_map['9'] = vector<char>{'w', 'x', 'y', 'z'};
        vector<string> result;
        for (auto &c : digits)
        {
            result = combine_string(result, number_letter_map[c]);
        }
        return result;
    }

private:
    vector<string> combine_string(vector<string> &src, vector<char> &target)
    {
        vector<string> result;
        if (src.empty())
        {
            for (auto &c : target)
            {
                result.emplace_back(1, c);
            }
        }
        else
        {
            for (auto &c : target)
            {
                for (auto &s : src)
                {
                    result.emplace_back(s + string(1, c));
                }
            }
        }
        return result;
    }
};