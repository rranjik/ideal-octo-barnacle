class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> m;
        for(auto ss : strings){
            auto s = ss;
            int i = 0;
            //try alls possible shifts by 1 
            //there are only 26 possible shifts
            for(;i<26;i++){
                //((c%97+1)%26)+97
                //c%97 => what's the index of this char in the alphabets ?
                //(c%97)+1 => what's the next letter's index ?
                //((c%97)+1)%26 => wrap index around, z+1 <-> a
                //(((c%97)+1)%26)+97 => get the next char
                transform(begin(s), end(s), begin(s), [](unsigned char c){return (char) (((c%97)+1)%26)+97;});
                //cout<<"i = "<<i<<" ss = "<<ss<<" s = "<<s<<endl;
                if(m.find(s)!=m.end()){
                    //if at some point you see a previous shift
                    m[s].push_back(ss);
                    //stop!
                    break;
                }
            }
            //unique shift never seen before 
            //s and ss must be same becaue we've done one full round
            if(i==26) m[s].push_back(s);
        }
        vector<vector<string>> res;
        for(auto it = m.begin(); it!=m.end(); it++){
            res.push_back(it->second);
        }
        return res;
    }
};
