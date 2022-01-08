class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> m;
        for(const auto& c : text){
            m[c]++;
        }
        int least = numeric_limits<int>::max();
        least = min(least, m['b']);
        least = min(least, m['a']);
        least = min(least, m['l']/2);
        least = min(least, m['o']/2);
        least = min(least, m['n']);
        return least;
    }
};
