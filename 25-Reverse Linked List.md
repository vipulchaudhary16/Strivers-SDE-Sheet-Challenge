### [Reverse Linked List](https://www.codingninjas.com/codestudio/problems/reverse-linked-list_8230724?challengeSlug=striver-sde-challenge&leftPanelTab=0)

#### Brute Force Approach
```
1. Convert the linked list into an array
2. Reverse the array
3. Convert the array into a linked 
list
```

#### Optimal Approach
```cpp
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    LinkedListNode<int> * temp = head, * prev = NULL;
    while(temp){
        LinkedListNode<int> * remain = temp->next;
        temp -> next = prev;
        prev = temp;
        temp = remain;
    }
    return prev;
    /*
    Time Complexity: O(n)
    Space Complexity: O(1)
    */
}
```