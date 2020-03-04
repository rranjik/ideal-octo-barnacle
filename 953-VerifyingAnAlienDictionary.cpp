string dict;
class Solution {
public:
    struct cmps{
        bool operator()(const string& a, const string& b)const {
            int i = 0;
            int j = 0;
            while(i<a.length()&& j<b.length()){
                cout<<"comapring "<<a[i]<<" "<<b[j]<<endl;
                cout<<"values "<<dict.find(a[i])<<" "<<dict.find(b[j])<<endl;
                if(dict.find(a[i])<dict.find(b[j])){
                    cout<<"returns true"<<endl;
                    return true;
                }else if(dict.find(a[i])>dict.find(b[j])){
                    cout<<"returns false"<<endl;
                    return false;
                }
                i++;
                j++;
            }
            if(i<a.length())
                return false;
            else return true;
        }
    };
    bool isAlienSorted(vector<string>& words, string order) {
        dict = order;
        return is_sorted(words.begin(), words.end(), cmps());
    }
};
