#include <algorithm>
#include <iostream>
using namespace std;

/* 
 * refer to 386
 *
 * Initially, image you are at node 1 (variable: curr),
 * the goal is move (k - 1) steps to the target node x. (substract steps from k after moving)
 * when k is down to 0, curr will be finally at node x, there you get the result.
 *
 * we don't really need to do a exact k steps preorder traverse of the denary tree,
 * the idea is to calculate the steps between curr and curr + 1 (neighbor nodes in same level),
 * in order to skip some unnecessary moves.
 */


class Solution {
public:
    /*
     * Firstly, calculate how many steps curr need to move to curr + 1.
     * if the steps <= k, we know we can move to curr + 1, and narrow down k to k - steps.
     * else if the steps > k, that means the curr + 1 is actually behind the target node x in the preorder path, we can't jump to curr + 1.
     * What we have to do is to move forward only 1 step (curr * 10 is always next preorder node) and repeat the iteration.
     */
    int findKthNumber(int n, int k) {
        int cur = 1;
        k = k - 1;
        while(k > 0)
        {
            int steps = calStep(n, cur, cur + 1);
            if(steps <= k)
            {
                cur += 1;
                k -= steps;
            }
            else
            {
                cur *= 10;
                k -= 1;
            }
        }
        return cur;
    }

    /*
     * calSteps function
     * 1. Let n1 = curr, n2 = curr + 1.
     *    n2 is always the next right node beside n1's right most node (who shares the same ancestor "curr")
     *    (refer to the pic, 2 is right next to 1, 20 is right next to 19, 200 is right next to 199).
     * 2. so, if n2 <= n, what means n1's right most node exists, we can simply add the number of nodes from n1 to n2 to steps.
     * 3. else if n2 > n, what means n (the biggest node) is on the path between n1 to n2, add (n + 1 - n1) to steps.
     * 4. organize this flow to "steps += Math.min(n + 1, n2) - n1; n1 *= 10; n2 *= 10;"
     */
    int calStep(int n, long n1, long n2)
    {
        int steps = 0;
        while(n1 <= n)
        {
        	// cout << n1 << ' ' << n2 << ' ' << steps << endl;
            steps += min((long)(n + 1), n2) - n1;
            n1 *= 10;
            n2 *= 10;
        }
        // cout << n1 << ' ' << n2 << ' ' << steps << endl;
        return steps;
    }
};

int main()
{
    Solution *s = new Solution();
    int n = 13, k = 2;
    cout << s->findKthNumber(n, k) << endl;
    return 0;
}
