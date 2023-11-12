#include "Stdafx.h"
#include "EventMap.h"
#include "Player.h"

HRESULT EventMap::vInit(void)
{
	_mapName = "�̺�Ʈ��";
	_image = IMAGEMANAGER->addImage("�м�&�����", "Resources/Images/Maps/MapImage/�м�&�����.bmp", WINSIZE_X, WINSIZE_Y);
	_colImg = IMAGEMANAGER->addImage("��-�м�&�����", "Resources/Images/Maps/Collision/��-�м�&�����.bmp", WINSIZE_X, WINSIZE_Y, true, RGB(255, 0, 255));
	
	_imgName = "��-�м�&�����";
	_pImgNameL = "��-�м�&�����";
	_pImgNameR = "��-�м�&�����";

	_rndEvent = RND->getInt(2);
	//_rndEvent = 0;

	if (_rndEvent == 0)
	{
		_fountainType = RND->getInt(2);
		//_fountainType = 1;

		if (_fountainType == 0) // ���
		{
			_fountain = new Fountain;
			_fountain->init(1);
		}
		else // ����
		{
			_fountain = new Fountain;
			_fountain->init(2);
		}
	}
	if (_rndEvent == 1)
	{
		_statueRightType = RND->getFromIntTo(1, 4);
		_statueLeftType = RND->getFromIntTo(1, 4);

		//_statueType = 0;
		// ���� �϶�

		_statue = new Statue;
		_statue->init(_statueLeftType, _statueRightType);
	}
	_isClear = true;

	return S_OK;
}

void EventMap::release(void)
{
	SAFE_DELETE(_fountain);
	SAFE_DELETE(_statue);
}

void EventMap::objectUpdate(void)
{
	if (_rndEvent == 0) // �м��̺�Ʈ �϶�
	{
		if (!_fountain->getOff()) // �м��� �����ִٸ�
		{
			_fountain->update(); //�������� ������

			// �÷��̾ ���� ���� ��
			if (KEYMANAGER->isOnceKeyDown('F'))
			{
				_fountain->fountainOff();
				//SD: ������Ʈ �м�, ���� ���ݽ� ��Ÿ Ÿ���� �߰�
				if (_fountainType == 0)
				{
					SOUNDMANAGER->play("������Ʈ����", 0.5f);
					while (*_player->getCurrentMP() < *_player->getMaxMP())
					{
						_player->setCurrentMP(1);
					}
				}
				else if (_fountainType == 1)
				{
					SOUNDMANAGER->play("������Ʈü��", 0.5f);
					while (*_player->getCurrentHP() < *_player->getMaxHP())
					{
						_player->setCurrentHP(1);
					}
				}
			}
		}
	}
	else if (_rndEvent == 1)// ���� �̺�Ʈ �϶�
	{
		if (!_statue->getOff1() || !_statue->getOff2()) // ������ ���� �ִٸ�
		{
			_statue->update(); // �������� ������.

			if (KEYMANAGER->isOnceKeyDown('F')) // �÷��̾ ���ݽ�
			{
				if (getDistance(_player->getPosition().x, _player->getPosition().y, _statue->getRightPosition().x, _statue->getRightPosition().y) < _statue->getRightDistanceWithPlayer())
				{
					_statue->statueOff(); // ������ ����.

					switch (_statueRightType)
					{
					case 1:
						SOUNDMANAGER->play("������Ʈ����", 0.1f);
						_player->setMaxMP(2);
						break;

					case 2:
						SOUNDMANAGER->play("����ǰ���", 0.1f);
						_player->setMaxMP(-2);
						if (_player->getMaxMP() < _player->getCurrentMP())
						{
							_player->setCurrentMP(-2);
						}
						break;

					case 3:
						SOUNDMANAGER->play("������Ʈü��", 0.1f);
						_player->setMaxHP(2);
						break;

					case 4:
						SOUNDMANAGER->play("����ǰ���", 0.1f);
						_player->setMaxHP(-2);
						if (_player->getMaxHP() < _player->getCurrentHP())
						{
							_player->setCurrentHP(-2);
						}
						break;

					default:
						break;
					}
				}
				else
				{
					_statue->statueOff(); // ������ ����.

					switch (_statueLeftType)
					{
					case 1:
						SOUNDMANAGER->play("������Ʈ����", 0.1f);
						_player->setMaxMP(2);
						break;

					case 2:
						SOUNDMANAGER->play("����ǰ���", 0.1f);
						_player->setMaxMP(-2);
						if (_player->getMaxMP() < _player->getCurrentMP())
						{
							_player->setCurrentMP(-2);
						}
						break;

					case 3:
						SOUNDMANAGER->play("������Ʈü��", 0.1f);
						_player->setMaxHP(2);
						break;

					case 4:
						SOUNDMANAGER->play("����ǰ���", 0.1f);
						_player->setMaxHP(-2);
						if (_player->getMaxHP() < _player->getCurrentHP())
						{
							_player->setCurrentHP(-2);
						}
						break;

					default:
						break;
					}
				}
				/*
				 ������ ������
				 -> ü�� / ����
				 -> õ�� / �Ǹ�
				 ��쿡 ���� �ߵ��� �ൿ�� ���ش�.
				*/
			}
		}
	}
}

void EventMap::objectRender(void)
{
	if (_rndEvent == 0)
	{
		_fountain->render();
	}
	else
	{
		_statue->render();
	}
}
