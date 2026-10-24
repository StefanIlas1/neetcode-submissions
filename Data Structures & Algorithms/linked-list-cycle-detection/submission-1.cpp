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

class Solution {
public:
    bool hasCycle(ListNode* head) {
        //the way to do this question is through a fast and a slow pointer which means that one pointer is going to be moving at a normal loop index rate so ++, while the other one will be moving twice as fast.
        //By doing so we can effectively see what's ahead, and if there's a loop the fast pointer will circle behind the slow pointer and eventually they will have that same address.
        //Another factor is that the fast poitner will never get to the nullptr...
        ListNode* slow = head; 
        ListNode* fast = head;
        //we just start at head, becuase there can be no node here and if there's no node adn we start with head->next then there's nothing pointing so it ruins the instantiation.
        //If there was one node, the next can contain nullptr adn it could work

        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next; // itterating through 
            fast = fast->next->next;
            if(fast == slow) { // if there's a cycle the memory addresses will match
                return true;
            }
        }
        return false;
        
    }
};
