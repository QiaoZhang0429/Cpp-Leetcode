class ValidWordAbbr {
private:
    unordered_map<string, unordered_set<string>> abbr;
public:
    ValidWordAbbr(vector<string> &dictionary) {
        for(auto w:dictionary){
            if(w.length() <= 2)
                abbr[w].insert(w);
            else
                abbr[w[0]+to_string(w.length()-2)+w.back()].insert(w);
        }
    }

    bool isUnique(string word) {
        string abbreviation = word.length() <= 2 ? word : word[0]+to_string(word.length()-2)+word.back();
        if(abbr.find(abbreviation) == abbr.end())
            return true;
        if(abbr[abbreviation].find(word) != abbr[abbreviation].end() && abbr[abbreviation].size() == 1)
            return true;
        return false;
    }
};