
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

vector<pair<int, int>> vaild_childen(const pair<int, int> src, const vector<string>& matrix){
    vector<pair<int, int>> children;
    if(src.first>0 && matrix[src.first-1][src.second]!='X'){
       children.push_back(pair<int, int>(src.first-1, src.second));
    }
    if(src.first<matrix.size()-1 && matrix[src.first+1][src.second]!='X'){
       children.push_back(pair<int, int>(src.first+1, src.second));
    }
    if(src.second>0 && matrix[src.first][src.second-1]!='X'){
       children.push_back(pair<int, int>(src.first, src.second-1));
    }
    if(src.second<matrix[0].length()-1 && matrix[src.first][src.second+1]!='X'){
       children.push_back(pair<int, int>(src.first, src.second+1));
    }
    return children;
}

pair<bool, int> DFS(const pair<int, int>& parent,
    const pair<int, int> src, 
                    const vector<string>& matrix, 
                    vector<vector<bool>>& visit){
   
    //cout<<"DFS at " << src.first <<" " << src.second <<endl;
    pair<bool, int> res(false, 0);
    if(!visit[src.first][src.second]){
        visit[src.first][src.second]= true;
        if(matrix[src.first][src.second]=='*'){
            res.first = true;
            res.second = 0;
        }
        else{
            auto children = vaild_childen(src, matrix);
            children.erase(
                remove_if(children.begin(), children.end(), 
                [&](pair<int, int> p){return p==parent;}), 
                children.end());
            for(size_t i = 0; i<children.size()&&!res.first; i++){
                auto ret = DFS(src, children[i], matrix, visit);
                if(ret.first){
                   res.first= true;
                   if(children.size()>1)
                   res.second += (ret.second+1); 
                   else 
                   res.second = ret.second;
                }
            }
        }
    }
    //cout<<src.first<<" "<<src.second<<" retruning " <<boolalpha << res.first <<" " << res.second <<endl;
    return res;
}

// Complete the countLuck function below.
string countLuck(vector<string> matrix, int k) {
    vector<vector<bool>> visited(matrix.size(), vector<bool>(matrix[0].length(), false));
    auto res = 0;
    for(size_t r = 0; r<matrix.size(); r++)
    {
        for(size_t c = 0; c<matrix[0].length(); c++)
        {
            if(matrix[r][c]=='M'){
              //cout<<"starting at " << r <<" " <<c <<endl;
              res = DFS(pair<int, int> (-1, -1), pair<int, int>(r,c), matrix, visited).second;

            }
        }
    }
    if(res==k)
    return "Impressed";
    else return "Oops!"; 
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string nm_temp;
        getline(cin, nm_temp);

        vector<string> nm = split_string(nm_temp);

        int n = stoi(nm[0]);

        int m = stoi(nm[1]);

        vector<string> matrix(n);

        for (int i = 0; i < n; i++) {
            string matrix_item;
            getline(cin, matrix_item);

            matrix[i] = matrix_item;
        }

        int k;
        cin >> k;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string result = countLuck(matrix, k);

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
