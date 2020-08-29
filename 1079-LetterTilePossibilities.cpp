class Solution {
public:
    int dfs(vector<int>& freq){
        int sum = 0;
        for(int i = 0; i<26; i++){
            if(freq[i]){
                sum++;
                freq[i]--;
                sum+=dfs(freq);
                freq[i]++;
            }
        }
        return sum;
    }
    int numTilePossibilities(string tiles) {
        vector<int> freq(26, 0);
        for(const auto& t : tiles){
            freq[t-'A']++;
        }
        cout<<"freq done"<<endl;
        return dfs(freq);
    }
};
