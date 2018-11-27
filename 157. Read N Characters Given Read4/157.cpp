#include <iostream>
using namespace std;

FILE *fp;

int read4(char *buf)
{
    return fread(buf,1,4,fp);
}

class Solution
{
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int count = 0;
        char tmp[4];
        while(count < n)
        {
            int size = read4(tmp);
            memcpy(buf + count, tmp, size);
            count += size;
            if(size < 4)
                break;
        }
        if(count > n)
        {
            buf[n] = '\0';
        }
        return count;
    }
};

int main()
{
    if(NULL == (fp = fopen("123.txt","r")))
        return 1;
    
    Solution s;
    char buf[1024];
    s.read(buf,22);
    cout << buf << endl;
    fclose(fp);
    return 0;
}
