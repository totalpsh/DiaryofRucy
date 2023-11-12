#include "Stdafx.h"
#include "ShopMap.h"

HRESULT ShopMap::vInit(void)
{
	_mapName = "������";
	_image = IMAGEMANAGER->addImage("������", "Resources/Images/Maps/MapImage/������.bmp", WINSIZE_X, WINSIZE_Y);
	_colImg = IMAGEMANAGER->addImage("��-������", "Resources/Images/Maps/Collision/��-������.bmp", WINSIZE_X, WINSIZE_Y, true, RGB(255, 0, 255));

	_imgName = "��-������";
	_pImgNameR = "��-������";
	_pImgNameL = "��-������";
	_isClear = true;

	return S_OK;
}
