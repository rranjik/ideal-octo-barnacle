// A hash function used to hash a pair of any kind 
struct hash_pair { 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const
    { 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    } 
}; 

class Solution {
    string q;
    unordered_map<pair<int, int>, bool, hash_pair> t;
    size_t longest_seen_so_far = 0;
    string answer;
public:
    bool isPalindrome(size_t start, size_t end){
        //cout<<"checking if palindrome. Start = "<< start << " End = "<< end<< endl;
        auto coor = pair<int, int>(start, end);
        if(t.find(coor)!=t.end()){
            //cout<<" found already"<<endl;
            return t[coor];
        }
        else if(start == end || (end - start == 1)){
            t.insert(pair<pair<int, int>, bool>(coor, true));
            return true;
        }
        else{
            if(q[start] == q[end-1]){
                return isPalindrome(start+1, end-1);
            }
            else {
                t.insert(pair<pair<int, int>, bool>(coor, false));
                //t.insert(coor, true);
                return false;
            }
        }
    }
    void generateAllSubstringOfL(string s, size_t length){
        //cout<<"generating all substring of L = "<<length<<endl;
        size_t start = 0;
        size_t end = start + length;
        while(end<=s.length()){
            //cout<<"start = "<< start << " end = " << end<< endl;
            auto ans = isPalindrome(start, end);
            if(ans){
                if(longest_seen_so_far <(string(s.begin()+start, s.begin()+end)).length()){
                    answer = string(s.begin()+start, s.begin()+end);
                } 
            }
            //cout<< (string(s.begin()+start, s.begin()+end))<< " is " << (ans ? "a palindrome" : "not a palindrome") <<endl;
            start +=1;
            end +=1;
        }
    }
    string longestPalindrome(string s) {
        q = s;
        for(size_t i = 0; i<=s.length(); i++){
            generateAllSubstringOfL(s, i);
        }
        return answer;
    }
};
