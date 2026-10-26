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
 //we're given the head, integer n remove nth node FROM THE END OF THE LIST
 // then return head... 

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0, head); // starts us at 0 --> giving us a little bit more room for our left pointer
        ListNode* left = &dummy;
        ListNode* right = head;

        while(n > 0) {
            right = right->next;
            n--;
        }

        while(right != nullptr) {
            left = left->next;
            right = right->next;
        }

        left->next = left->next->next;
        return dummy.next;



        
    }
};
