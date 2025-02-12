class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int result=-1;
        int digitmap[82]={};
        for(int element:nums){
            int digitsum=0;
            for(int curvalue=element;curvalue;curvalue/=10){
                digitsum+=curvalue%10;
            }
            if(digitmap[digitsum]>0){
                result=max(digitmap[digitsum]+element,result);
            }

         
            digitmap[digitsum]=max(digitmap[digitsum],element);
            
        }
        return result;
    }
};