#include <iostream>
using namespace std;

bool dfs(int arr[], int sz, int target, int cur, int index) {
    if (cur == target) {
        return true;
    }
    if (index >= sz) {
        return false;
    }

    return dfs(arr, sz, target, cur + arr[index], index + 1) || dfs(arr, sz, target, cur, index + 1);
}

bool split_array(int arr[], int sz) 
{
    if (sz == 0) {
        return 0;
    }

    int s = 0;
    for (int i = 0; i < sz; i++) {
        s += arr[i];
    }
    if (s & 1) {
        return false;
    }

    int target = s >> 1;
    return dfs(arr, sz, target, 0, 0); 
}

int main() {
    int arr[] = {1,2,4};
    cout << split_array(arr, 3) << endl;
    return 0;
}
