class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int l = 0;
        int r = s.size()-1;
        while(l<r){
            while(l<s.length()&&(vowels.find(s[l])==vowels.end()))
                l++;
            while(r>=0&&(vowels.find(s[r])==vowels.end()))
                r--;
            cout<<"l = "<<l<<"; r = "<<r<<endl;
            if(l<r){
                swap(s[l], s[r]);
                l++; r--;
            }
        }
        return s;
    }
};
