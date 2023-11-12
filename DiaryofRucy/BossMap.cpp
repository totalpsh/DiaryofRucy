#include "Stdafx.h"
#include "BossMap.h"

HRESULT BossMap::vInit(void)
{
    _mapName = "������";
    cout << "������ ����" << endl;
    _image = IMAGEMANAGER->addImage("������", "Resources/Images/Maps/MapImage/������.bmp", WINSIZE_X, WINSIZE_Y);
    _colImg = IMAGEMANAGER->addImage("��-������", "Resources/Images/Maps/Collision/��-������.bmp", WINSIZE_X, WINSIZE_Y, true, RGB(255, 0, 255));

    _imgName = "��-������";
    _pImgNameR = "��-������";
    _pImgNameL = "��-������";

    switch (*_stage)
    {
    case 1:

        _kingSlime = new KingSlime;
        _kingSlime->init({ WINSIZE_X / 2, WINSIZE_Y / 2 });
        _kingSlime->setPlayerMemoryAddress(_player);
        break;
    case 2:

        _megaFlime = new MegaFlime;
        _megaFlime->init({ WINSIZE_X / 2, WINSIZE_Y / 2 });
        _megaFlime->setPlayerMemoryAddress(_player);
        break;
    case 3:

        _mushMamBoss = new MushMamBoss;
        _mushMamBoss->init({ WINSIZE_X / 2, WINSIZE_Y / 2 });
        _mushMamBoss->setPlayerMemoryAddress(_player);
        break;
    default:
        break;
    }

    _isClear = false;
    
    _startImageAlpha = 2.0f;
   
    return S_OK;
}

void BossMap::release(void)
{
    SAFE_DELETE(_kingSlime);
    SAFE_DELETE(_megaFlime);
    SAFE_DELETE(_mushMamBoss);
}

void BossMap::bossUpdate(void)
{
    switch (*_stage)
    {
    case 1:
        _kingSlime->update();
        if (_kingSlime->getDie()) _isClear = true;
        break;
    case 2:
        _megaFlime->update();
        if (_megaFlime->getDie()) _isClear = true;
        break;
    case 3:
        _mushMamBoss->update();
        if (_mushMamBoss->getDie()) _isClear = true;
        break;
    default:
        break;
    }
    if (_isVisit)
    {
        if (_startImageAlpha > 0) _startImageAlpha -= 0.01;
    }
}

void BossMap::bossRender(void)
{
    switch (*_stage)
    {
    case 1:
        _kingSlime->render();
        break;
    case 2:
        _megaFlime->render();
        break;
    case 3:
        _mushMamBoss->render();
        break;
    default:
        break;
    }
}

void BossMap::d2dBossRender(void)
{
    switch (*_stage)
    {
    case 1:
        _kingSlime->d2drender();
        D2DMANAGER->alphaRender("ŷ����������UI",160,0, _startImageAlpha);
        break;
    case 2:
        _megaFlime->d2drender();
        D2DMANAGER->alphaRender("�ް��ö�������UI", 160, 0, _startImageAlpha);
        break;
    case 3:
        _mushMamBoss->d2drender();
        D2DMANAGER->alphaRender("�ӽ�����������UI", 160, 0, _startImageAlpha);
        break;
    default:
        break;
    }
}
