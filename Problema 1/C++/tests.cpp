#include <iostream>
#include <cassert>
#include "main.cpp" 

using namespace std;

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

int main() {
    Solution solution;
    run_tests(solution);  
    return 0;
}