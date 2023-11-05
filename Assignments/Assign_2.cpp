#include <iostream>
#include <vector>
using namespace std;

float calculateSimilarity(const vector<float> &a, const vector<float> &b)
{
    float answer = 0;
    for (int i = 0; i < a.size(); ++i)
    {
        answer += a[i] * b[i];
    }
    return answer;
}
vector<float> calculateClusterRepresentative(const vector<int> &cluster, const vector<vector<int>> &input, int noOfTokens)
{
    vector<float> answer(noOfTokens, 0);
    for (int i = 1; i <= cluster[0]; ++i)
    {
        for (int j = 0; j < noOfTokens; ++j)
        {
            answer[j] += input[cluster[i]][j];
        }
    }
    for (int i = 0; i < noOfTokens; ++i)
    {
        answer[i] /= cluster[0];
    }
    return answer;
}

int main()
{
    cout << "Enter the no of Tokens: ";
    int noOfTokens;
    cin >> noOfTokens;

    cout << "Enter the no of Documents: ";
    int noOfDocuments;
    cin >> noOfDocuments;

    cout << "Enter the threshold: ";
    float threshold;
    cin >> threshold;

    cout << "Enter the Document Token Matrix:" << endl;

    vector<vector<int>> input(noOfDocuments, vector<int>(noOfTokens));

    for (int i = 0; i < noOfDocuments; ++i)
    {
        for (int j = 0; j < noOfTokens; ++j)
        {
            cout << "Enter(" << i << "," << j << "): ";
            cin >> input[i][j];
        }
    }
    vector<vector<int>> cluster(noOfDocuments, vector<int>(noOfDocuments + 1));
    vector<vector<float>> clusterRepresentative;
    cluster[0][0] = 1;
    cluster[0][1] = 0;
    int noOfClusters = 1;
    vector<float> temp(noOfTokens);
    for (int i = 0; i < noOfTokens; ++i)
    {
        temp[i] = static_cast<float>(input[0][i]);
    }
    clusterRepresentative.push_back(temp);
    for (int i = 1; i < noOfDocuments; ++i)
    {
        float max = -1;
        int clusterId = -1;
        for (int j = 0; j < clusterRepresentative.size(); ++j)
        {
            float similarity = calculateSimilarity(vector<float>(input[i].begin(), input[i].end()), clusterRepresentative[j]);
            if (similarity > threshold)
            {
                if (similarity > max)
                {
                    max = similarity;
                    clusterId = j;
                }
            }
        }
        if (max == -1)
        {
            cluster[noOfClusters][0] = 1;
            cluster[noOfClusters][1] = i;
            noOfClusters++;
            clusterRepresentative.push_back(vector<float>(input[i].begin(), input[i].end()));
        }
        else
        {
            cluster[clusterId][0] += 1;
            int index = cluster[clusterId][0];
            cluster[clusterId][index] = i;
            clusterRepresentative[clusterId] = calculateClusterRepresentative(cluster[clusterId], input, noOfTokens);
        }
    }
    for (int i = 0; i < noOfClusters; ++i)
    {
        cout << "\n"
             << i << "\t";
        for (int j = 1; j <= cluster[i][0]; ++j)
        {
            cout << " " << cluster[i][j];
        }
    }
    return 0;
}
