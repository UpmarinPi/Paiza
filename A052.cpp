/*
* �𓚎��ԁF 42��8�b �o�C�g���F 1065 Byte �X�R�A�F 100�_

���Ȃ��͉Ƃ̊K�i��o��Ƃ��AA �i��΂��������� B �i��΂��œo�邱�Ƃɂ��Ă��܂��B
A �i��΂��� B �i��΂��������ēo�邱�Ƃ��ł��܂��B

������K�i�̑|�������悤�Ǝv���Ēi���悭���Ă݂�ƁA�S������Ă��Ȃ��i�����邱�ƂɋC�����܂����B�K�i�̒i���� A, B �̒l���^������̂ŁA�S������Ă��Ȃ��i�A���Ȃ킿�ǂ̂悤�Ɉړ����Ă����ނ��Ƃ̂Ȃ��i�͂������邩������v���O�������쐬���Ă��������B
�������A���Ȃ������݂���i���璸��܂ł̒i���� A ����� B �����������ꍇ�̂݁A���傤�ǒ���ɓ��B����悤�Ȓi�������o�邱�Ƃ��ł��܂��B


[���͂����l]

���͎͂��̃t�H�[�}�b�g�ŗ^�����܂��B
N
A B

�E1 �s�ڂɂ́A�K�i�̒i����\������ N ���^�����܂��B
�E2 �s�ڂɂ́A�o�邱�Ƃ̂ł���K�i�̒i����\������ A, B �����p�X�y�[�X��؂�œ��͂���܂��B
�E���͂͑S���� 2 �s�ƂȂ�A�Ō�ɉ��s�������܂��B


[���҂���o��]

���B���邱�Ƃ��ł��Ȃ��K�i�̒i�͂������邩�����ŏo�͂��Ă��������B

�����ɉ��s�����A�]�v�ȕ����A��s���܂�ł͂����܂���B


[����]

���ׂẴe�X�g�P�[�X�ɂ����āA�ȉ��̏������݂����܂��B
�E1 �� N �� 200,000
�E1 �� A < B �� 100


 ���͗�1

8
3 5


 �o�͗�1

	4


 ���͗�2

10
2 4

 �o�͗�2

	5


 ���͗�3

15
4 6

 �o�͗�3

	8


 ���͗�4

7
3 5

 �o�͗�4

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

	//������
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
	//�z��[0]�͕K���ʂ�i�Ƃ��āA�ŏ�i�̑���Ƃ���
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