#include <string>
#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

int main() 
{
    string str;
    // getline(cin, str);
    str = "132->2332->332->1988";
    vector<string> nums;
    for(int i = 0; i < str.size();i++) {
        
        if(isdigit(str[i])) {
            int beg = i;
            cout << i << "\t";
            while(isdigit(str[i])) {
                i++;
            } 
            cout << i << "\t";

            cout << str.substr(beg, i - beg) << endl;
            nums.emplace_back(str.substr(beg, i-beg));
        }
    }
    cout << "***" << endl;
    std::copy(nums.begin(), nums.end(), ostream_iterator<string>(cout, " "));
    cout << "***" << endl;

    if(nums.size() % 2 == 0) {
        for(int i = 1; i < nums.size(); i+=2) {
            cout << nums[i] << "->" << nums[i-1];
            if( i < nums.size() - 1) {
                cout << "->";
            }
        }
    }
    else {
        for(int i = 1; i < nums.size(); i+=2) {
            cout << nums[i] << "->" << nums[i-1] << "->";
        }
        cout << nums[nums.size()-1];
    }

    getchar();
    return 0;
}