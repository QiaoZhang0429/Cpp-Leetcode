#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution { 
private:
	unordered_map<char, char> stroMap;
	vector<string> same;
	int rslt; 
	string low;
	string high; 
public:   
    int strobogrammaticInRange(string low, string high) { 
    	this->rslt = 0;
    	this->low = low;
    	this->high = high;
    	stroMap['0'] = '0';
    	stroMap['1'] = '1';
    	stroMap['6'] = '9';
    	stroMap['8'] = '8';
    	stroMap['9'] = '6';
    	same.push_back("0");
    	same.push_back("1");
    	same.push_back("8");
    	for(int i = low.length(); i <= high.length(); i++)
    		dfs(i, ""); 
    	return rslt; 
    }
    void dfs(int n, string tmp){
    	if(n == 0){
    		if(tmp.length() == low.length() && tmp < low)
    			return ;
    		if(tmp.length() == high.length() && tmp > high)
    			return ;
    		rslt++;
    		return ;
    	}
    	if(n % 2){
    		for(auto a:same)
    			dfs(n-1, a);
    	}
    	else{
    		for(auto a:stroMap){
    			if(n == 2 && a.first == '0')
    				continue;
    			dfs(n-2, a.first + tmp + a.second);
    		}
    	}
    }
};

/*
class Solution1 {  
public:  
    int strobogrammaticInRange(string low, string high) {  
        this->low = stoll(low);  
        this->high = stoll(high);  
        unordered_map<char, string> d;  
        d.insert(pair<char, string>('0', "0"));  
        d.insert(pair<char, string>('1', "1"));  
        d.insert(pair<char, string>('6', "9"));  
        d.insert(pair<char, string>('8', "8"));  
        d.insert(pair<char, string>('9', "6"));  
          
        unordered_map<int, vector<string> > save;  
          
        string s = "01869";  
  
        for(int i = low.length(); i <= high.length(); i++) {  
            vector<string> results;  
            int mid = i / 2;  
            string result = "";  
            bool oneMore = (bool)(i % 2);  
  
            if(oneMore && save.find(i - 1) != save.end()) {  
                for(auto j : save[i - 1]) {  
                    recursion(d, j, mid, mid, s, oneMore, results);  
                }  
            } else if(!oneMore && save.find(i - 2) != save.end()) {  
                for(auto j : save[i - 2]) {  
                    recursion(d, j, mid, mid - 1, s, oneMore, results);  
                }  
            } else {  
                recursion(d, "", mid, 0, s, oneMore, results);  
            }  
            save.insert(pair<int, vector<string> >(i, results));  
        }  
  
        return this->count;  
    }  
      
    void recursion(unordered_map<char, string> &d, string result, int recur, int iter, string s, bool &oneMore, vector<string> &results) {  
        if(iter > recur) {  
            for(int i = 0; i < 3; i++) {  
                string t = result.substr(0, recur) + s[i] + result.substr(recur);  
                long long r = stoll(t);  
                if(r <= this->high && r >= this->low) {  
                    this->count++;  
                    results.push_back(t);  
                }  
            }  
            return;  
        }  
        if(iter == recur) {  
            if(oneMore) {  
                recursion(d, result, recur, iter + 1, s, oneMore, results);  
            } else {  
                long long r = stoll(result);  
                if(r <= this->high && r >= this->low) {  
                    this->count++;  
                    results.push_back(result);  
                }  
            }  
            return;  
        }  
        if(iter == 0) {  
            for(int i = 1; i < 5; i++) {  
                recursion(d, s[i] + d[s[i]], recur, iter + 1, s, oneMore, results);  
            }  
        } else {  
            for(int i = 0; i < 5; i++) {  
                recursion(d, result.substr(0, iter) + s[i] + d[s[i]] + result.substr(iter), recur, iter + 1, s, oneMore, results);  
            }  
        }  
    }  
      
private:  
    long long low, high;  
    int count = 0;  
}; */

int main(){
	Solution s;
	cout << s.strobogrammaticInRange("1", "89998");
	Solution1 s1;
	cout << s1.strobogrammaticInRange("1", "89998");
	return 0;
}






























/*
class Solution {
public:
    Solution() {
        mp = {{'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};
    }
    
    int strobogrammaticInRange(string low, string high) {
        int ans = 0, l = low.length(), u = high.length();
        for (int i = l; i <= u; i++) {
            string temp(i, ' ');
            strobogrammaticCount(temp, ans, low, high, 0, i - 1);
        }
        return ans;
    }
private:
    unordered_map<char, char> mp;
    void strobogrammaticCount(string temp, int& ans, string& low, string& high, int lo, int hi) {
        if (lo > hi) {
            if ((temp[0] != '0' || temp.length() == 1) && less(low, temp) && less(temp, high))
                ans++;
            return;
        }
        for (auto m : mp) {
            temp[lo] = m.first;
            temp[hi] = m.second;
            if ((lo == hi && m.first == m.second) || lo < hi)
                strobogrammaticCount(temp, ans, low, high, lo + 1, hi - 1);
        }
    }
    bool less(string& s, string& t) {
        int m = s.length(), n = t.length(), i;
        if (m != n) return m < n;
        for (i = 0; i < m; i++)
            if (s[i] == t[i]) continue;
            else break;
        return i == m || s[i] < t[i];
    }
};
*/