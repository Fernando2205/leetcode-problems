// test_p2.cpp
#include "P2.cpp"
#include <iostream>
#include <vector>
#include <iomanip>

struct TestCase
{
    std::vector<int> l1;
    std::vector<int> l2;
    std::vector<int> expected;
    std::string description;
};

std::vector<int> listToVector(ListNode *head)
{
    std::vector<int> result;
    while (head != nullptr)
    {
        result.push_back(head->val);
        head = head->next;
    }
    return result;
}

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

void runTests()
{
    std::vector<TestCase> testCases = {
        {{2, 4, 3}, {5, 6, 4}, {7, 0, 8}, "342 + 465 = 807"},
        {{0}, {0}, {0}, "0 + 0 = 0"},
        {{9, 9, 9, 9, 9, 9, 9}, {9, 9, 9, 9}, {8, 9, 9, 9, 0, 0, 0, 1}, "9999999 + 9999 = 10009998"},
        {{1, 8}, {0}, {1, 8}, "81 + 0 = 81"},
        {{5}, {5}, {0, 1}, "5 + 5 = 10"}};

    Solution solution;
    int passed = 0;

    std::cout << "\nRunning " << testCases.size() << " tests:\n\n";

    for (size_t i = 0; i < testCases.size(); i++)
    {
        const auto &tc = testCases[i];
        ListNode *l1 = createList(tc.l1);
        ListNode *l2 = createList(tc.l2);
        ListNode *result = solution.addTwoNumbers(l1, l2);
        std::vector<int> actual = listToVector(result);

        bool success = actual == tc.expected;
        if (success)
        {
            std::cout << "\033[32m[PASS]\033[0m Test " << (i + 1) << ": " << tc.description << "\n";
            passed++;
        }
        else
        {
            std::cout << "\033[31m[FAIL]\033[0m Test " << (i + 1) << ": " << tc.description << "\n";
            std::cout << "       Expected: ";
            for (int n : tc.expected)
                std::cout << n << " ";
            std::cout << "\n       Got:      ";
            for (int n : actual)
                std::cout << n << " ";
            std::cout << "\n";
        }
    }

    double percentage = (passed * 100.0) / testCases.size();
    std::cout << "\nResults: " << passed << "/" << testCases.size()
              << " tests passed (" << std::fixed << std::setprecision(1)
              << percentage << "%)\n";
}

int main()
{
    runTests();
    return 0;
}