class ZigzagIterator {
private:
	vector<vector<int>::iterator> its;
	vector<vector<int>::iterator> ends;
	int index;
	int nextVal;
public:
	ZigzagIterator(vector<int>& v1, vector<int>& v2){
		index = 0;
		its.push_back(v1.begin());
		its.push_back(v2.begin());
		ends.push_back(v1.end());
		ends.push_back(v2.end());
	}
	int next(){
		return nextVal;
	}
	bool hasNext(){
		int count = 0;
		while(its[index] == ends[index] && count < its.size()){
			index = (index + 1) % 2;
			count++;
		}
		if(count == its.size())
			return false;
		nextVal = *its[index];
		its[index]++;
		index = (index + 1) % 2;
		return true;
	}
};

class ZigzagIterator {
private:
	vector<vector<int>::iterator> its;
	vector<vector<int>::iterator> ends;
	int index;
	int nextVal;
public:
	ZigzagIterator(vector<int>& v1, vector<int>& v2){
		index = 0;
		its.push_back(v1.begin());
		its.push_back(v2.begin());
		ends.push_back(v1.end());
		ends.push_back(v2.end());
	}
	int next(){
		if(its[0] == ends[0])
			return *its[1]++;
		if(its[1] == ends[1])
			return *its[0]++;
		int val = *its[index]++;
		index = (index + 1) % 2;
		return val;
	}
	bool hasNext(){
		for(int i = 0; i < its.size(); i++)
			if(its[i] != ends[i])
				return true;
		return false;
	}
};