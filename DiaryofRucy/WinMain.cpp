#include "Stdafx.h"
#include "MainGame.h"


// ��������
HINSTANCE _hInstance;
HWND _hWnd;
POINT _ptMouse = { 0, 0 };
bool _loadGame = false;

LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
void setWindowSize(int x, int y, int width, int height); 

MainGame* _mg;

int APIENTRY WinMain(HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR     lpszCmdParam,
    int       nCmdShow)
{

    _mg = new MainGame;


    _hInstance = hInstance;

  
    WNDCLASS wndClass;

    wndClass.cbClsExtra = 0;                                                    // Ŭ���� ���� �޸� (�����̱� ������ �޸� ������ �ʿ����)
    wndClass.cbWndExtra = 0;                                                    // ������ ���� �޸� ( ���� )
    wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);               // ��׶��� (������� �ϰڴ�)
    wndClass.hCursor = LoadCursor(hInstance, MAKEINTRESOURCE(IDC_CURSOR1));      // ���콺 Ŀ�� ( �⺻ ���콺 Ŀ�� ���ڴ�)
    wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);                           // ������ ( ������ â ���� ������ ������ )
    wndClass.hInstance = hInstance;                                             // �����츦 �ҿ��� ���α׷��� �ĺ��� ����
    wndClass.lpfnWndProc = (WNDPROC)WndProc;                                    // ������ ���ν���
    wndClass.lpszClassName = WINNAME;                                             // Ŭ���� �̸�(�ĺ��� ���� - ������â �̸�)
    wndClass.lpszMenuName = NULL;                                               // �޴� �̸� (������â �޴�)
    wndClass.style = CS_HREDRAW | CS_VREDRAW;                                   // ������ ��Ÿ�� (�ٽ� �׸��� ����)

    // assert()�� �ɸ��� ��
    //HRESULT hr;
    //hr = RegisterClass(&wndClass);
    //assert(SUCCEEDED(hr));


    RegisterClass(&wndClass);
#ifdef FULLSCREEN
    // ����̽� ��� ����ü (ȭ�� ���÷��� ���� ����ü)
    DEVMODE dm;

    ZeroMemory(&dm, sizeof(DEVMODE));
    dm.dmSize = sizeof(DEVMODE);
    dm.dmBitsPerPel = 32;               // 32��Ʈ Ʈ���÷�
    dm.dmPanningWidth = 1980;           // ����
    dm.dmPanningHeight= 1020;           // ����
    dm.dmDisplayFrequency = 60;         // �ֻ��� (��� �� 60Hz)

    // �ʵ� ����
    dm.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT | DM_DISPLAYFREQUENCY;

    if (ChangeDisplaySettings(&dm, CDS_FULLSCREEN) != DISP_CHANGE_SUCCESSFUL)
    {
        ChangeDisplaySettings(&dm, 0);
    }
#endif 

    _hWnd = CreateWindow
    (
        WINNAME,                // ������ Ŭ���� �ĺ���
        WINNAME,                // ������ Ÿ��Ʋ �� �̸�
        WINSTYLE,               // ������ ��Ÿ�� (�����̱� ������ ��� ���� ����)
        WINSTART_X,             // ������ ȭ�� X��ǥ
        WINSTART_Y,             // ������ ȭ�� Y��ǥ
        WINSIZE_X,              // ������ ȭ�� ���� ũ��
        WINSIZE_Y,              // ������ ȭ�� ���� ũ�� 
        NULL,                   // �θ� ������ (GetDesktopWindow �� ���� �⺻ �����)
        (HMENU)NULL,            // �޴� �ڵ�
        hInstance,              // �ν��Ͻ� ����
        NULL                    // �������� �ڽ� �����츦 �����ϸ� �����ϰ� �׷��� �ʴٸ� NULL�� ��ƶ� (������â ������ ���� ����)
                                //  �� �ʿ信 ���� ����ϱ⵵ ������ ������ NULL
    );

    setWindowSize(WINSTART_X, WINSTART_Y, WINSIZE_X, WINSIZE_Y);

    ShowWindow(_hWnd, nCmdShow);

    if (FAILED(_mg->init()))
    {
        return 0;
    }

    MSG message;


    while (true)
    {
        if (PeekMessage(&message, NULL, 0, 0, PM_REMOVE))
        {
            if (message.message == WM_QUIT) break;
            TranslateMessage(&message);
            DispatchMessage(&message);
        }
        else
        {
            TIMEMANAGER->update(60.f);
            _mg->update();
            _mg->render();
        }
    }


    _mg->release();
    UnregisterClass(WINNAME, hInstance);
    return message.wParam;
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
    return _mg->MainProc(hWnd, iMessage, wParam, lParam);  
}


void setWindowSize(int x, int y, int width, int height)
{
    RECT rc = { 0,0,width,height };

    // ���� ������ ũ�� ����
    //AdjustWindowRect() : RECT ����ü, ������ ��Ÿ��, �޴� ����?
    AdjustWindowRect(&rc, WINSTYLE, false);

    // ���� ��Ʈ�� ������ ����������� ����
    SetWindowPos(_hWnd, NULL, x, y,
        (rc.right - rc.left),       // ������ ������� x,y�տ� c�� ������ center �߽��̴�
        (rc.bottom - rc.top),
        SWP_NOZORDER | SWP_NOMOVE);     // ������ �ɼ��̴� NOZORDER ���� �Ȱ����ڴ� | NOMOVE �ڽ����� �� ���°�..

}



