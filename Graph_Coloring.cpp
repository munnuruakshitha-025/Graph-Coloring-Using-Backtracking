#include <iostream>
#include <vector>
using namespace std;
bool isSafe(int vertex,
            int colorValue,
            vector<vector<int>>& graph,
            vector<int>& color,
            int n) {
    for (int i = 0; i < n; i++) {
 if (graph[vertex][i] == 1 &&
            color[i] == colorValue) {
return false;
        }
    }
    return true;
}

// Backtracking function
bool graphColoring(vector<vector<int>>& graph,
                   vector<int>& color,
                   int vertex,
                   int n,
                   int m) {

    // All vertices are colored
    if (vertex == n)
        return true;

    // Try every color
    for (int colorValue = 1; colorValue <= m; colorValue++) {

        // Check whether color is safe
        if (isSafe(vertex, colorValue,
                   graph, color, n)) {

            // Assign color
            color[vertex] = colorValue;

            // Color the next vertex
            if (graphColoring(graph, color,
                              vertex + 1, n, m)) {

                return true;
            }

            // Backtrack
            color[vertex] = 0;
        }
    }

    return false;
}

int main() {

    int n;

    cout << "Enter number of vertices: ";
    cin >> n;

    vector<vector<int>> graph(
        n, vector<int>(n)
    );

    cout << "Enter adjacency matrix:\n";

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

            cin >> graph[i][j];
        }
    }

    vector<int> color(n, 0);

    int minimumColors = 0;

    // Try different numbers of colors
    for (int m = 1; m <= n; m++) {

        // Reset solution vector
        for (int i = 0; i < n; i++) {
            color[i] = 0;
        }

        // Try coloring using m colors
        if (graphColoring(graph, color, 0, n, m)) {

            minimumColors = m;
            break;
        }
    }

    if (minimumColors != 0) {

        cout << "\nGraph Coloring Solution:\n\n";

        for (int i = 0; i < n; i++) {

            cout << "Vertex " << i
                 << " -> Color "
                 << color[i] << endl;
        }

        cout << "\nSolution Vector:\n";

        for (int i = 0; i < n; i++) {

            cout << color[i] << " ";
        }

        cout << "\n";

        cout << "\nMinimum Number of Colors Required: "
             << minimumColors << endl;

        cout << "\nSolution found successfully."
             << endl;
    }
    else {

        cout << "\nNo valid coloring exists."
             << endl;
    }

    return 0;
}
