#include <iostream>
#include <vector>

using namespace std;

// A utility function that returns maximum of two integers
int max(int a, int b)
{
    return (a > b) ? a : b;
}

// Returns the maximum value that can be put in a knapsack of capacity W
int limitedInfectionApproximation(int target, int graphSizes[], int graphNum)
{
    int K[graphNum + 1][target + 1];

    // Build table K[][] in bottom up manner
    for (int i = 0; i <= graphNum; i++)
    {
      for (int w = 0; w <= target; w++)
      {
        if (i == 0 || w == 0)
            K[i][w] = 0;
        else if (graphSizes[i - 1] <= w) {
            K[i][w] = max(graphSizes[i - 1] + K[i - 1][w - graphSizes[i - 1]], K[i - 1][w]);
        }
        else
          K[i][w] = K[i - 1][w];
      }
    }

    return K[graphNum][target];
}

// TEST FUNCTION
int main()
{
    cout << "Enter the number of disjoint graphs in total:";
    int n, W;
    cin >> n;

    int graphSizes[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter size of graph " << i << ":";
        cin >> graphSizes[i];
    }

    cout << "Enter the number of users you would like to infect: ";
    cin >> W;
    cout << "Possible users infected: " << limitedInfectionApproximation(W, graphSizes, n) << endl;

    return 0;
}
