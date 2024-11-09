class Solution {
public:
    long long minEnd(int n, int x) {
        long res=x,rem=n-1,pos=1;
        while(rem){
            if(!(x&pos)){
                res|=(rem&1)*pos;
                rem>>=1;
            }
            pos<<=1;
        }
        return res;
    }
};