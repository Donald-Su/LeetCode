#include "../header.h"
using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {
        int ret = 0;
        for (size_t i = 0; i < s.size(); i++)
        {
            /* code */
            switch (s[i])
            {
                //I = 1; V = 5; X = 10; L = 50; C = 100; D = 500; M = 1000
            case 'I':
                ret += 1;
                break;

                //I = 1; V = 5; X = 10; L = 50; C = 100; D = 500; M = 1000
            case 'V':
                ret += 5;

                if (s[i - 1] == 'I')
                {
                    //IV的这种情况需要恢复
                    ret -= 2;
                }
                break;
                //I = 1; V = 5; X = 10; L = 50; C = 100; D = 500; M = 1000
            case 'X':
                ret += 10;
                if (s[i - 1] == 'I')
                {
                    //IX的这种情况需要恢复
                    ret -= 2;
                }
                break;

                //I = 1; V = 5; X = 10; L = 50; C = 100; D = 500; M = 1000
            case 'L':
                ret += 50;
                if (s[i - 1] == 'X')
                {
                    //XL的这种情况需要恢复
                    ret -= 20;
                }
                break;

                //I = 1; V = 5; X = 10; L = 50; C = 100; D = 500; M = 1000
            case 'C':
                ret += 100;
                if (s[i - 1] == 'X')
                {
                    //XC的这种情况需要恢复
                    ret -= 20;
                }
                break;

                //I = 1; V = 5; X = 10; L = 50; C = 100; D = 500; M = 1000
            case 'D':
                ret += 500;
                if (s[i - 1] == 'C')
                {
                    //CD的这种情况需要恢复
                    ret -= 200;
                }
                break;

                //I = 1; V = 5; X = 10; L = 50; C = 100; D = 500; M = 1000
            case 'M':
                ret += 1000;
                if (s[i - 1] == 'C')
                {
                    //CM的这种情况需要恢复
                    ret -= 200;
                }
                break;

            default:
                return 0;
            }//end switch
        }//end for

        if (ret > 3999)
        {
            ret = 3999;
        }
        
        return ret;
    }
};

string stringToString(string input)
{
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() - 1; i++)
    {
        char currentChar = input[i];
        if (input[i] == '\\')
        {
            char nextChar = input[i + 1];
            switch (nextChar)
            {
            case '\"':
                result.push_back('\"');
                break;
            case '/':
                result.push_back('/');
                break;
            case '\\':
                result.push_back('\\');
                break;
            case 'b':
                result.push_back('\b');
                break;
            case 'f':
                result.push_back('\f');
                break;
            case 'r':
                result.push_back('\r');
                break;
            case 'n':
                result.push_back('\n');
                break;
            case 't':
                result.push_back('\t');
                break;
            default:
                break;
            }
            i++;
        }
        else
        {
            result.push_back(currentChar);
        }
    }
    return result;
}

int main()
{
    string line;
    while (getline(cin, line))
    {
        string s = stringToString(line);

        int ret = Solution().romanToInt(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}