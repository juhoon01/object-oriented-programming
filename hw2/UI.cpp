#include<iostream>
#include "UI.h"
using namespace std;

int UI::menuUI() {
	int num;
	cout << "����:1, ����:2, ��κ���:3, ����:4 >>";
	cin >> num;
	return num;
}
int UI::insertUI() {
	int num;
	cout << "��:1, ��:2, �簢��:3 >>";
	cin >> num;
	return num;
}
int UI::deleteUI(){
	int num;
	cout << "�����ϰ��� �ϴ� ������ �ε��� >>";
	cin >> num;
	return num;
}