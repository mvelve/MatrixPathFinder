#include <vector>
#include <cstdio>

using namespace std;

int calcMinValue(vector<vector<int>> &m);
bool path_finder(vector<vector<int>> &m, int col, int row, int sum, vector<vector<int>> &prev, int minValue);
int main() {
	vector<vector<int>> x = {{1,1,1,-5,-5},{-6,-3,-5,0,4},{-5,1,2,4,0},{1,0,-5,0,-4}};
	vector<vector<int>> y = {{0,-1,-1,0,0,0},{0,0,0,-1,0,0},{-1,-1,0,-1,-1,0},{0,-1,0,0,0,-1},{0,0,-1,-1,0,0},{0,0,0,0,-1,1}};
	vector<vector<int>> z = {{1,-10,1,-5,2},{2,3,-20,2,1},{-13,1,2,3,5},{1,1,5,-4,4}};
	vector<vector<int>> w = {{0,0,-1,0},{-2,0,1,-4},{-5,-2,-3,-1}};


	vector<vector<int>> init = {{-1,-1}};
	printf("%d\n", path_finder(x, 0, 0, 0, init, calcMinValue(x)));

	init = {{-1,-1}};
	printf("%d\n", path_finder(y, 0, 0, 0, init, calcMinValue(y)));
	
	init = {{-1,-1}};
	printf("%d\n", path_finder(z, 0, 0, 0, init, calcMinValue(z)));
	
	init = {{-1,-1}};
	printf("%d\n", path_finder(w, 0, 0, 0, init, calcMinValue(w)));
	return 0;
}

int calcMinValue(vector<vector<int>> &m) {
	int maxVal = 0;
	for(int i=0;i<m.size();i++) {
		for(int j=0;j<m[0].size();j++) {
			if(m[i][j] > maxVal) {	maxVal = m[i][j];	}
		}
	}
	if(!maxVal) {maxVal = 1;}
	return -maxVal;
}

bool path_finder(vector<vector<int>> &m, int col, int row, int sum, vector<vector<int>> &prev, int minValue) {
	if(sum < minValue) {return false;}
	if(col>=m.size()||row>=m[0].size()||col<0||row<0) {return false;}
	bool contained=false;
	//base cases
	for(int i=0;i<prev.size();i++) { if(prev[i][0] == col && prev[i][1] == row) { return false; } }
	if(col==m.size()-1 && row==m[0].size()-1) {return (sum+m[col][row]>0);}
	//add current block to traversed paths
	vector<int> x = {col, row};
	prev.push_back(x); bool a;
	//tail recursion
			 if(a = path_finder(m, col+1, row, sum+m[col][row], prev, minValue)) {prev.pop_back();return a;}
	else if(a = path_finder(m, col, row-1, sum+m[col][row], prev, minValue)) {prev.pop_back();return a;}
	else if(a = path_finder(m, col, row+1, sum+m[col][row], prev, minValue)) {prev.pop_back();return a;}
	else {prev.pop_back();return path_finder(m, col-1, row, sum+m[col][row], prev, minValue);}
}

