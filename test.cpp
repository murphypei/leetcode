#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v{1,2,3,4,5,6,7,8,8,9,9,0};
    for(auto it = v.begin(); it != v.end();)
    {
        cout << *it << endl;
        it = v.erase(it);
    }

    getchar();
    return 0;
}
