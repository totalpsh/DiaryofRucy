#pragma once
#include "GImage.h"

static GImage* _backBuffer = IMAGEMANAGER->addImage("backBuffer", WINSIZE_X, WINSIZE_Y);

class GameNode
{
private:
    HDC _hdc;
    bool _managerInit;
   

public:
    virtual HRESULT init(void);
    virtual HRESULT init(bool managerInit);
    virtual void release(void);
    virtual void update(void);
    virtual void render(void);
    virtual void d2drender(void);
    virtual void UIrender(void);

    // �������� �Լ� �� ���յ��� �������⿡ ������� �ʴ´�.
    // �����Լ��� ���������Լ��� ȥ���� �� ����
    //virtual void IFunction() PURE;  

    GImage* getBackBuffer(void) { return _backBuffer; }
   
    HBITMAP getMemBitmap() { return _backBuffer->getBit(); }
    HDC getMemDC() { return _backBuffer->getMemDC(); }
    HDC getHDC() { return _hdc; }

    LRESULT  MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);


    GameNode() {}
    virtual ~GameNode() {}
};

