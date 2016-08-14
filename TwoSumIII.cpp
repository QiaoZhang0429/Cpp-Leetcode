class TwoSum {
private:
    unordered_map<int, int> nums;
public:
    void add(int number) {
        nums[number]++;
    }
    bool find(int value) {
        for(auto pair:count){
            if(value != 2 * pair.first && nums.count(value - pair.first) > 0)
                return true;
            if(value == 2 * pair.first && pair.second > 1)
                return true;
        }
        return false;
    }
};