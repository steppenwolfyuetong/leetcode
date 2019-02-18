#include <iostream>
using namespace std;

// cur: currrent money, index: index of next coin try to use
void dfs(int coins[], int n, int amount, int cur, int index, int& result) {
    if (cur == amount) {
        result++;
        return;
    }
    if (index > n) {
        return;
    }

    for (int i = 0; i <= (amount - cur) / coins[index]; i++) {
        dfs(coins, n, amount, cur + coins[index] * i, index + 1, result);
    }
}

// dfs
int make_change(int coins[], int n, int amount)
{
    int result = 0;
    dfs(coins, n, amount, 0, 0, result);
    return result;
}

int main() {
    int coins[] = {2, 1};
    int result = make_change(coins, 2, 2);
    cout << result << endl;
}
