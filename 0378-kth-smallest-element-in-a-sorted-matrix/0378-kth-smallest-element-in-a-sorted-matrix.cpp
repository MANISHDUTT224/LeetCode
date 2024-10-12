class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int,vector<int>>maxheap;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(maxheap.size()<k){
                    maxheap.push(matrix[i][j]);
                }
                else{
                    if(maxheap.top()>matrix[i][j]){
                        maxheap.pop();
                        maxheap.push(matrix[i][j]);
                    }
                }
            }
        }
        return maxheap.top();
    }
};