class Solution {
public:
    string reverseOnlyLetters(string S) {
        string letters;
        for(const auto& c : S){
            if(isalpha(c)) letters.push_back(c);
        }
        reverse(begin(letters), end(letters));
        for(int i = 0, j = 0; i<S.size(); i++){
            if(isalpha(S[i])){
                S[i] = letters[j];
                j++;
            }
        }
        return S;
    }
};
