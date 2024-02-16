#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
	
	bool isValidIndex(int row, int col, int n){
		if(row<0 || col<0)return false;
		if(row>=n || col>=n)return false;
		else return true;
	}

	void solver(vector<vector<int>>&maze, int n, int row, int col,
				string &ds, vector<string>&ans, vector<vector<int>>&visited){
		
		//base case and reach
		if(row==n-1 && col==n-1){
			ans.push_back(ds);
			return;
		}

		//can't visit
		if(maze[row][col]!=1)return;
		//small calc and rec

		//down
		if(isValidIndex(row+1,col,n) && maze[row+1][col]==1 && visited[row+1][col]==0){
			visited[row][col]=1;
			ds.push_back('D');
			solver(maze,n,row+1,col,ds,ans,visited);
			//back track
			visited[row][col]=0;
			ds.pop_back();
		}
		//left 
		if(isValidIndex(row,col-1,n) && maze[row][col-1]==1 && visited[row][col-1]==0){
			visited[row][col]=1;
			ds.push_back('L');
			solver(maze,n,row,col-1,ds,ans,visited);
			//back track
			visited[row][col]=0;
			ds.pop_back();
		}
		//right
		if(isValidIndex(row,col+1,n) && maze[row][col+1]==1 && visited[row][col+1]==0){
			visited[row][col]=1;
			ds.push_back('R');
			solver(maze,n,row,col+1,ds,ans,visited);
			//back track
			visited[row][col]=0;
			ds.pop_back();
		}
		//up
		if(isValidIndex(row-1,col,n) && maze[row-1][col]==1 && visited[row-1][col]==0){
			visited[row][col]=1;
			ds.push_back('U');
			solver(maze,n,row-1,col,ds,ans,visited);
			//back track
			visited[row][col]=0;
			ds.pop_back();
		}
		
	}

    vector<string> findPath(vector<vector<int>> &m, int n) {
		vector<string>ans;
		string ds="";
		vector<vector<int>>visited(n,vector<int>(n,0));
		//source invalid
		if(m[0][0]==0)return ans;

		solver(m,n,0,0,ds,ans,visited);
		return ans;
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}