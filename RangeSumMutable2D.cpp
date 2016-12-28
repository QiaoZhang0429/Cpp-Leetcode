//O(log_4 mn) for both update and getsum
//Ref: very basic
//https://segmentfault.com/a/1190000004238792

class TreeNode{
	int tlRow, int tlCol, int brRow, int brCol;
	int sum;
	TreeNode* nw, ne, sw, se;
	TreeNode() : nw(NULL), ne(NULL), sw(NULL), se(NULL) {}
	TreeNode(int a, int b, int c, int d) : tlRow(a), tlCol(b), brRow(c), brCol(d), nw(NULL), ne(NULL), sw(NULL), se(NULL) {}
};
class NumMatrix{
private:
	TreeNode* root;
public:
	NumMatrix(vector<vector<int>>& matrix){
		if(matrix.size() == 0)
			return ;
		root = buildTree(0, 0, matrix.size()-1, matrix[0].size()-1, matrix);
	}
	void update(int row, int col, int val){
		updateTree(root, row, col, val);
	}
	int sumRegion(int row1, int col1, int row2, int col2){
		return queryTree(root, row1, col1, row2, col2);
	}
	TreeNode* buildTree(int tlRow, int tlCol, int brRow, int brCol, vector<vector<int>>& matrix){
		if(tlRow > brRow || tlCol > brCol)
			return NULL;
		TreeNode* root = new TreeNode(tlRow, tlCol, brRow, brCol);
		if(tlRow == brRow && tlCol == brCol){
			root->sum = matrix[tlRow][tlCol];
			return root;
		}
		int midRow = tlRow + (brRow - tlRow) / 2;
		int midCol = tlCol + (brCol - tlCol) / 2;
		root->nw = buildTree(tlRow, tlCol, midRow, midCol, matrix);
		root->ne = buildTree(tlRow, midCol+1, midRow, brCol, matrix);
		root->sw = buildTree(midRow+1, tlCol, brRow, midCol, matrix);
		root->se = buildTree(midRow+1, midCol+1, brRow, brCol, matrix);
		root->sum = root->nw ? root->nw->sum : 0 + root->ne ? root->ne->sum : 0 + root->sw ? root->sw->sum : 0 + root->se ? root->se->sum : 0;
		return root;
	}
	void updateTree(TreeNode* root, int row, int col, int val){
		if(root->tlRow == row && root->brRow == row && root->tlCol == col && root->brCol == col){
			root->sum = val;
			return ;
		}
		int midRow = root->tlRow + (root->brRow - root->tlRow) / 2;
		int midCol = root->tlCol + (root->brCol - root->tlCol) / 2;
		if(row <= midRow && col <= midCol)
			updateTree(root->nw, row, col, val);
		else if(row <= midRow && col > midCol)
			updateTree(root->ne, row, col, val);
		else if(row > midRow && col <= midCol)
			updateTree(root->sw, row, col, val);
		else
			updateTree(root->se, row, col, val);
		root->sum = root->nw ? root->nw->sum : 0 + root->ne ? root->ne->sum : 0 + root->sw ? root->sw->sum : 0 + root->se ? root->se->sum : 0;
	}
	int queryTree(TreeNode* root, int row1, int col1, int row2, int col2){
		if(root->tlRow == row1 && root->tlCol == col1 && root->brRow == row2 && root->brCol == col2)
			return root->sum;
		int midRow = root->tlRow + (root->brRow - root->tlRow) / 2;
		int midCol = root->tlCol + (root->brCol - root->tlCol) / 2;
		if(row2 <= midRow){
			if(col2 <= midCol)
				return queryTree(root->nw, row1, col1, row2, col2);
			else if(col1 > midCol)
				return queryTree(root->ne, row1, col1, row2, col2);
			else
				return queryTree(root->nw, row1, col1, row2, midCol) + queryTree(root->ne, row1, midCol+1, row2, col2);
		}
		else if(row1 > midRow){
			if(col2 <= midCol)
				return queryTree(root->sw, row1, col1, row2, col2);
			else if(col1 > midCol)
				return queryTree(root->se, row1, col1, row2, col2);
			else
				return queryTree(root->sw, row1, col1, row2, midCol) + queryTree(root->se, row1, midCol+1, row2, col2);
		}
		else{
			if(col2 <= midCol)
				return queryTree(root->nw, row1, col1, midRow, col2) + queryTree(root->sw, midRow+1, col1, row2, col2);
			else if(col1 > midCol)
				return queryTree(root->ne, row1, col1, midRow, col2) + queryTree(root->se, midRow+1, col1, row2, col2);
			else
				return queryTree(root->nw, row1, col1, midRow, midCol) + queryTree(root->ne, row1, midCol+1, midRow, col2) + queryTree(root->sw, midRow+1, col1, row2, midCol) + queryTree(root->se, midRow+1, midCol+1, row2, col2);
		}
	}
};
class NumMatrix {
private:
    vector<vector<int>> record;
	vector<vector<int>> bit;
public:
    NumMatrix(vector<vector<int>> &matrix) {
        if(matrix.size() == 0)
            return ;
        record.resize(matrix.size(), vector<int>(matrix[0].size(), 0));
		bit.resize(matrix.size()+1, vector<int>(matrix[0].size()+1, 0));
		for(int i = 0; i < matrix.size(); i++)
			for(int j = 0; j < matrix[0].size(); j++)
				update(i, j, matrix[i][j]);
    }

    void update(int row, int col, int val) {
        add(row+1, col+1, val-record[row][col]);
        record[row][col] = val;
    }
    
    void add(int row, int col, int diff){
        for(int i = row; i < bit.size(); i += lowbit(i)){
            for(int j = col; j < bit[0].size(); j += lowbit(j)){
                bit[i][j] += diff;
            }
        }
    }
    
    int getSum(int row, int col){
        int rslt = 0;
        for(int i = row; i > 0; i -= lowbit(i)){
            for(int j = col; j > 0; j -= lowbit(j)){
                rslt += bit[i][j];
            }
        }
        return rslt;
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return getSum(row2+1, col2+1) - getSum(row1, col2+1) - getSum(row2+1, col1) + getSum(row1, col1); 
    }
    
    int lowbit(int pos){
        return pos & (-pos);
    }
};
// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix = new NumMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.update(1, 1, 10);
// numMatrix.sumRegion(1, 2, 3, 4);