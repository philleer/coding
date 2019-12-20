/******************************************************************************
 * The source is part of my coding practice, a lightweight C++ solution for
 * leetcode program practice.
 *
 * For all of my code, after check it online by submit, I also compile and run
 * it by my offline machine
 * ============================================================================
 * ////////////// Microsoft Visual Studio 2010 when I use windows /////////////
 * //////////////           G++5.4.0 when I am on Linux           /////////////
 * ============================================================================
 *
 * If any question, feel free to send me an email << phillee2016@163.com >>
 * or just correct it via Pull Request or create an issue.
 ******************************************************************************
 */
#include <iostream>
#include <vector>
#include <string>

class Solution {
public:	
	// 79.Word Search
	/*=====================================================================
	 * Description: Given a 2D board and a word, find if the word exists in
	 *	the grid. The word can be constructed from letters of
	 *	sequentially adjacent cell, where "adjacent" are those
	 *	horizontally/vertically neighboring. The same letter cell may
	 *	not be used more than once.
	 *
	 * Example:
	 *	board = [['A','B','C','E'],['S','F','C','S'],['A','D','E','E']]
	 *	Given word = "ABCCED", return true
	 *	Given word = "SEE", return true
	 *	Given word = "ABCB", return false
	 *=====================================================================
	 */
	bool exist(vector<vector<char>>& board, string word) {
		if (word.empty()) return true;
		if (board.empty()) return false;
		
		int rows = board.size();
		int cols = board[0].size();
		if (word.length() > rows*cols) return false;
		
		std::vector<std::vector<int>> visited(rows,
						      std::vector<int>(
							      cols, 0));
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				if (word[0] == board[i][j]) {
					if (wordSearch(board, word, visited,
						       i, j, 0))
						return true;
				}
			}
		}
		
		return false;
	}
	
	bool wordSearch(std::vector<std::vector<char>> &board,
			std::string &word,
			std::vector<std::vector<int>> &visited,
			int row,
			int col,
			int index)
	{
		if (index == word.length()-1 &&
		    visited[row][col]==0 &&
		    word[index] == board[row][col])
		{
			return true;
		}
		
		int rows = board.size();
		int cols = board[0].size();
		if (row < rows &&
		    col < cols &&
		    visited[row][col]==0 &&
		    word[index] == board[row][col])
		{
			visited[row][col] = 1;
			if (row < rows-1 &&
			    wordSearch(board, word, visited, row+1,
				       col, index+1))
			{
				return true;
			}
			if (col < cols-1 &&
			    wordSearch(board, word, visited, row,
				       col+1, index+1))
			{
				return true;
			}
			if (row >= 1 &&
			    wordSearch(board, word, visited, row-1,
				       col, index+1))
			{
				return true;
			}
			if (col >= 1 &&
			    wordSearch(board, word, visited, row,
				       col-1, index+1))
			{
				return true;
			}
			visited[row][col] = 0;
		}
		
		return false;
	}
};

int main (int argc, char const *argv[]) {
	std::vector<std::vector<char>> board{{'A', 'B', 'C', 'E'},
					     {'S', 'F', 'C', 'S'},
					     {'A', 'D', 'E', 'E'}};
	std::string word = "ABCCED";
	Solution solver;

	std::cout << "The given board:" << std::endl;
	for (int i = 0; i < board.size(); ++i) {
		for (int j = 0; j < board[i].size(); ++j) {
			std::cout << board[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "word " << word << " exist in the board?"
		<< ((solver.exist(board, word)) ? "YES" : "NO")
		<< std::endl;

	return 0;
}

