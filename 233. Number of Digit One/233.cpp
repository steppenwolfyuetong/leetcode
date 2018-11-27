int countDigitOne(int n) {
    if(n < 1) 
        return 0;
    if(n >= 1 && n < 10) 
        return 1;

    // x: first digit
    int y = 1, x = n;
    while(!(x < 10))
    {
        x /= 10;
        y *= 10;
    }

    if(x == 1)
        return (n - y + 1) + x * countDigitOne(y - 1) + countDigitOne(n % y);
    else
        return y + x * countDigitOne(y - 1) + countDigitOne(n % y);
}

/*
 * 21345为例 x = 2, y = 10000
 * 万位数共出现10000-19999共一万次 即y次 (当x为1时，如对于n = 11345, 则只有n - y + 1 = 1346次)
 * 然后加上当万位数固定，后四位中出现1的个数乘以万位数，即x * countDigitOne(y-1) = 2 * countDigitOne(9999)次,即1346-21345这两万个数字钟后4位中1出现的次数
 * 以及余数的countDigitOne(n % y) = countDigitOne(1345)次
 */
