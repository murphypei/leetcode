#include <string>
#include <unordered_map>
#include <vector>

class Solution
{
public:
    std::vector<int> findSubstring(std::string s, std::vector<std::string> &words)
    {
        std::vector<int> result;
        if (s.empty() || words.empty())
        {
            return result;
        }
        auto wordSize = words[0].size();
        auto numWord = words.size();
        auto strSize = s.size();
        auto subStringSize = numWord * wordSize;
        if (subStringSize > strSize)
        {
            return result;
        }
        std::unordered_map<std::string, int> wordCountMap;
        for (auto &word : words)
        {
            wordCountMap[word]++;
        }

        std::unordered_map<std::string, int> wordTimes;
        for (int i = 0; i + subStringSize <= s.size(); ++i)
        {
            wordTimes.clear();
            int start = i;
            bool bingo = true;
            for (int j = 0; j < numWord; ++j)
            {
                std::string curWord = s.substr(start + j * wordSize, wordSize);
                if (!wordCountMap.count(curWord))
                {
                    bingo = false;
                    break;
                }
                wordTimes[curWord]++;
                if (wordTimes[curWord] > wordCountMap[curWord])
                {
                    bingo = false;
                    break;
                }
            }
            if (bingo)
            {
                result.push_back(i);
            }
        }
        return result;
    }
};