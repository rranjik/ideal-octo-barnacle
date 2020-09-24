class Solution {
public:
    pair<string, string> findFileAndContents(string f){
        auto bs = f.find('(', 0);
        string fileName;
        string contents;
        fileName = f.substr(0, bs);
        contents = f.substr(bs+1, string::npos);
        contents.pop_back();
        return pair<string, string>(fileName, contents);
    }
    vector<pair<string, string>> pathAndContents(string s){
        vector<pair<string, string>> res;
        auto space = s.find(' ', 0);
        string dirp = s.substr(0, space);
        int last_pos = space+1;
        int pos = 0;
        while((pos = s.find(' ', last_pos))!=string::npos){
            string nameAndContent = s.substr(last_pos, pos-last_pos);
            auto nameAndContentSeperated = findFileAndContents(nameAndContent);
            last_pos = pos+1;
            string fp = dirp+"/"+nameAndContentSeperated.first;
            string c = nameAndContentSeperated.second;
            res.push_back(pair<string, string>(fp, c));
        }
        string lastFileAndContent = s.substr(last_pos, string::npos);
        auto nameAndContent = findFileAndContents(lastFileAndContent);
        string fp = dirp+"/"+nameAndContent.first;
        string c = nameAndContent.second;
        res.push_back(pair<string, string>(fp, c));
        return res;
    }
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<pair<string, string>> files;
        unordered_map<string, vector<string>> m;
        for(const auto& p : paths){
            auto fap = pathAndContents(p);
            for(const auto& fp : fap){
                cout<<fp.first<<" "<<fp.second<<endl;
                m[fp.second].push_back(fp.first);
            }
        }
        vector<vector<string>> res;
        for(const auto it : m){
            if(it.second.size()>1){
                res.push_back(it.second);
            }
        }
        return res;
    }
};
