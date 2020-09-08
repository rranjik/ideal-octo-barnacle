class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string> words;
        int pos = 0;
        int last_pos = 0;
        while((pos = s.find(' ', last_pos))!=string::npos){
            string word = s.substr(last_pos, pos-last_pos);
            words.push_back(word);
            last_pos = pos+1;
        }
        string lastword = s.substr(last_pos, string::npos);
        words.push_back(lastword);
        cout<<"words follow "<<endl;
        for(const auto& w : words){
            cout<<w<<" "<<w.length()<<endl;
        }
        cout<<"words end"<<endl;
        vector<string> vert;
        for(int i = 0; i<words.size(); i++){
            if(words[i].length()>vert.size()){
                int na = words[i].length()-vert.size();
                vector<string> nas(na);
                for(auto& s : nas){
                    s.insert(0, i, ' ');
                }
                vert.insert(vert.end(), nas.begin(), nas.end());
            }
            for(int j = 0; j<words[i].length(); j++){
                vert[j]+=words[i][j];
                //if(j<vert.size()){
                //}else{
                //    vert.push_back(ns);
                //    vert[j]+=words[i][j];
                //}
            }
            for(int k = words[i].length(); k<vert.size(); k++){
                vert[k]+=((char)(32)) ;
            }
        }
        for(auto& s : vert){
            int lws = s.find_last_not_of(' ');
            auto sws = s.substr(0, lws+1);
            s = sws;
            cout<<s<<endl;
        }
        return vert;
    }
};
