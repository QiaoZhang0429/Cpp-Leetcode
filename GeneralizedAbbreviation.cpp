class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> rslt;
        string tmp = "";
        bt(rslt, tmp, word, 0, 0);
        return rslt;
    }
    void bt(vector<string>& rslt, string& tmp, string& word, int pos, int abbreviated){
        int tmpSize = tmp.length();
        if(pos == word.length()){
            if(abbreviated > 0)
                tmp += to_string(abbreviated);
            rslt.push_back(tmp);
            tmp.resize(tmpSize);
            return ;
        }
        //abbreviate word[pos]
        bt(rslt, tmp, word, pos+1, abbreviated+1);
        //not abbreviate word[pos]
        if(abbreviated > 0)
            tmp += to_string(abbreviated);
        tmp += word[pos];
        bt(rslt, tmp, word, pos+1, 0);//abbreviated is the number of abbreviated char before word[pos]
        tmp.resize(tmpSize);//for backtracking
    }
};