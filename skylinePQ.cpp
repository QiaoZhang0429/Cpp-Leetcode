class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> rslt;
        vector<pair<int, int>> height;
        for(auto b:buildings){
            height.push_back({b[0], -b[2]});
            height.push_back({b[1], b[2]});
        }
        sort(height.begin(), height.end());
        priority_queue<int> maxHeap;
        unordered_map<int, int> toBeDeleted;
        maxHeap.push(0);
        for(auto h:height){
            if(h.second < 0)
                maxHeap.push(-h.second);
            else{
                if(h.second == maxHeap.top()){
                    maxHeap.pop();
                    while(!maxHeap.empty() && toBeDeleted[maxHeap.top()]){
                        toBeDeleted[maxHeap.top()]--;
                        maxHeap.pop();                    
                    }
                }
                else
                    toBeDeleted[h.second]++;
            }
            if((rslt.empty() && maxHeap.top() > 0) || maxHeap.top() != rslt.back().second)
                rslt.push_back({h.first, maxHeap.top()});
        }
        return rslt;
    }
};