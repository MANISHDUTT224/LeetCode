class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int counter=1;
        int  c=0;
        while(c!=k){
            if(find(arr.begin(),arr.end(),counter)!=arr.end()){
                counter++;
            }
            else{
                counter++;
                c++;
            }
            
        }
    //    if(k==1){
    //     return counter-1;
    //    }
        
        return counter-1;
    }
};