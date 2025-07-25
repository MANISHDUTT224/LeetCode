class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // Time Complexity :  O(2N) || Space Complexity : O(k) 
        int n = nums.size();
        vector<int> result;
        deque<int> dq ; // for storing indices

        for(int i = 0 ; i < n ; i++){
            // Remove indices out of this window
            if(!dq.empty() && dq.front() == i-k){
                dq.pop_front();
            }

            // Remove smaller element in k range as they are useless
            while(!dq.empty() && nums[dq.back()] < nums[i]){
                dq.pop_back();
            }

            dq.push_back(i);  // Add current  element 
            // Add to result after first elements
            if(i>= k-1){
                result.push_back(nums[dq.front()]);
            }
        }
       return result;
    }
};