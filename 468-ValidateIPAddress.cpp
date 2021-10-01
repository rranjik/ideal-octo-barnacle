class Solution {
public:
    string validIPAddress(string s) {
        int dotcount = 0;
        int coloncount = 0;
        for(int i = 0; i<s.length(); i++){
            if(s[i]=='.') dotcount++;
            if(s[i]==':') coloncount++;
        }
        if(dotcount==3){
            int pos = 0;
            int last_pos = 0;
            while((pos=s.find('.', last_pos))!=string::npos){
                string segment = s.substr(last_pos, pos-last_pos);
                cout<<"segment = "<<segment<<endl;
                try{
                    auto segmentnum = stoi(segment);
                    if(segmentnum<0||segmentnum>255||to_string(segmentnum)!=segment){
                        return "Neither";
                    }
                }catch(...){
                    return "Neither";
                }
                last_pos = pos+1;
            }
            string segment = s.substr(last_pos, pos-last_pos);
            cout<<"segment = "<<segment<<endl;
            try{
                auto segmentnum = stoi(segment);
                if(segmentnum<0||segmentnum>255||to_string(segmentnum)!=segment){
                    return "Neither";
                }
            }catch(...){
                return "Neither";
            }
            return "IPv4";
        }
        if(coloncount==7){
            int pos = 0;
            int last_pos = 0;
            while((pos=s.find(':', last_pos))!=string::npos){
                string segment = s.substr(last_pos, pos-last_pos);
                cout<<"segment = "<<segment<<endl;
                try{
                    size_t numdigits = 0;
                    auto segmentnum = stoi(segment, &numdigits, 16);
                    if(numdigits!=segment.length()||segment.length()>4||segmentnum<0||
                      segment[0]=='-'){
                        return "Neither";
                    }
                }catch(...){
                    return "Neither";
                }
                last_pos = pos+1;
            }
            string segment = s.substr(last_pos, pos-last_pos);
            cout<<"segment = "<<segment<<endl;
            try{
                auto segmentnum = stoi(segment, 0, 16);
                if(segment.length()>4||segmentnum<0){
                    return "Neither";
                }
            }catch(...){
                return "Neither";
            }
            return "IPv6";
        }
        return "Neither";
    }
};
