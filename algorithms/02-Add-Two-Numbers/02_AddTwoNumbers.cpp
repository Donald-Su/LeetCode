#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
*/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode() : val(0), next(NULL) {}
};

class Solution
{
  public:
    // 最开始使用int，后来跑用例[9,9,9,9,9,9,9,9,9,9]    // [9,9,9,9,9,9,9,9,9,9]失败，改为long long
    // 再跑，来了如下的用例，一下子就崩了，说明该方法行不通
    // [2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,9]
    // [5,6,4,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,2,4,3,9,9,9,9]

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *p1 = l1;
        ListNode *p2 = l2;

        ListNode *head = new ListNode(0);
        ListNode *p_ret = head;
        int flag = false; //是否有进位
        while (p1 != NULL && p2 != NULL)
        {
            /* code */
            int temp = p1->val + p2->val;

            //判断上次是否有进位
            if (flag)
            {
                temp += 1;
            }

            //是否有进位，下次使用
            if (temp >= 10)
            {
                flag = true;
            }
            else
            {
                flag = false;
            }

            p_ret->val = temp % 10;

            //这里多了一个节点，需要处理下
            p1 = p1->next;
            p2 = p2->next;

            if (p1 != NULL && p2 != NULL)
            {
                ListNode *new_node = new ListNode(0);
                new_node->next = NULL;
                p_ret->next = new_node;
                p_ret = new_node;
            }
        }

        while (p1 != NULL)
        {

            ListNode *new_node = new ListNode(0);
            new_node->val = p1->val;
            new_node->next = NULL;

            if (flag)
            {
                //连续进位的情况
                int temp = new_node->val + 1;

                if (temp >= 10)
                {
                    flag = true;
                }
                else
                {
                    flag = false;
                }
                new_node->val = temp % 10;
            }

            p_ret->next = new_node;
            p_ret = new_node;

            p1 = p1->next;
        }

        while (p2 != NULL)
        {
            ListNode *new_node = new ListNode(0);
            new_node->val = p2->val;
            new_node->next = NULL;

            if (flag)
            {
                int temp = new_node->val + 1;

                if (temp >= 10)
                {
                    flag = true;
                }
                else
                {
                    flag = false;
                }
                new_node->val = temp % 10;
            }

            p_ret->next = new_node;
            p_ret = new_node;

            p2 = p2->next;
        }

        if (flag)
        {
            ListNode *new_node = new ListNode(0);
            new_node->val = 1;
            new_node->next = NULL;
            p_ret->next = new_node;

            flag = false;
        }

        return head;
    }

    //改变做法，通过链表进行相加减，链表的排列就是低位到高位，可以直接加，有进位也最多进一位
    ListNode *addTwoNumbers_err(ListNode *l1, ListNode *l2)
    {
        ListNode *p1 = l1;
        ListNode *p2 = l2;

        //使用带头结点的
        ListNode *head = NULL;
        ListNode *p_ret = head;
        bool is_head = true;

        int flag = false; //是否有进位
        while (p1 != NULL && p2 != NULL)
        {
            //这里多了一个节点，需要处理下
            ListNode *new_node = new ListNode;
            new_node->next = NULL;

            if (is_head)
            {
                head = new_node;
                is_head = false;
            }
            p_ret = new_node;

            /* code */
            int temp = p1->val + p2->val;

            //判断上次是否有进位
            if (flag)
            {
                temp += 1;
            }

            //是否有进位，下次使用
            if (temp >= 10)
            {
                flag = true;
            }
            else
            {
                flag = false;
            }

            p_ret->val = temp % 10;

            p1 = p1->next;
            p2 = p2->next;
        }

        while (p1 != NULL)
        {

            ListNode *new_node = new ListNode;
            new_node->val = p1->val;
            new_node->next = NULL;

            if (flag)
            {
                new_node->val += 1;
                flag = false;
            }

            p_ret->next = new_node;
            p_ret = new_node;

            p1->next = p1;
        }

        while (p2 != NULL)
        {
            ListNode *new_node = new ListNode;
            new_node->val = p2->val;
            new_node->next = NULL;

            if (flag)
            {
                new_node->val += 1;
                flag = false;
            }

            p_ret->next = new_node;
            p_ret = new_node;

            p2->next = p2;
        }

        return head;
    }

    ListNode *addTwoNumbers_bak(ListNode *l1, ListNode *l2)
    {
        long long firstRet = calNumVal(l1);
        long long secondRet = calNumVal(l2);

        long long sum = firstRet + secondRet;
        printf("%lld + %lld = %lld\n", firstRet, secondRet, sum);

        // ListNode *head = (ListNode*)malloc(sizeof(ListNode));
        ListNode *head = new ListNode(sum % 10);
        // head->val = sum %10;
        sum /= 10;
        ListNode *end = head;

        while (sum != 0)
        {
            // printf("sum = %d\n",sum);
            // ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
            ListNode *newNode = new ListNode(sum % 10);
            // newNode->val = sum %10;
            newNode->next = NULL;
            end->next = newNode;
            end = end->next;
            sum /= 10;
        }

        // end = head;
        // while(end != NULL)
        // {
        //     printf("%d\t",end->val);
        //     end = end->next;
        // }
        return head;
    }

    long long calNumVal(ListNode *l1)
    {
        long long ret = 0;
        long long index = 0;

        ListNode *p = l1;
        while (p != NULL)
        {
            ret += p->val * pow(10, index++);
            p = p->next;
        }
        return ret;
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

ListNode *stringToListNode(string input)
{
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode *dummyRoot = new ListNode(0);
    ListNode *ptr = dummyRoot;
    for (int item : list)
    {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

string listNodeToString(ListNode *node)
{
    if (node == nullptr)
    {
        return "[]";
    }

    string result;
    while (node)
    {
        result += to_string(node->val) + ", ";
        node = node->next;
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main()
{
    string line;
    while (getline(cin, line))
    {
        ListNode *l1 = stringToListNode(line);
        getline(cin, line);
        ListNode *l2 = stringToListNode(line);

        ListNode *ret = Solution().addTwoNumbers(l1, l2);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}