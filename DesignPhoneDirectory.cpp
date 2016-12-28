
/*
Design a Phone Directory which supports the following operations:

get: Provide a number which is not assigned to anyone.
check: Check if a number is available or not.
release: Recycle or release a number.
Example:

// Init a phone directory containing a total of 3 numbers: 0, 1, and 2.
PhoneDirectory directory = new PhoneDirectory(3);

// It can return any available phone number. Here we assume it returns 0.
directory.get();

// Assume it returns 1.
directory.get();

// The number 2 is available, so return true.
directory.check(2);

// It returns 2, the only number that is left.
directory.get();

// The number 2 is no longer available, so return false.
directory.check(2);

// Release number 2 back to the pool.
directory.release(2);

// Number 2 is available again, return true.
directory.check(2);
*/
#include <unordered_set>
#include <iostream>
using namespace std;

class PhoneDirectory {
private:
    unordered_set<int> released;
    int maxNumbers;
    int unusedLowerBound;
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
        this->maxNumbers = maxNumbers;
        unusedLowerBound = 0;
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        int number;
        if(!released.empty()){
            number = *released.begin();
            released.erase(number);
        }
        else if(unusedLowerBound >= maxNumbers)
            return -1;
        else{
            number = unusedLowerBound;
            unusedLowerBound++;
        }
        return number;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        if(number >= maxNumbers)
            return false;
        if(number >= unusedLowerBound)
            return true;
        return released.find(number) != released.end();
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        if(number >= unusedLowerBound)
            return ;
        released.insert(number);
    }
};

class PhoneDirectory {
private:
    ListNode* dummy;
    unordered_map<int, ListNode*> occupied;
public:
    // Initialize your data structure here
    //    @param maxNumbers - The maximum numbers that can be stored in the phone directory. 
    PhoneDirectory(int maxNumbers) {
        dummy = new ListNode(-1);
        ListNode* cur = dummy;
        for(int i = 0; i < maxNumbers; i++){
            cur->next = new ListNode(i);
            cur = cur->next;
        }
    }
    
    // Provide a number which is not assigned to anyone.
    //    @return - Return an available number. Return -1 if none is available. 
    int get() {
        ListNode* tmp = dummy->next;
        if(!tmp)
            return -1;
        dummy->next = tmp->next;
        occupied[tmp->val] = tmp;
        return tmp->val;
    }
    
    // Check if a number is available or not. 
    bool check(int number) {
        return occupied.find(number) == occupied.end();
    }
    
    // Recycle or release a number. 
    void release(int number) {
        if(occupied.find(number) == occupied.end())
            return ;
        ListNode* tmp = occupied[number];
        tmp->next = dummy->next;
        dummy->next = tmp;
        occupied.erase(number);
    }
};

int main(){
    PhoneDirectory obj(1);
    obj.check(0);
    obj.get();
    obj.check(0);
    obj.get();
    return 0;
}
/**
* Your PhoneDirectory object will be instantiated and called as such:
* PhoneDirectory obj = new PhoneDirectory(maxNumbers);
* int param_1 = obj.get();
* boolean param_2 = obj.check(number);
* obj.release(number);
*/