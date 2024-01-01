
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(const int &x) : val(x), next(nullptr) {}
    ListNode(const int x, ListNode *next) : val(x), next(next) {}
};

// ----------------------- Introduction ------------------------------------------
// Title : Remove Linked List Elements
// LeetCode No : 203
// Difficulty : Easy
// Topics : Linked List
// Link : https://leetcode.com/problems/remove-linked-list-elements/description/

// ----------------------- Problem Statement --------------------------------------
// Given the head of a linked list and an integer val,
// remove all the nodes of the linked list that has Node.val == val, and return the new head.

// Input: head = [1,2,6,3,4,5,6], val = 6
// Output: [1,2,3,4,5]

// ----------------------- Approach 1  --------------------------------------------
class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode *dummy = new ListNode();
        dummy->next = head;
        ListNode *curr = dummy;

        while (curr->next != nullptr)
        {
            if (curr->next->val == val)
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
        head = dummy->next;
        dummy->next = nullptr;
        delete dummy;

        return head;
    }
};
// T.C : O(n)
// S.C : O(1)