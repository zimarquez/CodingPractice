#include <iostream>
#include <cstdio>
#include <stack>
#include <vector>
#include <math.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp = new ListNode(0);
        ListNode* orig = temp;
        int carry = 0;
        int digit = 1;
        while (l1 != nullptr || l2 != nullptr || carry != 0)
        {
            long value1 = 0;
            if (l1 != nullptr)
            {
                value1 = l1->val;
                l1 = l1->next;
            }
            long value2 = 0;
            if (l2 != nullptr)
            {
                value2 = l2->val;
                l2 = l2->next;
            }
            //cout << "L1: " << value1 << endl;
            //cout << "L2: " << value2 << endl;
            cout << "Digit: " << digit << endl;
            digit++;

            int sum = value1 + value2 + carry;
            carry = sum / 10;
            sum = sum % 10;
            cout << "sum: " << sum << endl;
            cout << "carry: " << carry << endl;
            cout << endl;
            temp->next = new ListNode(sum);
            temp = temp->next;
        }
        return orig->next;
    }
};

ListNode* fillList(ListNode* list, vector<int> nums)
{
    ListNode* temp = new ListNode(nums[0]);
    ListNode* orig = temp;
    for (int i = 1; i < nums.size(); i++)
    {
        temp->next = new ListNode(nums[i]);
        temp = temp->next;
    }
    //cout << orig->next << endl;
    return orig;
}

void printList(ListNode* list)
{
    while (list != nullptr)
    {
        cout << list->val << ", ";
        list = list->next;
    }
    cout << endl;
}

int main()
{
    Solution s;
    ListNode* l1;
    ListNode* l2;
    vector<int> v1{9};
    vector<int> v2{1,9,9,9,9,9,9,9,9,9};
    l1 = fillList(l1, v1);
    l2 = fillList(l2, v2);
    printList(l1);
    printList(l2);
    //cout << s.bar(l1,l2) << endl;
    //cout << "Done" << endl;
    ListNode* l3 = s.addTwoNumbers(l1,l2);
    printList(l3);

    return 0;
}