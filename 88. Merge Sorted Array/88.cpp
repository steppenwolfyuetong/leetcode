#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		nums1.resize(m+n);
        int i = m - 1, j = n - 1, k = m + n - 1;
        while(i >= 0 && j >= 0)
            nums1[k--] = nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
        while(j >= 0)
            nums1[k--] = nums2[j--];
    }
};

int main()
{
    vector<int> a,b;
    int c[] = {1,4,7,23,834}, d[] = {2,8,23,69};
    for(int i = 0; i < sizeof(c)/sizeof(int); i++)
        a.push_back(c[i]);
    for(int i = 0; i < sizeof(d)/sizeof(int); i++)
        b.push_back(d[i]);
    Solution *s = new Solution;
	s->merge(a,sizeof(c)/sizeof(int),b,sizeof(d)/sizeof(int));
	for(int i = 0; i < a.size(); i++)
		cout<<a[i]<<' ';
	cout<<endl;
}
