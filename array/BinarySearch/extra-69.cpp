class Solution {
public:
    int mySqrt(int x) {
        int left=0,right=x;
        int ret=0;
        while(left<=right){
            int middle=left+(right-left)/2;
            if((long long)middle*middle<=x){
                //不要写成if((long long)(middle * middle) <= (long long)(x))
                //实际执行顺序是：先计算 middle * middle（两个 int 相乘，结果仍是 int）。
                //再将溢出后的 int 结果转换为 long long。
                left=middle+1;
                ret=middle;
            }else{
                right=middle-1;
            }
        }
        return ret;
    }
};