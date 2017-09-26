#include <string>
#include <iostream>

using namespace std;

string trans(string &s, int &i) {
  int cnt = 0;
  string res;
  while(i < s.size()){
  	if(isdigit(s.at(i))) {
    	cnt = s.at(i) - '0';
      i++;
    } else if(s.at(i) == '[') {
    	string tmp = trans(s, ++i);
      for(int j = 0; j < cnt; ++j) {
      	res += tmp;
      }
      cnt = 0;
    } else if(s.at(i) == ']') {
    	i++;
      return res;
    } else {
    	res += s[i++];
    }
  }
  return res;
  }
    	
  int main(int args, char* argv[]) {
  	string sin;
    cin >> sin;
    int idx = 0;
    string res = trans(sin, idx);
    cout << res << endl;
    
    getchar();
    return 0;
  }