using namespace std;
#include"iostream"
unordered_map<int, bool>upperD;
unordered_map<int, bool>lowerD;
unordered_map<int, bool>rowCheck;
void saveAns(vector<vector<string>> &output ,vector<vector<char>> &board){
    for(auto row:board){
        string temp;
        for(auto ele:row){
            temp+=ele;
            cout<<ele;
        }
        cout<<endl;
        // output.push_back(temp);
    }
    cout<<"completed"<<endl;
}

bool isSafe(vector<vector<char>> &board, int row, int col){
    int n = board.size();
    if(row<0 || row>=n ||col<0 || col>=n || upperD[row-col] || lowerD[row+col]|| rowCheck[row]) return false;
    return true;
}

void placeQueen(vector<vector<char>> &board, int n, int col,   vector<vector<string>> &output, vector<char>&ans){
    if( col==n){
        saveAns( output, board);
        return;
    }
    for(int row=0;  row<n; row++){
        if(isSafe(board, row, col)){
            upperD[row-col]=true;
            lowerD[row+col]=true;
            rowCheck[row]=true;
            board[row][col]='Q';
            placeQueen(board, n, col+1, output, ans );
            board[row][col]='.';
            upperD[row-col]=false;
            lowerD[row+col]=false;
            rowCheck[row]=false;
        }
    }
    
    
}


int main() {
    int n =4;
    vector<vector<char>> board(n, vector<char>(n, '.'));
    vector<vector<string>> output;
    vector<char>ans;
    placeQueen(board, n, 0,  output, ans);
    return 0;

}
