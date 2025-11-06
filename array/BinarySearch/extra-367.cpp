class Solution {
public:
    bool isPerfectSquare(int num) {
        int left=0,right=num;
        int ret=0;
        while(left<=right){
            int middle=left+(right-left)/2;
            if((long long)middle*middle<=num){
                left=middle+1;
                ret=middle;
            }else{
                right=middle-1;
            }
        }
        if(ret*ret==num)return true;
        return false;
    }
};