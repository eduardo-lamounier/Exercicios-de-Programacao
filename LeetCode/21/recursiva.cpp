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
            ListNode *smallest;

            // Casos base:
            if(list1 == nullptr) return list2;
            if(list2 == nullptr) return list1;

            // Inicia com o menor valor:
            if(list1->val < list2->val){
                smallest = list1;
                list1 = list1->next;
            }else{
                smallest = list2;
                list2 = list2->next;
            }
            
            // O segundo valor vai ser o menor para os elementos restantes:
            smallest->next = mergeTwoLists(list1, list2);
            return smallest;
        }
};