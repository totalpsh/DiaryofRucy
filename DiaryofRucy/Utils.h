#pragma once

//����ȭ ��Ű�� ���� ���� -> ������ ����� �����ϸ� ����.

// ��׸� 1���� ����
#define DEG_TO_RAD	0.017453f
// ����
#define PI			3.141592653f
#define PI_2		6.283185308f
#define DEGREE_RADIAN(_deg)			(PI*(_deg) / 180.0f)

/*
�� �ݿø� ���� (Rounding Error)

 - �ε��Ҽ��� �⺻������ �Ǽ��� ��Ȯ�ϰ� ǥ���ϴ°� �Ұ���
  �� ������ ���������� �Ǽ��� ������ �ݸ� �� �Ǽ��� ������ ��Ʈ�� ǥ���� �ؾ��ϱ� ����
  �� �׷��� ������ ��ǻ�ʹ� ��¿ �� ���� �ٻ簪���� ó���� �Ѵ�.

 - �̰� �ε��Ҽ��� �ݿø� ����
  �� ��ǻ�ʹ� �Ǽ��� �������� ���·� ����
  �� �̷��� Ư¡ ������ ���������� �߻��ϰ� ��Ȯ�� ����� ���ؼ��� ������� �ݵ�� �ʿ��ϴ�.

 - 2D��ǥ�迡���� ü���� ��������� ���� �� ������ 3D������ ü���� Ȯ �Ǵ� �κ�

*/
#define FLOAT_EPSILON			0.001f
//�Ǽ�->����
#define FLOAT_TO_INT(f1)		static_cast<int>(f1 + FLOAT_EPSILON)
// �� �Ǽ��� ������ ��
// �� ���⼭ ���� ���밪�� �Ҽ��� ���� ���밪 ��ȯ
#define FLOAT_EQUAL(f1, f2)		(fabs(f1 - f2) <= FLOAT_EPSILON)

/*
- C++ ĳ���� �����ڴ� 4����

  1. reinterpret_cast
   �� ������ ����ϸ� �����Ͱ� �޸𸮻� �迭�Ǵ� ������ �������� ���� �� �ִ�.
   �� �̴� ���α׷��Ӱ� �ǵ��� ��Ȳ�� �����ϴ� ��찡 �ƴϱ� ������ ��κ� -> ����
*/



namespace MY_UTIL
{
	// �� �� ������ �Ÿ�
	float getDistance(float startX, float startY, float endX, float endY);

	// ��ŸƮ -> �ε� -> ���� ��������
	float getAngle(float startX, float startY, float endX, float endY);

	// ���� ���κ��� ���� �Ÿ� �ȿ� ���� �ִ��� Ȯ���ϴ� �Լ�
	bool getAbsRange(float reference, float range, float comparison);
}


namespace OBB_COLLISION
{
	struct VECTOR
	{
		double x, y; // ���� ����ü (x,y ��ǥ)
	};

	struct SHAPE
	{
		double top, left, height, width, rot; // �簢�� ����ü (��ġ, ����, �ʺ�, ȸ����)
	};

	// �� ������ ���� ��� �Լ�
	double absDotVector(VECTOR a, VECTOR b);

	// �� �簢���� �߽ɰ� �Ÿ� ���� ��� �Լ�
	VECTOR getDistanceVector(SHAPE a, SHAPE b);

	// �簢���� ���� ���� ��� �Լ�
	VECTOR getHeightVector(SHAPE s);

	// �簢���� �ʺ� ���� ��� �Լ�
	VECTOR getWidthVector(SHAPE s);

	// �������� ��� �Լ�: �� ��Ҹ� ũ��� �������ν� ����
	VECTOR getUnitVector(VECTOR a);

	// RECT ����ü�� SHAPE ����ü�� ��ȯ�ϴ� �Լ�
	SHAPE rectToShape(RECT rc1, float radian1);

	// OBB �浹 �˻� �Լ�: �� �簢���� ������ �Է¹޾� �浹 ���� ��ȯ
	bool isOBBCollision(RECT rc1, float radian1, RECT rc2, float radian2);

	// OBB �浹 ȸ����Ʈ�� �׸��� �Լ�
	void OBBDrawRotatedRect(HDC hdc, RECT rc, float radian);
}