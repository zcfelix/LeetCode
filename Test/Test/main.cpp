#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include "../../Anagrams.h"
using namespace std;

int main(int argc, const char * argv[])
{
    Solution s;
    vector<string> input{"book", "koob", "kobo", "damn", "mnad", "every"};
    vector<string> ret = s.anagrams(input);
    for (auto i : ret)
        cout << i << endl;
    return 0;
}
