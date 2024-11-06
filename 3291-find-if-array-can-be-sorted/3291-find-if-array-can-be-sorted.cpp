class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        pair<int,int> prev={INT_MIN,INT_MIN},curr;
        int x,b;
        int prevbit=-1;
        int n=nums.size();
        for(int i=0;i<n;i++){
             x=nums[i];
             b=__builtin_popcount(x);
             if(prevbit!=b){
                if(prev.second>curr.first){return 0;}
                    prev=curr;
                    curr={x,x};
                    prevbit=b;
                }
                else{
                    curr.first=min(curr.first,x);
                    curr.second=max(curr.second,x);
                }
             }
        
        return prev.second<=curr.first;
    }
};