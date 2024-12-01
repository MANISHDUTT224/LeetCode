class Solution {
public:
    bool search(int target,int ind,vector<int>&arr){
    
        for(int i=0;i<arr.size();i++){
            if(i==ind){
                continue;
            }
            if(arr[i]==target){
                return true;
            }
        }
        return false;
    }
    bool checkIfExist(vector<int>& arr) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        
        for(int i=0;i<arr.size();i++){
             
            if(search(arr[i]*2,i,arr)){
                return true;
            }
           
        }
        return false;
    }
};