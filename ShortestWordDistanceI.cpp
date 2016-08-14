class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
    	int index1 = -1, index2 = -1;
    	int minDist = INT_MAX;
    	for(int i = 0; i < words.size(); i++){
    		if(words[i] == word1){
    			index1 = i;
    			if(index2 != -1)
    				minDist = min(minDist, index1 - index2);
    		}
    		if(words[i] == word2){
    			index2 = i;
    			if(index1 != -1)
    				minDist = min(minDist, index2 - index1);
    		}
    	}
    	return minDist;
    }
};