class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        vector<int>st;
        vector<int>et;
        for(int i=0;i<intervals.size();i++){

            st.push_back(intervals[i][0]);
            et.push_back(intervals[i][1]);
        }
        sort(st.begin(),st.end());
        sort(et.begin(),et.end());
        int eti=0;
        int count=0;
        for(int i:st){
            if(i>et[eti]){
                eti++;
            }
            else{
                count++;
            }
        }
        return count;

    }
};