
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'getCost' function below.
 *
 * The function accepts WEIGHTED_INTEGER_GRAPH g as parameter.
 */

/*
 * For the weighted graph, <name>:
 *
 * 1. The number of nodes is <name>_nodes.
 * 2. The number of edges is <name>_edges.
 * 3. An edge exists between <name>_from[i] and <name>_to[i]. The weight of the edge is <name>_weight[i].
 *
 */

using nd = pair<int, int>;
using ndptr = shared_ptr<nd>;

class prioq{
    vector<ndptr> heap;
    vector<ndptr> mapping;
    function<bool(ndptr, ndptr)> cmp;
    public:
    void decKey(const int& src, const int& value){
        //cout<<"in dexKey"<<endl;
        //cout<<src<<" "<<value<<endl;
        //cout<<(*mapping[src]).first<<" "<<(*mapping[src]).second<<endl;
        (*mapping[src]).second = value;
        make_heap(heap.begin(), heap.end(), cmp);
    }
    auto top()->nd{
       return *(heap.front()); 
    }
    auto pop()->void{
        pop_heap(heap.begin(), heap.end(), cmp);
        heap.pop_back();
    }
    auto empty()->bool{
        return heap.empty();
    }
    prioq(const size_t& size){
        for(size_t i = 0; i< size; i++){
            auto nnd = make_shared<nd>(i, numeric_limits<int>::max());
            mapping.push_back(nnd);
            heap.push_back(nnd);
        }
        cmp = []
              (const ndptr& left, const ndptr& right)
              {return (*left).second > (*right).second;}; 
    }
};

auto buildAdjList(int g_nodes, vector<int> g_from, vector<int> g_to, vector<int> g_weight) -> vector<vector<pair<int, int>>>
{
    vector<vector<pair<int, int>>> adjlist(g_nodes, vector<pair<int, int>>());
    for(size_t i = 0; i<g_from.size(); i++){
       adjlist[g_from[i]-1].push_back(pair<int, int>(g_to[i]-1, g_weight[i])); 
    }
    return adjlist;
}

void Dijkstra(int src, 
              const vector<vector<pair<int, int>>>& adjlist){
   vector<int> distances(adjlist.size(), numeric_limits<int>::max());
   vector<bool> visited(adjlist.size(), false);
   visited[src] = true;
   prioq Q(adjlist.size());
   Q.decKey(src, 0);
   distances[0] = 0;
   while(!Q.empty()){
       auto n = Q.top();
       //cout<<"n.first:" << n.first<<" n.second: "<<n.second<<endl;
       //cout<<"distances[n.first]: "<<distances[n.first]<<endl;
       Q.pop();
       for(const auto& c : adjlist[n.first]){
           //cout<<"c.first: "<<c.first<<" c.second: "<<c.second<<endl;
           //cout<<"distances[c.first]: "<<distances[c.first]<<endl;
           if (distances[c.first] >
                       (n.second +
                           (((c.second - n.second) < 0)
                   ? 0
                   : (c.second - n.second)))) {
            //cout<<"yes greater"<<endl;
             distances[c.first] =
                 n.second +
                 (((c.second - n.second) < 0)
                      ? 0
                      : (c.second - n.second));
             Q.decKey(c.first, distances[c.first]);
            }
       }
   }
   if(distances[adjlist.size()-1]==numeric_limits<int>::max())
     cout << "NO PATH EXISTS" << std::endl;
   else cout<<distances[adjlist.size()-1];
}   

void getCost(int g_nodes, vector<int> g_from, vector<int> g_to, vector<int> g_weight) {
    // Print your answer within the function and return nothing
    auto adjlist = buildAdjList(g_nodes, g_from, g_to, g_weight);
    Dijkstra(0, adjlist);
}

int main()
{
    string g_nodes_edges_temp;
    getline(cin, g_nodes_edges_temp);

    vector<string> g_nodes_edges = split(rtrim(g_nodes_edges_temp));

    int g_nodes = stoi(g_nodes_edges[0]);
    int g_edges = stoi(g_nodes_edges[1]);

    vector<int> g_from(g_edges);
    vector<int> g_to(g_edges);
    vector<int> g_weight(g_edges);

    for (int i = 0; i < g_edges; i++) {
        string g_from_to_weight_temp;
        getline(cin, g_from_to_weight_temp);

        vector<string> g_from_to_weight = split(rtrim(g_from_to_weight_temp));

        int g_from_temp = stoi(g_from_to_weight[0]);
        int g_to_temp = stoi(g_from_to_weight[1]);
        int g_weight_temp = stoi(g_from_to_weight[2]);

        g_from[i] = g_from_temp;
        g_to[i] = g_to_temp;
        g_weight[i] = g_weight_temp;
    }

    getCost(g_nodes, g_from, g_to, g_weight);

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
