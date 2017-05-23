/**
 * 反转句子中的每个单词，单词的顺序保持不变
 */

#include <string>
#include <iostream>
#include <algorithm>
#include <memory>

using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        auto it1 = s.begin();
        auto it2 = s.begin();
        while(it2 != s.end())
        {
            if(*it2 != ' ')
            {
                it2++;
            }
            else
            {
                std::reverse(it1, it2);
                it2++;
                it1 = it2;
            }
        }
        reverse(it1, it2);

        return s;
    }
};

int main()
{
    string s("Let's take LeetCode contest");
    shared_ptr<Solution> sptr = make_shared<Solution>();
    cout << sptr->reverseWords(s) << endl;

    getchar();
    return 0;
}