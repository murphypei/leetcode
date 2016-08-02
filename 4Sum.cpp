#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#include <iterator>
#include <algorithm>


using namespace std;

// 4 sum 的hash实现
class Solution {
public:
	vector<vector<int> > fourSum(vector<int>& nums, int target) {
		store(nums);
		map<int, vector<pair<int, int> > >::iterator iter_beg = mp.begin();
		map<int, vector<pair<int, int> > >::iterator iter_end = mp.end();
		map<int, vector<pair<int, int> > >::iterator iter1;
		map<int, vector<pair<int, int> > >::iterator iter2;

		vector<int> tmp_vec;
		for(iter1 = iter_beg; iter1 != iter_end; ++iter1) {
			iter2 = mp.find(target - iter1->first);
			
			// 只查找键较大的, 防止重复查找
			if(iter1->first > iter2->first)
				continue;
			
			if(iter2 != iter_end) {
				for(size_t i = 0; i < iter1->second.size(); ++i){
					for(size_t j = 0; j < iter1->second.size(); ++j){
						int a = (iter1->second[i]).first;
						int b = (iter1->second[i]).second;
						int c = (iter2->second[j]).first;
						int d = (iter2->second[j]).second;
						tmp_vec.clear();
						tmp_vec.push_back(a);
						tmp_vec.push_back(b);
						tmp_vec.push_back(c);
						tmp_vec.push_back(d);
						print_vector(tmp_vec);
						result.push_back(tmp_vec);
					}
				}
			}
		}

		return result;

	}
	

	inline void print_vector(vector<int>& nums) const{
		for(int i = 0; i < nums.size(); ++i) {
			cout << nums[i] << "\t";
		}
		cout << endl;
	}


	void store(vector<int>& nums) {
		if(nums.size() < 2)
			return;
		sort(nums.begin(), nums.end());
		for(size_t i = 0; i < nums.size(); ++i) {
			if(i > 0 && nums[i-1] == nums[i])
				continue;
			for(size_t j = i + 1; j < nums.size(); ++j) {
				if(j > i + 1 && nums[j-1] == nums[j])
					continue;
				pair<int, int> p(nums[i], nums[j]);
				mp[nums[i] + nums[j]].push_back(make_pair(nums[i], nums[j]));
			}
		}

		for(size_t i = 0; i < nums.size(); ++i) {
			cnt_map[nums[i]]++;
		}

		print_mp(mp);
	
	}
	

	void print_mp(map<int, vector<pair<int, int> > > &mp) {
		
		map<int, vector<pair<int, int> > >::iterator iter_beg = mp.begin();
		map<int, vector<pair<int, int> > >::iterator iter_end = mp.end();
		map<int, vector<pair<int, int> > >::iterator iter;

		for(iter = iter_beg; iter != iter_end; ++iter) {
			cout << "*SUM = " << iter->first << endl;
			for(size_t i = 0; i < iter->second.size(); ++i) {
				cout << (iter->second)[i].first << "\t" << (iter->second)[i].second << endl;
			}
		}

	}


private:
	vector<vector<int> > result;
	map<int, vector<pair<int, int> > > mp;
	map<int, int> cnt_map;
};

int main() {

	Solution s;

	int array[] = {-2,-1,1,2,0,-2,1};
	int length = sizeof(array) / sizeof(int);
	vector<int> vec(array, array+length);
	int target = 0;

	vector<vector<int> > r = s.fourSum(vec, target);

	getchar();
	return 0;
}
