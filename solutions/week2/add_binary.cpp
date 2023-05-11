#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        int index1 = a.length() - 1;
        int index2 = b.length() - 1;

        int carry = 0;
        string output = "";

        while (index1 >= 0 || index2 >= 0 || carry == 1)
        {
            if (index1 >= 0)
            {
                carry += a[index1--] - '0';
            }

            if (index2 >= 0)
            {
                carry += b[index2--] - '0';
            }

            // binary addition 1 + 1 + 1 = 1, 1 + 1 = 0, 1 + 0 = 1, 0 + 0 = 0
            output += carry % 2 + '0';

            // carry only if 1 + 1 + 1 = 3
            carry /= 2;
        }

        // reverse the solution
        reverse(output.begin(), output.end());
        return output;
    }
};