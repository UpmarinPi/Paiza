/*
* 解答時間： 2955分47秒 バイト数： 6771 Byte スコア： 0点
* ※2日かけて解いた問題のため、テスト自体は全問正解でしたが制限時間超過のため0点です

あなたはふと、子供の頃に遊んだ次のようなゲームを思い出しました。

このゲームは二人のプレイヤー (プレイヤー 1, プレイヤー 2 とします) によって行われます。
ゲームを行う舞台として、横 W マス、縦 H マスのグリッドが与えられます。
グリッドの各マスは「何もない」か「障害物がある」かのいずれかで、プレイヤーは「何もない」マスの上を移動することができます。
また、与えられるグリッドには閉路がないことが保証されています。
ここで、マスの列 (x_1, y_1), (x_2, y_2), ..., (x_n, y_n) (n ≧ 4) が閉路であるとは、次の 3 つの条件が満たされることとします。

・各 i (1≦ i ≦ n) に対して (x_i, y_i) は「何もない」マスである。
・各 i (1≦ i ≦ n) に対して (x_i, y_i) と (x_{i+1}, y_{i+1}) は上下左右のいずれかで隣接している。ただし x_{n+1}=x_1, y_{n+1}=y_1 とする。
・i ≠ j ならば (x_i, y_i) ≠ (x_j, y_j) である。

与えられるグリッドの例を次に示します。

ゲームの開始時には、各プレイヤーはグリッド内の「何もない」マスにいます。
ゲームは次の手順を繰り返すことで進行します。

1. プレイヤー 1 が隣接する「何もない」マスへ移動する。またはその場にとどまる。
2. プレイヤー 2 が隣接する「何もない」マスへ移動する。またはその場にとどまる。

プレイヤー 1 はプレイヤー 2 のいるマスに重なるとゲームクリアになります。
プレイヤー 2 はプレイヤー 1 がゲームクリアするのができるだけ遅くなるように逃げ回ります。
両プレイヤーが最適な行動をしたとき、プレイヤー 1 はゲームクリアまでに最小で何回移動することになるでしょうか。

なお、与えられる入力では、プレイヤー 1 の初期位置からプレイヤー 2 の初期位置へ「何もない」マスを通って移動できることが保証されています。


[入力される値]

入力は次のフォーマットで与えられます。
W H
s_1
s_2
...
s_H

・1 行目には、迷路の横幅と縦幅を表す整数 W, H が半角スペース区切りで与えられます。
・続く H 行のうちの i 行目 (1 ≦ i ≦ N) には、".", "#", "1", "2" からなる長さ W の文字列 s_i が与えられます。s_i の j 番目 (1 ≦ j ≦ W) の文字はグリッドにおけるマス (j, i) の状態を表し、"." はそのマスに「何もない」ことを、"#" はそのマスに「障害物がある」ことを、"1" はそのマスがプレイヤー 1 の初期位置であることを、"2" はそのマスがプレイヤー 2 の初期位置であることをそれぞれ意味します。
・入力は合計で H + 1 行となり、入力値最終行の末尾に改行が 1 つ入ります。

[期待する出力]

・両プレイヤーが最適な行動をしたとき、プレイヤー 1 がゲームクリアするために必要な最小の移動回数を出力してください。
・末尾に改行を入れ、余計な文字、空行を含んではいけません。


[条件]

すべてのテストケースにおいて、以下の条件をみたします。
・1 ≦ W, H ≦ 1,000
・s_i は ".", "#", "1", "2" で構成される長さ W の文字列 (1 ≦ i ≦ H)
・与えられるグリッドに "1" および "2" はちょうど 1 回ずつ現れる
・与えられるグリッドに閉路はない
・プレイヤー 1 の初期位置からプレイヤー 2 の初期位置へ「何もない」マスを通って移動できる


 入力例1

3 3
1#.
2..
.#.


 出力例1

	1


 入力例2

9 8
#####..##
...2#.#.#
###.#..1.
......###
.####.#..
....#####
###.##...
....#..#.

 出力例2

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
				_meiro[i][j] = -2;//meiro内の数字は0以上が情報となるので、通過可能は-2で処理
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
	if (_shortestMeiro[p2.GetY()][p2.GetX()] == -2)//p1がどう動いてもp2にたどり着かない場合
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
		if (nowTile.GetY() + 1 < h && _meiro[nowTile.GetY() + 1][nowTile.GetX()] == -2 &&//進む場所が端を超えないか && 通ったことのない通路か && p1に追いつかれない場所か
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