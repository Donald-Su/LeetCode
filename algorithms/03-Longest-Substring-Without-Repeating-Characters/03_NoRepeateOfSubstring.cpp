#include <iostream>
#include <string>

using namespace std;

class Solution
{
  public:
    int lengthOfLongestSubstring(string s)
    {
        int len = s.size();

        string first, second;
        bool first_flag = false; //是否发现重复substring元素
        bool   = false; //是否发现重复substring元素

        for (size_t i = 0; i < len; i++)
        {
            //string::npos = -1
            int first_pos = first.find(s[i]);
            if (first_pos == string::npos && !first_flag)
            {
                //没找到，说明没有重复的
                first += s[i];
            }
            else if (!first_flag && !second_flag)
            {
                /* 出现了重复元素 */
                i = first_pos + 1;
                second = first.substr[first_pos] + s[i];
                first_flag = true;
            }

            int second_pos = second.find(s[i]);
            if (second_pos == string::npos && !second_flag)
            {
               second += s[i];                
            }else if (!second_flag) 
            {
                /* second中出现了重复元素 */
                if(first.size() > second.size())
                {
                    //舍弃second中的元素
                    second.clear();
                    //i = second_pos + 1;
                    second = s[i];
                    second_flag = false;
                }else
                {
                    //舍弃first中的元素
                    first.clear();
                    i = second_pos + 1;
                    first = s[i];
                    first_flag = false;
                    second_flag = true;
                }                
            }           
        }// end for

        
        cout << "first = " << first
             << "; second = " << second << endl;

        return first.size() >= second.size() ? first.size() : second.size();
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

        int ret = Solution().lengthOfLongestSubstring(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}