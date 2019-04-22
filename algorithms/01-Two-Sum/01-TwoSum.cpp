#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#include <algorithm>

using namespace std;

class Solution
{
  public:
    vector<int> twoSum_lowPerformance(vector<int> &nums, int target)
    {
        int nFirstPos = 0;
        int nSecondPos = 0;
        int nLen = nums.size();

        for (int i = 0; i < nLen; i++)
        {
            for (int j = 0; j < nLen; j++)
            {
                //i，j不能一样
                if (i != j)
                {
                    int temp = nums[i] + nums[j];
                    if (temp == target)
                    {
                        if (i < j)
                        {
                            nFirstPos = i;
                            nSecondPos = j;
                            break;
                        }
                        else if (i > j)
                        {
                            nFirstPos = j;
                            nSecondPos = i;
                            break;
                        }
                    }
                }
            }
        }

        vector<int> vecRet;

        if (nFirstPos != nSecondPos)
        {
            vecRet.push_back(nFirstPos);
            vecRet.push_back(nSecondPos);
            return vecRet;
        }
        else
        {
            return vecRet;
        }
    }

    //先排序
    //target - first，然后在已有的数据中进行二分查找
    // 不能这么操作，不然顺序已经改变了，后面再检测到的下标已经无效
    vector<int> twoSum_err(vector<int> &nums, int target)
    {
        int nFirstPos = 0;
        int nSecondPos = 0;
        int nLen = nums.size();

        sort(nums.begin(), nums.end(), less<int>());

        for (int i = 0; i < nLen; i++)
        {
            int temp = target - nums[i];
            std::cout << "temp = " << temp << endl;

            //这样寻找有问题
            vector<int>::iterator index = lower_bound(nums.begin(), nums.end(), temp);

            if (index != nums.end())
            {
                nFirstPos = i;
                nSecondPos = index - nums.begin();
                break;
            }
        }

        vector<int> vecRet;
        if (nFirstPos != nSecondPos)
        {
            vecRet.push_back(nFirstPos);
            vecRet.push_back(nSecondPos);
            return vecRet;
        }
        else
        {
            return vecRet;
        }
    }

    //target - first，然后在已有的数据中遍历查找
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int nFirstPos = 0;
        int nSecondPos = 0;
        int nLen = nums.size();
        vector<int> vecRet;

        for (int i = 0; i < nLen; i++)
        {
            int temp = target - nums[i];

            for (int j = i + 1; j < nLen; j++)
            {
                // printf("i = %d,j = %d,temp = %d, tartget = %d\n", i, j, temp, target);
                if (temp == nums[j])
                {
                    nFirstPos = i;
                    nSecondPos = j;
                    //break; //仅有一个break只能跳出一个for循环，外围的for不能跳出
                           // 所以这里要么使用goto，要么直接return。
                    //    由于return报错，所以采用goto方式
                    if (nFirstPos != nSecondPos)
                    {
                        vecRet.push_back(nFirstPos);
                        vecRet.push_back(nSecondPos);
                        goto end;
                    }
                }
            }
        }
    end:
        return vecRet;
    }
};

void trimLeftTrailingSpaces(string &input)
{
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
                    return !isspace(ch);
                }));
}

void trimRightTrailingSpaces(string &input)
{
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
                    return !isspace(ch);
                })
                    .base(),
                input.end());
}

vector<int> stringToIntegerVector(string input)
{
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim))
    {
        output.push_back(stoi(item));
    }
    return output;
}

int stringToInteger(string input)
{
    return stoi(input);
}

string integerVectorToString(vector<int> list, int length = -1)
{
    if (length == -1)
    {
        length = list.size();
    }

    if (length == 0)
    {
        return "[]";
    }

    string result;
    for (int index = 0; index < length; index++)
    {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main()
{
    string line;
    while (getline(cin, line))
    {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int target = stringToInteger(line);

        vector<int> ret = Solution().twoSum(nums, target);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}