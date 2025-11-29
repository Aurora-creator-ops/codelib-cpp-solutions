class Solution {
public:
    bool isValid(string s) {
        if(s.size()%2!=0)return false;
        stack<char>stk;
        for(char x:s){
            if(x=='(' )stk.push(')');
            else if(x=='[')stk.push(']');
            else if(x=='{')stk.push('}');

            else if(stk.empty())return false;
            else if(stk.top()!=x)return false;
            
            else stk.pop(); 
        }
        return stk.empty();
    }
};