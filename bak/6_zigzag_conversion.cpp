// conversion for zigzag string


class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows <= 1) {
            return s;
        }

        string result = "";
        int cycle = 2 * numRows - 2;
        for(int i = 0; i < numRows; ++i) {
            for(int j = i; j < s.length(); j = j + cycle) {
                result = result + s[j];
                int secondJ = (j - i) + cycle - i;
                if(i != 0 && i != numRows-1 && secondJ < s.length())
                    result = result + s[secondJ];
            }
        }
        return result;
    }
};