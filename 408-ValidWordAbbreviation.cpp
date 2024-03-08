class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i = 0; int j = 0;
        int wlen = word.size();
        int alen = abbr.size();
        int num = 0;
        while(i<wlen&&j<alen){
            if(abbr[j]>='0'&&abbr[j]<='9'){
                string n;
                while(abbr[j]>='0'&&abbr[j]<='9'){
                    n+=abbr[j];
                    j++;
                }
                if(to_string(stoi(n)).size()!=n.size()||!(stoi(n))) return false;
                num = stoi(n);
            }else{
                i+=num;
                num = 0;
                if(abbr[j]!=word[i]) {
                    return false;
                }
                i++;
                j++;
            }
        }
        i+=num;
        return i==wlen&&j==alen;
    }
};
