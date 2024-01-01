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
// Title :  Linked List Cycle
// LeetCode No : 141
// Difficulty : Easy
// Topics : Linked List, Hash Table, Two Pointer
// Link : https://leetcode.com/problems/linked-list-cycle/

// ----------------------- Problem Statement --------------------------------------
// Given head, the head of a linked list, determine if the linked list has a cycle in it.
// There is a cycle in a linked list if there is some node in the list
// that can be reached again by continuously following the next pointer.
// Internally, pos is used to denote the index of the node that tail's next pointer is connected to.
// Note that pos is not passed as a parameter.

// Return true if there is a cycle in the linked list. Otherwise, return false.

// Input: head = [3,2,0,-4], pos = 1
// Output: true
// Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

// -------------------------- Approach 1  --------------------------------------------
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        unordered_set<ListNode *> set;
        ListNode *curr = head;
        while (curr != nullptr)
        {
            if (set.find(curr) != set.end())
                return true;

            set.insert(curr);
            curr = curr->next;
        }
    }
};
// T.C : O(n)
// S.C : O(n)

// -------------------------- Approach 2 : Slow & Fast pointer-------------------------------------
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }
        return false;
    }
};
// T.C : O(n)
// S.C : O(1)