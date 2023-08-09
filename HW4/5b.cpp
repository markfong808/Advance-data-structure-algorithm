#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        //Need 2 map as they can be switched backward
        unordered_map<char, char> ST;
        unordered_map<char, char> TS;

        for (int i = 0; i < s.length(); i++)
        {
            char char1 = s[i];
            char char2 = t[i];

            // check if the char exist in the map
            // check and make sure the char from string 's' has to match the char in
            // string 't'
            if (ST[char1] && ST[char1] != char2)
                return false;
            if (TS[char2] && TS[char2] != char1)
                return false;

            ST[char1] = char2;
            TS[char2] = char1;
        }
        return true;
    }
};
int main() { cout << "Done\n"; }