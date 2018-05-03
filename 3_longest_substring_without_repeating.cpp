// Given a string, find the length of the longest substring without repeating characters.


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() < 2) {
            return s.size();
        }
        vector<int> lens(s.size(), 1);
        int j;
        for(auto i = 0; i < s.size() - 1; ++i) { 
            for(j = i + 1; j < s.size(); ++j) {
                auto it = find(s.begin() + i, s.begin() + j, s[j]);
                // std:: cout << *(s.begin() + i) << "\t" << *(s.begin() + j) <<  "\t" << s[j] << "\t" << it - s.begin() << std::endl;
                if(it != s.begin() + j) {
                    break;
                }
            }
            lens[i] = j - i;
        }
        // for(auto it = lens.begin(); it != lens.end(); ++it) {
        //     std::cout << *it << std::endl;
        // }
        return *max_element(lens.begin(), lens.end());
    }
};

