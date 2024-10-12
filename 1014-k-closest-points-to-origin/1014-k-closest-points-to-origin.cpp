class Solution {
public:
    double distance(vector<int> &point){
        return point[0]*point[0]+point[1]*point[1];
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        priority_queue<pair<double,int>,vector<pair<double,int>>>  maxheap;
        for(int i=0;i<points.size();i++){
            double newdist=distance(points[i]);
            if(maxheap.size()<k){
                maxheap.push({newdist,i});
            }
            else{
                if(maxheap.top().first>newdist){
                    maxheap.pop();
                    maxheap.push({newdist,i});
                }
            }
        }
        vector<vector<int>> res;
        while(!maxheap.empty()){
            int index=maxheap.top().second;

            maxheap.pop();
            res.push_back(points[index]);
        }
        return res;
    }
};