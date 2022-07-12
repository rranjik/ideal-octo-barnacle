#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'calculateCost' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
*/

vector<int> A;

map<pair<int, int>, pair<int, int>> c;

pair<int, int> dfs(int i, int j){
    cout<<"i = "<<i<<"; j = "<<j<<endl;
    pair<int, int> p = make_pair(i, j);
    if(c.find(p)!=c.end()) {
        cout<<"i = "<<i<<"; j = "<<j<<
        "; returns res = "<<c[p].first<<", "<<c[p].second<<endl;
        return c[p];
    }
    //if(i>j||i<0||i>=A.size()||j<0||j>=A.size()) {
    //    c[p] = 1e9;
    //    cout<<"i = "<<i<<"; j = "<<j<<"; returns 1e9"<<endl;
    //    return 1e9;
    //}
    if(i==j) {
        cout<<"i = "<<i<<"; j = "<<j<<"; returns equal = "<<0<<", "<<A[i]<<endl;
        c[p] = make_pair(0, A[i]);
        return {0, A[i]};
    }
    int res = 1e9;
    auto m = 0;
    for(int k = i; k<j; k++){
        auto l = dfs(i, k);
        auto r = dfs(k+1, j);
        if(res>l.first+r.first+(l.second*r.second)){
            m = max(l.second, r.second);
            res = l.first+r.first+(l.second*r.second);
        }
    }
    c[p] = make_pair(res, m);
    cout<<"i = "<<i<<"; j = "<<j<<
    "; returns cache = "<<res<<", "<<m<<endl;
    return {res, m};
}
int calculateCost(vector<int> arr) {
    c.clear();
    A = arr;
    int m = 0;
    auto res = dfs(0, arr.size()-1);
    cout<<"max of entire tree = "<<res.second<<endl;
    return res.first;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string arr_count_temp;
    getline(cin, arr_count_temp);

    int arr_count = stoi(ltrim(rtrim(arr_count_temp)));

    vector<int> arr(arr_count);

    for (int i = 0; i < arr_count; i++) {
        string arr_item_temp;
        getline(cin, arr_item_temp);

        int arr_item = stoi(ltrim(rtrim(arr_item_temp)));

        arr[i] = arr_item;
    }

    int result = calculateCost(arr);

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
