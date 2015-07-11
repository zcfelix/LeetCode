#include <iostream>
#include <vector>
#include "../../BasicCalculatorII.h"
using namespace std;

int main(int argc, const char * argv[])
{
    Solution s;
    string input = "0-2147483648";
    cout << s.calculate(input) << endl;
    return 0;
}
