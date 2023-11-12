#include "Stdafx.h"
#include "Enemy.h"


Enemy::Enemy(void) : _rc(RectMake(0, 0, 0, 0)),
_currentFrameX(0),
_currentFrameY(0),
_x(0.f),
_y(0.f),
_fireCount(0.f),
_bulletFireCount(0.f),
_angle(0.f),
_startAngle(0.f),
_hp(0.f),
_die(false),
_isCanHit(true)
{
}



HRESULT Enemy::init()
{
	//!Do nothing
	return S_OK;
}

HRESULT Enemy::init(const char* imageName, POINT position)
{
	_image = IMAGEMANAGER->findImage(imageName);

	_x = position.x;
	_y = position.y;
	_rc = RectMakeCenter(_x, _y,
		_image->getFrameWidth(), _image->getFrameHeight());
	_die = false;
	_center = position;

	_bulletFireCount = TIMEMANAGER->getWorldTime();
	_fireCount = 0.6f; //�� ���缭 �Ѿ� �߻� �ֱ����Ұ�.

	
	_smallBullet = new EnemyBullet;
	_smallBullet->init("�����Ϲ�ź", 50, 400,0);
	_bigBullet = new EnemyBullet;
	_bigBullet->init("ū�Ϲ�ź", 50, 400,0);
	//_espBullet = new EnemyBullet;
	//_espBullet->init("����ź", 50, 400);

	_poisonBullet = new PoisonBullet;
	_poisonBullet->init("��ź", 50, 300);

	_thorn = new Thorn;
	_thorn->init("����", 300,600);


	
	_effectPlaying = false;
	_effectCurrentFrameX = 0;
	_effectCurrentFrameY = 0;
	_safeDistance = true;

	_dieSound = false;
	_idleFrameCount = 0;
	_moveFrameCount = 0;
	//_idleTime = 0.f;
	//_moveTime = 0.f; 
	//_attackTime = 0.f; 
	//_attackInitialized = false;
	return S_OK;
}



void Enemy::release(void)
{
	_smallBullet->release();
	_bigBullet->release();
	_poisonBullet->release();
	_thorn->release();
	SAFE_DELETE(_image);
}

void Enemy::update(void)
{	
	if (!_die)
	{
	
		_rc = RectMakeCenter(_x, _y,
			_image->getFrameWidth(), _image->getFrameHeight());
		_center.x = _x;
		_center.y = _y;
		_smallBullet->update();
		_bigBullet->update();
		_poisonBullet->update();
		_thorn->update();
	}




}

void Enemy::render(void)
{
}

void Enemy::d2drender(void)
{
	if (_effectPlaying)
	{
		if (_effectPlaying)
		{
			D2DMANAGER->frameRender("���������Ʈ", _x - D2DMANAGER->findImage("���������Ʈ")->frameWidth / 2, _y - D2DMANAGER->findImage("���������Ʈ")->frameHeight / 2,
				_effectCurrentFrameX, _effectCurrentFrameY);

			_effectCurrentFrameX++;
			if (D2DMANAGER->findImage("���������Ʈ")->maxFrameX < _effectCurrentFrameX)
			{
				_effectCurrentFrameX = 0;
				_effectCurrentFrameY++;
				if (D2DMANAGER->findImage("���������Ʈ")->maxFrameY < _effectCurrentFrameY)
				{
					_effectPlaying = false;
					_die = true;
				}
			}
		}
	}

	_smallBullet->d2drender();
 	_bigBullet->d2drender();

	_poisonBullet->d2drender();
	_thorn->d2drender();
}

void Enemy::stateUpdate(void)
{
}

void Enemy::draw(void)
{
	
}

void Enemy::animation(void)
{
}

bool Enemy::bulletCountFire(void)
{
	return false;
}

void Enemy::resetIdleCount()
{
	_idleFrameCount = 0;

}

void Enemy::resetMoveCount()
{
	_moveFrameCount = 0;
}

void Enemy::resetRndIdleFrame()
{
	_rndIdleFrame = RND->getFromIntTo(2, 3);
}

void Enemy::resetRndMoveFrame()
{
	_rndMoveFrame = RND->getFromIntTo(1, 2);
}



void Enemy::playDieEffect()
{
	if (!_effectPlaying)
	{

		//cout << "�״�����Ʈ ���" << endl;
		_effectPlaying = true;
		_effectCurrentFrameX = 0;
		_effectCurrentFrameY = 0;
	}
}
