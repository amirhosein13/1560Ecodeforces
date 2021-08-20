#include <bits/stdc++.h>

using namespace std;

vector< pair<char, int> > all;

bool checkit(string s, string result)
{
    string fake = result;
    for (int i = all.size() - 1; i >= 0; i--)
    {
        for (int j = 0; j < result.size(); j++)
        {
            if (result[j] != ' ' && result[j] != all[i].first)
            {
                fake += result[j];
            }
            else
            {
                result[j] = ' ';
            }
        }
    }
    return fake == s;
}

string solve(string s)
{
    for (int i = s.size() - 1; i >= 0; i--)
    {
        bool isbe = false;
        for (int j = 0; j < all.size(); j++)
        {
            if (s[i] == all[j].first)
            {
                all[j].second++;
                isbe = true;
                break;
            }
        }
        if (isbe == false)
        {
            all.push_back(make_pair(s[i], 1));
        }
    }
    string result = "";
    int a = 0;
    for (int i = 0; i < all.size(); i++)
    {
        if (all[i].second % (all.size() - i) != 0)
        {
            return "-1";
        }
        else
        {
            a += all[i].second / (all.size() - i);
        }
    }
    for (int i = 0; i < a; i++)
    {
        result += s[i];
    }
    string fakeresult=result;
    result += " ";
    for (int i = all.size() - 1; i >= 0; i--)
    {
        result += all[i].first;
    }
    if (checkit(s, fakeresult) == true)
    {
        return result;
    }
    else
    {
        return "-1";
    }
}

int main()
{
    int a;
    cin >> a;
    for (int i = 0; i < a; i++)
    {
        string ss;
        cin >> ss;
        cout << solve(ss) << endl;
        all.clear();
    }
}