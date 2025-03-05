class Solution {
public:
    
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int gc=numsDivide[0];
        for(int i=1;i<numsDivide.size();i++){
            gc=gcd(gc,numsDivide[i]);
        }
        int n=numsDivide.size();
       
        sort(nums.begin(),nums.end());
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(gc%nums[i]){
                count++;
            }
            else{
                break;
            }
        }
        return count==nums.size()?-1:count;
    }
};