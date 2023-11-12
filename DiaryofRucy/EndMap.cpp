#include "Stdafx.h"
#include "EndMap.h"
#include "StageScene.h"

HRESULT EndMap::vInit(void)
{
	_mapName = "�����";
	_image = IMAGEMANAGER->addImage("����&�ⱸ��", "Resources/Images/Maps/MapImage/����&�ⱸ.bmp", WINSIZE_X, WINSIZE_Y);
	_colImg = IMAGEMANAGER->addImage("��-����&�ⱸ", "Resources/Images/Maps/Collision/��-����&�ⱸ.bmp", WINSIZE_X, WINSIZE_Y, true, RGB(255, 0, 255));

	_potal = new Potal;
	_potal->init();

	_imgName = "��-����&�ⱸ";
	_pImgNameR = "��-����&�ⱸ";
	_pImgNameL = "��-����&�ⱸ";
	_isClear = true;
	_soundPotal = false;
	
	return S_OK;
}

void EndMap::release(void)
{
	_potal->release();
}

void EndMap::objectUpdate(void)
{
	_potal->update();;
	if (getDistance(_player->getPosition().x, _player->getPosition().y, _potal->getPosition().x, _potal->getPosition().y) < 50)
	{
		cout << "�־ȴ�?" << endl;
		if (!_soundPotal)
		{
			SOUNDMANAGER->play("����������", 0.1f);
			_soundPotal = true;
		}
		
		IMAGEMANAGER->fadeOut();
		if (*_stage == 1)
		{
			if (IMAGEMANAGER->getAlpha() == 255)
			{
				*_stage = 2;
				_player->setPosition(WINSIZE_X / 2, WINSIZE_Y / 2);
				return;
			}
		}
		if (*_stage == 2)
		{
			if (IMAGEMANAGER->getAlpha() == 255)
			{
				*_stage = 3;
				_player->setPosition(WINSIZE_X / 2, WINSIZE_Y / 2);
				return;
			}
		}
		if (*_stage == 3)
		{
			if (IMAGEMANAGER->getAlpha() == 255)
			{
				SCENEMANAGER->chanegeScene("������");
				return;
			}

		}
	}

}

void EndMap::d2dObjectRender(void)
{
	_potal->d2drender();
}
