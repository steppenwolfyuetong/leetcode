#include <iostream>
#include <algorithm>
#include <memory.h>
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
    Solution(): m_len(0)
    {
    }

    int read(char *buf, int n) {
        int count = 0, size;

        if(m_len > 0)
        {
            //写入上次剩余的数据
            int len = min(m_len,n);
            memcpy(buf,m_cache,len);
            count += len;
            if(n < m_len)
            {
                //写入的数据比cahche中的数据还要少
                memcpy(m_cache, m_cache + n, m_len - n);
                m_len -= n;
            }
            else
            {
                m_len = n;
            }
        }

        while(count < n)
        {
            size = read4(m_cache);
            memcpy(buf + count, m_cache, size);
            count += size;
            if(size < 4)
                break;
        }

        if(count > n)
        {
            //将已经读入 但是未写入的多余数据保存至cache
            buf[n] = '\0';
            m_len = count - n;
            memcpy(m_cache, m_cache + size - m_len, m_len);
            count = n;
        }
        return count;
    }
private:
    int m_len;          //cache剩余可用字节
    char m_cache[4];    //设置一个cache用于保存上次已读但未写入的数据
};

int main()
{
    if(NULL == (fp = fopen("123.txt","r")))
        return 1;
    
    Solution s;
    char buf[1024];
    memset(buf,0,sizeof(buf));
    s.read(buf,8);
    cout << buf << endl;
    s.read(buf,13);
    cout << buf << endl;
    fclose(fp);
    return 0;
}
