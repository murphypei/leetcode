class Solution {
public:
  bool isScramble(string s1, string s2) {
    // printf("s1: %s | s2: %s\n", s1.c_str(), s2.c_str());
    if (s1.size() != s2.size()) {
      return false;
    }
    // 两个字符串直接相等
    if (s1 == s2) {
      return true;
    }
    for (int mid = 1; mid < s1.size(); mid++) {
      // 两个字符串的前半部分和后半部分都符合条件
      // 或者s1的前半部分和s2的后半部分符合调教，同时s1的后半部分和s2的前半部分符合条件
      if ((isScramble(s1.substr(0, mid), s2.substr(0, mid)) &&
           isScramble(s1.substr(mid, s1.size() - mid),
                      s2.substr(mid, s1.size() - mid))) ||
          (isScramble(s1.substr(0, mid), s2.substr(s1.size() - mid, mid)) &&
           isScramble(s1.substr(mid, s1.size() - mid),
                      s2.substr(0, s1.size() - mid)))) {
        return true;
      }
    }
    return false;
  }
};