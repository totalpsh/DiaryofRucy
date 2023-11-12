#include "Stdafx.h"
#include "Timer.h"

HRESULT Timer::init(void)
{
	// QueryPerformanceFrequency(): �ʴ� ���� ���� üũ�ϰ� ���� Ÿ�̸Ӹ� �����ϸ� t,  �ݴ�� f�� �����Ѵ�.
	// �� LARGE_INTEGER
	// _periodFrequency : �ʴ� �ľ��� �� �ִ� �ð��� ����.(�⺻�� �и�����)
	// ����� ���� �� ���
	if (QueryPerformanceFrequency((LARGE_INTEGER*)&_periodFrequency))
	{
		_isHardware = true;

		// Ư�� �������� ��� �����ߴ°��� ��Ÿ���� �Լ�
		QueryPerformanceCounter((LARGE_INTEGER*)&_lastTime);

		// �ʴ� �ð��� ����� �� �ִ� �ð� �ֱ�
		_timeScale = 1.0f / _periodFrequency;
	}
	else
	{

		_isHardware = false;
		_lastTime = timeGetTime();
		_timeScale = 0.001f;
	}

	_frameRate = 0;
	_FPSFrameCount = 0;
	_FPSTimeElapsed = 0.0f;
	_worldTime = 0.0f;

	return S_OK;
}

void Timer::tick(float lockFPS)
{
	if (_isHardware)
	{
		QueryPerformanceCounter((LARGE_INTEGER*)&_curTime);
	}
	else
	{
		_curTime = timeGetTime();
	}

	// ������ �ð��� ���� �ð��� ����� ���� (�ʴ� ������Ʈ�Ǵ� ������ ����)
	_timeElapsed = (_curTime - _lastTime) * _timeScale;

	if (lockFPS > 0.0f)
	{
		while (_timeElapsed < (1.0f / lockFPS))
		{
			if (_isHardware)
			{
				QueryPerformanceCounter((LARGE_INTEGER*)&_curTime);
			}
			else
			{
				_curTime = timeGetTime();
			}
			_timeElapsed = (_curTime - _lastTime) * _timeScale;
		}
	}

	// ������ �ð� ���
	_lastTime = _curTime;

	// �ʴ� ������ ī��Ʈ ����
	_FPSFrameCount++;

	// �ʴ� ������ �ð������ ����
	_FPSTimeElapsed += _timeElapsed;

	// ��ü �ð� ����� ����
	_worldTime += _timeElapsed;

	// ������ 1�ʸ��� �ʱ�ȭ
	if (_FPSTimeElapsed > 1.0f)
	{
		_frameRate = _FPSFrameCount;
		_FPSFrameCount = 0;
		_FPSTimeElapsed = 0.0f;
	}

}

unsigned long Timer::getFrameRate(char* str) const
{
	if (str != nullptr)
	{
		wsprintf(str, "FPS : %d", _frameRate);
	}

	return _frameRate;
}
