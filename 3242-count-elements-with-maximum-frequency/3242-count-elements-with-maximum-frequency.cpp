class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int frq[101]={0},maxF=0,f=0;
        for(int x:nums){
           frq[x]++;
           f+=(frq[x]==maxF);
           if(maxF<frq[x]){
               f=1;
               maxF=frq[x];
           }

        }
        return f*maxF;

        

    }
    int count(vector<int> &nums,int i){
        int c=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==i){
                c++;
            }
        }
        return c;
    }
};