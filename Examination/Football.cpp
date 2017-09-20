#include <map>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

typedef pair<string, int> PAIR;  

bool cmp_by_value(const PAIR& lhs, const PAIR& rhs) {  
    return lhs.second > rhs.second;  
} 

int main() {

    int n;
    while(cin >> n) {
        map<string, int> jifen_mp;
        map<string, int> jingshengqiu_mp;
        map<string, int> jinqiu_mp;
        string str;
        for(int i = 0; i < n; ++i) {
            cin >> str;
            jifen_mp[str] = 0;
            jingshengqiu_mp[str] = 0;
            jinqiu_mp[str] = 0;
        }

        for(int i = 0; i < n * (n-1) / 2; ++i) {
            cin >> str;
            size_t it = str.find("-");
            string s1 = str.substr(0, it);
            string s2 = str.substr(it+1);
            // cout << s1 << endl;
            // cout << s2 << endl;

            string sscore;
            cin >> sscore;
            it = sscore.find(":");
            int i1 = stoi(sscore.substr(0, it));
            int i2 = stoi(sscore.substr(it+1));
            // cout << i1 << endl;
            // cout << i2 << endl;

            if(i1 == i2) {
                jifen_mp[s1] += 1;
                jifen_mp[s2] += 1;
            } else if (i1 > i2) {
                jifen_mp[s1] += 3;
            } else {
                jifen_mp[s2] += 3;
            }
            jinqiu_mp[s1] += i1;
            jinqiu_mp[s2] += i2;
            jingshengqiu_mp[s1] += (i1 - i2);
            jingshengqiu_mp[s2] += (i2 - i1);
        }

        vector<PAIR> jifen_sort_vec(jifen_mp.begin(), jifen_mp.end());  
        std::sort(jifen_sort_vec.begin(), jifen_sort_vec.end(), cmp_by_value);  

        for(int i = 0; i < n; ++i) {
            int k = i;
            string s1 = jifen_sort_vec[i].first;
            for(int j = i + 1; j < n; ++j) {
                string s2 = jifen_sort_vec[j].first;
                if(jifen_sort_vec[k].second == jifen_sort_vec[j].second && jingshengqiu_mp[s1] == jingshengqiu_mp[s2]) {
                    if(jinqiu_mp[s1] < jinqiu_mp[s2]) {
                        k = j;
                    } else if (jifen_sort_vec[k].second == jifen_sort_vec[j].second && jingshengqiu_mp[s1] < jingshengqiu_mp[s2]) {
                        k = j;
                    }
                }
            }
            if(i != k) {
                auto t = jifen_sort_vec[i];
                jifen_sort_vec[i] = jifen_sort_vec[k];
                jifen_sort_vec[k] = t;
            }
        }

        for (int i = 0; i < n / 2; ++i) {
            cout << jifen_sort_vec[i].first << endl;
        }
        
    }

    getchar();
    return 0;
}
