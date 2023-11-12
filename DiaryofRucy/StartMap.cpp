#include "Stdafx.h"
#include "StartMap.h"

HRESULT StartMap::vInit(void)
{
    _mapName = "���۸�";

    _image = IMAGEMANAGER->addImage("����&�ⱸ��", "Resources/Images/Maps/MapImage/����&�ⱸ.bmp", WINSIZE_X, WINSIZE_Y);
    _colImg = IMAGEMANAGER->addImage("��-����&�ⱸ", "Resources/Images/Maps/Collision/��-����&�ⱸ.bmp", WINSIZE_X, WINSIZE_Y, true, RGB(255, 0, 255));
    _d2dObjectImage = D2DMANAGER->findImage("������Ż");
    _rcObject = RectMakeCenter(WINSIZE_X / 2, WINSIZE_Y / 2, _d2dObjectImage->frameWidth, _d2dObjectImage->frameHeight);
    _frameWorldTime = TIMEMANAGER->getWorldTime() + 1.0f;
    _frameTime = 0.5;
    _isVisit = true;
    _startImage = false;
    _startImageAlpha = 2.0f;

    _imgName = "��-����&�ⱸ";
    _pImgNameR = "��-����&�ⱸ";
    _pImgNameL = "��-����&�ⱸ";
    // �⺻ ������ 3�� �̹��� ��ġ
    _isClear = true;



    return S_OK;
}

void StartMap::objectUpdate()
{
    if (_frameWorldTime < TIMEMANAGER->getWorldTime()) _startImage = true;
    if (_startImage)
    {
        if (_startImageAlpha > 0)
        {
            _startImageAlpha -= 0.02;
            if (IMAGEMANAGER->getAlpha() > 0) IMAGEMANAGER->fadeIn();
        }
    }
}

void StartMap::d2dObjectRender(void)
{
    D2DMANAGER->frameRender("������Ż", _rcObject.left, _rcObject.top, 1, 0);
    D2DMANAGER->alphaRender("�ݵ����̽�", WINSIZE_X / 3+60, WINSIZE_Y / 5, _startImageAlpha);

    switch (*_stage)
    {
    case 1:
        D2DMANAGER->alphaRender("1��", WINSIZE_X / 3+60, WINSIZE_Y / 5, _startImageAlpha);
        break;
    case 2:
        D2DMANAGER->alphaRender("2��", WINSIZE_X / 3+60, WINSIZE_Y / 5, _startImageAlpha);
        break;
    case 3:
        D2DMANAGER->alphaRender("3��", WINSIZE_X / 3+60, WINSIZE_Y / 5, _startImageAlpha);
        break;
    default:
        break;
    }
}


