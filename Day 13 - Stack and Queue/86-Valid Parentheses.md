### [Valid Parentheses](https://www.codingninjas.com/studio/problems/valid-parentheses_8230714?challengeSlug=striver-sde-challenge&leftPanelTab=0)

```cpp
bool isValidParenthesis(string expression)
{
    stack<char> st;
    for(auto parenthesis: expression){
        //opening parenthesis
        if(parenthesis == '[' 
            || parenthesis == '('
            || parenthesis == '{'
        ) st.push(parenthesis);
        else {
            // closing parenthesis
            if(st.empty()) return false;

            char top = st.top();
            if(parenthesis == ']' && top == '[' 
                ||parenthesis == '}' && top == '{' 
                ||parenthesis == ')' && top == '('
            ) st.pop(); 
            else return false;
        }
    }

    if(st.empty()) return true;
    return false;
}
/*
TC: O(n)
SC: O(n)
*/
```