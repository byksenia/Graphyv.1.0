#include <iostream>
#include <windows.h>

using namespace std;

struct item { //��������� ��� �������� �������� �����
	int s, c; //��������� � �������� ����
	int v; //"���" ����
};

const int m = 10; //���������� ����� �� �����
struct item map[m] = { //��� ����, ��������� ����� � ����
 {1,2,3}, {1,3,2}, {2,4,5}, {2,5,2}, {3,6,1},
 {6,5,6}, {5,7,3}, {7,10,8}, {6,8,3},{8,9,4}
};
const int n = 8; //���������� ������ �����
int road[n]; //������ ����� ������� "������"
bool incl[n]; //true, ���� i-�� ������� �������� � ����
int way[n]; //������� ����� �������� ����
int waylen; //��� �����
int start, finish; //��������� � �������� �������
bool found;
int len; //��������� "���" ��������
int c_len; //������� "���" ��������

int find(int s, int c) { //��� ���� �� s � c ��� 0, ���� ���� ���
	for (int i = 0; i < m; i++)
		if (map[i].s == s && map[i].c == c ||
			map[i].s == c && map[i].c == s) return map[i].v;
	return 0;
}

void step(int s, int f, int p) { //����������� ����� ���� ����
	int c; //����� �������, ���� ������ ���
	if (s == f) { //���� ������
		found = true; //��������� ������ "�������"
		len = c_len; //��������� ����� ��� ����
		waylen = p; //��������� ����� ���� (���������� �����)
		for (int i = 0; i < waylen; i++) way[i] = road[i]; //��������� ��� ����
	}
	else { //����� ��������� �����
		for (c = 0; c < n; c++) { //��������� ��� �������
			int w = find(s, c); //���� �� ���� �� s � c
			if (w && !incl[c] && (len == 0 || c_len + w < len)) { //������ ����� �� ��������?
				road[p] = c; //�������� ����� � ����
				incl[c] = true; //�������� ��� ����������
				c_len += w; //������ � ����� ���� ����
				step(c, f, p + 1); //������� ���� ��� ������ ��������� �����
				road[p] = 0; //������� �� ��� ����
				incl[c] = false;
				c_len -= w;
			}
		}
	}
}

int ways(int a, int b) {
	//������������� ������:
	for (int i = 0; i < n; i++) {
		road[i] = way[i] = 0; incl[i] = false;
	}
	len = c_len = waylen = 0;

	start = a; //������ ���� - ��������� � 0
	finish = b; //����� ���� - ��������� � 0
	road[0] = start; //������ ����� ������ � �������
	incl[start] = true; //� �������� ��� ����������
	found = false; //�� ���� ���� �� ������
	step(start, finish, 1); //���� ������ �����

	if (found) {
		cout << "Way is";
		for (int i = 0; i < waylen; i++) cout << " " << way[i];
		cout << ", weight is " << len;
	}
	else cout << "Way not found!";
	cout << endl;

	return len;
}

int main() {
	//ways(1, 7);
	system("pause");
	return 0;
}