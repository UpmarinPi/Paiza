/*
* �𓚎��ԁF 104��42�b �o�C�g���F 3277 Byte �X�R�A�F 80�_

�p�C�U����́u���b�v�o�g���v�Ƃ����J�[�h�Q�[���Ƀn�}���Ă��܂��B
�u���b�v�o�g���v�͕�����̏����ꂽ N ���̎�D���� 1 ���ȏ�̍D���Ȗ����̃J�[�h����ɏo���āA�u�����̃J�[�h���ǂꂾ���C�𓥂߂Ă��邩�v�Ƃ����ϓ_����X�R�A�����܂�A�X�R�A����荂���l�������ƂȂ�Q�[���ł��B

�X�R�A�̌v�Z���͈ȉ��ŕ\����܂��B

(�i��ɏo�����J�[�h�̖����j- 1) �~ �i��ɏo�����J�[�h�S�Ă̍Œ����ʐڔ����̒����j

�Ȃ��AK �̕����� S_1, S_2, ..., S_K �̋��ʐڔ��� T �͈ȉ��𖞂������̂ł���A�Œ����ʐڔ����͋��ʐڔ����̂��������Ƃ��������́i���ʐڔ��������݂��Ȃ��ꍇ�͋󕶎���j�Ƃ��܂��i���̂悤�Ȃ��͈̂�ӂɒ�܂邱�Ƃ��ؖ��ł��܂��j�B

�ET �̒����� |T| �ƕ\���ƁA�S�Ă� i (1 �� i �� K) �ɑ΂� S_i �̖��� |T| ������ T �Ɉ�v����B

�p�C�U����́u���b�v�o�g���v�ŋ����Ȃ邽�߁AN ���̎�D���^����ꂽ���̃X�R�A�̍ō��l��m�肽���Ȃ�܂����B

N ���̎�D�̏�񂪗^������̂ŁA 1 ���ȏ�̍D���Ȗ����̃J�[�h����ɏo�����Ƃ��̃X�R�A�̍ō��l�����߂Ă��������B
�Ⴆ�Γ��͗� 1 �̏ꍇ�A`paiza`, `pizza`, `gyoza` �� 3 ���̃J�[�h����ɏo�����Ƃɂ��A�X�R�A�� (3 - 1) �~ 2 = 4 �ƂȂ�A���̎����ő�ƂȂ�̂�
4
�Əo�͂���Ɛ����ƂȂ�܂��B


[���͂����l]

���͎͂��̃t�H�[�}�b�g�ŗ^�����܂��B
N
S_1
S_2
...
S_N

�E1 �s�ڂɁA�u���b�v�o�g���v�̎�D�̖�����\������ N ���^�����܂��B
�E���� N �s�̂����� i �s�� (1 �� i �� N) �ɂ́Ai �Ԗڂ̎�D�ɏ����ꂽ������ S_i ���^�����܂��B
�E���͍͂��v�� N + 1 �s�ƂȂ�A���͒l�ŏI�s�̖����ɉ��s�� 1 ����܂��B

[���҂���o��]

�X�R�A�̍ō��l�𐮐��ŏo�͂��Ă��������B
�����ɉ��s�����A�]�v�ȕ����A��s���܂�ł͂����܂���B


[����]

���ׂẴe�X�g�P�[�X�ɂ����āA�ȉ��̏������݂����܂��B
�E1 �� N �� 100,000
�E�e i (1 �� i �� N) �ɂ���
�@�ES_i �͉p���������݂̂ō\������镶����
�@�E1 �� (S_i �̒���) �� 100,000
�E(S_1 �̒���) + (S_2 �̒���) + ... + (S_N �̒���) �� 200,000


 ���͗�1

5
paiza
paijo
pizza
gyoza
kirishima


 �o�͗�1

	4


 ���͗�2

7
abc
abc
aaa
a
ba
cba
zzz

 �o�͗�2

	3


 ���͗�3

3
aba
abb
abc

 �o�͗�3

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
	//�Œ��������T��
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
		//cout << countCorrectStr << "����" << endl;
		if (countCorrectStr == 1)
		{
			break;
		}
		else
		{
			int nowscore;
			nowscore = CalcScore(i, countCorrectStr);
			//cout << "���_: " << nowscore << endl;
			if (maxscore < nowscore)
			{
				maxscore = nowscore;
			}
			//cout << "���ݓ��_: " << maxscore << endl << endl;
		}
	}

	return maxscore;
}
//�������̕������������݂��邩
//s:������̔z��, n:s�̗v�f��, suffixLength:���ׂ��������͈�
int FindSuffixArray(string s[], int n, int suffixLength)
{
	int maxcount = 0;
	string* suffix = new string[n];
	for (int i = 0; i < n; ++i)
	{
		suffix[i] = GetLastString(s[i], suffixLength);
		//cout << suffix[i] << ", ";
	}
	//cout << "�̒T�����J�n���܂�" << endl << endl;
	for (int i = 0; i < n; ++i)
	{
		int count = 1;
		if (DuplicateCheck(suffix, suffix[i], i))
		{
			//cout << suffix[i] << "�͑O�񌟍����������͒T��������͈̔͂𒴂��Ă���̂Ŗ������܂�" << endl;
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
	//cout << str << "��" << laststr << "������" << endl;
	for (int i = 0; i < (int)laststr.size(); ++i)
	{
		if (str[str.size() - laststr.size() + i] != laststr[i])
		{
			//cout << "�s��v" << endl;
			return false;
		}
	}
	//cout << "��v" << endl;
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