//Amazon Online Assessment (sample)
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


/*
 * Complete the 'processLogs' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts following parameters:
 *  1. STRING_ARRAY logs
 *  2. INTEGER threshold
 */

vector<string> processLogs(vector<string> logs, int threshold) {
    unordered_map<int, int> uidc;
    for(const auto& s : logs) {
        //cout<<s<<"\n";
        stringstream ss(s);
        vector<int> v;
        while(ss){
            int x;
            ss>>x;
            v.push_back(x);
        }
        v.pop_back();
        //for(const auto& b : v) cout<<b<<" * "; cout<<endl;
        if(v[0]!=v[1]){
            uidc[v[1]]++;           
            uidc[v[0]]++;
        }else{
            uidc[v[0]]++;
        }
    }
    vector<int> res;
    for(const auto& [udi, c]: uidc){
        if(c>=threshold)
            res.push_back(udi);
    }
    sort(res.begin(), res.end());
    vector<string> ress;
    for(const auto& g : res){
        ress.push_back(to_string(g));
    }
    return ress;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string logs_count_temp;
    getline(cin, logs_count_temp);

    int logs_count = stoi(ltrim(rtrim(logs_count_temp)));

    vector<string> logs(logs_count);

    for (int i = 0; i < logs_count; i++) {
        string logs_item;
        getline(cin, logs_item);

        logs[i] = logs_item;
    }

    string threshold_temp;
    getline(cin, threshold_temp);

    int threshold = stoi(ltrim(rtrim(threshold_temp)));

    vector<string> result = processLogs(logs, threshold);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }G

    fout << "\n";

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
