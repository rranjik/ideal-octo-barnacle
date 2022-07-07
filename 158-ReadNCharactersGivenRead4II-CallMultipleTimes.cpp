// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    char i4buff[4];
    int i4 = 0;
    int n4 = 0;
    int read(char *buf, int n) {
        int i = 0;
        while(i<n){//while we still have something to fill
            if(i4==n4){//we used up the small read buff by copying everything to actual buff
                i4 = 0; //reset 
                n4 = read4(i4buff); //read more chars
                if(!n4) break; //nothing can be read - just stop
            }
            buf[i] = i4buff[i4];
            i++; i4++;
        }
        return i;
    }
};
