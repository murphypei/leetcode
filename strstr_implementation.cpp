class Solution
{
public:
    int strStr(std::string haystack, std::string needle)
    {
        if (haystack.size() < needle.size())
        {
            return -1;
        }
        for (int i = 0; i < haystack.size() - needle.size() + 1; ++i)
        {
            bool ok = true;
            for (int j = 0; j < needle.size(); ++j)
            {
                if (haystack[i + j] != needle[j])
                {
                    ok = false;
                    break;
                }
            }
            if (ok)
            {
                return i;
            }
        }
        return needle.empty() ? 0 : -1;
    }
};