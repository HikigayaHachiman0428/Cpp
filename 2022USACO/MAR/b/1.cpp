#include<bits/stdc++.h>
const int maxn = 2e5 + 5;
using namespace std;
// 统计连续的GH和HG段的数量， 目标是把他们都变为HG
// 把以第i段为结尾的前缀，依次反转，每翻一次可以合并掉一段，最后全部变成HG
/* 14 GGGHGHHGHHHGHG */
int n;
char cow[maxn];
struct period
{
    int start;
    int end;
    bool HG;
};
string getHG(int index)
{
    string ret = "";
    ret += cow[index];
    ret += cow[index + 1];
    return ret;
}
bool chk(string loop, string cur)
{
    if (cur == "HH" || cur == "GG")
        return true;
    else if (loop.compare(cur))
        return false;
    else
        return true;
}

vector<period> h;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> cow[i];
    }
    period one;
    one.start = 1;
    h.push_back(one);
    bool first = true;
    string loop;
    for (int i = 1; i <= n - 1; i += 2)
    {
        string temp = getHG(i);
        if (first)
        {
            if (temp == "HH" || temp == "GG")
                continue;
            else
            {
                loop = temp;
                first = false;
                if (temp == "GH")
                    h.back().HG = false;
                else
                    h.back().HG = true;
            }
        }
        if (!chk(loop, temp))
        {
            h.back().end = i - 1;
            h.push_back({i, 0, 0});
            first = true;
        }
        if (first)
        {
            if (temp == "HH" || temp == "GG")
                continue;
            else
            {
                loop = temp;
                first = false;
                if (temp == "GH")
                    h.back().HG = false;
                else
                    h.back().HG = true;
            }
        }
    }
    h.back().end = n;
    // for (period i : h)
    //     cout << i.start << " " << i.end << " " << i.HG << endl;
    if (h.back().HG)
        cout << h.size() - 1;
    else
        cout << h.size();
}