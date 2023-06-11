/*
* 解答時間： 104分42秒 バイト数： 3277 Byte スコア： 80点

パイザさんは「ラップバトル」というカードゲームにハマっています。
「ラップバトル」は文字列の書かれた N 枚の手札から 1 枚以上の好きな枚数のカードを場に出して、「それらのカードがどれだけ韻を踏めているか」という観点からスコアが決まり、スコアがより高い人が勝ちとなるゲームです。

スコアの計算式は以下で表されます。

(（場に出したカードの枚数）- 1) × （場に出したカード全ての最長共通接尾辞の長さ）

なお、K 個の文字列 S_1, S_2, ..., S_K の共通接尾辞 T は以下を満たすものであり、最長共通接尾辞は共通接尾辞のうちもっとも長いもの（共通接尾辞が存在しない場合は空文字列）とします（そのようなものは一意に定まることが証明できます）。

・T の長さを |T| と表すと、全ての i (1 ≦ i ≦ K) に対し S_i の末尾 |T| 文字が T に一致する。

パイザさんは「ラップバトル」で強くなるため、N 枚の手札が与えられた時のスコアの最高値を知りたくなりました。

N 枚の手札の情報が与えられるので、 1 枚以上の好きな枚数のカードを場に出したときのスコアの最高値を求めてください。
例えば入力例 1 の場合、`paiza`, `pizza`, `gyoza` の 3 枚のカードを場に出すことにより、スコアが (3 - 1) × 2 = 4 となり、その時が最大となるので
4
と出力すると正答となります。


[入力される値]

入力は次のフォーマットで与えられます。
N
S_1
S_2
...
S_N

・1 行目に、「ラップバトル」の手札の枚数を表す整数 N が与えられます。
・続く N 行のうちの i 行目 (1 ≦ i ≦ N) には、i 番目の手札に書かれた文字列 S_i が与えられます。
・入力は合計で N + 1 行となり、入力値最終行の末尾に改行が 1 つ入ります。

[期待する出力]

スコアの最高値を整数で出力してください。
末尾に改行を入れ、余計な文字、空行を含んではいけません。


[条件]

すべてのテストケースにおいて、以下の条件をみたします。
・1 ≦ N ≦ 100,000
・各 i (1 ≦ i ≦ N) について
　・S_i は英字小文字のみで構成される文字列
　・1 ≦ (S_i の長さ) ≦ 100,000
・(S_1 の長さ) + (S_2 の長さ) + ... + (S_N の長さ) ≦ 200,000


 入力例1

5
paiza
paijo
pizza
gyoza
kirishima


 出力例1

	4


 入力例2

7
abc
abc
aaa
a
ba
cba
zzz

 出力例2

	3


 入力例3

3
aba
abb
abc

 出力例3

	0

*/
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int GetScore(string s[], int n);
int FindSuffixArray(string s[], int n, int suffixLength);
string GetLastString(string s, int suffixLength);
bool DuplicateCheck(string suffix[], string findsuffix, int m);
bool CompareLastStr(const string str, const string laststr);
int CalcScore(int length, int count);
void StrToInt(string str, int& n);
int main()
{

	string str;
	int n;
	int score;
	string* s;
	getline(cin, str);
	StrToInt(str, n);
	s = new string[n];

	for (int i = 0; i < n; ++i)
	{
		getline(cin, s[i]);
	}

	score = GetScore(s, n);

	cout << score << endl;

	delete[] s;
	return 0;
}

int GetScore(string s[], int n)
{
	int longestLength = 0;
	//最長文字列を探す
	for (int i = 0; i < n; ++i)
	{
		int length = s[i].size();
		if (longestLength < length)
		{
			longestLength = length;
		}
	}
	int maxscore = 0;
	for (int i = 1; i <= longestLength; ++i)
	{
		int countCorrectStr;
		countCorrectStr = FindSuffixArray(s, n, i);
		//cout << countCorrectStr << "個発見" << endl;
		if (countCorrectStr == 1)
		{
			break;
		}
		else
		{
			int nowscore;
			nowscore = CalcScore(i, countCorrectStr);
			//cout << "得点: " << nowscore << endl;
			if (maxscore < nowscore)
			{
				maxscore = nowscore;
			}
			//cout << "現在得点: " << maxscore << endl << endl;
		}
	}

	return maxscore;
}
//末尾辞の文字数が何個存在するか
//s:文字列の配列, n:sの要素数, suffixLength:調べたい末尾範囲
int FindSuffixArray(string s[], int n, int suffixLength)
{
	int maxcount = 0;
	string* suffix = new string[n];
	for (int i = 0; i < n; ++i)
	{
		suffix[i] = GetLastString(s[i], suffixLength);
		//cout << suffix[i] << ", ";
	}
	//cout << "の探索を開始します" << endl << endl;
	for (int i = 0; i < n; ++i)
	{
		int count = 1;
		if (DuplicateCheck(suffix, suffix[i], i))
		{
			//cout << suffix[i] << "は前回検索した或いは探索文字列の範囲を超えているので無視します" << endl;
			continue;
		}
		for (int j = i + 1; j < n; ++j)
		{
			if (CompareLastStr(s[j], suffix[i]))
			{
				++count;
			}
		}
		if (maxcount < count)
		{
			maxcount = count;
		}
	}
	delete[] suffix;
	return maxcount;
}
bool DuplicateCheck(string suffix[], string findsuffix, int m)
{
	if (findsuffix[0] == '\0')
	{
		return true;
	}
	for (int i = 0; i < m; ++i)
	{
		if (suffix[i] == findsuffix)
		{
			return true;
		}
	}
	return false;
}
string GetLastString(string s, int suffixLength)
{

	string laststr;
	if ((int)s.size() < suffixLength)
	{
		laststr.resize(1);
		laststr[0] = '\0';
		return laststr;
	}
	laststr.resize(suffixLength);
	for (int i = 0; i < suffixLength; ++i)
	{
		int copypoint = (int)s.size() - suffixLength + i;
		laststr[i] = s[copypoint];
	}

	return laststr;
}

bool CompareLastStr(const string str, const string laststr)
{
	if (str.size() < laststr.size())
	{
		return false;
	}
	//cout << str << "で" << laststr << "を検索" << endl;
	for (int i = 0; i < (int)laststr.size(); ++i)
	{
		if (str[str.size() - laststr.size() + i] != laststr[i])
		{
			//cout << "不一致" << endl;
			return false;
		}
	}
	//cout << "一致" << endl;
	return true;
}

int CalcScore(int length, int count)
{
	return (count - 1) * length;
}

void StrToInt(string str, int& n)
{
	n = 0;
	for (int i = 0; i < (int)str.size(); ++i)
	{
		int h = str[i] - '0';
		if (0 <= h && h <= 9)
		{
			n *= 10;
			n += h;
		}
		else
		{
			return;
		}
	}
}