class Solution {
private:
    void getNext(vector<int>&next,string s){
        int j=0;
        next[0]=0;
        for(int i=1;i<s.size();i++){//不是从0开始，因为next[0]已经是0了
            while(j>0 && s[i]!=s[j]) j=next[j-1];
            if(s[i]==s[j]) j++;
            next[i]=j;
        }
    }

public:
    int strStr(string haystack, string needle) {
        if(needle.size()==0)return 0;
        vector<int>next(needle.size());
        getNext(next,needle);
        int j=0;
        for(int i=0;i<haystack.size();i++){
            while(haystack[i]!=needle[j] && j>0){
                j=next[j-1];
            }
            if(haystack[i]==needle[j])j++;
            if(j==needle.size())return (i-needle.size()+1);//不是j==needle.size()-1,注意i,j代表的东西
        }
        return -1;
    }
};