#include <iostream>
#include <string>
#include <vector>

using namespace std;

int compare(char a, char b)
{
    if (a != b)
        return 0;

    return 1;
}

vector<int> indexPattern(string pttrn)
{   
    int j = 0;
    int i = 0;

    vector<int> indexed = {0}; 


    while(i < pttrn.size()-1)
    {
        int result = compare(pttrn.at(i+1), pttrn.at(j));

        if (result == 1)
        {
            j++;
            indexed.push_back(j);
        }
        else
        {
            if (j == 0)
            {
                indexed.push_back(j);
            } 
            else
            {
                j = indexed.at(j-1);
                i--;
            }
        }
        
        i++;
    }

    return indexed;
}

int match(vector<int> indexed, string pttrn, string str)
{
    int i = 0;
    int j = 0;

    int found = 0;

    while(j < str.size())
    {
        char toCompare = pttrn.at(i);
        int result = compare(toCompare, str.at(j));

        if (result == 1)
        {
            i++;
        } 
        else if (result == 0 && i == 0)
        {   
            i++;
        }
        else
        {
            i = indexed.at(i-1);
            j--;
        }

        if (i == indexed.size())
        {
            found = 1;
            break;
        }

        j++;
    }

    return found;
}

int main()
{
    string str = "a";
    string pattern = "a";

    vector<int> indexed = indexPattern(pattern);

    for (int i = 0; i < indexed.size(); i++)
        cout << indexed.at(i) << endl;
    
    cout << endl << match(indexed, pattern, str) << endl;

    return 0;
}