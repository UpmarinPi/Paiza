/*
* �𓚎��ԁF 83��12�b �o�C�g���F 2337 Byte �X�R�A�F 100�_

���Ȃ��̓Q�[���G���W�j�A�ŁA�_���W�����Q�[���̊J�������Ă��܂��B
�_���W�����̃}�b�v�͏c H �}�X �~ �� W �}�X����Ȃ��Ă���A���̃_���W�����̂������̃}�X�͍ǂ����Ă��܂��B
���Ȃ��́A�ǂ����Ă��Ȃ��}�X�݂̂���Ȃ钷���`�̂����ŁA�ʐς��ő�ƂȂ钷���`���{�X�̕����ɂ��悤�ƍl���Ă��܂��B
���̂Ƃ��A�{�X�̕����̖ʐς��o�͂��Ă��������B


[���͂����l]

���͎͂��̃t�H�[�}�b�g�ŗ^�����܂��B
H W
s_1
s_2
...
s_H

�E1 �s�ڂɂ��ꂼ��_���W�����̏c���A������\������ H, W �����̏��Ŕ��p�X�y�[�X��؂�ŗ^�����܂��B
�E���� H �s�̂����� i �s�� (1 �� i �� H) �ɂ͔��p�L�� "#" ����� "." ����Ȃ钷�� W �̕����� s_i ���^�����܂��Bs_i �� j �Ԗ� (1 �� j �� W) �̕��� s_{i, j} �� i �s j ��̃}�X��\���A"#" �͂��̃}�X���ǂ����Ă��邱�Ƃ��A"." �͍ǂ����Ă��Ȃ����Ƃ�\���܂��B
�E���͍͂��v�� H + 1 �s�ƂȂ�A���͒l�ŏI�s�̖����ɉ��s�� 1 ����܂��B

[���҂���o��]

�ǂ����Ă��Ȃ��}�X�݂̂���Ȃ钷���`�̂����A�ʐς��ő�ƂȂ钷���`�̖ʐς��o�͂��Ă��������B
�����ɉ��s�����A�]�v�ȕ����A��s���܂�ł͂����܂���B


[����]

���ׂẴe�X�g�P�[�X�ɂ����āA�ȉ��̏������݂����܂��B
�E1 �� H, W �� 500
�Es_{i, j} �͔��p�L���� "#", "." �̂����ꂩ (1 �� i �� H, 1 �� j �� W)


 ���͗�1

4 5
.##..
.....
...##
#.###


 �o�͗�1

	6


 ���͗�2

6 6
#..#..
.....#
.#....
......
#...#.
.#.#..


 �o�͗�2

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
					//cout << "(" << maxh << " * " << maxw << ")�ɍX�V" << endl;
				}
			}
		}
	}
	cout << maxh * maxw << endl;

	return 0;
}

tuple<int, int> CheckArea(char** room, int h, int w, int y, int x)
{
	int maxWidth = 0;//�ő�̉��������߂�
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
	for (int i = 0; i < maxWidth; ++i)//�����ŏ�����ő�܂ŋ��߂�
	{
		nextwFlag = false;
		for (int j = 0; j < h - y; ++j)
		{
			for (k = 0; k < i + 1; ++k)
			{
				if (room[j + y][k + x] != '.')
				{

					//cout << "(" << j + y << ", " << k + x << ")" << room[j + y][k + x] << "�ɂ��ُ킠��" << endl;
					nextwFlag = true;
					break;
				}
				//cout << "(" << j + y << ", " << k + x << ")" << room[j + y][k + x] << "�ɂ��ُ�Ȃ�" << endl;
			}
			if (nextwFlag)
			{
				break;
			}
			else
			{
				//cout << "(" << y << ", " << x << ")����(" << j + 1 << " * " << k << ")" << endl;
				karimaxw = k;
				karimaxh = j + 1;
			}
		}
		if (karimaxw * karimaxh > realMax)
		{
			//cout << "(" << y << ", " << x << ")�ɂ�" << karimaxh << " * " << karimaxw << "�𔭌�" << endl;
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