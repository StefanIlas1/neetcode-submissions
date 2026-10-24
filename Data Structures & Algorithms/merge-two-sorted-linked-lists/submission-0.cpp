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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
     ListNode dummy(0);
     ListNode* node = &dummy; // stores the address at dummy

     while(list1 && list2) {
        if(list1->val < list2->val){
            node->next = list1;
            list1 = list1->next;
        }
        else {
            node->next = list2;
            list2 = list2->next;
        }
        node = node->next;

     }  
        if(list1) {
            node->next = list1;
        } else {
            node->next = list2;
        }

        return dummy.next;



    }
};