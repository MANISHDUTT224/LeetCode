class Solution {
public:
    double  distance(vector<int>&point){
        return point[0]*point[0]+point[1]*point[1];
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        priority_queue<pair<double,int>,vector<pair<double,int>>>minheap;
        for(int i=0;i<points.size();i++){
            double newdist=distance(points[i]);
            if(minheap.size()<k){
                minheap.push({newdist,i});
            }
            else{
                if(minheap.top().first>newdist){
                minheap.pop();
                minheap.push({newdist,i});
                }
            }
        }
        
        while(!minheap.empty()){
            int index=minheap.top().second;
            minheap.pop();
            res.push_back({points[index]});
        }

        return res;
    }
};