#include "../include.h"

using namespace std;

class Solution {
public:
    int reverse(int x) 
    {
        //Line 9: Char 15: runtime error: negation of -2147483648 cannot be represented in type 'int'; cast to an unsigned type to negate this value to itself (solution.cpp)
       /* bool isMinus = false;
        if (x < 0) 
        {
            isMinus = true;   
            x = -x;         
        }*/
        long long ret = 0;

        // while(x % 10 != 0 )
        while(x)
        {           
            ret = ret * 10 + x % 10;
            x  = x / 10;
        }
        
        // if (isMinus)
        // {
        //     ret = - ret;
        // }
        
        return (ret > INT_MAX || ret < INT_MIN) ? 0: ret;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int x = stringToInteger(line);
        
        int ret = Solution().reverse(x);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}