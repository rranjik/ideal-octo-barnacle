class Solution {
public:

    unordered_map<string, string> m;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        auto h = to_string(hash<string>()(longUrl));
        m[h] = longUrl;
        cout<<"hash of "<<longUrl<<" is "<<h<<endl;
        return "http://tinyurl.com/"+h;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        auto l = shortUrl.substr(19, string::npos);
        cout<<"looking up "<<l<<endl;
        return m[l];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
