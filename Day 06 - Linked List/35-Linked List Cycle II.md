### [Linked List Cycle II](https://www.codingninjas.com/codestudio/problems/linked-list-cycle-ii_8230823?challengeSlug=striver-sde-challenge&leftPanelTab=0)

```cpp
Node *firstNode(Node *head)
{
    Node * slow = head, * fast = head;
    while(fast and fast->next){
        slow = slow->next;
        fast = fast->next->next;
        
        //if cycle is present
        if(slow == fast){
            fast = head; //move fast to head
            //move both slow and fast by one step
            while(slow != fast){
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }

    return NULL;
    /*
    Time Complexity: O(N)
    Space Complexity: O(1)
    */
}
```