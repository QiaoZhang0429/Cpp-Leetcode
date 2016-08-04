class Solution{
public: 
	bool isStrobogrammatic(string number){
		unordered_map<char, char> stroMap;
		stroMap['0'] = '0';
		stroMap['1'] = '1';
		stroMap['6'] = '9';
		stroMap['8'] = '8';
		stroMap['9'] = '6';
		int left = 0; 
		int right = number.length() - 1;
		while(left <= right){
			if(stroMap.find(number[left]) != stroMap.end() && stroMap[number[left]] == number[right]){
				left++;
				right--;
			}
			else
				return false;
		}
		return true;
	}
};