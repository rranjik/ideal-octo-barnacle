
#include <bits/stdc++.h>

using namespace std;

// Complete the sherlockAndAnagrams function below.
int sherlockAndAnagrams(string s) {
    int res = 0;
    map<vector<int>, int> freq;
    vector<int> b(26, 0);
    for(int i = 0; i<s.length(); i++){
        b = vector<int> (26,0);
        for(int j = i; j< s.length(); j++){
            b[s[j]-'a']++;
            freq[b]++;
        }
    }
    for(auto it = freq.begin(); it!=freq.end(); it++){
        res += ((it->second)*((it->second)-1))/2;
    }
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = sherlockAndAnagrams(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
