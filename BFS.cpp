#include <iostream>
using namespace std;
#define MAX 10

void breadth_first_search(int adj[][MAX], int visited[], int start) {
    int queue[MAX], rear = -1, front = -1, i;
    queue[++rear] = start;
    visited[start] = 1;

    while (rear != front) {
        start = queue[++front];

        if (start == 4)
            cout << "5\t";
        else
            cout << static_cast<char>(start + 65) << "\t";

        for (i = 0; i < MAX; i++) {
            if (adj[start][i] == 1 && visited[i] == 0) {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int visited[MAX] = {0};
    int adj[MAX][MAX], i, j;

    cout << "\nEnter the adjacency matrix: ";

    for (i = 0; i < MAX; i++)
        for (j = 0; j < MAX; j++)
            cin >> adj[i][j];

    breadth_first_search(adj, visited, 0);

    return 0;
}
