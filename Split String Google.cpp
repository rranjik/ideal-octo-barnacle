// you can use includes, for example:
// #include <algorithm>
#include <algorithm>
#include <string>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int count_alnums(const std::string& s)
{
    return std::count_if(s.begin(), s.end(), 
                      // static_cast<int(*)(int)>(std::isalnum)         // wrong
                      // [](int c){ return std::isalnum(c); }           // wrong
                      // [](char c){ return std::isalnum(c); }          // wrong
                         [](unsigned char c){ return std::isalnum(c); } // correct
                        );
}


string solution(string &S, int K) {
    // write your code in C++14 (g++ 6.2.0)
    std::string result;
    std::string alpha_num_string;
    std::transform(S.begin(), S.end(), S.begin(), ::toupper);
    for(const auto& c:S){
        if(std::isalnum(c))
            alpha_num_string+=c;
    }
    int alpha_nums = count_alnums(S);
    cout<<"alpha_nums: "<<alpha_nums<<endl;
    //int number_of_groups = alpha_nums/K;
    int first_group = alpha_nums%K;
    
    cout<<"first_group: "<<first_group<<endl;
    bool is_first_group = true;
    if(first_group!=0){
        result = std::string(alpha_num_string.begin(), alpha_num_string.begin()+first_group);
        is_first_group = false;
    }
     bool first_time = true;
    for(auto it = alpha_num_string.begin()+first_group; it!=alpha_num_string.end(); it+=K){
        if(is_first_group&&first_time)
        {
            result += std::string(it, it+K);
            first_time = false;
        }
        else
        {
            result +="-";
            result += std::string(it, it+K);
        }
        // if(!is_first_group&&first_time)
        // {result +="-"; is_first_group= true;first_time=false;}
        // else{if(!first_time)result +="-";
        // result += std::string(it, it+K);}
    }
    return result;
}