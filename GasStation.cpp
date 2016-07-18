// There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

// You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

// Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

// 思路:从某个站点开始(0), 不断的前往下一站点, 遇到不能继续前进的时候, 则将出发站点改变, 然后继续上述前进动作
// 最后判断总的路程是否可达
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0;          // 总的剩余油量
        int current = 0;        // 从出发点到目前的剩余油量
        int begin = -1;
        for(int i = 0; i < gas.size(); ++i){
            total += gas[i] - cost[i];
            current += gas[i] - cost[i];
            if(current < 0) {       // 改变出发点(在出发点之前遍历过的点, 这段路程能够到达)
                begin = i;
                current = 0;
            }
            cout << begin << endl;
        }
        
        return total >= 0 ? begin + 1 : -1; 
    }
};

int main() {
    Solution solution;
    int result;
    int gasArray[] = {0,4,5};
    int costArray[] = {1,2,6};
    vector<int> gas(gasArray, gasArray + sizeof(gasArray) / sizeof(gasArray[0]));  
    vector<int> cost(costArray, costArray + sizeof(costArray) / sizeof(costArray[0]));
    result = solution.canCompleteCircuit(gas,cost);
    printf("Result:%d\n",result);
    getchar();
    return 0;
} 
