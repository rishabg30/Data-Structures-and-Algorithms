#include <bits/stdc++.h>
using namespace std;
bool comp(pair<double, pair<double, double>> p1, pair<double, pair<double, double>> p2)
{
    return p1.first > p2.first;
}
double maximumValue(vector<pair<int, int>> &items, int n, int w)
{
    double ans = 0.0;

    // {value_by_weight, {weight,value}}
    vector<pair<double, pair<double, double>>> value_by_weight;
    for (int i = 0; i < n; i++)
    {
        pair<double, pair<double, double>> curr_pair;
        curr_pair.first = (items[i].second * 1.0 / items[i].first * 1.0);
        curr_pair.second.first = items[i].first * 1.0;
        curr_pair.second.second = items[i].second * 1.0;
        value_by_weight.push_back(curr_pair);
    }
    sort(value_by_weight.begin(), value_by_weight.end(), comp);

    int curr_weight = 0;
    double sum_value = 0.0;
    for (int i = 0; i < n; i++)
    {
        // If our curr_weight = given weight, we cannot add more weight
        if (curr_weight >= w)
        {
            break;
        }
        // If we have capacity to add more weight
        if (curr_weight + value_by_weight[i].second.first <= w)
        {
            curr_weight += value_by_weight[i].second.first;
            sum_value = sum_value + value_by_weight[i].second.second;
        }
        // We can add some portion of weight
        else
        {
            int leftOverWeight = w - curr_weight;
            // Now our curr_weight will become equal to given weight capacity
            sum_value = sum_value + (double)(value_by_weight[i].second.second / value_by_weight[i].second.first) * (leftOverWeight * 1.0);
            curr_weight = w;
        }
    }
    return sum_value;
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    /*
    Time complexity: O(N)
    Space complexity: O(N)
    */
    int n, w;
    cin >> n >> w;
    vector<pair<int, int>> arr;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        arr.push_back(make_pair(x, y));
    }
    cout << maximumValue(arr, n, w) << endl;
}