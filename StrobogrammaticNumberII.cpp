class Solution{
private:
	vector<string> rslt;
	vector<string> single{"0", "1", "8"};
	vector<pair<char,char>> stroMap{{'0','0'}, {'1','1'}, {'6','9'}, {'8','8'}, {'9','6'}};
public: 
	vector<string> findStrobogrammatic(int n){
		dfs(n ,"");
		return rslt;
	}
	void dfs(int n, string str){
		if(n == 0)
			return rslt.push_back(str);
		if(n % 2 == 1){
			for(auto s:single)
				dfs(n-1, s);
		}
		else{
			for(int i = (n == 2)? 1:0; i < stroMap.size(); i++)
				dfs(n-2, stroMap[i].first + str + stroMap[i].second);
		}

	}
};

class Solution{
private:
	vector<pair<char,char>> stroMap{{'0','0'}, {'1','1'}, {'6','9'}, {'8','8'}, {'9','6'}};
public: 
	vector<string> findStrobogrammatic(int n){
		vector<string> rslt;
		if(n == 0)
			return vector<string>(1, "");
		if(n == 1){
			rslt.push_back("0");
			rslt.push_back("1");
			rslt.push_back("8");
		}
		else{
			vector<string> tmp = findStrobogrammatic(n-2);
			for(auto t:tmp)
				for(auto s:stroMap)
					rslt.push_back(s.first + t + s.second);
		}
		for(auto it = rslt.begin(); it != rslt.end(); it++)
			if((int)(*it.length()) == 1 && *it[0] == '0')
				rslt.erase(it);
		return rslt;
	}
};