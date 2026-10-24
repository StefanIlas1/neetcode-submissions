/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// Split the linked list down the middle using slow and fast pointers.
// Reverse the second half, then alternate between the two lists:
// first, last, second, second last, and so on.
// This takes O(n) time.

// A ListNode* stores the address of a node.
// Move slow one step and fast two steps to find the middle.

// Store slow->next in second before separating the two halves.
// This keeps the second half accessible after cutting the connection.

// slow->next = nullptr cuts the connection between the halves.
// ListNode* prev = nullptr creates a pointer that points to nothing.
// It does not remove a node or change node 4's "previous" pointer.
// A singly-linked node only has a next pointer.

// Reverse the second half:
// Save second->next in tmp so we don't lose the remaining nodes.
// Point second->next at prev to reverse the current arrow.
// Move prev to second.
// Move second to tmp to process the next node.
// Stop when second becomes nullptr.
// prev now points to the head of the reversed second half.

// Weaving step:
// first starts at head.
// second starts at prev, the head of the reversed second half.

// Save first->next in tmp1 and second->next in tmp2.
// Point first->next at second.
// Point second->next at tmp1 to connect back to the first half.
// Move first to tmp1 and second to tmp2.
// Continue until second points to nullptr.

class Solution {
public:
    void reorderList(ListNode* head) {
        //1. find middle
        //2. split list
        //3. sort second half of list --> reverse
        //4. weave between the two ends of the list 

        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next; //we're indexing the middle
            fast = fast->next->next;
        }

        ListNode* second = slow->next;
        ListNode* prev = slow->next = nullptr;
        //slow->next = nullptr;
        //ListNode* prev = nullptr;
        while(second != nullptr) {
            ListNode* tmp = second->next;
            second->next = prev;
            prev = second;
            second = tmp;
        }

        //weaving step as i like to call it:
        ListNode* first = head;
        second = prev;
        while(second != nullptr) {
            ListNode* tmp1 = first->next;
            ListNode* tmp2 = second->next;
            first->next = second;
            second->next = tmp1;

            first = tmp1;
            second = tmp2;
        }
    }
};