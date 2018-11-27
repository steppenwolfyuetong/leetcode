/*
T(n) is the total number of all possible attendance records with length n.
P(n) is the total number of all possible attendance records ended with 'P' with length n.
L(n) is the total number of all possible attendance records ended with 'L' with length n.
A(n) is the total number of all possible attendance records ended with 'A' with length n.


初始条件
P(1) = 1.
L(1) = 1, L(2) = 3.
A(1) = 1, A(2) = 2, A(3) = 4.
递推公式
P(n) = A(n - 1) + P(n - 1) + L(n - 1), n ≥ 2

L(n) = A(n - 1) + P(n - 1) + A(n - 2) + P(n - 2), n ≥ 3

A(n) = A(n - 1) + A(n - 2) + A(n - 3), n ≥ 4
 */



class Solution {
public:
    int checkRecord(int n) {
        int m = 1000000007;
        int *A = new int [n];
        int *P = new int [n];
        int *L = new int [n];
        
        P[0] = 1;
        L[0] = 1;
        L[1] = 3;
        A[0] = 1;
        A[1] = 2;
        A[2] = 4;
        
        if(n == 1) return 3;
        
        for(int i = 1; i < n; i++)
        {
            A[i - 1] %= m;
            P[i - 1] %= m;
            L[i - 1] %= m;
            
            P[i] = ((A[i - 1] + P[i - 1]) % m + L[i - 1]) % m;
            
            if(i > 1) L[i] = ((A[i - 1] + P[i - 1]) % m + (A[i - 2] + P[i - 2]) % m) % m;
            
            if(i > 2) A[i] = ((A[i - 1] + A[i - 2]) % m + A[i - 3]) % m;
        }
        
        return ((A[n - 1] % m + P[n - 1] % m) % m + L[n - 1] % m) % m;
    }
};
