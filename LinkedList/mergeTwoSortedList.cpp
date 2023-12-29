
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(const int &x) : val(x), next(nullptr) {}
    ListNode(const int x, ListNode *next) : val(x), next(next) {}
};

// ----------------------- Introduction ------------------------------------------
// Title : Merge Two Sorted Lists
// LeetCode No : 21
// Difficulty : Easy
// Topics : Linked List
// Link : https://leetcode.com/problems/merge-two-sorted-lists/description/

// ----------------------- Problem Statement --------------------------------------
// You are given the heads of two sorted linked lists list1 and list2.
// Merge the two lists into one sorted list.
// The list should be made by splicing together the nodes of the first two lists.

// Return the head of the merged linked list.

// Input: list1 = [1,2,4], list2 = [1,3,4]
// Output: [1,1,2,3,4,4]

// ----------------------- Approach 1  --------------------------------------------
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == nullptr)
            return list2;

        if (list2 = nullptr)
            return list1;

        ListNode *dummy = new ListNode();
        ListNode *list3 = dummy;

        while (list1 != nullptr && list2 != nullptr)
        {
            ListNode *newNode = new ListNode();
            if (list1->val <= list2->val)
            {
                newNode->val = list1->val;
                list1 = list1->next;
            }
            else
            {
                newNode->val = list2->val;
                list2 = list2->next;
            }
            list3->next = newNode;
            list3 = list3->next;
        }

        if (list1 != nullptr)
            list3->next = list1;

        if (list2 != nullptr)
            list3->next = list2;

        list3 = dummy->next;
        delete dummy;

        return list3;
    }
};
// T.C : O(n)
// S.C : O(1)