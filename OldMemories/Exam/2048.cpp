#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <iomanip>
#include <cmath>

using namespace std;
 
int cells[4][4] = { 2,0,0,0,0,32,0,0,0,4,0,0,0,0,2048,0 };
int score = 0;
char op;
 
enum class State{Playing,GameOver,Success };
State nowState = State::Playing;
 
void init();//游戏初始化
void refresh();//界面刷新
void randomNumber();//随机产生2、4
bool full();
bool GameOver();//判断游戏是否结束
bool Success();//达成2048
 
 
void clickUp();//点W键
bool canMoveUp();//是否可向上
void upCol(int);//向上合并
 
void clickDown();
bool canMoveDown();
void downCol(int);
 
void clickLeft();
bool canMoveLeft();
void leftCol(int);
 
void clickRight();
bool canMoveRight();
void rightCol(int);
 
int getNextInCol(int col, int startRow, int step);
int getNextInRow(int row, int startCol, int step);
 
int main() {
	init();
	refresh();
	while ((op=_getche())!= EOF) {
		switch(op) {
		case 'w':
			clickUp(); break;
		case 's':
			clickDown(); break;
		case 'a':
			clickLeft(); break;
		case 'd':
			clickRight(); break;
		default:
			break;
		}
		if (Success() || nowState == State::Success) {
			refresh();//刷新当前游戏状态
			MessageBox(0, TEXT("真棒"), TEXT("Success!"), 0);
			break;
		}
		else if (GameOver() || nowState == State::GameOver) {
			refresh();//刷新当前游戏状态
			MessageBox(0, TEXT("不要灰心，再接再厉"), TEXT("GameOver!"), 0);
			break;
		}
	}
	return 0;
}
void init() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cells[i][j] = 0;
		}
	}
	randomNumber();
	randomNumber();
}
 
void refresh() {
	system("cls");
	cout << "     *****************************" << endl;
	cout << "           2048（得分："<<score<<"分 ）" << endl;
	cout << "          按（w、s、a、d）键" << endl;
	if (nowState == State::Playing) {
		cout << "       当前游戏状态：游戏中···" << endl;
	}
	else if (nowState == State::Success) {
		cout << "       当前游戏状态：胜利！！！" << endl;
	}
	else {
		cout << "       当前游戏状态：失败！！！" << endl;
	}
	cout << "     *****************************" << endl;
	cout << endl << endl;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (cells[i][j] == 0)
				cout << setw(8) << "□";
			else
				cout << setw(8) << cells[i][j];
		}
		cout << endl << endl << endl << endl;
	}
	cout << "请输入w、s、a、d键：";
}
 
 
void randomNumber() {
	if (full()) {
		return;
	}
	while (true) {
		srand((int)time(NULL));
		int col = rand() % 4;
		int row = rand() % 4;
		int n = (rand() % 2 + 1) * 2;
		if (cells[row][col] == 0){
			cells[row][col] = n;
			break;
		}
	}
}
 
bool full() {
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (cells[i][j] == 0)
				return false;
	return true;
}
void clickUp() {
	if (GameOver()||!canMoveUp())//游戏结束或者不能上移则不执行
		return;
	for (int col = 0; col < 4; col++)
		upCol(col);
	randomNumber();
	refresh();
}
bool canMoveUp() {
	for (int col = 0; col < 4; col++)
		for (int row = 1; row < 4; row++) {
			if (cells[row][col] != 0 && cells[row - 1][col] == 0)
				return true;//某个数字上面为空时为真
			if (cells[row][col] != 0 && (cells[row][col] == cells[row - 1][col]))
				return true;//某个数字与上面相同可以合并为真
		}
	return false;//不可以上移
}
void upCol(int col) {
	for (int row = 0; row < 4;) {
		int current = cells[row][col];
		int nextRow = getNextInCol(col, row + 1, 1);
		if (nextRow == -1)
			return;
		int next = cells[nextRow][col];
		if (current == 0) {
			cells[row][col] = next;
			cells[nextRow][col] = 0;
		}
		else if (current == next) {
			cells[row][col] = next + current;
			cells[nextRow][col] = 0;
			score += cells[row][col];
			row++;
		}
		else {
			row++;
		}
	}
}
int getNextInCol(int col, int startRow, int step) {
	int row = startRow;
	while (true) {
		if (row < 0 || row >= 4)
			return -1;
		if (cells[row][col] != 0)
			return row;
		row += step;
	}
}
void clickDown() {
	if (GameOver())
		return;
	if (!canMoveDown())
		return;
	for (int col = 0; col < 4; col++) {
		downCol(col);
	}
	randomNumber();
	refresh();
}
bool canMoveDown() {
	for (int col = 0; col < 4; col++)
		for (int row = 0; row < 3; row++){
			if (cells[row][col] != 0 && cells[row + 1][col] == 0)
				return true;
			if (cells[row][col] != 0 && (cells[row][col] == cells[row + 1][col]))
				return true;
		}
	return false;
}
void downCol(int col) {
	for (int row = 3; row >= 0;) {
		int current = cells[row][col];
		int nextRow = getNextInCol(col, row - 1, -1);
		if (nextRow == -1)
			return;
		int next = cells[nextRow][col];
		if (current == 0) {
			cells[row][col] = next;
			cells[nextRow][col] = 0;
		}
		else if (current == next) {
			cells[row][col] = next + current;
			cells[nextRow][col] = 0;
			score += cells[row][col];
			row--;
		}
		else {
			row--;
		}
	}
}
void clickLeft() {
	if (GameOver()|| !canMoveLeft())
		return;
	for (int row = 0; row < 4; row++)
		leftCol(row);
	randomNumber();
	refresh();
}
bool canMoveLeft() {
	for(int col=1;col<4;col++)
		for (int row = 0; row < 4; row++) {
			if (cells[row][col] != 0 && cells[row][col - 1] == 0)
				return true;
			if (cells[row][col] != 0 && (cells[row][col] == cells[row][col - 1]))
				return true;
		}
	return false;
}
void leftCol(int row) {
	for (int col = 0; col < 4;) {
		int current = cells[row][col];
		int nextCol = getNextInRow(row, col + 1, 1);
		if (nextCol == -1)
			return;
		int next = cells[row][nextCol];
		if (current == 0) {
			cells[row][col] = next;
			cells[row][nextCol] = 0;
		}
		else if (current == next) {
			cells[row][col] = next + current;
			cells[row][nextCol] = 0;
			score += cells[row][col];
			col++;
		}
		else
			col++;
	}
}
int getNextInRow(int row, int startCol, int step) {
	int col = startCol;
	while (true) {
		if (col < 0 || col >= 4)
			return -1;
		if (cells[row][col] != 0)
			return col;
		col += step;
	}
}
void clickRight() {
	if (GameOver() || !canMoveRight())
		return;
	for (int row = 0; row < 4; row++)
		rightCol(row);
	randomNumber();
	refresh();
}
bool canMoveRight() {
	for(int col=0;col<3;col++)
		for (int row = 0; row < 4; row++) {
			if (cells[row][col] != 0 && cells[row][col + 1] == 0)
				return true;
			if (cells[row][col] != 0 && cells[row][col] == cells[row][col + 1])
				return true;
		}
	return false;
}
void rightCol(int row) {
	for (int col = 3; col >= 0;) {
		int current = cells[row][col];
		int nextCol = getNextInRow(row, col - 1, -1);
		if (nextCol == -1)
			return;
		int next = cells[row][nextCol];
 
		if (current == 0) {
			cells[row][col] = next;
			cells[row][nextCol] = 0;
		}
		else if (current == next) {
			cells[row][col] = next + current;
			cells[row][nextCol] = 0;
			score += cells[row][col];
			col--;
		}
		else
			col--;
	}
}
bool GameOver() {
	if (!full())
		return false;
	if (canMoveUp() || canMoveDown() || canMoveLeft() || canMoveRight())
		return false;
	nowState = State::GameOver;
	return true;
}
bool Success() {
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (cells[i][j] == 2048) {
				nowState = State::Success;
				return true;
			}
	return false;
	
}
