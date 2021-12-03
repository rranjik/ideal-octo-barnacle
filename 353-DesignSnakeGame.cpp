namespace std{
    template <>
    struct hash<pair<int, int>>{
        size_t operator()(const pair<int, int>& p)const{
            return (p.first^0x20483024F)^
            (p.second^0xA8E2592D);
        }
    };
}
class SnakeGame {
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    using pii = pair<int, int>;
    deque<pii> body;
    unordered_set<pii> bodyparts;
    vector<vector<int>> food;
    SnakeGame(int width, int height, vector<vector<int>>& food) {
        this->food = food;
        m = height;
        n = width;
        body.push_front({0, 0});
        bodyparts.insert({0, 0});
    }
    bool gameover = false;
    int m{};
    int n{};
    int pos{};
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        if(gameover) return-1;
        auto tail = body.back(); 
        auto head = body.front();
        body.pop_back();
        bodyparts.erase(bodyparts.find(tail));
        if(direction=="U") head.first--;
        else if(direction=="D") head.first++;
        else if(direction=="L") head.second--;
        else head.second++;
     
        if(head.first<0||head.first>=m
           ||head.second<0||head.second>=n||bodyparts.find(head)!=bodyparts.end()) {
            gameover = true;
            return -1;
        }
        
        body.push_front(head);
        bodyparts.insert(head);
        
        if(pos>=food.size()) return body.size()-1;
        
        if(head.first==food[pos][0]&&head.second==food[pos][1]){
            pos++;
            body.push_back(tail);
            bodyparts.insert(tail);
        }
        
        return body.size()-1;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */
