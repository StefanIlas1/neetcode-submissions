/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

// PASS 1: Create copies and temporarily store their locations.

// Save the original random target in the copy's next field.
// This is temporary storage, not the copy's final next connection.

// Before overwriting a pointer, preserve its target if we'll need it later.
// Here, the copy's next field preserves the original random target.

// Replace the original node's random pointer with a pointer to its copy.
// We can now find any original node's copy through original->random.

// The original head's random field now points to its copy.
// Save that copy's address as the new list's head.
// We need to remember where the copied list starts before restoring
// the original head's random pointer.

// PASS 2: Set the copied nodes' random pointers.

// Move the traversal pointer back to the first original node.

// Retrieve the current original node's copy using l1->random.
// l2 is a pointer to that existing copy; this does not create another node.

// l2->next currently holds the original random target.
// If that target exists, its random field points to ITS copy.
// Set l2->random to that target's copy; otherwise, set it to nullptr.

// PASS 3: Restore the originals and connect the copies' next pointers.

// Before processing each original node:
// Its random pointer still points to its copy.
// Its copy's next pointer still holds the original random target.

// Retrieve the original node's copy before restoring its random field.

// Restore the original random pointer using the target saved in l2->next.

// If there is a next original node, its random field still points to its copy.
// Connect our copy's next pointer to that next copy.
// If there is no next original node, end the copied list with nullptr.

// Example: l1->next points to B, and l1->next->random points to B'.
// This works because we haven't restored B's random pointer yet.

// Move through the original list using its unchanged next pointers.
// Return the saved head of the copied list.

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) { return nullptr;}
        Node* l1 = head;

        while(l1) {
            Node* l2 = new Node(l1->val);
            l2->next = l1->random;
            l1->random = l2;
            l1 = l1->next;
        }

        Node* newHead = head->random;
        l1 = head;
        
        while(l1) {
            Node* l2 = l1->random;
            l2->random = (l2->next != nullptr) ? l2->next->random : nullptr;
            l1 = l1->next;
        }

        l1 = head;
        while(l1) {
            Node* l2 = l1->random;
            l1->random = l2->next;
            l2->next = (l1->next != nullptr) ? l1->next->random : nullptr;
            l1 = l1->next;
        }

        return newHead;


        
    }
};
