/*
21. Merge Two Sorted Lists - Easy
|https://leetcode.com/problems/merge-two-sorted-lists/
Topics:
|Linked List, Recursion
*/

// ----------------------------------------------------------------------------

// Definição pra a linked list:
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
typedef struct ListNode ListNode;

// ----------------------------------------------------------------------------

class Solution {
    public:
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
            ListNode dummy; // Nó para apontar para o início da nova linked
                            // list
            ListNode *curr_node = &dummy; // Nó atual da nova linked list

            while(list1 != nullptr && list2 != nullptr){
                // Adiciona o menor elemento na nova linked list fazendo o nó
                // atual apontar para ele
                if(list1->val < list2->val){
                    curr_node->next = list1;
                    list1 = list1->next; // Continua a iteração pelos elementos
                                         // da primeira linked list
                }else{
                    curr_node->next = list2;
                    list2 = list2->next; // Continua a iteração pelos elementos
                                         // da segunda linked list
                }
                curr_node = curr_node->next; // Passa para o próximo nó
            }

            if(list1 != nullptr){
                // Adiciona os nós restantes da primeira linked list
                curr_node->next = list1;
            }
            if(list2 != nullptr){
                // Adiciona os nós restantes da segunda linked list
                curr_node->next = list2;
            }

            return dummy.next;
        }
};