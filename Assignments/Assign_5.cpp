#include <iostream>
#include <cmath>
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

// Function to calculate harmonic mean (F-measure)
double calculateFMeasure(double precision, double recall)
{
    if (precision + recall == 0)
    {
        return 0.0; // Prevent division by zero
    }
    return (2 * precision * recall) / (precision + recall);
}

// Function to calculate E-measure
double calculateEMeasure(double alpha, double precision, double recall)
{
    if (precision == 0 && recall == 0)
    {
        return 0.0; // Prevent division by zero
    }
    return (1 + alpha) * (precision * recall) / (alpha * precision + recall);
}

int main()
{
    // Different values for relevant documents (Rq1) and retrieved documents (A)
    vector<int> Rq1 = {1, 3, 5};  // Relevant documents for query q1
    vector<int> A = {2, 4, 5, 6}; // Retrieved documents from the answer set
    double precision = calculatePrecision(Rq1, A);
    double recall = calculateRecall(Rq1, A);
    double fMeasure = calculateFMeasure(precision, recall);
    // Sample alpha value for E-measure
    double alpha = 0.5;
    double eMeasure = calculateEMeasure(alpha, precision, recall);
    cout << "Relevant documents for query q1: ";
    for (int doc : Rq1)
    {
        cout << doc << " ";
    }
    cout << endl;
    cout << "Retrieved documents: ";
    for (int doc : A)
    {
        cout << doc << " ";
    }
    cout << endl;
    cout << "Alpha value for E-measure: " << alpha << endl;
    cout << "Precision: " << precision << endl;
    cout << "Recall: " << recall << endl;
    cout << "F-Measure: " << fMeasure << endl;
    cout << "E-Measure: " << eMeasure << endl;
    return 0;
}