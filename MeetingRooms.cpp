/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

//Important tip:
//sort comparator: True : xy , False : yx
//pq comparator: True : y on top of x , False : x on top of y 
struct{
    bool operator() (const Interval& a, const Interval& b){
        if(a.start != b.start)
            return a.start < b.start;
        return a.end <= b.end;
    }    
} comp;
class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i].start < intervals[i-1].end)
                return false;
        }
        return true;
    }
};

bool comp(const Interval& a, const Interval& b){
    if(a.start != b.start)
        return a.start < b.start;
    return a.end <= b.end;
}
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(int i = 0; i < intervals.size(); i++){
            if(minHeap.empty()){
                minHeap.push(intervals[i].end);
                continue;
            }
            if(intervals[i].start >= minHeap.top()){
                minHeap.pop();
                minHeap.push(intervals[i].end);
            }
            else
                minHeap.push(intervals[i].end);
        }
        return minHeap.size();
    }
};