class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int i=0,j=arr.size()-1;
        while(i<=j){
            int mid=(i+j)/2;
            int missing=arr[mid]-(mid+1);
            if(missing<k){
              
                i=mid+1;
            }
            else{
                j=mid-1;
            }
        }
        return j+k+1;
    }
};