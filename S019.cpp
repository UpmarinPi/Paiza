/*
* �𓚎��ԁF 89��24�b �o�C�g���F 3413 Byte �X�R�A�F 90�_

���Ȃ��͍s���l�ł��B �l�X�ȊX���߂��菤�����Ă��܂��B
���̐��E��2�����O���b�h�ŕ\������A �E�[�ƍ��[�A��[�Ɖ��[�Ń��[�v�����s�v�c�Ȑ��E�ł��B
�c���ǂ��炩�� 1 �}�X�Âړ����邽�߁A�X����X�ֈړ�����̂����J�ł��B

���Ȃ��́A�����̌����������邽�ߊX�ƊX�̊Ԃ��e���|�[�g����������o���܂����B
���炩���ߊX�𖂏p���ɓo�^���Ă����ƁA���̊X�܂ňړ����� 0 �Ńe���|�[�g�o���܂��B �܂��o�^���Ă���X���������߁A����͍s�������X��o�^���Ă������ɂ��܂����B

���Ȃ��͒n�}��Ў�ɁA�e���|�[�g����g���đS�Ă̊X������s�����[�g�𒲂ׂĂ��܂��B
�ǂ̊X����o�����Ă��ǂ��Ƃ��āA�S�Ă̊X������ۂɕK�v�ȍŏ��̈ړ��������v�Z���Ă��������B

�Ⴆ�΁A���͗� 1 �ł� �X1�A�X2�A�X3 ��3�̊X������܂��B
�X1 ����o������ꍇ�A ��ԋ߂� �X2 �֍s���ƈړ����� 5 �ƂȂ�܂��B
�X2 �ɍs������� �X3 �֍s���ꍇ�A �X1 �Ƀe���|�[�g����ƈړ������� 6 �ł��B
����āA�X1�A�X2�A�X3�̏��̍s������ۂ̍ŏ��̈ړ������� 11 �ƂȂ�܂��B


[���͂����l]

���͎͂��̃t�H�[�}�b�g�ŗ^�����܂��B
N H W
x_1 y_1
x_2 y_2
...
x_N y_N

�E1 �s�ڂɂ́A�X�̐� N�A�n�}�̏c����\������ H�A �n�}�̉������������� W �����̏��Ŕ��p�X�y�[�X��؂�ŗ^�����܂��B
�E���� N �s�ɂ́A i �s�� (1 �� i �� N) �� i �Ԗڂ̊X�� x ���W x_i�Ay ���W y_i �����̏��Ŕ��p�X�y�[�X��؂�ŗ^�����܂��B
�E���͍͂��v�� N + 1 �s�ƂȂ�A���͒l�ŏI�s�̖����ɉ��s���P����܂��B

[���҂���o��]

�ǂ̊X����o�����Ă��ǂ��Ƃ��āA�S�Ă̊X���e���|�[�g���g���ď���ۂ̍ŏ��̈ړ������𐮐��ŏo�͂��Ă��������B
�Ō�͉��s���A�]�v�ȕ����A��s���܂�ł͂����܂���B


[����]

���ׂẴe�X�g�P�[�X�ɂ����āA�ȉ��̏������݂����܂��B
�E1 �� N �� 2,000
�E1 �� H, W �� 1,000
�E�e i (1 �� i �� N) �ɂ��āA�ȉ��𖞂���
�@�E1 �� x_i �� W
�@�E1 �� y_i �� H


 ���͗�1

3 10 10
3 9
2 3
6 6


 �o�͗�1

	11


 ���͗�2

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

 �o�͗�2

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
	/*1 �� N �� 2,000
�E1 �� H, W �� 1,000*/
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

	/*�e i (1 �� i �� N) �ɂ��āA�ȉ��𖞂���
�@�E1 �� x_i �� W
�@�E1 �� y_i �� H
 */
 //����������
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
	//��ԒZ��������T��
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
	//�e���|�[�g�\
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