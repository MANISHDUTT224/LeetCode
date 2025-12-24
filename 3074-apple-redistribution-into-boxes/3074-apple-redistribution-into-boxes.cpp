class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int s=0;
        for(auto it:apple){
            s+=it;
        }
        sort(capacity.begin(),capacity.end());
        reverse(capacity.begin(),capacity.end());
        int n=0;
        for(int i=0;i<capacity.size();i++){
            if(s>capacity[i]){
                s-=capacity[i];
                n++;
            }
            else{
                n++;
                
                break;
            }
            
        }
        return n;
        
    }
};