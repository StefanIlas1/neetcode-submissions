/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// introduces initializing a pointer;
// ListNode dummy(0) creates a node with value 0.
// Now we make the pointer to the address of "dummy".
// list1 = list1->next iterates fwd.
// list2 = list2->next iterates fwd.
// node = node->next just iterates the main linked list either way.
// Attach whatever is left over after one of the lists runs out.
// Return a pointer to the head of the linked list;
// the rest of the nodes are accessible because they're all interconnected.

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       ListNode dummy(0);
       ListNode* curr = &dummy;
        //carry --> val = v1 + v2 + carry } > 10 --> 
        int carry = 0;
        while( l1 != nullptr || l2 != nullptr || carry != 0) {
            int v1 = (l1 != nullptr) ? l1->val : 0;
            int v2 = (l2 != nullptr) ? l2->val : 0;

            //Engine --> this is where all the addition happens
            int val = v1 + v2 + carry;
            carry = val / 10; 
            val = val % 10;

            curr->next = new ListNode(val);


            curr = curr->next;
            l1 = (l1 != nullptr) ? l1->next : nullptr;
            l2 = (l2 != nullptr) ? l2->next : nullptr;
        }
        return dummy.next; // this is because we declared an object rather than a pointer.
        //




    }

};