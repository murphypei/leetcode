// Given an array of integers and an integer k, 
// ind out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the difference between i and j is at most k.

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> num_mp;
        num_mp.clear();
        
        for(size_t i = 0; i != nums.size(); ++i) {
            if(num_mp.find(nums[i]) != num_mp.end()) {
                if(i - num_mp[nums[i]] <= k)
                    return true;
                else
                    num_mp[nums[i]] = i;
            }
            else {
                num_mp.insert(make_pair(nums[i], i));
            }
                
        }
        
        return false;
    }
};