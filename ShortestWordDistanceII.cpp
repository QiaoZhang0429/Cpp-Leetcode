class WordDistance {
private:
	unordered_map<string, vector<int>> indices;
public:
	WordDistance(vector<string>& words) {
		for(int i = 0; i < words.size(); i++)
			indices[words[i]].push_back(i);
	}

	int shortest(string word1, string word2) {
		vector<int>& index1 = indices[word1];
		vector<int>& index2 = indices[word2];
		int i = 0, j = 0;
		int minDist = INT_MAX;
		while(i < index1.size() && j < index2.size()){
			minDist = min(minDist, abs(index1[i] - index2[j]));
			if(index1[i] < index2[j])
				i++;
			else
				j++;
		}
		return minDist;
	}
};