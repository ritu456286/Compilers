#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

// Function to read the grammar from file
void ReadGrammar(string file, vector<string> &pro)
{
    string line;
    ifstream myfile;
    myfile.open(file);
    while (getline(myfile, line))
    {
        pro.push_back(line);
    }
}

// Function to recognize if a string can be derived from the grammar
bool RecognizeString(vector<string> &pro, string str)
{
    int n = str.length();
    int v = pro.size();

    // DP table to keep track of which non-terminals can generate substrings
    vector<vector<unordered_map<char, bool>>> dp(n + 1, vector<unordered_map<char, bool>>(n + 1));

    // Initialize the DP table for base cases
    for (int i = 0; i < v; ++i)
    {
        if (pro[i].length() == 4 && pro[i][3] == str[0])
        {
            dp[1][0][pro[i][0]] = true; // 'A->a' rule handling for a single character
        }
    }

    // Fill the DP table for substrings of increasing lengths
    for (int l = 2; l <= n; ++l)
    {
        for (int s = 0; s < n - l + 1; ++s)
        {
            for (int p = 1; p <= l - 1; ++p)
            {
                for (int i = 0; i < v; ++i)
                {
                    if (pro[i].length() == 5)
                    {
                        char nonTerminal = pro[i][0];  // Non-terminal on the left-hand side
                        char firstSymbol = pro[i][3];  // First symbol (non-terminal or terminal)
                        char secondSymbol = pro[i][4]; // Second symbol (non-terminal or terminal)

                        if (dp[p][s].count(firstSymbol) && dp[l - p][s + p].count(secondSymbol))
                        {
                            dp[l][s][nonTerminal] = true;
                        }
                    }
                }
            }
        }
    }

    // Check if the string can be derived from 'S'
    return dp[n][0].count('S');
}

int main()
{
    vector<string> pro;
    string str;

    // Read the grammar from file
    ReadGrammar("text.txt", pro);

    cout << "Context-free Grammar" << endl;
    for (int i = 0; i < pro.size(); ++i)
    {
        cout << pro[i] << endl;
    }

    // Input string to be tested
    cout << "Enter a String: ";
    cin >> str;

    // Check if the string can be derived from the given grammar
    if (RecognizeString(pro, str))
    {
        cout << "The input string can be derived using the given CFL" << endl;
    }
    else
    {
        cout << "The input string cannot be derived using the given CFL" << endl;
    }

    return 0;
}
