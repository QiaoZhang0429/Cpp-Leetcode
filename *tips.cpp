//memory
stack
pointer variables (new)

heap
static
constant
object new

//const
reference to constant must also be declared constant
constant can not be passed by reference
constant attribute can only be initialized in list of constructor
Const member functions in C++ A function becomes const when const keyword is used in function's declaration. The idea of const functions is not allow them to modify the object on which they are called.

//template
template<typename Data>
class BSTNode {
public:
    BSTNode<Data>* left; 
    BSTNode<Data>* right; 
    BSTNode<Data>* parent; 
    Data const data;
    BSTNode( const Data & d ) : data(d) {
        left = right = parent = 0;
    }
};
parent->left = new BSTNode<Data>(item);

//iterator
generalized pointer
avoid implement iterator for different container

//STL
unordered_map
    //traverse
    for(auto i:map)
        cout << i.first << " " << i.second;
    for(auto it = map.begin(); it != map.end(); it++)
        cout << it->first << " " << it->second;
map
unordered_set -- hash table
    
    //property
    value as hash key
    no duplicate

    //member function 
    empty();
    size();

    find(key);
    count(key);//1 or 0

    insert(key);
    erase(key);
    clear();
    swap();

    //init list
    unordered_set<string> first;
    first = {"red","green","blue"};

    //copy
    first = second;
    unordered_set<string> second(first);
    unordered_set<string> second(first.begin(), first.end());

    //traverse
    for(auto &s:first)
        cout << s << " ";//value in ascending order of hash key
    
set -- RB tree 
    
    //property
    specific order
    no duplicate
    value cannot be changed once in

    //member function 
    empty();
    size();

    find(key);//iterator
    count(key);//1 or 0

    insert(key, it, it range);//T or vector<T>的iterator range
    erase(key);
    lower_bound(key);//>=
    upper_bound(key);//>
    clear();
    swap();

    //init list
    set<string> first. second;
    first = {"red","green","blue"};
    first = set<int>();

    //copy
    second = first;

    //traverse
    for(auto &s:first)
        cout << s << " ";//value in specific order

    //compare
    struct classcomp {
        bool operator() (const int& lhs, const int& rhs) const {
            return lhs < rhs;//ascending
        }
    };
    set<int, classcomp> first; 

    bool (*fn_pt)(int, int) = fncomp;
    set<int, bool(*)(int, int)> first(fn_pt);

multiset -- RB tree 

    //property
    specific order
    have duplicate
    value cannot be changed once in

    //others
    same as set
    erase(key);//erase all if there exist duplicates

priority_queue -- max heap

    //property
    root is always greater/smaller than its left subtree and right subtree

    //member function 
    empty();
    size();

    push(val);
    top();
    pop();

    swap();

    //compare
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int, vector<int>, less<int>> maxHeap;
    priority_queue<int, vector<int>, classcomp> userHeap;
    struct classcomp {
        bool operator() (const int& lhs, const int& rhs) const {
            return lhs > rhs;//min heap, true -- rhs on the top
        }
    };

queue -- FIFO

    //member function
    empty();
    size();

    push(val);
    front();
    back();
    pop();

    swap();

stack -- FILO

    //member function
    empty();
    size();

    push(val);
    top();
    pop();

    swap();

list -- doubly linked lists

    //property
    O(1) insert & erase operations anywhere within the sequence
    iteration in both directions

    //member function
    empty();
    size();
    resize();
    clear();

    front();
    back();

    push_back();
    push_front();
    pop_back();
    pop_front();

    insert();
    erase();

    splice();

deque -- double ended queue

    //property
    allow for the individual elements to be accessed directly through random access iterators
    can be expanded or contracted on both ends
    similar to vector
    efficient insertion and deletion of elements also at the beginning of the sequence
    scattered in different chunks of storage
    access of constant time with iterator

    //member function
    empty();
    size();
    resize();
    clear();

    push_back();
    push_front();
    pop_back();
    pop_front();

    front();
    back();
    at();
    []

    insert(it, (offset), val/it range);
    erase();

    swap();

vector -- array
    
    //property
    a single array that needs to be occasionally reallocated for growth

    //member function
    empty();
    size();
    resize();
    clear();

    push_back();
    pop_back();

    insert(it/index, val);//time consuming
    erase(it, index);
    []

    swap();

//algorithm
sort(.begin(), .end(), cmp);
bool cmp
accumulate(.begin(), .end(), init);

distance(.begin(), .end());

lower_bound(.begin(), .end(), key);

//left value & right value
cout << is_lvalue_reference<decltype(++i)>::value << endl;//1 - left, 0 - not right
xvalue, 
prvalue,

//string <-> int
to_string(val);
atoi(str.c_str());
stoll(str.c_str());

//Implementation
bst lower_bound upper_bound return count

//LAMBDA EXPRESSION
http://blog.csdn.net/liyongofdm/article/details/7686048

[ capture ] ( params ) mutable exception attribute -> ret { body }  (1)  
[ capture ] ( params ) -> ret { body }  (2)  
[ capture ] ( params ) { body } (3)  
[ capture ] { body }

#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
int main(){
    std::vector<int> c { 1,2,3,4,5,6,7 };
    int x = 5;
    c.erase(std::remove_if(c.begin(), c.end(), [x](int n) { return n < x; } ), c.end());
 
    std::cout << "c: ";
    for (auto i: c) {
        std::cout << i << ' ';
    }
    std::cout << '\n';
 
    // the type of a closure cannot be named, but can be inferred with auto
    auto func1 = [](int i) { return i+4; };
    std::cout << "func1: " << func1(6) << '\n'; 
 
    // like all callable objects, closures can be captured in std::function
    // (this may incur unnecessary overhead)
    std::function<int(int)> func2 = [](int i) { return i+4; };
    std::cout << "func2: " << func2(6) << '\n'; 
}

//some functions
generate_n();
template <class OutputIterator, class Size, class Generator>
void generate_n ( OutputIterator first, Size n, Generator gen ){
    while (n > 0){
        *first = gen();
        ++first; 
        --n;
    }
}
for_each();
template<class InputIterator, class Function>//function or function object type
Function for_each(InputIterator first, InputIterator last, Function fn){
    while (first!=last) {
        fn (*first);
        ++first;
    }
    return fn;      // or, since C++11: return move(fn);
}
remove_if();
template <class ForwardIterator, class UnaryPredicate>
ForwardIterator remove_if (ForwardIterator first, ForwardIterator last, UnaryPredicate pred){
    ForwardIterator result = first;
    while (first!=last) {
        if (!pred(*first)) {
            *result = *first;
            ++result;
        }
        ++first;
    }
    return result;
}

//function object
//function pointer
//template function
template <class T>
T GetMax (T a, T b) {
  T result;
  result = (a>b)? a : b;
  return (result);
}
int main () {
  int i=5, j=6, k;
  long l=10, m=5, n;
  k=GetMax<int>(i,j);
  n=GetMax<long>(l,m);
  cout << k << endl;
  cout << n << endl;
  return 0;
}
//struct