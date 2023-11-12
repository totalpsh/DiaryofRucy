#include "Stdafx.h"
#include "NormalMap.h"



HRESULT NormalMap::vInit()
{
    _mapName = "��ָ�";
    randMap = RND->getFromIntTo(1, 11);

    switch (randMap)
    {
    case 1:
        _image = IMAGEMANAGER->addImage("��ֹ�1", "Resources/Images/Maps/MapImage/��ֹ�1.bmp", WINSIZE_X, WINSIZE_Y);
        _colImg = IMAGEMANAGER->addImage("��-��ֹ�1", "Resources/Images/Maps/Collision/��-��ֹ�1.bmp", WINSIZE_X, WINSIZE_Y, true, RGB(255, 0, 255));

        _imgName = "��-��ֹ�1";
        

        break;

    case 2:
        _image = IMAGEMANAGER->addImage("��ֹ�2", "Resources/Images/Maps/MapImage/��ֹ�2.bmp", WINSIZE_X, WINSIZE_Y);
        _colImg = IMAGEMANAGER->addImage("��-��ֹ�2", "Resources/Images/Maps/Collision/��-��ֹ�2.bmp", WINSIZE_X, WINSIZE_Y, true, RGB(255, 0, 255));

        _imgName = "��-��ֹ�2";
        break;

    case 3:
        _image = IMAGEMANAGER->addImage("��ֹ�3", "Resources/Images/Maps/MapImage/��ֹ�3.bmp", WINSIZE_X, WINSIZE_Y);
        _colImg = IMAGEMANAGER->addImage("��-��ֹ�3", "Resources/Images/Maps/Collision/��-��ֹ�3.bmp", WINSIZE_X, WINSIZE_Y, true, RGB(255, 0, 255));

        _imgName = "��-��ֹ�3";
        break;

    case 4:
        _image = IMAGEMANAGER->addImage("��ֹ�4", "Resources/Images/Maps/MapImage/��ֹ�4.bmp", WINSIZE_X, WINSIZE_Y);
        _colImg = IMAGEMANAGER->addImage("��-��ֹ�4", "Resources/Images/Maps/Collision/��-��ֹ�4.bmp", WINSIZE_X, WINSIZE_Y, true, RGB(255, 0, 255));

        _imgName = "��-��ֹ�4";

        break;

    case 5:
        _image = IMAGEMANAGER->addImage("��ֹ�5", "Resources/Images/Maps/MapImage/��ֹ�5.bmp", WINSIZE_X, WINSIZE_Y);
        _colImg = IMAGEMANAGER->addImage("��-��ֹ�5", "Resources/Images/Maps/Collision/��-��ֹ�5.bmp", WINSIZE_X, WINSIZE_Y, true, RGB(255, 0, 255));
        
        _imgName = "��-��ֹ�5";
        break;

    case 6:
        _image = IMAGEMANAGER->addImage("��ֹ�6", "Resources/Images/Maps/MapImage/��ֹ�6.bmp", WINSIZE_X, WINSIZE_Y);
        _colImg = IMAGEMANAGER->addImage("��-��ֹ�6", "Resources/Images/Maps/Collision/��-��ֹ�6.bmp", WINSIZE_X, WINSIZE_Y, true, RGB(255, 0, 255));

        _imgName = "��-��ֹ�6";
        break;

    case 7:
        _image = IMAGEMANAGER->addImage("��ֹ�7", "Resources/Images/Maps/MapImage/��ֹ�7.bmp", WINSIZE_X, WINSIZE_Y);
        _colImg = IMAGEMANAGER->addImage("��-��ֹ�7", "Resources/Images/Maps/Collision/��-��ֹ�7.bmp", WINSIZE_X, WINSIZE_Y, true, RGB(255, 0, 255));

        _imgName = "��-��ֹ�7";
        break;

    case 8:
        _image = IMAGEMANAGER->addImage("��ֹ�8", "Resources/Images/Maps/MapImage/��ֹ�8.bmp", WINSIZE_X, WINSIZE_Y);
        _colImg = IMAGEMANAGER->addImage("��-��ֹ�8", "Resources/Images/Maps/Collision/��-��ֹ�8.bmp", WINSIZE_X, WINSIZE_Y, true, RGB(255, 0, 255));

        _imgName = "��-��ֹ�8";
        break;

    case 9:
        _image = IMAGEMANAGER->addImage("��ֹ�9", "Resources/Images/Maps/MapImage/��ֹ�9.bmp", WINSIZE_X, WINSIZE_Y);
        _colImg = IMAGEMANAGER->addImage("��-��ֹ�9", "Resources/Images/Maps/Collision/��-��ֹ�9.bmp", WINSIZE_X, WINSIZE_Y, true, RGB(255, 0, 255));

        _imgName = "��-��ֹ�9";
        break;

    case 10:
        _image = IMAGEMANAGER->addImage("��ֹ�10", "Resources/Images/Maps/MapImage/��ֹ�10.bmp", WINSIZE_X, WINSIZE_Y);
        _colImg = IMAGEMANAGER->addImage("��-��ֹ�10", "Resources/Images/Maps/Collision/��-��ֹ�10.bmp", WINSIZE_X, WINSIZE_Y, true, RGB(255, 0, 255));

        _imgName = "��-��ֹ�10";
        break;

    case 11:
        _image = IMAGEMANAGER->addImage("��ֹ�11", "Resources/Images/Maps/MapImage/��ֹ�11.bmp", WINSIZE_X, WINSIZE_Y);
        _colImg = IMAGEMANAGER->addImage("��-��ֹ�11", "Resources/Images/Maps/Collision/��-��ֹ�11.bmp", WINSIZE_X, WINSIZE_Y, true, RGB(255, 0, 255));

        _imgName = "��-��ֹ�11";
        break;
    }
    _em = new EnemyManager;
    _em->init();
    _em->setPlayerMemoryAddress(_player);


    _pImgNameL = _imgName;
    _pImgNameR = _imgName;
    //_em->setMushMam(600,400);
    
    int rndSpownNum = RND->getFromIntTo(3,6);
    for (int i = 0; i < rndSpownNum; i++)
    {
        switch (RND->getInt(4))
        {
        case 0:
            _em->setSnake(RND->getFromIntTo(WINSIZE_X/2-200,WINSIZE_X/2+200), RND->getFromIntTo(WINSIZE_Y / 2 -150, WINSIZE_Y / 2 + 150));
            break;
        case 1:
            _em->setMushMam(RND->getFromIntTo(WINSIZE_X / 2 - 200, WINSIZE_X / 2 + 200), RND->getFromIntTo(WINSIZE_Y / 2 - 150, WINSIZE_Y / 2 + 150));
            break;
        case 2:
            _em->setSlime(RND->getFromIntTo(WINSIZE_X / 2 - 200, WINSIZE_X / 2 + 200), RND->getFromIntTo(WINSIZE_Y / 2 - 150, WINSIZE_Y / 2 + 150));
            break;
        case 3:
            _em->setFlime(RND->getFromIntTo(WINSIZE_X / 2 - 200, WINSIZE_X / 2 + 200), RND->getFromIntTo(WINSIZE_Y / 2 - 150, WINSIZE_Y / 2 + 150));
            break;
        default:
            break;
        }
    }



    _isClear = false;
    return S_OK;

}

void NormalMap::release(void)
{
    SAFE_DELETE(_em);
}

void NormalMap::enemyUpdate(void)
{
    if (_em != nullptr)
    {
        if (IMAGEMANAGER->getAlpha() == 0) _em->update();
        if ((_em->getSnake().size() == 0) && (_em->getSlime().size() == 0) && (_em->getFlime().size() == 0) && (_em->getMushMam().size() == 0) && (_em->getTurret().size() == 0))
        {
            _isClear = true;
        }
    }
    if (_isClear)
    {
        for (int i = 0; i < _em->getSnake().size(); i++)  _em->removeSnake(i);
        for (int i = 0; i < _em->getSlime().size(); i++)  _em->removeSlime(i);
        for (int i = 0; i < _em->getFlime().size(); i++)  _em->removeFlime(i);
        for (int i = 0; i < _em->getMushMam().size(); i++)  _em->removeMushMam(i);
        for (int i = 0; i < _em->getTurret().size(); i++)  _em->removeTurret(i);
    }
}

void NormalMap::enemyRender(void)
{
    _em->render();
}

void NormalMap::d2dEnemyRender(void)
{
   _em->d2drender();
}

void NormalMap::d2dObjectRender(void)
{
    if (!_isClear)
    {
        // ī�޶� ���� �� ������ ������
        //D2DMANAGER->render("��-��", WINSIZE_X / 2 - D2DMANAGER->findImage("��-��")->width / 2, -D2DMANAGER->findImage("��-��")->height + 180);
    }

}
