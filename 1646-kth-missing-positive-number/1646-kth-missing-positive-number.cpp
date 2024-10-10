class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
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
  
        
        return counter-1;
    }
};