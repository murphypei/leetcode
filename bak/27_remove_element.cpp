// Given an array nums and a value val, remove all instances of that value in-place and return the new length.


class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        for(auto it = nums.begin(); it != nums.end();) {
            if(*it == val) {
                nums.erase(it);
            } else {
                it++;
            }
        }
        return nums.size();
    }
};