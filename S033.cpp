/*
* �𓚎��ԁF 2955��47�b �o�C�g���F 6771 Byte �X�R�A�F 0�_
* ��2�������ĉ��������̂��߁A�e�X�g���̂͑S�␳���ł������������Ԓ��߂̂���0�_�ł�

���Ȃ��͂ӂƁA�q���̍��ɗV�񂾎��̂悤�ȃQ�[�����v���o���܂����B

���̃Q�[���͓�l�̃v���C���[ (�v���C���[ 1, �v���C���[ 2 �Ƃ��܂�) �ɂ���čs���܂��B
�Q�[�����s������Ƃ��āA�� W �}�X�A�c H �}�X�̃O���b�h���^�����܂��B
�O���b�h�̊e�}�X�́u�����Ȃ��v���u��Q��������v���̂����ꂩ�ŁA�v���C���[�́u�����Ȃ��v�}�X�̏���ړ����邱�Ƃ��ł��܂��B
�܂��A�^������O���b�h�ɂ͕H���Ȃ����Ƃ��ۏ؂���Ă��܂��B
�����ŁA�}�X�̗� (x_1, y_1), (x_2, y_2), ..., (x_n, y_n) (n �� 4) ���H�ł���Ƃ́A���� 3 �̏�������������邱�ƂƂ��܂��B

�E�e i (1�� i �� n) �ɑ΂��� (x_i, y_i) �́u�����Ȃ��v�}�X�ł���B
�E�e i (1�� i �� n) �ɑ΂��� (x_i, y_i) �� (x_{i+1}, y_{i+1}) �͏㉺���E�̂����ꂩ�ŗאڂ��Ă���B������ x_{n+1}=x_1, y_{n+1}=y_1 �Ƃ���B
�Ei �� j �Ȃ�� (x_i, y_i) �� (x_j, y_j) �ł���B

�^������O���b�h�̗�����Ɏ����܂��B

�Q�[���̊J�n���ɂ́A�e�v���C���[�̓O���b�h���́u�����Ȃ��v�}�X�ɂ��܂��B
�Q�[���͎��̎菇���J��Ԃ����ƂŐi�s���܂��B

1. �v���C���[ 1 ���אڂ���u�����Ȃ��v�}�X�ֈړ�����B�܂��͂��̏�ɂƂǂ܂�B
2. �v���C���[ 2 ���אڂ���u�����Ȃ��v�}�X�ֈړ�����B�܂��͂��̏�ɂƂǂ܂�B

�v���C���[ 1 �̓v���C���[ 2 �̂���}�X�ɏd�Ȃ�ƃQ�[���N���A�ɂȂ�܂��B
�v���C���[ 2 �̓v���C���[ 1 ���Q�[���N���A����̂��ł��邾���x���Ȃ�悤�ɓ������܂��B
���v���C���[���œK�ȍs���������Ƃ��A�v���C���[ 1 �̓Q�[���N���A�܂łɍŏ��ŉ���ړ����邱�ƂɂȂ�ł��傤���B

�Ȃ��A�^��������͂ł́A�v���C���[ 1 �̏����ʒu����v���C���[ 2 �̏����ʒu�ցu�����Ȃ��v�}�X��ʂ��Ĉړ��ł��邱�Ƃ��ۏ؂���Ă��܂��B


[���͂����l]

���͎͂��̃t�H�[�}�b�g�ŗ^�����܂��B
W H
s_1
s_2
...
s_H

�E1 �s�ڂɂ́A���H�̉����Əc����\������ W, H �����p�X�y�[�X��؂�ŗ^�����܂��B
�E���� H �s�̂����� i �s�� (1 �� i �� N) �ɂ́A".", "#", "1", "2" ����Ȃ钷�� W �̕����� s_i ���^�����܂��Bs_i �� j �Ԗ� (1 �� j �� W) �̕����̓O���b�h�ɂ�����}�X (j, i) �̏�Ԃ�\���A"." �͂��̃}�X�Ɂu�����Ȃ��v���Ƃ��A"#" �͂��̃}�X�Ɂu��Q��������v���Ƃ��A"1" �͂��̃}�X���v���C���[ 1 �̏����ʒu�ł��邱�Ƃ��A"2" �͂��̃}�X���v���C���[ 2 �̏����ʒu�ł��邱�Ƃ����ꂼ��Ӗ����܂��B
�E���͍͂��v�� H + 1 �s�ƂȂ�A���͒l�ŏI�s�̖����ɉ��s�� 1 ����܂��B

[���҂���o��]

�E���v���C���[���œK�ȍs���������Ƃ��A�v���C���[ 1 ���Q�[���N���A���邽�߂ɕK�v�ȍŏ��̈ړ��񐔂��o�͂��Ă��������B
�E�����ɉ��s�����A�]�v�ȕ����A��s���܂�ł͂����܂���B


[����]

���ׂẴe�X�g�P�[�X�ɂ����āA�ȉ��̏������݂����܂��B
�E1 �� W, H �� 1,000
�Es_i �� ".", "#", "1", "2" �ō\������钷�� W �̕����� (1 �� i �� H)
�E�^������O���b�h�� "1" ����� "2" �͂��傤�� 1 �񂸂����
�E�^������O���b�h�ɕH�͂Ȃ�
�E�v���C���[ 1 �̏����ʒu����v���C���[ 2 �̏����ʒu�ցu�����Ȃ��v�}�X��ʂ��Ĉړ��ł���


 ���͗�1

3 3
1#.
2..
.#.


 �o�͗�1

	1


 ���͗�2

9 8
#####..##
...2#.#.#
###.#..1.
......###
.####.#..
....#####
###.##...
....#..#.

 �o�͗�2

	18

*/
#include <iostream>
#include <string>
#include <sstream>
#include <queue>
using namespace std;

class Coords {
protected:
	int x;
	int y;
public:
	Coords()
	{
		x = 0;
		y = 0;
	}
	Coords(int _x, int _y)
	{
		x = _x;
		y = _y;
	}
	void SetX(int _x)
	{
		this->x = _x;
	}
	void SetY(int _y)
	{
		this->y = _y;
	}

	int GetX()
	{
		return this->x;
	}
	int GetY()
	{
		return this->y;
	}
	void SetCoords(int _x, int _y)
	{
		this->x = _x;
		this->y = _y;
	}
	void Cout()
	{
		cout << "(" << this->x << ", " << this->y << ")" << endl;
	}
	bool operator ==(Coords coords)
	{
		return (this->x == coords.GetX() && this->y == coords.GetY());
	}
	bool operator !=(Coords coords)
	{
		return (this->x != coords.GetX() || this->y != coords.GetY());
	}
};
class InfoTile {
private:
	Coords coords;
	int nowCount;
public:
	InfoTile()
	{
		nowCount = 0;
	}
	InfoTile(int _x, int _y, int _nowcount)
	{
		coords.SetCoords(_x, _y);
		nowCount = _nowcount;
	}
	InfoTile(Coords _coords, int _nowcount)
	{
		coords = _coords;
		nowCount = _nowcount;
	}

	Coords GetCoords()
	{
		return coords;
	}
	int GetX()
	{
		return coords.GetX();
	}
	int GetY()
	{
		return coords.GetY();
	}
	int GetNowCount()
	{
		return nowCount;
	}

	void SetInfoTile(int _x, int _y, int _nowcount)
	{
		coords.SetCoords(_x, _y);
		nowCount = _nowcount;
	}
	void SetInfoTile(Coords _coords, int _nowcount)
	{
		coords = _coords;
		nowCount = _nowcount;
	}
	void SetCoords(Coords _coords)
	{
		coords = _coords;
	}
	void SetCoords(int _x, int _y)
	{
		coords.SetCoords(_x, _y);
	}
	void SetX(int _x)
	{
		coords.SetX(_x);
	}
	void SetY(int _y)
	{
		coords.SetY(_y);
	}
	void SetNowCount(int _nowcount)
	{
		nowCount = _nowcount;
	}
};

void DrawMeiro(int** _meiro, int** _shortestMeiro);
void OutputMeiro(int** _meiro);
void DrawShortestMeiro(int** _shortestMeiro);
int LongestRoadForP2(int** _meiro, int** _shortestMeiro);
void ResetCanMoveCoords();

Coords p1, p2;

int w, h;
queue<InfoTile> canmoveCoords;

int main()
{
	int answer;
	int** shortestMeiro;
	int** meiro;
	string str;
	getline(cin, str);
	istringstream s(str);
	s >> w >> h;

	shortestMeiro = new int* [h];
	meiro = new int* [h];
	for (int i = 0; i < h; ++i)
	{
		shortestMeiro[i] = new int[w];
		meiro[i] = new int[w];
	}

	DrawMeiro(meiro, shortestMeiro);
	//p1.Cout();
	//p2.Cout();
	DrawShortestMeiro(shortestMeiro);

	answer = LongestRoadForP2(meiro, shortestMeiro);

	//OutputMeiro(shortestMeiro);
	//OutputMeiro(meiro);
	cout << answer << endl;
	for (int i = 0; i < h; ++i)
	{
		delete[] meiro[i];
		delete[] shortestMeiro[i];
	}

	delete[] meiro;
	delete[] shortestMeiro;
}

void DrawMeiro(int** _meiro, int** _shortestMeiro)
{
	string str;
	for (int i = 0; i < h; ++i)
	{
		getline(cin, str);
		for (int j = 0; j < w; ++j)
		{
			switch (str[j])
			{
			case '#':
				_meiro[i][j] = -1;
				_shortestMeiro[i][j] = -1;
				break;
			case '.':
				_meiro[i][j] = -2;//meiro���̐�����0�ȏオ���ƂȂ�̂ŁA�ʉ߉\��-2�ŏ���
				_shortestMeiro[i][j] = -2;
				break;
			case '1':
				_meiro[i][j] = -2;
				_shortestMeiro[i][j] = -2;
				p1.SetCoords(j, i);
				break;
			case '2':
				_meiro[i][j] = -2;
				_shortestMeiro[i][j] = -2;
				p2.SetCoords(j, i);
				break;
			}
		}
	}
}

void OutputMeiro(int** _meiro)
{
	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			printf("%2d", _meiro[i][j]);
		}
		cout << endl;
	}
	cout << endl;
}
void DrawShortestMeiro(int** _shortestMeiro)
{
	InfoTile canmove(p1, 0);
	canmoveCoords.push(canmove);
	_shortestMeiro[p1.GetY()][p1.GetX()] = 0;
	while (!canmoveCoords.empty())
	{
		InfoTile nowTile = canmoveCoords.front();
		canmoveCoords.pop();
		_shortestMeiro[nowTile.GetY()][nowTile.GetX()] = nowTile.GetNowCount();

		if (nowTile.GetY() + 1 < h && _shortestMeiro[nowTile.GetY() + 1][nowTile.GetX()] == -2)
		{
			//_shortestMeiro[nowTile.GetY() + 1][nowTile.GetX()] = nowTile.GetNowCount() + 1;
			canmove.SetInfoTile(nowTile.GetX(), nowTile.GetY() + 1, nowTile.GetNowCount() + 1);
			canmoveCoords.push(canmove);

		}
		if (nowTile.GetY() - 1 >= 0 && _shortestMeiro[nowTile.GetY() - 1][nowTile.GetX()] == -2)
		{
			//_shortestMeiro[nowTile.GetY() - 1][nowTile.GetX()] = nowTile.GetNowCount() + 1;
			canmove.SetInfoTile(nowTile.GetX(), nowTile.GetY() - 1, nowTile.GetNowCount() + 1);
			canmoveCoords.push(canmove);
		}
		if (nowTile.GetX() + 1 < w && _shortestMeiro[nowTile.GetY()][nowTile.GetX() + 1] == -2)
		{
			//_shortestMeiro[nowTile.GetY()][nowTile.GetX() + 1] = nowTile.GetNowCount() + 1;
			canmove.SetInfoTile(nowTile.GetX() + 1, nowTile.GetY(), nowTile.GetNowCount() + 1);
			canmoveCoords.push(canmove);
		}
		if (nowTile.GetX() - 1 >= 0 && _shortestMeiro[nowTile.GetY()][nowTile.GetX() - 1] == -2)
		{
			canmove.SetInfoTile(nowTile.GetX() - 1, nowTile.GetY(), nowTile.GetNowCount() + 1);
			canmoveCoords.push(canmove);
		}
	}

	ResetCanMoveCoords();
}

int LongestRoadForP2(int** _meiro, int** _shortestMeiro)
{
	if (_shortestMeiro[p2.GetY()][p2.GetX()] == -2)//p1���ǂ������Ă�p2�ɂ��ǂ蒅���Ȃ��ꍇ
	{
		return -1;
	}
	int longestCount = 0;
	InfoTile canmove(p2, 0);
	canmoveCoords.push(canmove);
	_meiro[p2.GetY()][p2.GetX()] = 0;
	while (!canmoveCoords.empty())
	{
		InfoTile nowTile = canmoveCoords.front();
		canmoveCoords.pop();
		_meiro[nowTile.GetY()][nowTile.GetX()] = nowTile.GetNowCount();
		int nowp1cost = _shortestMeiro[nowTile.GetY()][nowTile.GetX()];
		if (longestCount < nowp1cost)
		{
			longestCount = nowp1cost;
		}
		if (nowTile.GetY() + 1 < h && _meiro[nowTile.GetY() + 1][nowTile.GetX()] == -2 &&//�i�ޏꏊ���[�𒴂��Ȃ��� && �ʂ������Ƃ̂Ȃ��ʘH�� && p1�ɒǂ�����Ȃ��ꏊ��
			nowTile.GetNowCount() < _shortestMeiro[nowTile.GetY() + 1][nowTile.GetX()] - 2)
		{
			canmove.SetInfoTile(nowTile.GetX(), nowTile.GetY() + 1, nowTile.GetNowCount() + 1);
			canmoveCoords.push(canmove);
		}
		if (nowTile.GetY() - 1 >= 0 && _meiro[nowTile.GetY() - 1][nowTile.GetX()] == -2 &&
			nowTile.GetNowCount() < _shortestMeiro[nowTile.GetY() - 1][nowTile.GetX()] - 2)
		{
			canmove.SetInfoTile(nowTile.GetX(), nowTile.GetY() - 1, nowTile.GetNowCount() + 1);
			canmoveCoords.push(canmove);
		}
		if (nowTile.GetX() + 1 < w && _meiro[nowTile.GetY()][nowTile.GetX() + 1] == -2 &&
			nowTile.GetNowCount() < _shortestMeiro[nowTile.GetY()][nowTile.GetX() + 1] - 2)
		{
			canmove.SetInfoTile(nowTile.GetX() + 1, nowTile.GetY(), nowTile.GetNowCount() + 1);
			canmoveCoords.push(canmove);
		}
		if (nowTile.GetX() - 1 >= 0 && _meiro[nowTile.GetY()][nowTile.GetX() - 1] == -2 &&
			nowTile.GetNowCount() < _shortestMeiro[nowTile.GetY()][nowTile.GetX() - 1] - 2)
		{
			canmove.SetInfoTile(nowTile.GetX() - 1, nowTile.GetY(), nowTile.GetNowCount() + 1);
			canmoveCoords.push(canmove);
		}
	}
	return longestCount;
}
void ResetCanMoveCoords()
{
	for (int i = 0; i < (int)canmoveCoords.size(); ++i)
	{
		canmoveCoords.pop();
	}
}