class Solution {
private:
    string build(string s){
        string ret="";
        for(char c:s){
            if(c!='#')ret.push_back(c);
            else if(!ret.empty()) ret.pop_back();
        }
        return ret;
    }
public:
    bool backspaceCompare(string s, string t) {
        return build(s)==build(t);
    }
};