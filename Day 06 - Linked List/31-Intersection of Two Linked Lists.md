### [Intersection of Two Linked Lists](https://www.codingninjas.com/codestudio/problems/intersection-of-two-linked-lists_8230688?challengeSlug=striver-sde-challenge&leftPanelTab=0)

#### Brute Force Approach:
```cpp
Node * findIntersection(Node *firstHead, Node *secondHead)
{
    Node * temp1 = firstHead;
    Node * temp2 = secondHead;
    int len1 = 0, len2 = 0;
    
    //find length of LL
    while(temp1 || temp2){
        if(temp1){
            len1++;
            temp1 = temp1->next;
        }
        if(temp2){
            len2++;
            temp2 = temp2->next;
        }
    }

    temp1 = firstHead;
    temp2 = secondHead;

    //move pointer to same distance from end
    int diff = len1 - len2;
    if(diff > 0){ //first is longer
        while(diff-- != 0) temp1 = temp1->next;
    } else if(diff < 0) //second is longer
        while(diff++ != 0) temp2 = temp2->next;

    //move both pointer until they are same
    while(temp1 && temp2){
        if(temp1 == temp2) return temp2;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    return NULL;
    /*
    Time Complexity: O(n + m)
    Space Complexity: O(1)
    */
}
```

#### Hashing Approach:
```cpp
Node * findIntersection(Node *firstHead, Node *secondHead)
{
    unordered_set<Node *> s; //hashing
    Node * temp = firstHead;
    while(temp){
        s.insert(temp); //insert all nodes of first LL
        temp = temp->next;
    }

    temp = secondHead;
    while(temp){
        if(s.find(temp) != s.end()) return temp; //if node is present in set then it is intersection point
        temp = temp->next;
    }

    return NULL;
    /*
    Time Complexity: O(n)
    Space Complexity: O(n)
    */
}
```

#### Optimal Approach:
```cpp
Node * findIntersection(Node *firstHead, Node *secondHead)
{
    Node * a = firstHead, * b = secondHead; //two pointers

    //if a & b are not same then move them to next
    while(a != b){
        a = a ? a->next : secondHead; //if a is not null then move a to next else move it to head of second LL
        b = b ? b->next : firstHead; //if b is not null then move b to next else move it to head of first LL
    }

    return a;    
    /*
    Time Complexity: O(n)
    Space Complexity: O(1)
    */
}
```