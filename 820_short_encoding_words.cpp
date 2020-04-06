#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution
{
public:
    int minimumLengthEncoding(vector<string> &words)
    {
        unordered_set<string> unique_words(words.begin(), words.end());
        for (auto &word : words)
        {
            // 对每个单词，从 1 开始找其子串，将子串从 set 中删除（如果在 set 中的话）。
            for (int i = 1; i < word.size(); ++i)
            {
                unique_words.erase(word.substr(i));
            }
        }
        int res = 0;
        for (auto &s : unique_words)
        {
            res += s.size() + 1;
        }
        return res;
    }
};