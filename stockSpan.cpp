#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};
    vector<int> ans;
    stack<pair<int, int>> st;

    for (auto price : prices)
    {
        int days = 1;
        while (!st.empty() and st.top().first <= price)
        {
            days += st.top().second;
            st.pop();
        }
        st.push({price, days});
        ans.push_back(days);
    }
    for (auto span : ans)
        cout << span;
    return 0;
}