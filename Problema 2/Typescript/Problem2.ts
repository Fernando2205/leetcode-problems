
// Definición de la lista enlazada simple.
export class ListNode {
     val: number
     next: ListNode | null
     constructor(val?: number, next?: ListNode | null) {
         this.val = (val===undefined ? 0 : val)
         this.next = (next===undefined ? null : next)
     }
 }

export function addTwoNumbers(l1: ListNode | null, l2: ListNode | null): ListNode | null  {
    //Inicio de código compatible con leetcode
    let head = new ListNode(0);
    let current = head;
    let digito_extra = 0;

    while (l1 !== null || l2 !== null) {
        const val1 = l1?.val ?? 0;
        const val2 = l2?.val ?? 0;
        const sum = val1 + val2 + digito_extra;
        digito_extra = Math.floor(sum / 10);

        current.next = new ListNode(sum % 10);
        current = current.next;

        if (l1 !== null) l1 = l1.next;
        if (l2 !== null) l2 = l2.next;
    }

    if (digito_extra > 0) {
        current.next = new ListNode(digito_extra);
    }
    console.log(head.next);
    return head.next;
    //Fin de código compatible con leetcode
}



// Función auxiliar para crear una lista enlazada a partir de un array.
export function createList(arr: number[]): ListNode | null {
    if (arr.length === 0) return null;
    let dummy = new ListNode(0);
    let current = dummy;
    for (const num of arr) {
        current.next = new ListNode(num);
        current = current.next;
    }
    return dummy.next;
}


// Función auxiliar para convertir una lista enlazada a un array (para facilitar las pruebas).
export function listToArray(head: ListNode | null): number[] {
    const result: number[] = [];
    let current = head;
    while (current !== null) {
        result.push(current.val);
        current = current.next;
    }
    return result;
}
