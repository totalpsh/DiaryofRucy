#include "Stdafx.h"
#include "WindScar.h"

// ���ʹ� �浹ó��
// ���ʹ̺Ҹ� ���� ó��

HRESULT WindScar::init(void)
{
	_iconImage = D2DMANAGER->findImage("�ٶ��ǻ�ó������");
	_frameImage = D2DMANAGER->findImage("�ٶ��ǻ�ó");
	_coolTime = 8;
	_manaCost = 2;
	_damageMultiple = 2.7;
	_speed = 15;
	_range = 500;
	return S_OK;
}

void WindScar::shot(float x, float y, float fireX, float fireY)
{
	if (_isCoolTimeOn) return;
	_worldTimeCount = TIMEMANAGER->getWorldTime();
	_angle = getAngle(fireX, fireY, x, y);
	_fireX = fireX;
	_fireY = fireY;
	_x = fireX;
	_y = fireY;
	_rc = RectMakeCenter(_x, _y, D2DMANAGER->findImage("�ٶ��ǻ�ó")->frameWidth, D2DMANAGER->findImage("�ٶ��ǻ�ó")->frameHeight);
	_frameCount = 0;
	_frameX = 0;
	_frameY = 0;
	_isSkillCollision = true;
	_isSkillShoot = true;
	_isCoolTimeOn = true;

}

void WindScar::animation(void)
{
	if (_isSkillShoot)
	{
		_frameCount++;

		if (_frameCount == 1)
		{
			// SD : �ٶ��ǻ�ó ���� �߰� 
			SOUNDMANAGER->play("��ų�ٶ��ǻ�ó", 0.1f);
		}

		if (_frameCount % 3 == 0)
		{
			_frameX++;
			if (_frameX > _frameImage->maxFrameX)
			{
				_frameX = 0;
				_frameY++;
				if (_frameY > _frameImage->maxFrameY)
				{
					_frameX = _frameImage->maxFrameX;
					_frameY = _frameImage->maxFrameY;
				}
			}
		}

	}
}

void WindScar::draw(void)
{
	if (_isSkillShoot)
	{
		D2DMANAGER->frameRotateRender("�ٶ��ǻ�ó", _rc.left, _rc.top, _frameX, _frameY, -_angle * 180 / PI -45);
	}
}

void WindScar::move(void)
{
	_x += cosf(_angle) * _speed;
	_y += -sinf(_angle) * _speed;
	_rc = RectMakeCenter(_x, _y, D2DMANAGER->findImage("�ٶ��ǻ�ó")->frameWidth, D2DMANAGER->findImage("�ٶ��ǻ�ó")->frameHeight);

	if (_range < getDistance(_fireX, _fireY, _x, _y)) _isSkillShoot = false;

}
