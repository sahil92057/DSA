#include"iostream"
using namespace std;

bool isSafe(vector<vector<int>> &maze, vector<vector<bool>> &vis, int i, int j, int n){
    if(i >= n || i < 0 || j >= n || j < 0 || vis[i][j] || maze[i][j] == 0)
        return false;
    return true;
}

void func(vector<vector<int>> &maze, vector<string> &ans, int i, int j, int n, vector<vector<bool>> &vis){
    if(i == n - 1 && j == n - 1){
        for(auto it : ans){
            cout << it;
        }
        cout << endl;
        return;
    }

    vector<int> dirx = {1, -1, 0, 0};
    vector<int> diry = {0, 0, 1, -1};
    vector<string> dirChar = {"D", "U", "R", "L"};

    for(int k = 0; k < 4; k++){
        int newx = i + dirx[k];
        int newy = j + diry[k];

        if(isSafe(maze, vis, newx, newy, n)){
            vis[newx][newy] = true;
            ans.push_back(dirChar[k]);
            func(maze, ans, newx, newy, n, vis);
            ans.pop_back();
            vis[newx][newy] = false;
        }
    }
}

int main (){
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };
    int n = maze.size();
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    vector<string> ans;

    if (maze[0][0] == 1) {
        vis[0][0] = true;
        func(maze, ans, 0, 0, n, vis);
    } else {
        cout << "No path exists!" << endl;
    }

    return 0;
}
