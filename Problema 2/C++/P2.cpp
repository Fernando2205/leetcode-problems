#include <iostream>
// Definición de la lista enlazada simple.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        // Inicio de código compatible con leetcode
        ListNode *auxiliar_node = new ListNode(0);
        ListNode *actual_node = auxiliar_node;
        int tens = 0;

        while (l1 != nullptr || l2 != nullptr || tens > 0)
        {
            int value1 = (l1 != nullptr) ? l1->val : 0;
            int value2 = (l2 != nullptr) ? l2->val : 0;

            int sum = value1 + value2 + tens;
            tens = sum / 10;

            actual_node->next = new ListNode(sum % 10);
            actual_node = actual_node->next;

            if (l1 != nullptr)
                l1 = l1->next;
            if (l2 != nullptr)
                l2 = l2->next;
        }
        return auxiliar_node->next;
        // Fin de código compatible con leetcode
    }
};
