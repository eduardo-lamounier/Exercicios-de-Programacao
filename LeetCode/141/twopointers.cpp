/*
141. Linked List Cycle - Easy
|https://leetcode.com/problems/linked-list-cycle/description/
Topics:
|Hast Table, Linked List, Two Pointers
*/

// ----------------------------------------------------------------------------

// Definição para a linked list:
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
typedef struct ListNode ListNode;

// ----------------------------------------------------------------------------

class Solution {
    public:
        bool hasCycle(ListNode *head) {
            ListNode *slow = head, // Avança uma posição por vez 
            *fast = head; // Avança duas posições por vez

            while(fast != nullptr && fast->next != nullptr){
                slow = slow->next;
                fast = fast->next->next;

                // Se fast alcançar slow, fast deu uma volta pela linked list:
                if(slow == fast) return true;
            }

            return false; // Fast chegou ao fim da linked list
        }
};