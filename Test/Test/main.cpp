#include <iostream>
#include <vector>
#include "../../4Sum.h"
using namespace std;

int main(int argc, const char * argv[])
{
    Solution s;
    vector<int> g{1, 1, 1, 0};
    vector<vector<int> > r = s.fourSum(g, 1);
    return 0;
}
