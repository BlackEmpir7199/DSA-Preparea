#include <bits/stdc++.h>
using namespace std;

void rabinkarp(string &text, string &pattern)
{
    int m = pattern.size();
    int n = text.size();
    int d = 256;
    int h = 1;
    int q = 101;
    int i, j;
    int t_hash = 0;
    int p_hash = 0;

    // this gives the m-1 th pow , like if 1242 -> 1*10^3 meaning we had 4 digit -> m -> we need the m-1 for hash recal
    for (i = 0; i < m - 1; i++)
        h = (h * d) % q;

    // calc has for the first m chars
    for (i = 0; i < m; i++)
    {
        p_hash = (p_hash * d + pattern[i]) % q;
        t_hash = (t_hash * d + text[i]) % q;
    }

    // now iterate the pattern + when hash match do a char by char comp, else skip
    // if true -> print index, else break the loop
    for (i = 0; i <= n - m; i++)
    {
        if (p_hash == t_hash)
        {
            for (j = 0; j < m; j++)
            {
                if (text[i + j] != pattern[j])
                    break;
            }

            if (j == m)
            {
                cout << "A pattern match found at index : " << i << endl;
            }
        }

        // not the last possible substring
        if (i < n - m)
        {
            // reupdate hash val
            t_hash = ((t_hash - h * text[i]) * d + text[i + m]) % q;

            // incase if it reached negative
            if (t_hash < 0)
                t_hash += q;
        }
    }
}

int main()
{
    string text = "PAININTHEASS";
    string pattern = "IN";

    rabinkarp(text, pattern);

    return 0;
}