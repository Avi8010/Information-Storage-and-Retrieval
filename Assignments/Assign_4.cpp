#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Function to calculate precision
double calculatePrecision(const vector<int> &Rq1, const vector<int> &A)
{
    int truePositives = 0;
    for (int doc : A)
    {
        if (find(Rq1.begin(), Rq1.end(), doc) != Rq1.end())
        {
            truePositives++;
        }
    }
    int falsePositives = A.size() - truePositives;
    if (A.size() == 0)
    {
        return 0.0; // Prevent division by zero
    }
    return static_cast<double>(truePositives) / A.size();
}
// Function to calculate recall
double calculateRecall(const vector<int> &Rq1, const vector<int> &A)
{
    int truePositives = 0;
    for (int doc : A)
    {
        if (find(Rq1.begin(), Rq1.end(), doc) != Rq1.end())
        {
            truePositives++;
        }
    }
    int falseNegatives = Rq1.size() - truePositives;
    if (Rq1.size() == 0)
    {
        return 0.0; // Prevent division by zero
    }
    return static_cast<double>(truePositives) / Rq1.size();
}
int main()
{
    // Sample input
    vector<int> Rq1 = {1, 3, 5};  // Relevant documents for query q1
    vector<int> A = {2, 4, 5, 6}; // Retrieved documents from the answer set
    double precision = calculatePrecision(Rq1, A);
    double recall = calculateRecall(Rq1, A);
    cout << "Precision: " << precision << endl;
    cout << "Recall: " << recall << endl;
    return 0;
}