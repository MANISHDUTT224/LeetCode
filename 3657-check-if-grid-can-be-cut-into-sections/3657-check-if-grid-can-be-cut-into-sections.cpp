class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        return checkCuts(rectangles,0)||checkCuts(rectangles,1);
    }
    bool checkCuts(vector<vector<int>>&rectangles,int dim){
        int gapcount=0;
        sort(rectangles.begin(),rectangles.end(),[dim](const vector<int>&a,const vector<int>&b){
            return a[dim]<b[dim];
        });
        int last=rectangles[0][dim+2];
        for(int i=1;i<rectangles.size();i++){
            vector<int>&rect=rectangles[i];
            if(last<=rect[dim]){
                gapcount++;
            }
            last=max(last,rect[dim+2]);
        }
        return gapcount>=2;
    }
};