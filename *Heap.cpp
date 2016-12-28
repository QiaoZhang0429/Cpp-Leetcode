Definition:
  father > / < children
  children are heap as well
  complete binary tree
  pop the element with highest priority

for node i:
  //starting from 0
  children : 2i+1, 2i+2
  father : (i-1) / 2
  //starting from 1
  children : 2i, 2i+1
  father : i / 2

class minHeap{
private:
  vector<int> a;
  int n;//number of nodes in the heap
public:
  minHeap(vector<int>& nums){
    a.resize(100, 0);
    initialize(nums);
    make_heap();
  }
  void initialize(vector<int>& nums){
    for(int i = 0; i < nums.size(); i++)
      a[i+1] = nums[i];
    n = nums.size();
  }
  //fix down each non-leaf node
  void make_heap(){
    for(int k = n / 2; k > 0; k--){
      for(int i = k, j = 2 * i; j <= n; i = j, j = 2 * i){
        if(j+1 <= n && a[j+1] < a[j])
          j++;
        if(a[i] <= a[j])
          break;
        swap(a[i], a[j]);
      }
    }
  }
  //add to the end, pop up like insert sort
  void push_heap(int x){
    n++;
    a[n] = x;
    for(int j = n / 2, i = n; j > 0 && a[j] > a[i]; i = j, j = i / 2;)
      swap(a[i], a[j]);
  }
  //move end to front, fix down, pop the smaller child up
  int pop_heap(){
    int top = a[1];
    swap(a[n], a[1]);
    n--;
    for(int i = 1, j = 2 * i; j <= n; i = j, j = 2 * i){
      if(j+1 <= n && a[j+1] < a[j])
        j++;
      if(a[i] <= a[j])
        break;
      swap(a[i], a[j]);
    }
    return top;
  }
};

// constructing priority queues
#include <iostream>       // std::cout
#include <queue>          // std::priority_queue
#include <vector>         // std::vector
#include <functional>     // std::greater

struct comp{
    bool operator() (ListNode*& a, ListNode*& b){
        return a->val > b->val;
    }
};

class mycomparison{//True : y on top of x , False : x on top of y
private:
  bool reverse;
public:
  mycomparison(const bool& revparam=false){
    reverse=revparam;
  }
  bool operator() (const int& lhs, const int&rhs) const{
    if (reverse) return (lhs>rhs);
    else return (lhs<rhs);
  }
};

int main (){
  int myints[] = {10,60,50,20};

  std::priority_queue<int> first;
  std::priority_queue<int> second (myints,myints+4);

  //True : y on top, False : x on top
  std::priority_queue<int, std::vector<int>, std::greater<int> > third1 (myints,myints+4);//min heap
  std::priority_queue<int, std::vector<int>, std::less<int> > third2 (myints,myints+4);//max heap

  std::priority_queue<int, std::vector<int>, comp > third1;

  typedef std::priority_queue<int, std::vector<int>, mycomparison> mypq_type;

  mypq_type fourth;                       // less-than comparison
  mypq_type fifth (mycomparison(true));   // greater-than comparison

  return 0;
}

template <class T> struct greater : binary_function <T,T,bool> {
  bool operator() (const T& x, const T& y) const {return x > y;}
};