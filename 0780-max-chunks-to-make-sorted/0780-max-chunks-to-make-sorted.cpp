class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size(),chunks=0,prefixsum=0,sortedprefixsum=0;
        for(int i=0;i<n;i++){
            prefixsum+=arr[i];
            sortedprefixsum+=i;
            if(prefixsum==sortedprefixsum){
                chunks++;
            }
        }
        return chunks;
    }
};