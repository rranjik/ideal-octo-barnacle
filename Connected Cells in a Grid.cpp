#include <bits/stdc++.h>

using namespace std;

void DFS(int source, vector<int>& component, vector<pair<bool, vector<int>>>& adj_list){
    adj_list[source].first = true;
    component.push_back(source);
    for(auto node: adj_list[source].second){
        if(!adj_list[node].first){
            DFS(node, component, adj_list);
        }
    }
}

int max_connected_component(vector<pair<bool, vector<int>>>& adj_list)
{
    int max = 0;
    for(int i=0; i<adj_list.size();i++){
        if(!adj_list[i].first){
            vector<int> component;
            DFS(i, component, adj_list);
            if(component.size()>max)
                max = component.size();
        }
    }
    return max;
}

// Complete the connectedCell function below.
int connectedCell(vector<vector<int>> matrix) {
    vector<pair<bool, vector<int>>> adj_list(matrix.size()*matrix[0].size());
        for(auto n : adj_list){
            n.first = false;
    }
    for(int r=0; r<matrix.size(); r++){
        for(int c=0; c<matrix[r].size(); c++ ){
            if(matrix[r][c]==1){
                if(r-1>=0&&c-1>=0&&matrix[r-1][c-1]==1)
                    adj_list[(r*(matrix[0].size()))+c].second.push_back
                        (((r-1)*(matrix[0].size()))+(c-1));
                if(c-1>=0&&matrix[r][c-1]==1)
                    adj_list[(r*(matrix[0].size()))+c].second.push_back
                        (((r)*(matrix[0].size()))+(c-1));
                if(r+1<matrix.size()&&c-1>=0&&matrix[r+1][c-1]==1)
                    adj_list[(r*(matrix[0].size()))+c].second.push_back
                        (((r+1)*(matrix[0].size()))+(c-1));
                if(r+1<matrix.size()&&matrix[r+1][c]==1)
                    adj_list[(r*(matrix[0].size()))+c].second.push_back
                        (((r+1)*(matrix[0].size()))+(c));
                if(r+1<matrix.size()&&c+1<matrix[0].size()&&matrix[r+1][c+1]==1)
                    adj_list[(r*(matrix[0].size()))+c].second.push_back
                        (((r+1)*(matrix[0].size()))+(c+1));
                if(c+1<matrix[0].size()&&matrix[r][c+1]==1)
                    adj_list[(r*(matrix[0].size()))+c].second.push_back
                        (((r)*(matrix[0].size()))+(c+1));
                if(r-1>=0&&c+1<matrix[0].size()&&matrix[r-1][c+1]==1)
                    adj_list[(r*(matrix[0].size()))+c].second.push_back
                        (((r-1)*(matrix[0].size()))+(c+1));
                if(r-1>=0&&matrix[r-1][c]==1)
                    adj_list[(r*(matrix[0].size()))+c].second.push_back
                        (((r-1)*(matrix[0].size()))+(c));
            }
        }
    }
    // for(int n = 0; n< adj_list.size(); n++){
    //     cout<<n<<" -> ";
    //     for(const auto& node : adj_list[n].second){
    //         cout<<node<<" -> ";
    //     }
    //     cout<<endl;
    // }
    return max_connected_component(adj_list);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> matrix(n);
    for (int i = 0; i < n; i++) {
        matrix[i].resize(m);

        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = connectedCell(matrix);

    fout << result << "\n";

    fout.close();

    return 0;
}
