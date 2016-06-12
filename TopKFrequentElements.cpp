// Top K Frequent Elements 
// Given a non-empty array of integers, return the k most frequent elements.

// For example,
// Given [1,1,1,2,2,3] and k = 2, return [1,2].

// Note: 
// You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
// Your algorithm's time complexity must be better than O(n log n), where n is the array's size.



class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        map<int, int> num_frequent_map;
        vector< pair<int, int> > num_frequent_vec;
        
        // sort
        heapSort(nums);
        // count frequent of every number
        frequentMapInit(nums, num_frequent_map);
        // sort frequent
        sortMapByValue(num_frequent_map, num_frequent_vec);

        // get the Top K frequent of number
        for(int index = 0; index != k ; ++index)
            result.push_back(num_frequent_vec[index].first);

        return result;
    }
    
    // compare two pair by second element
    static bool isGreater(const pair<int,int> &x, const pair<int,int> &y)
    {
        return x.second > y.second;
    }
    

    void sortMapByValue(map<int, int> &frequent_map, vector< pair<int, int> > &frequent_vec)
    {
        for(map<int, int>::const_iterator iter = frequent_map.begin(); iter != frequent_map.end(); ++iter)
            frequent_vec.push_back(*iter);

        stable_sort(frequent_vec.begin(), frequent_vec.end(), isGreater);
    }

     void frequentMapInit(vector<int>& nums, map<int, int>& frequent)
    {
        for(int i = 0; i < nums.size(); ++i)
        {
            if(frequent.count(nums[i]) == 0)
                frequent[nums[i]] = 1;
            else
                frequent[nums[i]]++;
        }
    }
    
    
    
    void heapSort(vector<int>& nums)
    {
        size_t length = nums.size();
        buildHeap(nums);
        for(size_t i = nums.size() - 1;  i > 0; --i)
        {
            
            swap(nums[0], nums[i]);
            percolateDown(nums, 0, i);
        }
            
    }
    
    void buildHeap(vector<int>& nums)
    {
        for(size_t i = nums.size() / 2; i < nums.size() && i >= 0; i--)
        {
            percolateDown(nums, i, nums.size());
        }
    }
    
    void percolateDown(vector<int>& nums, size_t hole, size_t length)
    {
        int child;
        int tmp = nums[hole];
        for(; hole * 2 + 1 < length; hole = child)
        {
            child = hole * 2 + 1;   // left child
            if(child + 1 < length && nums[child+1] < nums[child])
            {
                child++;
            }
            if(nums[child] < tmp)
            {
                nums[hole] = nums[child];
            }
            else
                break;
        }
        nums[hole] = tmp;
    }
    
    
    void swap(int &a, int &b)
    {
        int tmp = a;
        a = b;
        b = tmp;
        
    }
    
};