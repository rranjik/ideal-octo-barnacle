
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

vector<vector<int>> buildAdjList(const vector<vector<int>>& edges){
    vector<vector<int>> adjlist(edges.size()+1);
    for(const auto& e : edges){
        adjlist[e[0]-1].push_back(e[1]-1);
        adjlist[e[1]-1].push_back(e[0]-1);
    }
    return adjlist;
}

void DFS(int prnt, int src, const vector<vector<int>>& adjlist, 
            /*vector<vector<int>>& children, */vector<bool>& visit, vector<int>& parent){ 
    if(!visit[src]){
        visit[src] = true;
        for(const auto& c : adjlist[src]){
           //if(!visit[c]){
           //    children[src].push_back(c);
           //}
           parent[src] = prnt;
           DFS(src, c, adjlist, /*children,*/ visit, parent);
        }
    }
}

vector<int> buildParentMatrix(int root, const vector<int>& pa){
   //cout<<"here"<<endl;
  vector<int> pam(pa);
   //reverse(pam[0].begin(), pam[0].end());
//    for(const auto& pe : pam[0]){
//        cout<<pe<<" ";
//    }
   //cout<<endl;
       pam[root] = -1;
       int curr = root;
       //cout<<"here"<<endl;
       vector<int> pathToRoot;
       pathToRoot.push_back(root);
       int parent = pa[root];
       while(parent!=-1){
           pathToRoot.push_back(parent);
           parent = pa[parent];
       }
       //cout<<"path to root "<< i <<endl;
    //    for(const auto& pow : pathToRoot){
    //        cout<<pow<<" ";
    //    }
       //cout<<endl;
       reverse(pathToRoot.begin(), pathToRoot.end());
       for(size_t j = 0; j<pathToRoot.size()-1; j++){
           pam[pathToRoot[j]] = pathToRoot[j+1];
       }
//    for(const auto& l : pam){
//        for(const auto& r : l){
//            cout<<r<< " ";
//        }
//        cout<<endl;
//    }
   return pam;
}

int gcd(int x, int y){
    if(x==0){
        return y;
    }
        return gcd(y%x, x);
}

/*
 * Complete the storyOfATree function below.
 */
string storyOfATree(int n, vector<vector<int>> edges, int k, vector<vector<int>> guesses) {
    /*
     * Write your code here.
     */
    //  for(const auto& e : edges){
    //      cout<<e[0]<<" "<<e[1]<<endl;
    //  }
    //cout<<n<<" "<<edges.size()<<" "<<k<<" "<<guesses.size()<<endl;
     auto adjlist = buildAdjList(edges);
    //  for(size_t n = 0; n<adjlist.size(); n++){
    //      cout<<n<<" -> ";
    //      for(size_t c = 0; c<adjlist[n].size(); c++){
    //          cout<<adjlist[n][c]<<" -> ";
    //      }
    //      cout<<endl;
    //  }
     vector<bool> visit(edges.size()+1, false);
     //vector<vector<int>> children(edges.size()+1, vector<int>());
     vector<int> pa(edges.size()+1); 
     DFS(-1, 0, adjlist, /*children,*/ visit, pa);
    //  for(const auto& l : children){
    //      for(const auto& c : l){
    //          cout<<c<<" ";
    //      }
    //      cout<<endl;
    //  }
    //  pa[0]  = -1;
    //  int parent_count = 0;
    //  for(const auto& childlist : children){
    //      for(const auto& child : childlist){
    //          pa[child] = parent_count;
    //      }
    //      parent_count++;
    //  }
    //  for(const auto& p :pa){
    //      cout<<p<<" ";
    //  }
     //cout<<endl;
     int win = 0;
     for(size_t root = 0; root< pa.size(); root++){
     auto parentmatrix = buildParentMatrix(root, pa);
        int right = 0;
        for(const auto& guess : guesses){
            if(guess[0]-1 == parentmatrix[guess[1]-1]){
                right++;
            }
        } 
        if(right>=k){
            //cout<<"won"<< win<<endl;
            win++;
        }
     }
     //cout<<"ello"<<endl;
     cout<<win<<endl;
     if(win == 0){
         return "0/1";
     }
     else if(win == pa.size()){
         return "1/1";
     }
     
     int GCD = gcd(win, pa.size());
     int numer = win/GCD;
     int denom = pa.size()/GCD;
         string res = "";
         res += to_string(numer) + "/" + to_string(denom);
         //cout<<"res "<<res<<endl;
         return res;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<vector<int>> edges(n-1);
        for (int edges_row_itr = 0; edges_row_itr < n-1; edges_row_itr++) {
            edges[edges_row_itr].resize(2);

            for (int edges_column_itr = 0; edges_column_itr < 2; edges_column_itr++) {
                cin >> edges[edges_row_itr][edges_column_itr];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        string gk_temp;
        getline(cin, gk_temp);

        vector<string> gk = split_string(gk_temp);

        int g = stoi(gk[0]);

        int k = stoi(gk[1]);

        vector<vector<int>> guesses(g);
        for (int guesses_row_itr = 0; guesses_row_itr < g; guesses_row_itr++) {
            guesses[guesses_row_itr].resize(2);

            for (int guesses_column_itr = 0; guesses_column_itr < 2; guesses_column_itr++) {
                cin >> guesses[guesses_row_itr][guesses_column_itr];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        string result = storyOfATree(n, edges, k, guesses);

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
