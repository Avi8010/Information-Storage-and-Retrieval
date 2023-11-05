#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

void displayIndex(const vector<string> &invertedData, const vector<vector<int>> &docno)
{
    for (size_t i = 0; i < invertedData.size(); ++i)
    {
        cout << invertedData[i] << "\t";
        for (size_t j = 1; j <= docno[i][0]; ++j)
        {
            cout << docno[i][j] << "\t";
        }
        cout << "\n";
    }
}

void indexing(const string &text, vector<string> &invertedData, vector<vector<int>> &docno, int fileno)
{
    istringstream iss(text);
    string currenttoken;
    while (iss >> currenttoken)
    {
        int indx = -1;
        for (size_t i = 0; i < invertedData.size(); ++i)
        {
            if (invertedData[i] == currenttoken)
            {
                indx = static_cast<int>(i);
                break;
            }
        }
        if (indx == -1)
        {
            invertedData.push_back(currenttoken);
            indx = static_cast<int>(invertedData.size()) - 1;
            docno[indx][0] = 1;
            docno[indx][1] = fileno;
        }
        else
        {
            docno[indx][docno[indx][0] + 1] = fileno;
            docno[indx][0] += 1;
        }
    }
}

int main()
{
    vector<string> invertedData;
    vector<vector<int>> docno(100, vector<int>(10, 0));
    cout << "\nEnter total number of files:" << endl;
    int no;
    cin >> no;
    cin.ignore(); // Clear the newline character left in the buffer.
    for (int i = 1; i <= no; ++i)
    {
        cout << "\nEnter text for FILE " << i << ":" << endl;
        string text;
        getline(cin, text); // Read the entire line as text.
        indexing(text, invertedData, docno, i);
    }
    displayIndex(invertedData, docno);
    return 0;
}