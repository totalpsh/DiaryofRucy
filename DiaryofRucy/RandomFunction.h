#pragma once
#include "SingletonBase.h"


class RandomFunction : public SingletonBase <RandomFunction>
{
public:
	RandomFunction()
	{
		//GetTickCount() : API�����Լ�
		// �� API �Լ��� OS�� ���õ� ���� ��� �ð��� üũ���ش�.
		// �� �и����� ������ üũ�� �����ϸ� �и����� ������ �ð� ���� ��ȯ�ϱ� ������ �Ը� ũ�� �ʴ� ������ �����ϴ�
		srand(GetTickCount());
	}


	~RandomFunction() {}

	HRESULT init(void) { return S_OK; }

	inline int getInt(int num)
	{
		return rand() % num;
	}


	// 0�� ��������
	inline int getFromIntTo(int fromNum, int toNum)
	{
		// if�� ���� ���� : �����ü�� ����ó���� �� �Ӵ��� inlineȭ �ȵ� �� �� ����
		return rand() % (toNum - fromNum + 1) + fromNum;
	}

	// 0 ~ 1
	float getFloat(void)
	{
		return (float)rand() / (float)RAND_MAX;
	}

	// 0 ~ num
	float getFloat(float num)
	{
		return (float)rand() / (float)RAND_MAX * num;
	}
	
	// fromNum ~ toNum
	float getFromFloatTo(float fromNum, float toNum)
	{
		float rnd = (float)rand() / (float)RAND_MAX;

		return (rnd * (toNum - fromNum) + fromNum);
	}




};