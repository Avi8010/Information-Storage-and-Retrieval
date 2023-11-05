#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to tokenize a string into words
vector<string> tokenize(const string &text)
{
    vector<string> tokens;
    istringstream iss(text);
    string word;
    while (iss >> word)
    {
        tokens.push_back(word);
    }
    return tokens;
}

// Function to remove stopwords from a vector of words
vector<string> removeStopwords(const vector<string> &words, const vector<string> &stopwords)
{
    vector<string> result;
    for (const string &word : words)
    {
        if (find(stopwords.begin(), stopwords.end(), word) == stopwords.end())
        {
            // Word is not in the stopwords list, so add it to the result
            result.push_back(word);
        }
    }
    return result;
}
int main()
{
    // Input text
    string inputText = "This is a sample input text with some common stopwords.";

    // List of stopwords
    vector<string> stopwords = {"is", "a", "with", "some"};

    // Tokenize the input text
    vector<string> words = tokenize(inputText);

    // Remove stopwords
    vector<string> filteredWords = removeStopwords(words, stopwords);

    // Construct the conflated text
    string conflatedText;
    for (const string &word : filteredWords)
    {
        conflatedText += word + " ";
    }

    // Print the conflated text
    cout << "Conflated Text: " << conflatedText << endl;
    return 0;
}