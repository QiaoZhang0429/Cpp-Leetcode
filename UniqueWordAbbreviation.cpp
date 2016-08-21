class ValidWordAbbr {
private:
	unordered_map<string, unordered_set<string>> abbrHash;
public:
	ValidWordAbbr(vector<string> &dictionary) {
		for(auto d:dictionary){
			string abbr = d;
			if(d.length() > 2)
				abbr = d.front() + to_string((int)(d.length())-2) + d.back();
			abbrHash[abbr].insert(d);
		}
	}
	bool isUnique(string word) {
		string abbr = word;
		if(word.length() > 2)
			abbr = word.front() + to_string((int)(word.length())-2) + word.back();
		if(abbrHash.find(abbr) == abbrHash.end())
			return true;
		else if(abbrHash[abbr].size() == 1 && abbrHash[abbr].find(word) != abbrHash[abbr].end())
			return true;
		return false;
	}
};
// Your ValidWordAbbr object will be instantiated and called as such:
// ValidWordAbbr vwa(dictionary);
// vwa.isUnique("hello");
// vwa.isUnique("anotherWord");