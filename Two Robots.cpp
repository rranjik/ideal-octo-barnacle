#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

namespace hash_tuple{

template <typename TT>
struct hash
{
    size_t
    operator()(TT const& tt) const
    {                                              
        return std::hash<TT>()(tt);                                 
    }                                              
};
}


namespace hash_tuple{

    namespace{
        template <class T>
        inline void hash_combine(std::size_t& seed, T const& v)
        {
            seed ^= hash_tuple::hash<T>()(v) + 0x9e3779b9 + (seed<<6) + (seed>>2);
        }
    }
}
namespace hash_tuple{

    namespace
    {
        // Recursive template code derived from Matthieu M.
        template <class Tuple, size_t Index = std::tuple_size<Tuple>::value - 1>
        struct HashValueImpl
        {
          static void apply(size_t& seed, Tuple const& tuple)
          {
            HashValueImpl<Tuple, Index-1>::apply(seed, tuple);
            hash_combine(seed, std::get<Index>(tuple));
          }
        };

        template <class Tuple>
        struct HashValueImpl<Tuple,0>
        {
          static void apply(size_t& seed, Tuple const& tuple)
          {
            hash_combine(seed, std::get<0>(tuple));
          }
        };
    }

    template <typename ... TT>
    struct hash<std::tuple<TT...>> 
    {
        size_t
        operator()(std::tuple<TT...> const& tt) const
        {                                              
            size_t seed = 0;                             
            HashValueImpl<std::tuple<TT...> >::apply(seed, tt);    
            return seed;                                 
        }                                              
    };

}

unordered_map<tuple<int, int, int>, int, hash_tuple::hash<tuple<int, int, int>>> lookup;

int DP(int r1, int r2, int q, const int m, const vector<vector<int>>& queries){
  auto coordinate = tuple<int, int, int>(r1, r2, q);
  if (q>=queries.size()) 
    return 0;
  else if(lookup.find(coordinate)!=lookup.end())
    return lookup[coordinate];
  else {
      lookup[coordinate] = min(DP(queries[q][1], r2, q+1, m, queries)
                                +((r1==-1)?0:abs(r1-queries[q][0]))
                                +abs(queries[q][1]-queries[q][0]),
                                DP(r1, queries[q][1], q+1, m, queries)
                                +((r2==-1)?0:abs(r2-queries[q][0]))
                                +abs(queries[q][1]-queries[q][0]));
      return lookup[coordinate];
  } 
}

/*
    * Complete the twoRobots function below.
    */
int twoRobots(int m, vector<vector<int>> queries) {
    return DP(-1, -1, 0, m, queries);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
while(t){
    string mn_temp;
    getline(cin, mn_temp);

    vector<string> mn = split_string(mn_temp);

    int m = stoi(mn[0]);

    int n = stoi(mn[1]);

    vector<vector<int>> queries(n);
    for (int queries_row_itr = 0; queries_row_itr < n; queries_row_itr++) {
        queries[queries_row_itr].resize(2);

        for (int queries_column_itr = 0; queries_column_itr < 2; queries_column_itr++) {
            cin >> queries[queries_row_itr][queries_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = twoRobots(m, queries);
    lookup.clear();
    fout << result << "\n";
    t--;
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
