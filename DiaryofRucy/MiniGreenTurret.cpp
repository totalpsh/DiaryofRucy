#include "Stdafx.h"
#include "MiniGreenTurret.h"

HRESULT MiniGreenTurret::init(const char* imageName, POINT position)
{
	Turret::init(imageName,position);
	_fireCount = 5;
	_fireTime = RND->getFromFloatTo(1.5f,3.5f);
	return S_OK;
}

bool MiniGreenTurret::bulletCountFire()
{
	if (_fireTime + _bulletFireCount <= TIMEMANAGER->getWorldTime())
	{
		_fireCount--;
		if (_fireCount == 1)
		{
			//SD: �̴Ϲ��� ������ �� ���� (��..��..��!)
			SOUNDMANAGER->play("�̴Ϲ�������ī��Ʈ", 1.0f);
		}

		if (_fireCount > 0)
		{
			_bulletFireCount = TIMEMANAGER->getWorldTime();
			_fireTime = RND->getFromFloatTo(1.5f, 3.5f);

			return true;
		}
		else
		{
			_lastFire = true;
			
		}
	
	}
	return false;
}
