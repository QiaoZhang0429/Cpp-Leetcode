#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {  
private:
	unordered_map<char, unordered_set<char> > adjList;
	unordered_map<char, int> inDegree;
	string order;
public:  
    string alienOrder(vector<string>& words) {
    	constructGraph(words);
    	topologicalSort();
    	return order.length() == inDegree.size() ? order : "";
    }
    void constructGraph(vector<string>& words){
    	for(int i = 0; i < words.size(); i++){
    		for(int j = 0; j < words[i].length(); j++){
    			adjList[words[i][j]] = unordered_set<char>();
    			inDegree[words[i][j]] = 0;
    		}
    	}
    	for(int i = 1; i < words.size(); i++){
    		string cur = words[i];
    		string pre = words[i-1];
    		for(int j = 0; j < min(pre.length(), cur.length()); j++){
    			if(cur[j] != pre[j]){
    				adjList[pre[j]].insert(cur[j]);
    				inDegree[cur[j]]++;
    				break;
    			}
    		}
    	}
    }
    void topologicalSort(){
    	queue<char> q;
    	//for(auto it = inDegree.begin(); it != inDegree.end(); it++)
    	for(auto it:inDegree)
    		if(it.second == 0)
    			q.push(it.first);
    	while(!q.empty()){
    		char v = q.front();
    		q.pop();
    		order.push_back(v);
    		for(auto w:adjList[v])
    			if(--inDegree[w] == 0)
    				q.push(w);
    	}
    }
};

int main(){
	vector<string> words;
	words.push_back("wrt");
	words.push_back("wrf");
	words.push_back("er");
	words.push_back("ett");
	words.push_back("rftt");
	Solution s;
	cout << s.alienOrder(words);
	return 0;
}