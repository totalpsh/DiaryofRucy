
#pragma once

#pragma warning(disable: 4005)

#include <sdkddkver.h>

#define WIN32_LEAN_AND_MEAN 

#pragma comment (linker, "/entry:WinMainCRTStartup /subsystem:console")

#pragma comment (lib, "lib/FMOD/fmodex_vc.lib")

#pragma comment (lib, "Jsoncpp/lib_json/json_vc71_libmtd.lib")

#pragma comment (lib, "msimg32.lib")

#include "inc/FMOD/fmod.hpp"
#include "Jsoncpp/Include/json.h"
#include <Windows.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <stdio.h>
#include <time.h>




#include <iostream>
#include <chrono>
#include <random>
#include <vector>
#include <map>
#include <unordered_map>
#include <cassert>
#include <functional>
#include <fstream>
#include <queue>
#include <deque>
#include <bitset>

using namespace std;

#include <d2d1.h>
#include <wincodec.h>
#pragma comment(lib, "d2d1.lib")
#pragma comment(lib, "windowscodecs.lib")

#include "resource.h"
#include "CommonMacroFunction.h" 
#include "RandomFunction.h"  
#include "KeyManager.h"
#include "ImageManager.h"
#include "FontManager.h"
#include "TempSoundManager.h"
#include "Utils.h"
#include "D2DImageManager.h"
#include "TimeManager.h"
#include "SceneManager.h"
#include "SoundManager.h"
#include "INIData.h"
#include "JsonSaveLoader.h"

using namespace MY_UTIL;
using namespace OBB_COLLISION;


#define RND				 RandomFunction::getSingleton()
#define KEYMANAGER		 KeyManager::getSingleton()
#define IMAGEMANAGER	 ImageManager::getSingleton()
#define TEMPSOUNDMANAGER TempSoundManager::getSingleton()
#define FONTMANAGER		 FontManager::getSingleton()
#define D2DMANAGER       D2DImageManager::getSingleton()
#define TIMEMANAGER      TimeManager::getSingleton()
#define SCENEMANAGER	 SceneManager::getSingleton()
#define SOUNDMANAGER	 SoundManager::getSingleton()
#define INIDATAMANAGER	 INIData::getSingleton()
#define JSONDATAMANAGER  JsonSaveLoader::getSingleton()

#define WINNAME			(LPTSTR)(TEXT("WindowsAPI"))
#define MAGENTA			RGB(255,0,255)


//#define FULLSCREEN
#ifdef FULLSCREEN //FULLSCREEN

#define WINSTART_X		0
#define WINSTART_Y		0
//GetSystemMetrics() : ���ڷ� ���޵Ǵ� �ý��� ���� ������ ��ȯ
// �� SM_CXSCREEN / SM_CYSCREEN  = ���� ȭ�� �ػ� X / Y �� ��ȯ
#define WINSIZE_X		GetSystemMetrics(SM_CXSCREEN)
#define WINSIZE_Y		GetSystemMetrics(SM_CYSCREEN)
#define WINSTYLE		WS_POPUPWINDOW | WS_MAXIMIZE


#else
// # ��ũ�� # (������â �ʱ�ȭ)
#define WINSTART_X		200
#define WINSTART_Y		100
#define WINSIZE_X		1280
#define WINSIZE_Y		720
#define WINSTYLE		WS_CAPTION | WS_SYSMENU

#endif // FULLSCREEN




// WS_CAPTION : Ÿ��Ʋ �ٸ� ������ ���� �ɼ�
// WS_SYSMENU : ���� ǥ���ٿ� ��Ʈ�� �޴� ���� â

// # ��ũ�� �Լ� #  ( Ŭ�������� �����Ҵ�� �κ��� ������ �� ���)
#define SAFE_DELETE(p)			{if(p) {delete (p); (p) = nullptr;}}
#define SAFE_DELETE_ARRAY(p)	{if(p) {delete[] (p); (p) = nullptr;}}
#define SAFE_RELEASE(p)			{if(p) {(p)->release(); (p) = nullptr;}}
#define SAFE_RELEASE_SCENE(p)	{if(p) {(p)->Release(); (p) = nullptr;}}

// # ���� ���� #
// extern Ű����� �ٸ� ��� / cpp���� ������ �����ؼ� ���� ���� ����Ѵ�.
//  �� ��ü�� �ַ� ���
// �⺻������ ���������� Ű���带 �����ص� �⺻������ externȭ �Ǵ� ��찡 ����.
extern HINSTANCE		_hInstance;
extern HWND				_hWnd;
// X ��ǥ�� Y��ǥ�� ����� ��ǥ�� ������ �� ����Ѵ�
extern POINT			_ptMouse; // ��𿡼��� ��밡���ؼ� ������ ���� ����
//extern int				_changeGame;
//extern ID2D1HwndRenderTarget* _ID2DRenderTarget = nullptr; // ���ü�� ��ȣ�ؼ�(null�� ����������) externȭ �ȵ� �� �ִ�

extern bool				_loadGame;
