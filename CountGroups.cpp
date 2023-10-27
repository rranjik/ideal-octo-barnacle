//Amazon online assesment (sample)
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


/*
 * Complete the 'countGroups' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING_ARRAY related as parameter.
 */
 
void dfs(int i, vector<bool>& v, const vector<vector<int>>& adjl){
    if(v[i]) return;
    v[i] = true;
    for(const auto& c : adjl[i]){
        dfs(c, v, adjl);
    }
}

int countGroups(vector<string> related) {
    int n = related.size();
    vector<vector<int>> adjl(n);
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(i!=j&&related[i][j]=='1'){
                adjl[i].push_back(j);
            }
        }
    }
    vector<bool> v(n);
    int cc = 0;
    for(int i = 0; i<n; i++){
        if(v[i]) continue;
        cc++;
        dfs(i, v, adjl);
    }
    return cc;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string related_count_temp;
    getline(cin, related_count_temp);

    int related_count = stoi(ltrim(rtrim(related_count_temp)));

    vector<string> related(related_count);

    for (int i = 0; i < related_count; i++) {
        string related_item;
        getline(cin, related_item);

        related[i] = related_item;
    }

    int result = countGroups(related);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

