class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        if(input.length()==0)
            return res;
        for(int i = 0; i<input.size(); i++){
            if(input[i]=='+'||input[i]=='*'||input[i]=='-'){
                vector<int> left = diffWaysToCompute(input.substr(0,i));
                vector<int> right = diffWaysToCompute(input.substr(i+1, input.size()));
                for(int j = 0; j<left.size(); j++){
                    for(int k = 0; k<right.size(); k++){
                        if(input[i]=='+')
                            res.push_back((left[j]+right[k]));
                        else if(input[i]=='-')
                            res.push_back((left[j]-right[k]));
                        else 
                            res.push_back((left[j]*right[k]));
                    }
                }
            }
        }
        if(res.size()==0)
            res.push_back(stoi(input));
        return res;
    }
};
