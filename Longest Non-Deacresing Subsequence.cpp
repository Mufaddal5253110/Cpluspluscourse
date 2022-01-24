/*
Function return length of longest Non-Deacresing subsequence in an array
i.e LIS with not strickly increasing
*/

/*
TC : O(NlogN)
SC : O(N)
*/

int longestSubsequence(int n, int a[])
{
    vector<int> ans;
    ans.push_back(a[0]);
    for (int i = 1; i < n; i++)
    {
        if (a[i] >= ans.back())
        {
            ans.push_back(a[i]);
        }
        else
        {
            int ind = upper_bound(ans.begin(), ans.end(), a[i]) - ans.begin();
            ans[ind] = a[i];
        }
    }
    return ans.size();
}