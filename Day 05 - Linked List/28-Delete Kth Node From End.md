### [Delete Kth Node From End](https://www.codingninjas.com/codestudio/problems/delete-kth-node-from-end_8230725?challengeSlug=striver-sde-challenge)

#### Brute Force

```cpp
Node* removeKthNode(Node* head, int K)
{
    Node * temp = head;
    int len = 0;
    // find length of LL
    while(temp){
        temp=temp->next;
        len++;
    }
    // if K is same as length of LL then delete first node
    if(K == len) return head->next;
    
    // else find the node before Kth node from end
    K = len-K-1;
    temp = head;
    int count = 0;
    while(count < K){
        temp = temp->next;
        count++;
    }
    // delete Kth node from end
    temp->next = temp->next ? temp->next->next : NULL;
    return head;
    /*
    Time Complexity: O(N)
    Space Complexity: O(1)
    */
}
```

#### Optimized
```cpp
Node* removeKthNode(Node* head, int K)
{
    Node * result = new Node(-1);
    result -> next = head;

    Node * p1 = result, * p2 = result;

    //find kth node from first
    for(int i = 0; i < K; i++) p1 = p1->next;

    //find kth node from end
    //until p1 reaches end of LL p2 will be kth node from end
    while(p1->next){
        p1 = p1->next;
        p2 = p2->next;
    }

    p2->next = p2->next->next;

    return result->next;
    /*
    Time Complexity: O(N)
    Space Complexity: O(1)
    */
}
```