class Solution {
private:
    void removeExtraSpace(string &s){
        int slow=0;
        for(int i=0;i<s.size();i++){
            if(s[i]!=' '){
                if(slow!=0)s[slow++]=' ';
                while(s[i]!=' ' && i<s.size()){
                    s[slow++]=s[i++];
                }
            }
        }
        s.resize(slow);
    }

    void reverse(string &s,int start,int end){
        for(int i=start,j=end;i<j;i++,j--){
            swap(s[i],s[j]);
        }
    }
public:
    string reverseWords(string s) {
        removeExtraSpace(s);
        reverse(s,0,s.size()-1);
        int start=0;
        for(int i=0;i<=s.size();i++){
            if(s[i]==' ' || i==s.size()){
                reverse(s,start,i-1);
                start=i+1;
            }
        }
        return s;
    }
};