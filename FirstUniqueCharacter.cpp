#include <string>
#include <iostream>

using namespace std;

class Solution {
	public:
		int firstUniqChar(string s) {
			int alphabet[26] = {0};
			for(size_t i = 0; i != s.size(); ++i) 
				++alphabet[s[i] - 'a'];

			size_t i = 0;
			while( i < s.size() && alphabet[s[i] - 'a'] > 1)
				++i;
			
			return i == s.size() ? -1 : i;
		}
};

int main() {
	string str = "loveleetcode";
	Solution s;
	cout << s.firstUniqChar(str) << endl;
	return 0;
}

