#include <iostream>
#include <vector>
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
        ListNode *dummyHead = new ListNode(0);
        ListNode *current = dummyHead;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0)
        {
            int val1 = (l1 != nullptr) ? l1->val : 0;
            int val2 = (l2 != nullptr) ? l2->val : 0;
            int sum = val1 + val2 + carry;

            carry = sum / 10;
            current->next = new ListNode(sum % 10);
            current = current->next;

            if (l1 != nullptr)
                l1 = l1->next;
            if (l2 != nullptr)
                l2 = l2->next;
        }

        ListNode *result = dummyHead->next;
        delete dummyHead;
        return result;
        // Fin de código compatible con leetcode
    }
};

// Función auxiliar para crear una lista enlazada a partir de un vector.
ListNode *createList(const std::vector<int> &nums)
{
    ListNode *dummyHead = new ListNode(0);
    ListNode *current = dummyHead;
    for (int num : nums)
    {
        current->next = new ListNode(num);
        current = current->next;
    }
    ListNode *result = dummyHead->next;
    delete dummyHead;
    return result;
}

// Función para imprimir una lista enlazada.
void printList(ListNode *head)
{
    while (head != nullptr)
    {
        std::cout << head->val;
        if (head->next != nullptr)
            std::cout << " -> ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main()
{
    Solution sol;

    // Caso de prueba 1
    // Input: l1 = [2,4,3], l2 = [5,6,4]
    // Output: [7,0,8]
    ListNode *l1_1 = createList({2, 4, 3});
    ListNode *l2_1 = createList({5, 6, 4});
    ListNode *result1 = sol.addTwoNumbers(l1_1, l2_1);
    std::cout << "Caso de prueba 1: ";
    printList(result1); // Debería imprimir: 7 -> 0 -> 8

    // Caso de prueba 2
    // Input: l1 = [0], l2 = [0]
    // Output: [0]
    ListNode *l1_2 = createList({0});
    ListNode *l2_2 = createList({0});
    ListNode *result2 = sol.addTwoNumbers(l1_2, l2_2);
    std::cout << "Caso de prueba 2: ";
    printList(result2); // Debería imprimir: 0

    // Caso de prueba 3
    // Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
    // Output: [8,9,9,9,0,0,0,1]
    ListNode *l1_3 = createList({9, 9, 9, 9, 9, 9, 9});
    ListNode *l2_3 = createList({9, 9, 9, 9});
    ListNode *result3 = sol.addTwoNumbers(l1_3, l2_3);
    std::cout << "Caso de prueba 3: ";
    printList(result3); // Debería imprimir: 8 -> 9 -> 9 -> 9 -> 0 -> 0 -> 0 -> 1

    // Caso de prueba 4
    // Input: l1 = [1,8], l2 = [0]
    // Output: [1,8]
    ListNode *l1_4 = createList({1, 8});
    ListNode *l2_4 = createList({0});
    ListNode *result4 = sol.addTwoNumbers(l1_4, l2_4);
    std::cout << "Caso de prueba 4: ";
    printList(result4); // Debería imprimir: 1 -> 8

    // Caso de prueba 5
    // Input: l1 = [5], l2 = [5]
    // Output: [0,1]
    ListNode *l1_5 = createList({5});
    ListNode *l2_5 = createList({5});
    ListNode *result5 = sol.addTwoNumbers(l1_5, l2_5);
    std::cout << "Caso de prueba 5: ";
    printList(result5); // Debería imprimir: 0 -> 1

    return 0;
}