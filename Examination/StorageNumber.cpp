/**
菜鸟仓库是一个很大很神奇的地方，各种琳琅满目的商品整整齐齐地摆放在一排排货架上，通常一种品类(sku)的商品会放置在货架的某一个格子中，
格子设有统一的编号，方便工人们拣选。 有一天沐哲去菜鸟仓库参观，无意中发现第1个货架格子编码为1，第2-3个分别为1,2，第4-6个格子分别是1，2，3，
第7-10个格子编号分别是1,2,3,4，每个格子编号都是0-9中的一个整数，
且相邻格子的编号连在一起有如下规律 1|12|123|1234|...|123456789101112131415|...|123456789101112131415……n 
*/

#include <iostream>
#include <string>
#include <iterator>

using namespace std;

int main() {
    constexpr long k = 10000;
    int maxIdx = 1;
    int number = 1;
    int result[k] = {0};
    while(number < k) {
        for(int i = 1; i < maxIdx; i++) {
            string s = to_string(i);
            for(auto &c : s) {
                result[number++ - 1] = c - '0';
            }
        }
        maxIdx++;
    }

    std::copy(std::begin(result), std::end(result), ostream_iterator<int>(cout, " "));

    getchar();
    return 0;

}