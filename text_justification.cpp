#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<string> fullJustify(vector<string> &words, int L)
    {
        vector<string> res;
        int i = 0;
        while (i < words.size())
        {
            int j = i, char_len = 0;
            while (j < words.size() && char_len + words[j].size() + j - i <= L)
            {
                char_len += words[j].size();
                j++;
            }
            int space_size = L - char_len;
            string temp_line;
            for (int k = i; k < j; ++k)
            {
                temp_line += words[k];
                if (space_size > 0)
                {
                    int temp_space_size = 0;
                    if (j == words.size()) // the last line
                    {
                        if (j - k - 1 == 0) // the second to last word in this line
                        {
                            temp_space_size = space_size;
                        }
                        else
                        {
                            temp_space_size = 1; // no extra space in the last line.
                        }
                    }
                    else // other line
                    {
                        if (j - k - 1 == 0) // the second to last word
                        {
                            temp_space_size = space_size;
                        }
                        else // other word
                        {
                            if (space_size % (j - k - 1) == 0) // no extra space
                            {
                                temp_space_size = space_size / (j - k - 1);
                            }
                            else
                            {
                                temp_space_size = space_size / (j - k - 1) + 1; // extra space
                            }
                        }
                    }
                    space_size -= temp_space_size;
                    temp_line.append(temp_space_size, ' ');
                }
            }
            res.push_back(temp_line);
            i = j;
        }
        return res;
    }
};