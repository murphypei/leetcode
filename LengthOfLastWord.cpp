class Solution {
	int lengthOfLastWord(string s) {
		int len = 0;
		istringstream iss(s);
		for(string tmp; getline(iss, tmp, ' '); )
			if(!tmp.empty())
				len = tmp.size();
		return len;
	}
};
