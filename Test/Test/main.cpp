#include <iostream>
#include <vector>
#include <algorithm>
#include "../../CombinationSumII.h"
using namespace std;

int main(int argc, const char * argv[])
{
    Solution s;
    vector<int> candidates{1, 1};
    int target = 2;
    vector<vector<int> > ret = s.combinationSum2(candidates, target);
    for (auto i : ret)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
