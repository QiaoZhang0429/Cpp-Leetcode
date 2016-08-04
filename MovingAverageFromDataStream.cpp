class MovingAverage {
//or circular array
private:
    int size;
    queue<int> q;
    int sum;
public:
    MovingAverage(int size){
        this.size = size;
        sum = 0;
    }
    
    double next(int val){
        if(q.size() == size){
            sum -= q.front();
            q.pop();
        }
        q.push(val);
        sum += val;
        return sum * 1.0 / q.size();
        //return 1.0 * accumulate(q.begin(), q.end(), 0) / q.size();
    }
};