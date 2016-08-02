#include <iostream>
#include <vector>
#include <cstdio>


using namespace std;

class Solution_kSum {

public:
	vector<vector<int> >& FourSum(vector<int>& nums, int target) {
		
		if(nums.empty() || nums.size() < 4) {
			return result;
		}
		
		quickSort(nums, 0, nums.size());
		print_vector(nums);
		
		for(size_t i = 0; i < nums.size(); ++i){
			if(i > 0 && nums[i] == nums[i-1])
				continue;
			int choosen = nums[i];
			
			vector<int> tmp_nums(nums.begin()+i, nums.end());
			vector<vector<int> > tmp_result = findThree(tmp_nums, target-choosen);
			
			for(size_t idx = 0; idx < tmp_result.size(); ++idx) {
				tmp_result[idx].push_back(choosen);
				result.push_back(tmp_result[idx]);
			}
		}

		return result;
	}
	
	
	vector<vector<int> > findThree(vector<int>& nums, int target) {
		vector<int> tmp;
		vector<vector<int> > res;
		res.clear();
		


		if(nums.empty() || nums.size() < 3) {
			return res;
		}
		
		for(size_t i = 0; i < nums.size(); ++i){
			if(i > 0 && nums[i] == nums[i-1])
				continue;
			int choosen = nums[i];
			
			vector<int> tmp_nums(nums.begin()+i, nums.end());
			
			vector<vector<int> > tmp_result = findTwo(tmp_nums, target-choosen);
			
			for(size_t idx = 0; idx < tmp_result.size(); ++idx) {
				tmp_result[idx].push_back(choosen);
				res.push_back(tmp_result[idx]);
			}
		}

		return res;

	}
	
	
	vector<vector<int> >& ThreeSum(vector<int>& nums, int target) {
		if(nums.empty() || nums.size() < 3) {
			return result;
		}
		
		quickSort(nums, 0, nums.size());
		print_vector(nums);
		
		for(size_t i = 0; i < nums.size(); ++i){
			if(i > 0 && nums[i] == nums[i-1])
				continue;
			int choosen = nums[i];
			
			vector<int> tmp_nums(nums.begin()+i, nums.end());
			vector<vector<int> > tmp_result = findTwo(tmp_nums, target-choosen);
			
			for(size_t idx = 0; idx < tmp_result.size(); ++idx) {
				tmp_result[idx].push_back(choosen);
				result.push_back(tmp_result[idx]);
			}
		}

		return result;
	}
	
	
	vector<vector<int> >& TwoSum(vector<int>& nums, int target) {
		
		quickSort(nums, 0, nums.size());
		print_vector(nums);

		result = findTwo(nums, target);
		return result;
	}


	// 基本的二元寻找，给定有序数组，寻找相加等于target的值
	vector<vector<int> > findTwo(vector<int>& nums, int target) {
		vector<int> tmp;
		vector<vector<int> > res;
		res.clear();

		if(nums.empty() || nums.size() < 2) {
			return res;
		}

		size_t low = 0;
		size_t high = nums.size() - 1;

		while(low < high) {
			if(nums[low]+nums[high] == target) {
				tmp.clear();
				tmp.push_back(nums[low]);
				tmp.push_back(nums[high]);
				res.push_back(tmp);
				print_vector(tmp);
				tmp.clear();
				while(nums[low+1] == nums[low] && low < high) 
					low++;
				while(nums[high-1] == nums[high] && high > low) 
					high--;
				low++;
				high--;
			}
			else if(nums[low] + nums[high] > target) 
				high--;
			else 
				low++;
		}

		return res;
	}
	
	
	inline void print_vector(vector<int>& nums) const{
		for(int i = 0; i < nums.size(); ++i) {
			cout << nums[i] << "\t";
		}
		cout << endl;
	}


	void quickSort(vector<int>& nums, int begin, int end) {
		if(end - begin <= 1)
			return;

		//cout << begin << "\t" << end << endl;
		int low = begin, high = end;
		int key_idx = low;	// 记录key值位置
		
		while(low < high) {
			while(--high > low) {
				if(nums[high] <= nums[key_idx]) { 
					swap(nums[high], nums[key_idx]);
					key_idx = high;
					break;
				}
			}

			while(++low < high) {
				if(nums[low] >= nums[key_idx]) {
					swap(nums[low], nums[key_idx]);
					key_idx = low;
					break;
				}
			}
		}
		//cout << "###" << key_idx << endl;
		//cout << "****" << low  << "\t" << high << endl;
		//print_vector(nums);
		quickSort(nums, begin, low);
		quickSort(nums, low, end);
	}


	inline void swap(int &a, int &b){
		int tmp = a;
		a = b;
		b = tmp;
	}

private:
	vector<vector<int> > result;
};


int main() {
	vector<vector<int> > res;
	Solution_kSum sk;
	int target = 2;

	int array[] = {1,-1,-1,1,2,0,-2,3};
	int length = sizeof(array) / sizeof(int);
	vector<int> vec(array, array+length);
	
	res = sk.FourSum(vec, 0);
	
	cout << "result: " << endl;
	for(int i = 0; i < res.size(); ++i) {
		sk.print_vector(res[i]);
	}
	
	cout << "run successfully!" << endl;
	getchar();
	return 0;
}

	

