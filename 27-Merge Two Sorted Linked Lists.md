### [Merge Two Sorted Linked Lists](https://www.codingninjas.com/codestudio/problems/merge-two-sorted-linked-lists_8230729?challengeSlug=striver-sde-challenge&leftPanelTab=0)

### Approach 1: Iterative
```cpp
Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    if(!first) return second;
    if(!second) return first;
    if(first->data > second->data) swap(first, second); // first should be smaller
    Node<int> * ans = first; // ans will be the head of the sorted list

    while(first and second){
        Node<int> * prev; // prev will be the node just before the node pointed by first
        // find the node just before the node pointed by first
        while(first and first->data <= second->data){
            prev = first;
            first = first->next;
        }
        // insert the node pointed by second in between prev and first
        prev->next=second;
        // swap first and second so that first is always smaller
        swap(second, first);
    }
    return ans;
    /*
    Time Complexity: O(N)
    Space Complexity: O(1)
    */
}
```

### Approach 2: Recursive
```cpp
#include <bits/stdc++.h>
Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    if(first == NULL)
        return second;

    if(second == NULL)
        return first;

    // Pick the smaller value
    if(first -> data < second -> data){
        first -> next = sortTwoLists(first -> next, second);
        return first;
    } else {
        second -> next = sortTwoLists(first, second -> next);
        return second;
    }
    /*
    Time Complexity: O(N)
    Space Complexity: O(N)
    */
}
```