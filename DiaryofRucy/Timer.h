#pragma once

/*
 - �ð����� API ���� �Լ�
  �� ������ �ִ�....
  �� ���� ����ܰ迡�� ������ ����ϰ� ���� Ÿ�̸ӵ��� �ƴϱ� ������ ���е��� ��������.

timeGetTime (�����찡 ���۵ǰ� 1���� �������� 60000����)
GetTickCount (���ýð� üũ -> ���õ� ���� 1�ʿ� 1000�� ƽ�� �����Ѵ� �� 50�� ���� ����)
				��ȯ �ð��� �ִ� DWORD(32��Ʈ)�̴�. 49.7�ϵ��� �����츦 �������� ������ 0���� �ʱ�ȭ�ȴ�.
GetTickCount64

 - Ÿ�̸�
  �� �ð��� �����ϴ� �Լ����� �⺻������ �����찡 ���۵� ���� ���� �ð��� Milli Second ������ ��ȯ(1/1000��)
  �� �и������� �⺻������ ���е��� �������� -> ���ӿ���
  �� �׷��� ������ ���� ���� ���е��� ���Ѵٸ� ���ػ� Ÿ�̸Ӹ� �߰��ؼ� ����ؾ� �Ѵ�.

 - Ÿ�̸Ӹ� ������ ���� ���� �ػ󵵿� Ŭ���� �˰� �־�� �Ѵ�.

 �� �ػ�?

  - �پ��� �ð� �Լ����� �ð��� �����ϱ� ���� ������ ƽ ��� ������ �ִ�.
	�� �� ������ 1���� �������� ����� �� �󸶳� ���� ���������� ���� �� �ִ��� ���
  - 1�е��� �󸶳� ���� ƽ���� ������ �ð��� ��Ȯ���� ���̴��İ� ���ػ󵵿� ���ػ��� ���̸� �߻���Ų��.

  �� Ŭ�� (������)
  - Ÿ�̸ӿ��� ���ϴ� Ŭ���� CPUŬ��
  - Ŭ�� ��ü�� ������ ȸ���� ������ ���� �� �̸� �츣��(Hz) ������ ǥ���ϴ°� �Ϲ���
	�� EX: 1�ʿ� 1Hz�� �������� ��ȣ�� �ѹ� �شٴ� ��� (0�Ǵ�1)
		�� 1 ��Ʈ�� �ű� �� �ִٴ� ��
		�� 1GHz�� 10�� 9���� -> 10���
		�� 3.7GHz�� �� 37��� (1�ʿ� 36�� ��Ʈ�� �ű� �� �ִ�.)

  ����
  �� Milli Second
  �� 10 Milli Second (��Ƽ)
  �� 100 Milli Second (����)
*/

class Timer
{
private:
	float _timeScale;				// ����ð�
	float _timeElapsed;				// ����~������ �����
	bool _isHardware;				// �ϵ���� ���� ����

	__int64 _curTime;
	__int64 _lastTime;
	__int64 _periodFrequency;

	unsigned long _frameRate;
	unsigned long _FPSFrameCount;
	float _FPSTimeElapsed;
	float _worldTime;

public:

	HRESULT init(void);
	// -> ������ ������ �� �̰� Ǯ�� �غ���
	void tick(float lockFPS = 0.0f);

	unsigned long getFrameRate(char* str = nullptr) const;
	inline float getElapsedTime(void) const { return _timeElapsed; }
	inline float getWorldTime(void) const { return _worldTime; }
	// const ��������� ���� �����Ű�� �ʰڴ� (������ ���� ������� �ʰڴ�)


	Timer() {}
	~Timer() {}
};

