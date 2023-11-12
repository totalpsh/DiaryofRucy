#pragma once
#include "GameNode.h"

// ĳ���Ͱ� ����������
// ���� ������.

class Fountain : public GameNode
{
private:

	GImage* _objImg;
	RECT _rc;

	float _x, _y;

	int _fountainType;

	int _currentFrameX;
	int _currentFrameY;
	float _worldTimeCount;

	bool _off;

	// ������� ��������
	// �÷��̾� ü��/���� ���� ��������
public:
	HRESULT init(int fountainType);
	void release(void);
	void update(void);
	void render(void);

	void fountainOff();

	bool getOff() { return _off; }

	// �÷��̾ �м��� �������� ��
	// ü��/������ ��´�.
	// ��带 �������� ��´�.


	Fountain() {}
	~Fountain() {}
};

