#include <iostream>
#include <vector>
using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
string dir[] = {"D", "R", "U", "L"};

bool isSafe(int x, int y, vector<vector<int>> &maze, vector<vector<bool>> &visited, int n)
{
    return x >= 0 && y >= 0 && x < n && y < n &&
           maze[x][y] == 0 && !visited[x][y];
}

void findAllPaths(int x, int y, vector<vector<int>> &maze, vector<vector<bool>> &visited, string path, vector<string> &result)
{
    int n = maze.size();

    // Base Case
    if (x == n - 1 && y == n - 1)
    {
        result.push_back(path);
        return;
    }

    visited[x][y] = true;
    // Explore all 4 directions
    for (int i = 0; i < 4; i++)
    {
        int newX = x + dx[i];
        int newY = y + dy[i];

        if (isSafe(newX, newY, maze, visited, n))
        {
            findAllPaths(newX, newY, maze, visited, path + dir[i], result);
        }
    }

    visited[x][y] = false;
    // BACKTRACK
}

int main()
{
    vector<vector<int>> maze = {
        {0, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 0, 0},
        {0, 1, 0, 0}};
    int n = maze.size();

    vector<vector<bool>> visited(n, vector<bool>(n, false));
    vector<string> result;

    findAllPaths(0, 0, maze, visited, "", result);

    cout << "Total paths: " << result.size() << endl;
    for (string path : result)
    {
        cout << path << endl;
    }

    return 0;
}
