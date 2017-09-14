/**
 * 求数组元素的任意组合：
 * 思路： 假设原有元素 n 个，则最终组合结果是 2n−1 个。我们可以用位操作方法：
 * 假设元素原本有：a,b,c 三个，则 1 表示取该元素，0 表示不取。故取a则是001，
 * 取ab则是011。所以一共三位，每个位上有两个选择 0 和 1。而000没有意义，所以是2n−1个结果。
 */
 
#include <vector>
#include <string>
#include <iostream>

using namespace std;

void Combination(vector<string> &strs)
{
	if(strs.empty())
		return;
	int len = strs.size();
	int n = 1 << len;
	for(int i = 1; i < n; i++)    //从 1 循环到 2^len -1
	{
		for(int j = 0; j < len; j++)
		{
			int temp = i;
			if(temp & (1 << j))   //对应位上为1，则输出对应的字符
			{
				cout << strs.at(j);
			}
		}
		cout << endl;
	}
}

int  main()
{
	vector<string> strs{"a", "b", "c"};
    Combination(strs);
    
    getchar();
    return 0;
}