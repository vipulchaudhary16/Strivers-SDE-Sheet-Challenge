### [Palindrome Linked List](https://www.codingninjas.com/codestudio/problems/palindrome-linked-list_8230717?challengeSlug=striver-sde-challenge&leftPanelTab=0)

```cpp
#include <bits/stdc++.h> 
LinkedListNode<int> * reverseList(LinkedListNode<int> * head){
    LinkedListNode<int> * temp = head, *prev = NULL;

    while(temp){
        LinkedListNode<int> * remain = temp->next;
        temp->next = prev;
        prev = temp;
        temp = remain;
    }

    return prev;
}

bool isPalindrome(LinkedListNode<int> *head) {
    if(!head || !head->next) return true;

    //find mid point of LL
    LinkedListNode<int> * slow = head, * fast = head;
    while(fast->next and fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }

    slow -> next = reverseList(slow->next);

    LinkedListNode<int> * h1 = head, *h2 = slow->next;

    //compare both LL
    while(h2){
        if(h1->data != h2->data) return false;
        h1 = h1->next;
        h2 = h2->next;
    }

    return true;
    /*
    Time Complexity: O(N)
    Space Complexity: O(1)
    */

}
```