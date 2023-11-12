#pragma once
#include "Stdafx.h"
#include "SingletonBase.h"
// ��ü���� ��ȯ -> ���� ��� / �����  (���� �׷�����..)
// 123~126���� Ű ������ ǥ�� �����ϴ� fnŰ �������� 256������ ����ִ°� ����
// Ű ��� ���� os�� �����ϸ� ���������� ������ ��ģ�� = �̱��������� ����ϸ� ����


#define KEY_MAX 256


class KeyManager : public SingletonBase <KeyManager>
{
private:
	//BOOL _keyUp[KEY_MAX];
	//BOOL _keyDown[KEY_MAX];

	bitset<KEY_MAX> _keyUp;
	bitset<KEY_MAX> _keyDown;


public:
	// �ʱ�ȭ
	HRESULT init(void);

	// Ű�� �ѹ��� ���ȴ���
	bool isOnceKeyDown(int key);	// ���߾� Ű���� int�� �ؼ� �޸� ���� �ϴ���? ������ ���� ó���߿��� �ֿ켱������ ó���ϱ� ����
	// �ѹ� ������ �������
	bool isOnceKeyUp(int key);
	// Ű�� ��� ���� �ִ���
	bool isStayKeyDown(int key);
	// ���Ű
	bool isToggleKey(int key);
	// 4����Ű�� �ϳ��� ������ ���� ���¸� Ȯ��
	bool checkMoveKeyDown(int key1, int key2, int key3, int key4);

	bitset<KEY_MAX> getKeyUp(void) { return _keyUp; }
	bitset<KEY_MAX> getKeyDown(void) { return _keyDown; }

	void setKeyUp(int key, bool state) { _keyUp.set(key, state); }
	void setKeyDown(int key, bool state) { _keyDown.set(key, state); }

	KeyManager() {}
	~KeyManager() {}
};

