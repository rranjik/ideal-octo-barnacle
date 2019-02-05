#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the gridSearch function below.
string gridSearch(vector<string> G, vector<string> P) {
    cout<<"hello"<<endl;
    cout<<"(G[0].length())-(P[0].length())+1) = "<<(G[0].length())-(P[0].length())+1<<endl;
    for(auto g = 0;g<=G.size()-P.size()+1;g++)
    {   
        int index=-1;
        auto first_time = false;
        cout<<index<<endl;
        if(index<=((G[0].length())-(P[0].length())+1))
            cout<<"!@#$"<<endl;
        while(!first_time || ((index<=((G[0].length())-(P[0].length())+1)) && index!=std::string::npos))
        {
            cout<<"entering while"<<endl;
            first_time = true;
            index = G[g].find(P[0], index+1);
            if(index!=std::string::npos)
            {
              auto gc = g;
              bool flag = false;
              for (auto p = 1; p < P.size() && !flag; p++) {
                gc++;
                cout<<"found at p = "<<p<<" g = "<<gc<<endl;
                if (G[gc].find(P[p], index) == std::string::npos || 
                    G[gc].find(P[p], index) > index )
                  flag = true;
                  else{cout<<"found at p = "<<p<<" g = "<<gc<<endl;}
              }
                if(!flag)
                    return "YES";
            }
        }
    }
    return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string RC_temp;
        getline(cin, RC_temp);

        vector<string> RC = split_string(RC_temp);

        int R = stoi(RC[0]);

        int C = stoi(RC[1]);

        vector<string> G(R);

        for (int i = 0; i < R; i++) {
            string G_item;
            getline(cin, G_item);

            G[i] = G_item;
        }

        string rc_temp;
        getline(cin, rc_temp);

        vector<string> rc = split_string(rc_temp);

        int r = stoi(rc[0]);

        int c = stoi(rc[1]);

        vector<string> P(r);

        for (int i = 0; i < r; i++) {
            string P_item;
            getline(cin, P_item);

            P[i] = P_item;
        }

        string result = gridSearch(G, P);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
    