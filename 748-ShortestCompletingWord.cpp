class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> f(26, 0);
        for(const auto& c : licensePlate){
            if(isalpha(c)){
                auto cc = tolower(c);
                f[cc-'a']++;
            }
        }
        cout<<licensePlate<<endl;
        for(int i = 0; i<26; i++){
            if(f[i]){
                cout<<static_cast<char>('a'+i)<<f[i];
            }
        }
        cout<<endl;
        vector<pair<string, int>> wi;
        for(int i = 0; i<words.size(); i++){
            wi.push_back({words[i], i});
        }
        sort(wi.begin(), wi.end(), [](const pair<string, int>& a, const pair<string, int>& b){
            if(a.first.length()!=b.first.length()){
                return a.first.length()<b.first.length();
            }
            return a.second<b.second;
        });
        for(const auto& wii : wi){
            vector<int> ff(26, 0);
            auto w = wii.first;
            for(const auto& c : w){
                if(isalpha(c)&&f[c-'a']&&ff[c-'a']<f[c-'a']){
                    auto cc = tolower(c);
                    ff[cc-'a']++;
                }
            }
            cout<<w<<endl;
            for(int i = 0; i<26; i++){
                if(ff[i]){
                    cout<<static_cast<char>('a'+i)<<ff[i];
                }
            }
            cout<<endl;
            if(f==ff) return w;
        }
        return {};
    }
};
