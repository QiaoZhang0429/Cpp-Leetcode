/*
Design a hit counter which counts the number of hits received in the past 5 minutes.

Each function accepts a timestamp parameter (in seconds granularity) and you may assume that calls are being made to the system in chronological order (ie, the timestamp is monotonically increasing). You may assume that the earliest timestamp starts at 1.

It is possible that several hits arrive roughly at the same time.

Example:
HitCounter counter = new HitCounter();

// hit at timestamp 1.
counter.hit(1);

// hit at timestamp 2.
counter.hit(2);

// hit at timestamp 3.
counter.hit(3);

// get hits at timestamp 4, should return 3.
counter.getHits(4);

// hit at timestamp 300.
counter.hit(300);

// get hits at timestamp 300, should return 4.
counter.getHits(300);

// get hits at timestamp 301, should return 3.
counter.getHits(301);
*/

class HitCounter {
private:
    queue<int> q;
public:
    /** Initialize your data structure here. */
    HitCounter() {
        ;
    }    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        q.push(timestamp);
    }    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        while(!q.empty() && (timestamp - q.front()) >= 300)
            q.pop();
        return q.size();
    }
};

class HitCounter {
private:
    vector<pair<int, int>> hits;
public:
    /** Initialize your data structure here. */
    HitCounter() {
        hits.resize(300, {0, 0});
    }    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        int index = timestamp % 300;
        if(hits[index].first == timestamp)
            hits[index].second++;
        else{
            hits[index].first = timestamp;
            hits[index].second = 1;
        }
    }    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        int rslt = 0;
        for(int i = 0; i < 300; i++){
            if(timestamp - hits[i].first < 300)
                rslt += hits[i].second;
        }
        return rslt;
    }
};

class HitsCounter{
private:
    vector<int> hitcnt;//store the hit count for each second
    long long total;//always keeps the current total hit count
    long long last;//the time of last hit
    int size;//size of hitcnt, set to 300 for 5 minute
    mutex mtx;
public:
    HitsCounter(int secCnt){//5*60
        hitcnt = vector<int>(secCnt, 0);
        total = 0;
        size = hitcnt.size();
    }
    long long getHit(){
        return total;
    }
    void hit(long long cur){//single thread
        //long long cur = time(NULL);//in unit of second
        mtx.lock();
        for(long long t = last+1; t <= cur && t-last <= size; t++){
            total -= hitcnt[t % size];
            hitcnt[t % size] = 0;
        }
        hitcnt[cur % size]++;
        total++;
        last = cur;
        mtx.unlock();
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter obj = new HitCounter();
 * obj.hit(timestamp);
 * int param_2 = obj.getHits(timestamp);
 */