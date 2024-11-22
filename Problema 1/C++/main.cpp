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

/**
Given the head of a linked list, remove the nth node from the end of the list and return its head.

Remove Nth Node From End of List

Input: head = [1,2,3,4,5], n = 2

Output: [1,2,3,5]
*/

#include <iostream>  
#include <cassert>   // para usar assert
using namespace std;

// clse ListNode (nodo de la lista enlazada)
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

//LEETCODE
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* aux = new ListNode(0, head);  
        ListNode* first = aux;  
        ListNode* second = aux;

        for (int i = 0; i < n + 1; i++) {
            if (first == nullptr) return nullptr; 
            first = first->next;
        }

        while (first != nullptr) {
            first = first->next;
            second = second->next;
        }

        second->next = second->next->next;

        return aux->next; 
    }

    // convertir un array en una lista enlazada
    ListNode* list_to_listnode(int arr[], int size) {
        if (size < 1 || size > 30) return nullptr;  
        ListNode* head = new ListNode(arr[0]);
        ListNode* current = head;

        for (int i = 1; i < size; i++) {
            if (arr[i] < 0 || arr[i] > 100) return nullptr;  
            current->next = new ListNode(arr[i]);
            current = current->next;
        }

        return head;
    }

    //convertir una lista enlazada a un aray
    void listnode_to_list(ListNode* node) {
        while (node != nullptr) {
            cout << node->val << " "; 
            node = node->next;
        }
        cout << endl;
    }

    // comparar dos listas enlazadas
    bool areListsEqual(ListNode* list1, ListNode* list2) {
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val != list2->val) {
                return false;  
            }
            list1 = list1->next;
            list2 = list2->next;
        }
        return list1 == nullptr && list2 == nullptr;  
    }
};
// fin leetcode

// pruebas automatizadas
void run_tests(Solution& solution) {
    // Caso 1: Lista normal, eliminar el segundo nodo desde el final
    cout << "Caso 1: ";
    int arr1[] = {1, 2, 3, 4, 5};
    ListNode* head1 = solution.list_to_listnode(arr1, 5);
    ListNode* expected1 = solution.list_to_listnode(arr1, 5);
    expected1 = solution.removeNthFromEnd(expected1, 2);
    head1 = solution.removeNthFromEnd(head1, 2);
    solution.listnode_to_list(head1);  
    assert(solution.areListsEqual(head1, expected1));  

    // Caso 2: Lista con un solo elemento, eliminar ese nodo
    cout << "Caso 2: ";
    int arr2[] = {1};
    ListNode* head2 = solution.list_to_listnode(arr2, 1);
    ListNode* expected2 = nullptr;  
    head2 = solution.removeNthFromEnd(head2, 1);
    solution.listnode_to_list(head2);  
    assert(solution.areListsEqual(head2, expected2)); 

    // Caso 3: Eliminar el primer nodo desde el final
    cout << "Caso 3: ";
    int arr3[] = {1, 2, 3};
    ListNode* head3 = solution.list_to_listnode(arr3, 3);
    ListNode* expected3 = solution.list_to_listnode(arr3, 3);
    expected3 = solution.removeNthFromEnd(expected3, 3);
    head3 = solution.removeNthFromEnd(head3, 3);
    solution.listnode_to_list(head3);  
    assert(solution.areListsEqual(head3, expected3));  

    // Caso 4: Valor n mayor que el tamaño de la lista
    cout << "Caso 4: ";
    int arr4[] = {1, 2, 3};
    ListNode* head4 = solution.list_to_listnode(arr4, 3);
    ListNode* expected4 = solution.list_to_listnode(arr4, 3);  
    head4 = solution.removeNthFromEnd(head4, 4);
    solution.listnode_to_list(head4);  
    assert(solution.areListsEqual(head4, expected4)); 
    // Caso 5: Lista vacía
    cout << "Caso 5: ";
    ListNode* head5 = nullptr;
    ListNode* expected5 = nullptr;  
    head5 = solution.removeNthFromEnd(head5, 1);
    solution.listnode_to_list(head5);  
    assert(solution.areListsEqual(head5, expected5));  

    // Caso 6: Lista con valores extremos
    cout << "Caso 6: ";
    int arr6[] = {0, 100};
    ListNode* head6 = solution.list_to_listnode(arr6, 2);
    ListNode* expected6 = solution.list_to_listnode(arr6, 2);
    expected6 = solution.removeNthFromEnd(expected6, 2);
    head6 = solution.removeNthFromEnd(head6, 2);
    solution.listnode_to_list(head6);  
    assert(solution.areListsEqual(head6, expected6));  
}

// Función principal
int main() {
    Solution solution;
    run_tests(solution);  
    return 0;
}
