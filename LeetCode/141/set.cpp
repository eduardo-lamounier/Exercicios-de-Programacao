#include <unordered_set>

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
            // Armazena os endereços de nós já vistos:
            std::unordered_set<ListNode*> seen{};

            ListNode *curr_node = head;
            while(curr_node != nullptr){
                // Se o nó atual já tiver sido visto, é porque houve um ciclo:
                if(seen.find(curr_node) != seen.end()){
                    return true;
                }

                // Caso contrário, marca esse nó como visto e passa para o
                // próximo:
                seen.insert(curr_node);
                curr_node = curr_node->next;
            }

            return false; // Se a linked list teve um fimn não há ciclos
        }
};