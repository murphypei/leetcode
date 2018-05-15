// Remove Duplicates from Sorted Array


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for(auto it = nums.begin(); it != nums.end();) {
            if(it != nums.begin() && *it == *(it-1)) {
                nums.erase(it);
            } 
            else {
                it++;
            }
        }
        return nums.size();
    }
};