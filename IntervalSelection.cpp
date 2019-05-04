
#include <bits/stdc++.h>

using namespace std;
using coor = pair<int, int>;
using  vvi = vector<vector<int>>;
/*
 * Complete the intervalSelection function below.
 */

namespace hash_tuple {

template <typename TT> struct hash {
  size_t operator()(TT const &tt) const { return std::hash<TT>()(tt); }
};
} // namespace hash_tuple

namespace hash_tuple {

namespace {
template <class T> inline void hash_combine(std::size_t &seed, T const &v) {
  seed ^= hash_tuple::hash<T>()(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}
} // namespace
} // namespace hash_tuple
namespace hash_tuple {

namespace {
// Recursive template code derived from Matthieu M.
template <class Tuple, size_t Index = std::tuple_size<Tuple>::value - 1>
struct HashValueImpl {
  static void apply(size_t &seed, Tuple const &tuple) {
    HashValueImpl<Tuple, Index - 1>::apply(seed, tuple);
    hash_combine(seed, std::get<Index>(tuple));
  }
};

template <class Tuple> struct HashValueImpl<Tuple, 0> {
  static void apply(size_t &seed, Tuple const &tuple) {
    hash_combine(seed, std::get<0>(tuple));
  }
};
} // namespace

template <typename... TT> struct hash<std::tuple<TT...>> {
  size_t operator()(std::tuple<TT...> const &tt) const {
    size_t seed = 0;
    HashValueImpl<std::tuple<TT...>>::apply(seed, tt);
    return seed;
  }
};

} // namespace hash_tuple

unordered_map<tuple<int, int, int>, int, hash_tuple::hash<tuple<int, int, int>>>
    lookup;

pair<bool, int> overlap(const coor& one, const coor& two){
    auto res = pair<bool, int>(false, -1);
    bool one_to_right = (one.first>two.second);
    bool two_to_right = (one.second<two.first);
    bool overlap = (!one_to_right||!two_to_right);
    if(overlap){
        auto late = (one.first<two.first)?two:one;
        res.first = true;
        res.second = late.second;
    }
    return res;
}

int DP(int index, int last, int last_op, const vector<vector<int>>& intervals){
   auto prob = tuple<int, int, int>(index, last, last_op);
   if(index==-1){
       return 0;
       //cout<<"bad index";
   }
   if(lookup.find(prob)!=lookup.end()){
       return lookup[prob];
       //cout<<"found already"<<endl;
   }
   else{
       //cout<<"prob is "<<index<<" "<<last<<" "<<last_op<<endl;
       auto include_yet_overlap = 0; 
       auto include_no_overlap = 0;
       if(intervals[index][1]<last_op&&intervals[index][1]>=last){
           include_yet_overlap =  DP(index-1, intervals[index][0], last, intervals)+1;
           //cout<<"include_yet_overlap"<<endl;
       }
       if(intervals[index][1]<last){
          include_no_overlap = DP(index-1, intervals[index][0], last_op, intervals)+1; 
           //cout<<"include_no_overlap"<<endl;
       } 
       lookup[prob] = max(DP(index-1, last, last_op, intervals), max(include_no_overlap, include_yet_overlap));
       return lookup[prob];
   }
}

int intervalSelection(vector<vector<int>> intervals) {
    /*
     * Write your code here.
     */
     sort(intervals.begin(), intervals.end(), [](const vector<int>& left, const vector<int>& right){return left[1]<right[1];});
     return DP(intervals.size()-1, numeric_limits<int>::max(), numeric_limits<int>::max(), intervals);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int s;
    cin >> s;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int s_itr = 0; s_itr < s; s_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<vector<int>> intervals(n);
        for (int intervals_row_itr = 0; intervals_row_itr < n; intervals_row_itr++) {
            intervals[intervals_row_itr].resize(2);

            for (int intervals_column_itr = 0; intervals_column_itr < 2; intervals_column_itr++) {
                cin >> intervals[intervals_row_itr][intervals_column_itr];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        int result = intervalSelection(intervals);
        lookup.clear();

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
