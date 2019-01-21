#include <bits/stdc++.h>

using namespace std;

// Complete the isValid function below.
string isValid(string s) {
    //string res = "NO";
    vector<int> mapping(26, 0);
    int first = -1;
    int second = -1;
    int third = -1;
    map<int, int> real_mapping;
    for(const auto& c : s)
        mapping[((int)c-((int)'a'))]++;
    for(const auto m : mapping){
        if(m!=0)
        {
            if(first==-1)
                first = m;
            else if (first!=m){
                if(second==-1)
                    second = m;
                    else //if(second!=m)
                        return "NO";
            }
        }
    }
    cout<<"first: "<<first<<" second: "<<second<<endl;
    //cout<<"first: "<<first<<" second: "<<second<<endl;
    //cout<<"first: "<<first<<" second: "<<second<<endl;
    //cout<<"first: "<<first<<" second: "<<second<<endl;
    if(second==-1||(abs(first-second)==1||abs(first-second)==0))
        return "YES";
    else
        return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
