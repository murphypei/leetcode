// Forward declaration of isBadVersion API.
// 
#include <iostream>

using namespace std;

static const int FirstBadVersion = 1;

bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        bool result;
        unsigned int begin = 0;
        unsigned int end = n + 1;
        int version = (begin + end) / 2;
        while(begin < end) {
            result = isBadVersion(version);
            if(result == true){         // this version is bad
                if(isFirstBasVersion(version))  // this version is first bad version
                    return version;
                else      // this version is not the first bad version
                    end = version;
            }
            else {                      // this version is good
                begin = version;
            }
            version = (begin + end) / 2;
        }
        return -1;
    }
    
    bool isFirstBasVersion(int n) {
        if(isBadVersion(n) && !isBadVersion(n - 1))
            return true;
        else 
            return false;
    }
};

bool isBadVersion(int version) {
	if(version >= FirstBadVersion) 
		return true;
	else
		return false;
}


int main() {
	Solution s;
	cout << s.firstBadVersion(6) << endl;

	return 0;
}
