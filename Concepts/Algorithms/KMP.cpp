#include <bits/stdc++.h>
using namespace std;

void LPS(string &pattern, int lps[])
{
    int n = pattern.size();
    int len = 0, i = 1;
    while (i < n)
    {
        if (pattern[len] == pattern[i])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMP(string &text, string &pattern)
{
    int n = text.size();
    int m = pattern.size();
    int lps[m];
    memset(lps, 0, sizeof(lps));
    // compute Lps
    LPS(pattern, lps);
    int i = 0, j = 0;

    while (i < n)
    {
        if (pattern[j] == text[i])
        {
            i++;
            j++;
        }
        else
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }

        if (j == m)
            cout << "Match idx found at: " << i - j << endl;
    }
}

int main()
{

    string text = "onionsions";
    string pattern = "ions";

    KMP(text, pattern);

    return 0;
}