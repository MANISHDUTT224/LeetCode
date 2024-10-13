class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>minheap;
        
        for(auto it:nums){
           if(minheap.size()<k){
            minheap.push(it);
           }
           else{
            if(minheap.top()<it){
                minheap.pop();
                minheap.push(it);
            }
           }
            
        }
        return minheap.top();
    }
};