/**
 * 利用分区算法找最小的第K个数
 */

#include <vector>
#include <iostream>
#include <random>
#include <iterator>

using namespace std;

inline int random_idx(int min, int max) {
    random_device rd;       
    return rd() % (max - min) + min;        // rd() 用于产生一个min()和max()之间的随机整数
}

int partition(vector<int> &vec, int beg, int end) {
    cout << beg << " " << end << endl;
    if(beg < 0 && end >= vec.size()) {
        cout << "partition error" << endl;
        return -1;
    }
    int start = beg;
    int small = start - 1;
    swap(vec[random_idx(beg, end)], vec[end]);
    for(int i = start; i <= end; ++i) {
        if(vec[i] < vec[end]) {  
            ++small;
            if(small != i) {
                swap(vec[small], vec[i]); 
            }
        } 
    }
    ++small;
    swap(vec[small], vec[end]);
    cout << "small: " << small << endl;
    return small;
}

int main() {
    vector<int> vec{9, 8, 7, 6, 10, 20, 5, 4, 3, 2, 11, 1};
    int k;
    cin >> k;
    int start = 0;
    int end = vec.size() - 1;
    int idx = partition(vec, start, end);
    while(idx != k) {
        if(k > idx) {
            start = idx;
        } else {
            end = idx;
        }
        idx = partition(vec, start, end);
    }

    std::copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
    cout << vec[idx] << endl;

    return 0;
}