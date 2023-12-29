
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(const int &x) : val(x), next(nullptr) {}
    ListNode(const int x, ListNode *next) : val(x), next(next) {}
};

// ----------------------- Introduction ------------------------------------------
// Title : Remove Duplicates from Sorted List
// LeetCode No : 83
// Difficulty : Easy
// Topics : Linked List
// Link : https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/

// ----------------------- Problem Statement --------------------------------------
// Given the head of a sorted linked list, delete all duplicates such that each element appears only once.
// Return the linked list sorted as well.

// Input: head = [1,1,2,3,3]
// Output: [1,2,3]

// ----------------------- Approach 1  --------------------------------------------
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;

        ListNode *curr = head;

        while (curr->next != nullptr)
        {
            if (curr->val == curr->next->val)
            {
                ListNode *temp = curr->next;
                curr->next = curr->next->next;

                temp->next = nullptr;
                delete temp;
            }
            else
            {
                curr = curr->next;
            }
        }
        return head;
    }
};
// T.C : O(n)
// S.C : O(1)