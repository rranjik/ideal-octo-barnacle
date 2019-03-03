
#include <bits/stdc++.h>

using namespace std;

// Complete the substrCount function below.
long substrCount(int n, string s) {
    vector<pair<char, int>> freq;
    char last = s[0];
    int count = 1;
    for(int i=1; i<s.length(); i++){
        if(s[i]==last)
            count++;
        else{
            freq.push_back(make_pair<char, int>(char(last), int(count)));
            last = s[i];
            count = 1;
        }
    }
    freq.push_back(make_pair<char, int>(char(last), int(count)));
    // for(const auto& p : freq){
    //     cout<<string(1, p.first)<<" "<<p.second<<endl;
    // }
    long ans = 0;
    for(const auto& p : freq){
        ans = ans + ((p.second*(p.second+1))/2);
    }
    for(int i = 1; i<freq.size()-1; i++){
        if(freq[i-1].first==freq[i+1].first && freq[i].second==1){
            ans = ans + min(freq[i-1].second, freq[i+1].second);
        }
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    long result = substrCount(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}
