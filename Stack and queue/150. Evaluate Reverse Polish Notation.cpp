class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long>stk;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/"){
                int num1=stk.top();
                stk.pop();
                int num2=stk.top();
                stk.pop();
                long long ret=0;
                if(tokens[i]=="+")ret=num2+num1;
                if(tokens[i]=="-")ret=num2-num1;
                if(tokens[i]=="*")ret=num2*num1;
                if(tokens[i]=="/")ret=num2/num1;
                stk.push(ret);
            }
            else{
                stk.push(stoll(tokens[i]));
            }
        }
        int ret=stk.top();
        stk.pop();
        return ret;
    }
};