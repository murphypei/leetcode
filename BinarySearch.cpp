#include <iostream>
#include <vector>

using namespace std;

int test() {
    vector<int> nums;
    int target = 2;
    int left = 0;
    int right = nums.size();
    while(left < right) {
        cout << "..." << endl;
        int mid = (left + right) / 2;
        if(nums[mid] < target)
            left = mid + 1;
        else if(nums[mid] > target) {
            right = mid - 1;
        }
        else {
            while(nums[mid] == target) {
                mid++;
            }
            return mid - 1;
        }
    }
    return -1;
}

int main() {

    cout << test();

    getchar();
    return 0;
}