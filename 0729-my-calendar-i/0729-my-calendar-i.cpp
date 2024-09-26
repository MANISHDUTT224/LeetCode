class MyCalendar {
public:
    MyCalendar() {
        
    }
    vector<pair<int,int>> v;
    bool book(int start, int end) {
        cin.tie(0);
        cout.tie(0);
        ios::sync_with_stdio(false);
        for(int i=0;i<v.size();i++){
            if((v[i].first<=start && v[i].second>start )||(v[i].first<end && v[i].second>=end)||(v[i].first<=start && v[i].second>=end)||(v[i].first>start && v[i].second<end)){
                return false;
            }
        }
        v.push_back(make_pair(start,end));
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */