#include <string>
#include <vector>

class Solution
{
public:
    std::string simplifyPath(std::string path)
    {
        auto parts = splitString(path, "/");
        std::vector<bool> valid(parts.size(), true);
        for (int i = parts.size() - 1; i >= 0; i--)
        {
            if (parts[i] == "." || parts[i].empty())
            {
                valid[i] = false;
                continue;
            }
            int parent_count = 0;
            while (parts[i] == "..")
            {
                valid[i] = false;
                parent_count += 1;
                i--;
            }
            // 根据储存得父目录标志来删除前向路径
            for (int j = 0; j < parent_count && i >= j;)
            {
                valid[i - j] = false;
                // 如果当前路径是空或者"."，则父目录标志不减少，整体向左移动一步
                if (parts[i - j] == "." || parts[i - j].empty())
                {
                    i--;
                }
                else if (parts[i - j] == "..") // 如果是".."，增加父目录得标记数目，向左移动一步
                {
                    parent_count++;
                    i--;
                }
                else // 常规路径，则减少父目录的标记
                {
                    j++;
                }
            }
        }

        std::string res;
        for (int i = 0; i < parts.size(); ++i)
        {
            if (valid[i] && !parts[i].empty())
            {
                res += ("/" + parts[i]);
            }
        }
        return res.empty() ? "/" : res;
    }

    std::vector<std::string> splitString(const std::string &src, const std::string &delim)
    {
        size_t start_pos = 0;
        size_t find_pos = src.find(delim, start_pos);
        std::vector<std::string> res;
        while (find_pos != std::string::npos)
        {
            res.emplace_back(src.substr(start_pos, find_pos - start_pos));
            start_pos = find_pos + 1;
            find_pos = src.find(delim, start_pos);
        }
        res.emplace_back(src.substr(start_pos, src.size() - start_pos));
        return res;
    }
};