#include "Stdafx.h"
#include "GameNode.h"

HRESULT GameNode::init(void)
{
	return S_OK;
}

HRESULT GameNode::init(bool managerInit)
{
    _hdc = GetDC(_hWnd);
    _managerInit = managerInit;

    if (managerInit)
    {
   
        setlocale(LC_ALL, "korean");


        RND->init();
        KEYMANAGER->init();
        IMAGEMANAGER->init();
        D2DMANAGER->init(getMemDC());
        TIMEMANAGER->init();
        SCENEMANAGER->init();
        SOUNDMANAGER->init();
        INIDATAMANAGER->init();
        JSONDATAMANAGER->init();

    }

    return S_OK;
}



void GameNode::release(void)
{
	// �����Ҵ�� ���� �������� �ʰ� �����ϸ� �޸� ������...
    if (_managerInit)
    {
      //  KillTimer(_hWnd, 1);

        RND->releaseSingleton();
        KEYMANAGER->releaseSingleton();
        IMAGEMANAGER->release();
        IMAGEMANAGER->releaseSingleton();
        D2DMANAGER->release();
        D2DMANAGER->releaseSingleton();
        TIMEMANAGER->release();
        TIMEMANAGER->releaseSingleton();
        SCENEMANAGER->release();
        SCENEMANAGER->releaseSingleton();
        SOUNDMANAGER->release();
        SOUNDMANAGER->releaseSingleton();
        INIDATAMANAGER->release();
        INIDATAMANAGER->releaseSingleton();
        JSONDATAMANAGER->release();
        JSONDATAMANAGER->releaseSingleton();
    }

    ReleaseDC(_hWnd, _hdc);
}

void GameNode::update(void)
{

}

void GameNode::render(void)
{
	// ! Do Nothing
}

void GameNode::d2drender(void)
{
    // ! Do Nothing
}


void GameNode::UIrender(void)
{
    // ! Do Nothing
}



// ���� ���ν���
LRESULT GameNode::MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
    HDC hdc;             
    PAINTSTRUCT ps;      


    switch (iMessage) 
    {
    case WM_TIMER:
        this->update();
        break;

    case WM_PAINT:    
        hdc = BeginPaint(hWnd, &ps);
        this->render();
        EndPaint(hWnd, &ps);
        break;

    case WM_MOUSEMOVE:
        _ptMouse.x = LOWORD(lParam);
        _ptMouse.y = HIWORD(lParam);

        break;


    case WM_KEYDOWN:

        switch (wParam)
        {
        case VK_ESCAPE:
            PostMessage(hWnd, WM_DESTROY, 0, 0);
            break;
        }
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }

    return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}
