### [Middle Of Linked List](https://www.codingninjas.com/codestudio/problems/middle-of-linked-list_8230764?challengeSlug=striver-sde-challenge)

```cpp
Node *findMiddle(Node *head) {
    Node * slow = head, *fast = head; // slow and fast pointer
    while(fast and fast->next){ // fast pointer moves twice as fast as slow pointer
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow; // when fast pointer reaches end, slow pointer will be at middle
    /*
    Time Complexity: O(N)
    Space Complexity: O(1)
    */
}

```