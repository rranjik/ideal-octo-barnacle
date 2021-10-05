class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        vector<int> positivesat;
        vector<int> negativesat;
        for(const auto& sat : satisfaction) if(sat>=0) positivesat.push_back(sat);
        for(const auto& sat : satisfaction) if(sat<0) negativesat.push_back(sat);
        if(positivesat.size()==0) return 0;
        sort(positivesat.begin(), positivesat.end());
        sort(negativesat.begin(), negativesat.end(), greater<int>());
        for(const auto& n : negativesat) cout<<n<<" "; cout<<endl;
        int last{};
        for(int i = 0; i<positivesat.size(); i++) last+=((i+1)*positivesat[i]);
        cout<<"just postive = "<<last<<endl;
        for(int i = 0; i<negativesat.size(); i++){
            int includeinegative = 0;
            for(int j = i, k = 0; j>=0; j--, k++) 
                includeinegative += ((k+1)*negativesat[j]);
            for(int j = 0; j<positivesat.size(); j++){
                includeinegative += ((i+1+j+1)*positivesat[j]);
            }
            cout<<"include first "<<i+1<<" negative "<<includeinegative<<endl;
            if(includeinegative<last) break;
            else last = includeinegative;
        }
        return last;
    }
};
