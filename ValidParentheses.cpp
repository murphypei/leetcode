// Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.


#include <string>
#include <stack>
#include <iostream>
#include <boost/unordered_set.hpp>
#include <boost/unordered_map.hpp>

using namespace std;

using boost::unordered_map;
using boost::unordered_set;

class Solution {
public:
	bool isValid(string s) {
		stack<char> st;
		unordered_map<char, char>  char_map;
		unordered_set<char> char_set;
		char_set.insert('(');
		char_set.insert(')');
		char_set.insert('{');
		char_set.insert('}');
		char_set.insert('[');
		char_set.insert(']');
		char_map.insert(make_pair(')', '('));
		char_map.insert(make_pair('}', '{'));
		char_map.insert(make_pair(']', '['));
		
		for(string::size_type idx = 0; idx != s.size(); ++idx) {
			if(char_set.find(s[idx]) == char_set.end())
				return false;
			else if(char_map.find(s[idx]) == char_map.end()) {
				st.push(s[idx]);
			}
			else {
				if(!st.empty() && st.top() == char_map[s[idx]])
					st.pop();
				else 
					return false;
			}
		}

		return st.empty() ? true : false;

	}
};


int main() {
	string str("[()]{}");
	Solution s;
	cout << s.isValid(str) << endl;

	return 0;
}


		
