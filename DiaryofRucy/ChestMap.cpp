#include "Stdafx.h"
#include "ChestMap.h"
#include "Player.h"
#include "Ability.h"

HRESULT ChestMap::vInit(void)
{
	_mapName = "���ڸ�";
	_image = IMAGEMANAGER->addImage("���ڹ�", "Resources/Images/Maps/MapImage/���ڹ�.bmp", WINSIZE_X, WINSIZE_Y);
	_colImg = IMAGEMANAGER->addImage("��-���ڹ�", "Resources/Images/Maps/Collision/��-���ڹ�.bmp", WINSIZE_X, WINSIZE_Y, true, MAGENTA);

	_imgName = "��-���ڹ�";
	_pImgNameR = "��-���ڹ�";
	_pImgNameL = "��-���ڹ�";
	_itemChest = new ItemChest;

	_itemChest->init(RND->getFromIntTo(1, 4));

	_isClear = true;

	return S_OK;
}

void ChestMap::objectUpdate(void)
{
	if (getDistance(_player->getPosition().x, _player->getPosition().y, _itemChest->getPosition().x, _itemChest->getPosition().y) < _itemChest->getDistanceWithPlayer())
	{
		if (!_itemChest->getAction())
		{
			if (KEYMANAGER->isOnceKeyDown('F'))
			{
				_itemChest->openChest();
				switch (*_stage)
				{
				case 1:
					_player->setAbility(Ability(D2DMANAGER->findImage("����"), "����", "�ִ�ü��, ���� +1", 1, 1, 0, 0, 0, 0));
					break;
				case 2:
					_player->setAbility(Ability(D2DMANAGER->findImage("������"), "������", "�������ݷ� +10, ź��ũ�� ����", 0, 0, 0, 10, 0, 30));
					break;
				case 3:
					_player->setAbility(Ability(D2DMANAGER->findImage("�ż�������"), "�ż�������", "���ݷ� +4 ���ݼӵ� +50%", 0, 0, 4, 0, 25, 0));
					break;
				default:
					break;
				}

				//SD: ���� ������ ȿ���� �߰�(����� ���ڴ� �Ƿ� �ϴ� �Ҹ��� �ϳ� �� �ִ�.)
				SOUNDMANAGER->play("���ڿ���", 0.1f);

			}
		}
	}

	if (_itemChest->getAction() == true)
	{
		_itemChest->update();
	}

}

void ChestMap::objectRender(void)
{
	_itemChest->render();
}
