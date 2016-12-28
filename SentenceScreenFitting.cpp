class Solution {
public:
    int wordsTyping(vector<string>& strs, int rows, int cols) {
        string str = "";
        for (string& s: strs)
            str += s + ' ';
        int count = 0, n = str.size();
        while (rows--) {
            count += cols;
            if (str[count % n] == ' ') 
                count++;
            else {
                while (count % n && str[count % n - 1] != ' ') 
                    count--; 
            }
        }
        return count / n;
    }
    /*
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        vector<int> cnt(sentence.size(), 0);
        vector<int> next(sentence.size(), 0);
        for(int i = 0; i < sentence.size(); i++){
            int k = i;
            int left = cols;
            int count = 0;
            while(left >= sentence[k].length()){
                left -= (int)sentence[k].length();
                left--;//white space separator
                k++;
                if(k == sentence.size()){
                    k = 0;
                    count++;
                }
            }
            cnt[i] = count;
            next[i] = k;
        }
        int rslt = 0;
        int cur = 0;
        for(int i = 0; i < rows; i++){
            rslt += cnt[cur];
            cur = next[cur];
        }
        return rslt;
    }
    */
    /* brute force TLE
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int k = 0;//sentence index
        int count = 0;
        int left;//space left in this row
        for(int i = 0; i < rows; i++){
            left = cols;
            while(left >= sentence[k].length()){
                left -= (int)sentence[k].length();
                left--;//white space separator
                k++;
                if(k == sentence.size()){
                    k = 0;
                    count++;
                }
            }
        }
        return count;
    }
    */
};