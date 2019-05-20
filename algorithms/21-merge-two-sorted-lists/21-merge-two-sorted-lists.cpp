#include "../header.h"
#include <sstream>
// #include <fstream>

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

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution
{
public:
	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
	{
		if (l1 == NULL)
			return l2;
		if (l2 == NULL)
			return l1;

		ListNode *head, *p;
		head = p = NULL;
		bool isHead = true; // 单独处理head
		while (l1 != NULL && l2 != NULL)
		{
			if (l1->val <= l2->val)
			{
				if (isHead)
				{
					p = l1;
					head = p;
					isHead = false;
					l1 = l1->next;
				}
				else
				{
					p->next = l1;
					p = p->next;
					l1 = l1->next;
				}
			}
			else
			{
				if (isHead)
				{
					p = l2;
					head = p;
					l2 = l2->next;
					isHead = false;
				}
				else
				{
					p->next = l2;
					p = p->next;
					l2 = l2->next;
				}
			}
		} // end while

		if (l1 != NULL)
		{
			if (isHead)
			{
				p = l1;
				head = p;
				l1 = l1->next;
				isHead = false;
			}
			else
			{
				p->next = l1;
				l1 = l1->next;
				p = p->next;
			}
		}

		while (l2 != NULL)
		{
			if (isHead)
			{
				p = l2;
				head = p;
				l2 = l2->next;
				isHead = false;
			}
			else
			{
				p->next = l2;
				p = p->next;
				l2 = l2->next;
			}
		}

		return head;
	}

	ListNode *mergeTwoLists_head(ListNode *l1, ListNode *l2)
	{
		if (l1 == NULL) return l2;
		if (l2 == NULL) return l1;

		ListNode head(0);
		ListNode *p = &head;
		while (l1 != NULL && l2 != NULL)
		{
			if (l1->val <= l2->val)
			{
				p->next = l1;
				l1 = l1->next;
			}
			else
			{
				p->next = l2;
				l2 = l2->next;
			}
			p = p->next;

		} // end while

		if (l1 != NULL)
			p->next = l1;
		if (l2 != NULL)
			p->next = l2;
		
		return head.next;
	}

}

ListNode *mergeTwoLists_recursion(ListNode *l1, ListNode *l2)
{
	if (l1 == NULL)
		return l2;
	if (l2 == NULL)
		return l1;

	if (l1->val <= l2->val)
	{
		l1->next = mergeTwoLists_recursion(l1->next, l2);
		return l1;
	}
	else
	{
		l2->next = mergeTwoLists_recursion(l1, l2->next);
		return l2;
	}
}
}
;

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

		ListNode *ret = Solution().mergeTwoLists_recursion(l1, l2);

		string out = listNodeToString(ret);
		cout << out << endl;
	}
	return 0;
}