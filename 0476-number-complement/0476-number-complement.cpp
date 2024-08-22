class Solution {
public:
    int findComplement(int num) {
        if(num==2){
            return 1;
        }
        string bits="";
        while(num>0){
            bits+=to_string(1-(num%2));
            num/=2;
        }
        int l=bits.length();

        int p=l;
        int val=0;
        for(int i=0;i<l;i++){
            if(bits[i]=='1'){
                val+=pow(2,p-1);
            }
            p--;
        }
        return val;
    }
};