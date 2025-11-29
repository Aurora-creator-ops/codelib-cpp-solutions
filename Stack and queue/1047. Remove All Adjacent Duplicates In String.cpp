class Solution {
public:
    string removeDuplicates(string s) {
        string ret="";
        for(char x:s){
            if(ret.empty() || ret.back()!=x){
                ret.push_back(x);
            }
            else{
                ret.pop_back();
            }
        }
        return ret;
    }
};