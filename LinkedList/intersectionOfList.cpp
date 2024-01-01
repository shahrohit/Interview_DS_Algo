#include <unordered_set>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(const int &x) : val(x), next(nullptr) {}
    ListNode(const int x, ListNode *next) : val(x), next(next) {}
};

// ----------------------- Introduction ------------------------------------------
// Title : Intersection of Two Linked Lists
// LeetCode No : 160
// Difficulty : Easy
// Topics : Linked List, Hash Table, Two Pointer
// Link : https://leetcode.com/problems/intersection-of-two-linked-lists/

// ----------------------- Problem Statement --------------------------------------
// Given the heads of two singly linked-lists headA and headB,
// return the node at which the two lists intersect.
// If the two linked lists have no intersection at all, return null.

// -------------------------- Approach 1  --------------------------------------------
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {

        unordered_set<ListNode *> set;
        ListNode *curr = headA;
        while (curr != nullptr)
        {
            set.insert(curr);
            curr = curr->next;
        }

        curr = headB;
        while (curr != nullptr && set.find(curr) == set.end())
        {
            curr = curr->next;
        }

        return curr;
    }
};
// T.C : O(n)
// S.C : O(n)

// -------------------------- Approach 2 : Slow & Fast pointer-------------------------------------
class Solution
{
public:
    int getLen(ListNode *head)
    {
        int len = 0;
        while (head != nullptr)
        {
            len++;
            head = head->next;
        }
        return len;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        // pointer for headA and headB
        ListNode *currA = headA;
        ListNode *currB = headB;
        // calculate the length of the list
        int lenA = getLen(headA);
        int lenB = getLen(headB);
        int diff = lenA - lenB;
        // making currA always greater than currB in terms of length
        if (diff < 0)
        {
            swap(currA, currB);
            diff = lenB - lenA;
        }
        // traverse the extra length
        for (int i = 0; i < diff; i++)
            currA = currA->next;

        while (currA && currB)
        {
            if (currA == currB)
                return currA;

            currA = currA->next;
            currB = currB->next;
        }
        return nullptr;
    }
};
// T.C : O(n)
// S.C : O(1)