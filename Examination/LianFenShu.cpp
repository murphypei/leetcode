#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <iterator>
#include <algorithm>

using namespace std;

void calc(vector<int> &nums, int &fenzi, int &fenmu) {

    int n = nums.size() - 1;
    for(int i = n; i > 0; --i) {
        fenzi = fenzi + nums[i] * fenmu;
        swap(fenzi, fenmu);
    }
    fenzi = nums[0] * fenmu + fenzi;
}


int main() {
      
    int n;
    cin >> n;
    vector<int> nums(n+1, 0);
    for(int i = 0; i <= n; ++i) {
        cin >> nums[i];
    }

    int fenzi1 = 0, fenmu1 = 1;
    calc(nums, fenzi1, fenmu1);
    // copy(nums.begin(), nums.end(), ostream_iterator<int>(cout, " "));
    // cout << endl;
    // cout << fenzi1 << " " << fenmu1 << endl;

    nums.clear();
    cin >> n;  
    nums.resize(n + 1);
    for(int i = 0; i <= n; ++i) {
        cin >> nums[i];
    }

    int fenzi2 = 0, fenmu2 = 1;
    calc(nums, fenzi2, fenmu2);
    // copy(nums.begin(), nums.end(), ostream_iterator<int>(cout, " "));
    // cout << endl;
    // cout << fenzi2 << " " << fenmu2 << endl;

    if(fenzi1 * fenmu2 > fenzi2 * fenmu1) {
        cout << ">";
    } else if(fenzi1 * fenmu2  < fenzi2 * fenmu1) {
        cout << "<";
    } else {
        cout << "=";
    }
    cout << endl;

    getchar();
    return 0;
}