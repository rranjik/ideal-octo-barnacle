class Solution {
public:
    vector<string> wordify(string s){
        stringstream ss;
        ss << s;
        vector<string> res;
        string w;
        while(getline(ss, w, ' ')){
            res.push_back(w);
        }
        return res;
    }
    struct student {
        int id;
        int score;
        student(int _id, int _score) : id(_id), score(_score) {};
        student() {}
        bool operator<(const student& other){
            if(score==other.score){
                return id>other.id;
            }
            return score<other.score;
        }
    };
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        string ex = "hello there how are you";
        unordered_map<int, int> sm;
        unordered_set<string> pos(positive_feedback.begin(), positive_feedback.end()), neg(negative_feedback.begin(), negative_feedback.end());
        //for(const auto& id : student_id){
        //    sm[id] = student({id, 0});
        //}
        for(int i = 0; i<report.size(); i++){
            auto rw = wordify(report[i]);
            auto s = sm[student_id[i]];
            auto id = student_id[i];
            for(const auto& w : rw){
                if(pos.find(w)!=pos.end()){
                    sm[id]+=3;
                }
                if(neg.find(w)!=neg.end()){
                    sm[id]-=1;
                }
            }
        }
        vector<student> students;
        for(const auto& [id, stu] : sm){
            students.push_back({id, stu});
        }
        sort(students.begin(), students.end());
        reverse(students.begin(), students.end());
        vector<int> res;
        for(int i = 0; i<k; i++){
            res.push_back(students[i].id);
        }
        return res;
    }
};
