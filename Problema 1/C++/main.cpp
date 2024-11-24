
/**
Given the head of a linked list, remove the nth node from the end of the list and return its head.

Remove Nth Node From End of List

Input: head = [1,2,3,4,5], n = 2

Output: [1,2,3,5]
*/

#include <iostream>  
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

//codigo para leetcode
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

    // lista enlazada a un aray
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

