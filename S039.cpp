/*
* 解答時間： 83分12秒 バイト数： 2337 Byte スコア： 100点

あなたはゲームエンジニアで、ダンジョンゲームの開発をしています。
ダンジョンのマップは縦 H マス × 横 W マスからなっており、このダンジョンのいくつかのマスは塞がっています。
あなたは、塞がっていないマスのみからなる長方形のうちで、面積が最大となる長方形をボスの部屋にしようと考えています。
このとき、ボスの部屋の面積を出力してください。


[入力される値]

入力は次のフォーマットで与えられます。
H W
s_1
s_2
...
s_H

・1 行目にそれぞれダンジョンの縦幅、横幅を表す整数 H, W がこの順で半角スペース区切りで与えられます。
・続く H 行のうちの i 行目 (1 ≦ i ≦ H) には半角記号 "#" および "." からなる長さ W の文字列 s_i が与えられます。s_i の j 番目 (1 ≦ j ≦ W) の文字 s_{i, j} は i 行 j 列のマスを表し、"#" はそのマスが塞がっていることを、"." は塞がっていないことを表します。
・入力は合計で H + 1 行となり、入力値最終行の末尾に改行が 1 つ入ります。

[期待する出力]

塞がっていないマスのみからなる長方形のうち、面積が最大となる長方形の面積を出力してください。
末尾に改行を入れ、余計な文字、空行を含んではいけません。


[条件]

すべてのテストケースにおいて、以下の条件をみたします。
・1 ≦ H, W ≦ 500
・s_{i, j} は半角記号で "#", "." のいずれか (1 ≦ i ≦ H, 1 ≦ j ≦ W)


 入力例1

4 5
.##..
.....
...##
#.###


 出力例1

	6


 入力例2

6 6
#..#..
.....#
.#....
......
#...#.
.#.#..


 出力例2

	9

*/
#include <iostream>
#include <string>
#include <sstream>
#include <tuple>
using namespace std;

void OutputRoom(char** room, int h, int w);
tuple<int, int> CheckArea(char** room, int h, int w, int y, int x);

int main()
{
	char** room;
	int h, w;
	int maxh = 0, maxw = 0;
	int max = 0;

	string str;
	getline(cin, str);
	istringstream s(str);
	s >> h >> w;

	room = new char* [h];
	for (int i = 0; i < h; ++i)
	{
		room[i] = new char[w];
	}

	for (int i = 0; i < h; ++i)
	{
		getline(cin, str);
		for (int j = 0; j < w; ++j)
		{
			room[i][j] = str[j];
		}
	}

	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			if (room[i][j] == '.')
			{
				int karimaxh, karimaxw;

				tie(karimaxh, karimaxw) = CheckArea(room, h, w, i, j);
				if (karimaxh * karimaxw > maxh * maxw)
				{
					maxh = karimaxh;
					maxw = karimaxw;
					//cout << "(" << maxh << " * " << maxw << ")に更新" << endl;
				}
			}
		}
	}
	cout << maxh * maxw << endl;

	return 0;
}

tuple<int, int> CheckArea(char** room, int h, int w, int y, int x)
{
	int maxWidth = 0;//最大の横幅を求める
	for (maxWidth = 0; maxWidth < w - x; ++maxWidth)
	{
		if (room[y][x + maxWidth] != '.')
		{
			break;
		}
	}
	int k;
	int counth = 0;
	int countw = 0;
	int karimaxw = 0, karimaxh = 0;
	int realMax = 0;
	bool nextwFlag;
	for (int i = 0; i < maxWidth; ++i)//横幅最小から最大まで求める
	{
		nextwFlag = false;
		for (int j = 0; j < h - y; ++j)
		{
			for (k = 0; k < i + 1; ++k)
			{
				if (room[j + y][k + x] != '.')
				{

					//cout << "(" << j + y << ", " << k + x << ")" << room[j + y][k + x] << "により異常あり" << endl;
					nextwFlag = true;
					break;
				}
				//cout << "(" << j + y << ", " << k + x << ")" << room[j + y][k + x] << "により異常なし" << endl;
			}
			if (nextwFlag)
			{
				break;
			}
			else
			{
				//cout << "(" << y << ", " << x << ")から(" << j + 1 << " * " << k << ")" << endl;
				karimaxw = k;
				karimaxh = j + 1;
			}
		}
		if (karimaxw * karimaxh > realMax)
		{
			//cout << "(" << y << ", " << x << ")にて" << karimaxh << " * " << karimaxw << "を発見" << endl;
			realMax = karimaxw * karimaxh;
			counth = karimaxh;
			countw = karimaxw;
		}
	}
	return forward_as_tuple(counth, countw);
}

void OutputRoom(char** room, int h, int w)
{
	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			cout << room[i][j];
		}
		cout << endl;
	}
	cout << endl;
}