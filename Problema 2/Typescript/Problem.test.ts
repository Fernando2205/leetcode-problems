// src/Problem.test.ts

import { ListNode, addTwoNumbers, createList, listToArray } from './Problem';

describe('addTwoNumbers', () => {
    interface TestCase {
        l1: number[];
        l2: number[];
        expected: number[];
    }
    const testCases: TestCase[] = [
        // Caso de prueba 1
        {
            l1: [2, 4, 3],
            l2: [5, 6, 4],
            expected: [7, 0, 8],
        },
        // Caso de prueba 2
        {
            l1: [0],
            l2: [0],
            expected: [0],
        },
        // Caso de prueba 3
        {
            l1: [9, 9, 9, 9, 9, 9, 9],
            l2: [9, 9, 9, 9],
            expected: [8, 9, 9, 9, 0, 0, 0, 1],
        },
        // Caso de prueba 4
        {
            l1: [1, 8],
            l2: [0],
            expected: [1, 8],
        },
        // Caso de prueba 5
        {
            l1: [5],
            l2: [5],
            expected: [0, 1],
        },
        // Caso de prueba 6
        {
            l1: [3, 2, 1],
            l2: [6, 5, 4],
            expected: [9, 7, 5],
        },
        // Caso de prueba 7
        {
            l1: [9],
            l2: [1],
            expected: [0, 1],
        },
        // Caso de prueba 8
        {
            l1: [1, 0, 0, 0],
            l2: [1],
            expected: [2, 0, 0, 0],
        },
        // Caso de prueba 9
        {
            l1: [2, 4],
            l2: [5, 6, 4],
            expected: [7, 0, 5],
        },
        // Caso de prueba 10
        {
            l1: [7, 1, 6],
            l2: [5, 9, 2],
            expected: [2, 1, 9],
        },
        // Caso de prueba 11
        {
            l1: [9, 9],
            l2: [1],
            expected: [0, 0, 1],
        },
        // Caso de prueba 12
        {
            l1: [0],
            l2: [1, 2, 3],
            expected: [1, 2, 3],
        },
        // Caso de prueba 13
        {
            l1: [4, 5, 6],
            l2: [3, 2, 1],
            expected: [7, 7, 7],
        },
        // Caso de prueba 14
        {
            l1: [1, 9, 9],
            l2: [1],
            expected: [2, 9, 9],
        },
        // Caso de prueba 15
        {
            l1: [5, 9, 9],
            l2: [5, 1],
            expected: [0, 1, 0, 1],
        },
        // Caso de prueba 16
        {
            l1: [2, 7, 4],
            l2: [5, 6, 4],
            expected: [7, 3, 9],
        },
        // Caso de prueba 17
        {
            l1: [6, 1, 7],
            l2: [2, 9, 5],
            expected: [8, 0, 3, 1],
        },
        // Caso de prueba 18
        {
            l1: [3, 4, 2],
            l2: [4, 6, 5],
            expected: [7, 0, 8],
        },
        // Caso de prueba 19
        {
            l1: [9, 8],
            l2: [1],
            expected: [0, 9],
        },
        // Caso de prueba 20
        {
            l1: [1, 0, 0, 0, 0],
            l2: [1, 1, 1, 1, 1],
            expected: [2, 1, 1, 1, 1],
        },
        // Caso de prueba 21
        {
            l1: [4, 5, 6, 7],
            l2: [3, 2, 1],
            expected: [7, 7, 7, 7],
        },
        // Caso de prueba 22
        {
            l1: [1],
            l2: [9, 9, 9],
            expected: [0, 0, 0, 1],
        },
        // Caso de prueba 23
        {
            l1: [2, 4, 3, 7],
            l2: [5, 6, 4],
            expected: [7, 0, 8, 7],
        },
        // Caso de prueba 24
        {
            l1: [5, 6, 4],
            l2: [5, 6, 4],
            expected: [0,3,9],
        },
        // Caso de prueba 25
        {
            l1: [9, 9, 9],
            l2: [9, 9, 9],
            expected: [8, 9, 9, 1],
        },
        // Caso de prueba 26
        {
            l1: [1, 2, 3],
            l2: [4, 5, 6, 7],
            expected: [5, 7, 9, 7],
        },
        // Caso de prueba 27
        {
            l1: [0],
            l2: [1, 0, 0],
            expected: [1, 0, 0],
        },
        // Caso de prueba 28
        {
            l1: [8, 9],
            l2: [1],
            expected: [9, 9],
        },
        // Caso de prueba 29
        {
            l1: [7, 0, 8],
            l2: [5, 6, 4],
            expected: [2, 7, 2, 1],
        },
        // Caso de prueba 30
        {
            l1: [3, 4, 2],
            l2: [4, 6, 5],
            expected: [7, 0, 8],
        },
        // Caso de prueba 31
        {
            l1: [9, 9, 9, 9],
            l2: [9, 9, 9, 9],
            expected: [8, 9, 9, 9, 1],
        },
        // Caso de prueba 32
        {
            l1: [1, 0],
            l2: [1],
            expected: [2, 0],
        },
        // Caso de prueba 33
        {
            l1: [6, 1, 7],
            l2: [2, 9, 5],
            expected: [8, 0, 3, 1],
        },
        // Caso de prueba 34
        {
            l1: [2, 4, 3],
            l2: [5, 6, 4, 9],
            expected: [7, 0, 8, 9],
        },
        // Caso de prueba 35
        {
            l1: [1, 1, 1],
            l2: [9, 9, 9],
            expected: [0, 1, 1, 1],
        },
        // Caso de prueba 36
        {
            l1: [0, 0, 1],
            l2: [0, 0, 1],
            expected: [0, 0, 2],
        },
        // Caso de prueba 37
        {
            l1: [4],
            l2: [5, 6, 7],
            expected: [9, 6, 7],
        },
        // Caso de prueba 38
        {
            l1: [1, 8, 3],
            l2: [0, 6, 7],
            expected: [1,4, 1, 1],
        },
        // Caso de prueba 39
        {
            l1: [2, 4, 9],
            l2: [5, 6, 4],
            expected: [7, 0, 4, 1],
        },
        // Caso de prueba 40
        {
            l1: [3, 9, 9],
            l2: [7, 2],
            expected: [0, 2, 0, 1],
        },
        // Caso de prueba 41
        {
            l1: [9, 9, 9],
            l2: [1],
            expected: [0, 0, 0, 1],
        },
        // Caso de prueba 42
        {
            l1: [2, 7, 4],
            l2: [5, 6, 4],
            expected: [7, 3, 9],
        },
        // Caso de prueba 43
        {
            l1: [1, 0, 0, 0, 1],
            l2: [9, 9, 9, 9],
            expected: [0, 0, 0, 0, 2],
        },
        // Caso de prueba 44
        {
            l1: [4, 5],
            l2: [5, 5],
            expected: [9, 0, 1],
        },
        // Caso de prueba 45
        {
            l1: [1],
            l2: [9, 9, 9],
            expected: [0, 0, 0, 1],
        },
        // Caso de prueba 46
        {
            l1: [2, 4, 3],
            l2: [5, 6, 4],
            expected: [7, 0, 8],
        },
        // Caso de prueba 47
        {
            l1: [9, 8, 7],
            l2: [6, 5, 4],
            expected: [5, 4, 2, 1],
        },
        // Caso de prueba 48
        {
            l1: [1, 0, 1],
            l2: [9, 9],
            expected: [0, 0, 2],
        },
        // Caso de prueba 49
        {
            l1: [3, 4, 2],
            l2: [4, 6, 5],
            expected: [7, 0, 8],
        },
        // Caso de prueba 50
        {
            l1: [7, 9, 9, 9],
            l2: [5, 8, 2],
            expected: [2, 8, 2, 0, 1],
        },
    ];

    testCases.forEach(({ l1, l2, expected }, index) => {
        it(`Caso de prueba ${index + 1}`, () => {
            const list1 = createList(l1);
            const list2 = createList(l2);
            const result = addTwoNumbers(list1, list2);
            expect(listToArray(result)).toEqual(expected);
        });
    });
});