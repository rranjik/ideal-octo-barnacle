/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */
class Solution {
public:
    string gethostname(string url){
        string res;
        int posslashes = url.find("//", 0);
        if(posslashes!=string::npos){
            url = url.substr(posslashes+2);
        }
        int pospathslash = url.find("/");
        if(pospathslash!=string::npos){
            url = url.substr(0, pospathslash);
        }
        int firstdot = url.find(".");
        int seconddot = url.find(".", firstdot);
        if(seconddot!=string::npos){
            res = url.substr(firstdot+1);
        }else{
            res = url;
        }
        return res;
    }
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        string parenthost = gethostname(startUrl);
        unordered_set<string> crawled;
        queue<string> q;
        q.push(startUrl);
        vector<string> res;
        res.push_back(startUrl);
        crawled.insert(startUrl);
        while(!q.empty()){
            auto t = q.front();
            q.pop();
            auto urls = htmlParser.getUrls(t);
            for(const auto& url : urls){
                auto hostname = gethostname(url);
                if(hostname==parenthost&&crawled.find(url)==crawled.end()){
                    crawled.insert(url);
                    res.push_back(url);
                    q.push(url);
                }
            }
        }
        return res;
    }
};
