class KthLargest {
public:
    int curk;
    priority_queue<int,vector<int>,greater<int>> minheap;
    KthLargest(int k, vector<int>& nums) {
        curk=k;
        for(int i:nums){
            add(i);
        }
    }
    
    int add(int val) {
        minheap.push(val);
        if(minheap.size()>curk){
            minheap.pop();
        }
        return minheap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */