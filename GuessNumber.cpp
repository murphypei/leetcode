// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
// 
#include <iostream>

using namespace std;

static const int pickNumber = 6;

int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int count = 100;
        int begin = 0;
        int end = n + 1;
        int myGuessNumber = (begin + end) / 2;
        int guessResult = guess(myGuessNumber);
        
        while(guessResult != 0 && begin <= end && count > 0) {
            if(guessResult == 1) {
                cout <<  "+++" << myGuessNumber << endl;
                begin = myGuessNumber;
            }
            else {
                cout << "---" << myGuessNumber << endl;
                end = myGuessNumber;
            }
            myGuessNumber = (begin + end) / 2;
            guessResult = guess(myGuessNumber);
            --count;
            
        }
        
        if(guessResult == 0)
            return myGuessNumber;
        else
            return -1;
    }
    
    // 当guess结果为-1时

};



int guess(int num) {

    if(num == pickNumber)
        return 0;
    else if(num < pickNumber)
        return 1;
    else
        return -1;
}

int main() {

    Solution s;
    int result = s.guessNumber(6);
    cout << result << endl;

    getchar();
    return 0;
}
