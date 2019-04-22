#include "../header.h"
#include <stdio.h>
#include <math.h>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) 
    {
        if(x < 0) return false;

        char buff[32] = {0};
        // linux 下没有itoa函数，使用sprintf
        // itoa(x, buff, 10);
        sprintf(buff, "%d", x);
        cout << "buff = " << buff << endl;

        int len = strlen(buff);
        for(int i = 0; i <= len/2; ++i)
        {
            if(buff[i] != buff[len-i-1]) 
                return false;
        }
        return true;
    }

    bool isPalindrome_int(int x) 
    {
        if(x < 0) return false;
        int temp = x;
        long long reverse = 0;
        while(temp)
        {
            reverse = reverse * 10 + temp % 10;
            temp /= 10;
        }

        // cout << "rev = " << reverse << endl;
        return x == reverse;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        int x = stringToInteger(line);
        
        bool ret = Solution().isPalindrome_int(x);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}