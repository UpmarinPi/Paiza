/*
* 解答時間： 42分8秒 バイト数： 1065 Byte スコア： 100点

あなたは家の階段を登るとき、A 段飛ばしもしくは B 段飛ばしで登ることにしています。
A 段飛ばしと B 段飛ばしを混ぜて登ることもできます。

ある日階段の掃除をしようと思って段をよく見てみると、全く汚れていない段があることに気がつきました。階段の段数と A, B の値が与えられるので、全く汚れていない段、すなわちどのように移動しても踏むことのない段はいくつあるか数えるプログラムを作成してください。
ただし、あなたが現在いる段から頂上までの段数が A および B よりも小さい場合のみ、ちょうど頂上に到達するような段数だけ登ることができます。


[入力される値]

入力は次のフォーマットで与えられます。
N
A B

・1 行目には、階段の段数を表す整数 N が与えられます。
・2 行目には、登ることのできる階段の段数を表す整数 A, B が半角スペース区切りで入力されます。
・入力は全部で 2 行となり、最後に改行が一つ入ります。


[期待する出力]

到達することができない階段の段はいくつあるか整数で出力してください。

末尾に改行を入れ、余計な文字、空行を含んではいけません。


[条件]

すべてのテストケースにおいて、以下の条件をみたします。
・1 ≦ N ≦ 200,000
・1 ≦ A < B ≦ 100


 入力例1

8
3 5


 出力例1

	4


 入力例2

10
2 4

 出力例2

	5


 入力例3

15
4 6

 出力例3

	8


 入力例4

7
3 5

 出力例4

	3

*/
#include <iostream>
#include <string>
using namespace std;

void StringToInt(const string str, int& a);
int main()
{

	string nStr;
	int n;
	int a, b;
	bool* nBool;
	int count = 0;

	getline(cin, nStr);
	cin >> a >> b;
	StringToInt(nStr, n);

	if (!(1 <= n && n <= 200000 &&
		1 <= a && a <= b && b <= 100))
	{
		cout << "missed number" << endl;
		return 0;
	}
	nBool = new bool[n];

	//初期化
	for (int i = 0; i < n; ++i)
	{
		nBool[i] = true;
	}
	for (int ac = 0; ac < n; ac += a)
	{
		for (int bc = 0; ac + bc < n; bc += b)
		{
			nBool[ac + bc] = false;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		if (nBool[i] == true)
		{
			++count;
		}
	}
	//配列[0]は必ず通る段として、最上段の代わりとする
	delete[] nBool;

	//cout << "n: " << n << endl << "a: " << a << endl << "b: " << b << endl << "count: " << count << endl;

	cout << count << endl;
	return 0;
}

void StringToInt(const string str, int& a)
{
	int num = 0;
	a = 0;
	for (int i = 0; i < (int)str.size(); ++i)
	{
		num = (int)str[i] - '0';
		for (int j = 0; j < (int)str.size() - i - 1; ++j)
		{
			num *= 10;
		}
		a += num;
	}
}