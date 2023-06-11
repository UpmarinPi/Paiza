/*
* 解答時間： 89分24秒 バイト数： 3413 Byte スコア： 90点

あなたは行商人です。 様々な街をめぐり商売しています。
この世界は2次元グリッドで表せられる、 右端と左端、上端と下端でループした不思議な世界です。
縦横どちらかに 1 マスづつ移動するため、街から街へ移動するのも一苦労です。

あなたは、商売の効率をあげるため街と街の間をテレポートする呪文を覚えました。
あらかじめ街を魔術書に登録しておくと、その街まで移動距離 0 でテレポート出来ます。 まだ登録してある街が無いため、今後は行商した街を登録していく事にしました。

あなたは地図を片手に、テレポートを駆使して全ての街を巡る行商ルートを調べています。
どの街から出発しても良いとして、全ての街を巡る際に必要な最小の移動距離を計算してください。

例えば、入力例 1 では 街1、街2、街3 の3つの街があります。
街1 から出発する場合、 一番近い 街2 へ行くと移動距離 5 となります。
街2 に行った後に 街3 へ行く場合、 街1 にテレポートすると移動距離は 6 です。
よって、街1、街2、街3の順の行商する際の最小の移動距離は 11 となります。


[入力される値]

入力は次のフォーマットで与えられます。
N H W
x_1 y_1
x_2 y_2
...
x_N y_N

・1 行目には、街の数 N、地図の縦幅を表す整数 H、 地図の横幅を示す整数 W がこの順で半角スペース区切りで与えられます。
・続く N 行には、 i 行目 (1 ≦ i ≦ N) に i 番目の街の x 座標 x_i、y 座標 y_i がこの順で半角スペース区切りで与えられます。
・入力は合計で N + 1 行となり、入力値最終行の末尾に改行が１つ入ります。

[期待する出力]

どの街から出発しても良いとして、全ての街をテレポートを使って巡る際の最小の移動距離を整数で出力してください。
最後は改行し、余計な文字、空行を含んではいけません。


[条件]

すべてのテストケースにおいて、以下の条件をみたします。
・1 ≦ N ≦ 2,000
・1 ≦ H, W ≦ 1,000
・各 i (1 ≦ i ≦ N) について、以下を満たす
　・1 ≦ x_i ≦ W
　・1 ≦ y_i ≦ H


 入力例1

3 10 10
3 9
2 3
6 6


 出力例1

	11


 入力例2

15 200 100
23 181
45 111
7 169
51 188
59 68
40 197
19 49
59 198
43 59
19 118
69 32
27 46
11 189
83 53
65 29

 出力例2

	385

*/
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Coords;
void Swap(int& a, int& b);
int GetDistanceCoords(Coords acoords, Coords bcoords, int h, int w);
int GetDistanceNum(int a, int b, int worh);
bool CheckAllVisit(bool flag[], int yousosu);

class Coords {
private:
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



	int GetX()
	{
		return x;
	}
	int GetY()
	{
		return y;
	}


	void SetX(int _x)
	{
		x = _x;
	}
	void SetY(int _y)
	{
		y = _y;
	}
};

void Swap(int& a, int& b)
{
	int c = a;
	a = b;
	b = c;
}
int GetDistanceCoords(Coords acoords, Coords bcoords, int h, int w)
{

	int xdis = GetDistanceNum(acoords.GetX(), bcoords.GetX(), w);
	int ydis = GetDistanceNum(acoords.GetY(), bcoords.GetY(), h);
	return xdis + ydis;
}
int GetDistanceNum(int a, int b, int worh)
{
	if (a < b)
	{
		Swap(a, b);
	}
	int dis = a - b;
	if (dis > worh / 2)
	{
		dis = (worh - a) + b;
	}
	return dis;
}

bool CheckAllVisit(bool flag[], int yousosu)
{
	for (int i = 0; i < yousosu; ++i)
	{
		if (flag[i] == false)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	string str;
	int n, h, w;
	Coords* coords;
	bool* teleportFlag;
	getline(cin, str);
	istringstream s(str);
	int sumDistance = 0;
	s >> n >> h >> w;
	/*1 ≦ N ≦ 2,000
・1 ≦ H, W ≦ 1,000*/
	if (1 > n || n > 2000 || 1 > h || w > 1000)
	{
		return 0;
	}

	if (n == 1)
	{
		cout << "0" << endl;
		return 0;
	}
	//cout << "n: " << n << endl << "h: " << h << endl << "w: " << w << endl << endl;
	coords = new Coords[n];
	teleportFlag = new bool[n];

	/*各 i (1 ≦ i ≦ N) について、以下を満たす
　・1 ≦ x_i ≦ W
　・1 ≦ y_i ≦ H
 */
 //初期化処理
	for (int i = 0; i < n; ++i)
	{
		getline(cin, str);
		istringstream s(str);
		int karix, kariy;

		s >> karix >> kariy;

		if (1 > karix || karix > w ||
			1 > kariy || kariy > h)
		{
			return 0;
		}

		Coords kariCoords(karix - 1, kariy - 1);
		coords[i] = kariCoords;
		teleportFlag[i] = false;
		//cout << "karix: " << karix << endl << "kariy: " << kariy << endl << endl;
	}

	int minDistance = 0;
	int firstCoords = 0;
	int secondCoords = 0;
	//一番短い距離を探す
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			int dis = GetDistanceCoords(coords[i], coords[j], h, w);
			if (minDistance == 0 || dis < minDistance)
			{
				firstCoords = i;
				secondCoords = j;
				minDistance = dis;
				//cout << "[" << i << "][" << j << "] now minDistance is " << minDistance << endl;
			}
		}
	}

	sumDistance = minDistance;
	//テレポート可能
	teleportFlag[firstCoords] = true;
	teleportFlag[secondCoords] = true;

	do
	{
		bool updateFlag = false;
		int minDistance = 0;
		int newWayCoords = 0;
		for (int i = 0; i < n; ++i)
		{
			if (teleportFlag[i])
			{
				for (int j = 0; j < n; ++j)
				{
					if (!teleportFlag[j])
					{
						//cout << "[" << i << "][" << j << "]" << endl;
						int dis = GetDistanceCoords(coords[i], coords[j], h, w);
						if (minDistance == 0 || dis < minDistance)
						{
							updateFlag = true;
							newWayCoords = j;
							minDistance = dis;
						}
					}
				}
			}
		}
		if (updateFlag)
		{
			teleportFlag[newWayCoords] = true;
			sumDistance += minDistance;
			//cout << teleportFlag[0] << endl << teleportFlag[1] << endl << teleportFlag[2] << endl << endl;
		}
	} while (!CheckAllVisit(teleportFlag, n));


	cout << sumDistance << endl;

	delete[] coords;
	delete[] teleportFlag;
	return 0;
}