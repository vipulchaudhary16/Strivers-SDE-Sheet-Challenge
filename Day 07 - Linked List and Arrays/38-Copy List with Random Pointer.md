### [Copy List with Random Pointer](https://www.codingninjas.com/codestudio/problems/copy-list-with-random-pointer_8230734?challengeSlug=striver-sde-challenge&leftPanelTab=0)

```cpp
LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    LinkedListNode<int> * clone;
    bool isFirst = true; // to check if it is first node or not

    LinkedListNode<int> *temp = head;
    while(temp){
        LinkedListNode<int> * curr = new LinkedListNode<int> (temp->data); // creating new node
        
        if(isFirst){ // if it is first node then make clone point to it
            clone = curr;
            isFirst = false;
        } 
        curr -> next = temp->next; // making next of curr point to next of temp
        curr -> random = temp -> random; // making random of curr point to random of temp
        temp = temp->next; // moving temp to next node
        curr = curr->next; // moving curr to next node
    }
    return clone;
    /*
    TC: O(N)
    SC: O(1)
    */
}
```