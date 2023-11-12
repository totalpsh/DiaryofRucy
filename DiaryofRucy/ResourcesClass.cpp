#include "Stdafx.h"
#include "ResourcesClass.h"

#define RESIZE      1.3


HRESULT ResourcesClass::init()
{
	//============ȣ��============
#pragma region ȣ��
    // Player
    D2DMANAGER->loadImageD2D("�������Ҹ�", L"Resources/Images/Player/Bullets/�������Ҹ�.png", 32, 32);
    D2DMANAGER->loadImageD2D("�ַο�", L"Resources/Images/Player/Bullets/�ַο�.png", 50, 50);
    D2DMANAGER->loadImageD2D("��1", L"Resources/Images/Player/Bullets/��1.png", 960, 576, 5, 3);
    D2DMANAGER->loadImageD2D("��2", L"Resources/Images/Player/Bullets/��2.png", 960, 576, 5, 3);
    D2DMANAGER->loadImageD2D("��3", L"Resources/Images/Player/Bullets/��3.png", 960, 768, 5, 4);
    D2DMANAGER->loadImageD2D("�׸���", L"Resources/Images/Player/�׸���.png", 20, 8);

    IMAGEMANAGER->addFrameImage("��ô޸���", "Resources/Images/Player/�޸���.bmp", 400, 800, 4, 8, true, MAGENTA);
    IMAGEMANAGER->addFrameImage("��ñ⺻����", "Resources/Images/Player/�⺻����.bmp", 600, 800, 6, 8, true, MAGENTA);
    IMAGEMANAGER->addFrameImage("��ð˰���", "Resources/Images/Player/�˰���.bmp", 900, 800, 9, 8, true, MAGENTA);
    IMAGEMANAGER->addFrameImage("���Ȱ����", "Resources/Images/Player/Ȱ����.bmp", 300, 800, 3, 8, true, MAGENTA);
    IMAGEMANAGER->addFrameImage("���������", "Resources/Images/Player/������.bmp", 300, 800, 3, 8, true, MAGENTA);
    IMAGEMANAGER->addFrameImage("���ȸ��", "Resources/Images/Player/����Ʈȸ��.bmp", 600, 800, 6, 8, true, MAGENTA);
    IMAGEMANAGER->addFrameImage("����ǰ�", "Resources/Images/Player/�ǰ�.bmp", 300, 800, 3, 8, true, MAGENTA);
    IMAGEMANAGER->addFrameImage("��ðȱ�", "Resources/Images/Player/�ȱ�.bmp", 300, 800, 3, 8, true, MAGENTA);
    IMAGEMANAGER->addImage("��û��", "Resources/Images/Player/���.bmp", 100, 100, true, MAGENTA);

    // Skill
    D2DMANAGER->loadImageD2D("�����ϼ�������", L"Resources/Images/Player/Skills/�����ϼ�������.png", 32, 32);
    D2DMANAGER->loadImageD2D("�����ϼ�", L"Resources/Images/Player/Skills/�����ϼ�.png", 960, 960, 5, 5);
    D2DMANAGER->loadImageD2D("���̽�Ŭ����ũ������", L"Resources/Images/Player/Skills/���̽�Ŭ����ũ������.png", 32, 32);
    D2DMANAGER->loadImageD2D("���̽�Ŭ����ũ2", L"Resources/Images/Player/Skills/���̽�Ŭ����ũ2.png", 960, 768, 5, 4);
    D2DMANAGER->loadImageD2D("���̽�Ŭ����ũ1", L"Resources/Images/Player/Skills/���̽�Ŭ����ũ1.png", 960, 576, 5, 3);
    D2DMANAGER->loadImageD2D("�ٶ��ǻ�ó������", L"Resources/Images/Player/Skills/�ٶ��ǻ�ó������.png", 32, 32);
    D2DMANAGER->loadImageD2D("�ٶ��ǻ�ó", L"Resources/Images/Player/Skills/�ٶ��ǻ�ó.png", 875, 350, 5, 2);
    D2DMANAGER->loadImageD2D("�ͽ��÷���������", L"Resources/Images/Player/Skills/�ͽ��÷���������.png", 32, 32);
    D2DMANAGER->loadImageD2D("�ͽ��÷���1", L"Resources/Images/Player/Skills/�ͽ��÷���1.png", 960, 960, 5, 5);
    D2DMANAGER->loadImageD2D("�ͽ��÷���2", L"Resources/Images/Player/Skills/�ͽ��÷���2.png", 960, 3840, 5, 20);
    D2DMANAGER->loadImageD2D("��ųĳ����", L"Resources/Images/Player/Skills/��ųĳ����.png", 960, 384, 5, 2);


    // UI
    IMAGEMANAGER->addImage("������", "Resources/Images/UI/������.bmp", WINSIZE_X, WINSIZE_Y);

    D2DMANAGER->loadImageD2D("���׹̳�UI", L"Resources/Images/UI/commonUI/���׹̳�UI.png", 230* RESIZE, 90* RESIZE);
    D2DMANAGER->loadImageD2D("����ġ������UI", L"Resources/Images/UI/commonUI/����ġ������UI.png", 126* RESIZE, 7* RESIZE);
    D2DMANAGER->loadImageD2D("���׹̳�������UI", L"Resources/Images/UI/commonUI/���׹̳�������UI.png", 166* RESIZE, 14* RESIZE);
    D2DMANAGER->loadImageD2D("����UI", L"Resources/Images/UI/commonUI/����UI.png", 320, 19,10,1);
    D2DMANAGER->loadImageD2D("���UI", L"Resources/Images/UI/commonUI/���UI.png", 14, 19 );
    D2DMANAGER->loadImageD2D("������UI", L"Resources/Images/UI/commonUI/������UI.png", 140, 20, 10, 1);
    D2DMANAGER->loadImageD2D("���⽽��A", L"Resources/Images/UI/commonUI/���⽽��A.png", 70, 68);
    D2DMANAGER->loadImageD2D("���⽽��B", L"Resources/Images/UI/commonUI/���⽽��B.png", 70, 68);
    D2DMANAGER->loadImageD2D("���ǽ���", L"Resources/Images/UI/commonUI/���ǽ���UI.png", 44, 44);
    D2DMANAGER->loadImageD2D("ü��UI", L"Resources/Images/UI/commonUI/ü��UI.png", 48, 22, 2, 1);
    D2DMANAGER->loadImageD2D("����UI", L"Resources/Images/UI/commonUI/����UI.png", 48, 24, 2, 1);
    D2DMANAGER->loadImageD2D("��ų����UI", L"Resources/Images/UI/commonUI/��ų����UI.png", 40, 40);
    D2DMANAGER->loadImageD2D("�ҽ�ų����UI", L"Resources/Images/UI/commonUI/�ҽ�ų����UI.png",     24, 24);
    D2DMANAGER->loadImageD2D("�ٶ���ų����UI", L"Resources/Images/UI/commonUI/�ٶ���ų����UI.png", 24, 24);
    D2DMANAGER->loadImageD2D("������ų����UI", L"Resources/Images/UI/commonUI/������ų����UI.png", 24, 24);
    D2DMANAGER->loadImageD2D("������ų����UI", L"Resources/Images/UI/commonUI/������ų����UI.png", 24, 24);
    D2DMANAGER->loadImageD2D("�����Ҹ�UI", L"Resources/Images/UI/commonUI/�����Ҹ�UI.png", 200, 29, 10, 1);
    D2DMANAGER->loadImageD2D("��ų��Ÿ��UI", L"Resources/Images/UI/commonUI/��ų��Ÿ��UI.png", 200, 29, 10, 1);
        
    D2DMANAGER->loadImageD2D("�̴ϸʹ��UI", L"Resources/Images/UI/MapUI/�̴ϸʹ��UI.png", 200, 200);
    D2DMANAGER->loadImageD2D("�̴ϸ���ġUI", L"Resources/Images/UI/MapUI/�̴ϸ���ġUI.png", 64, 8, 8, 1);

    D2DMANAGER->loadImageD2D("����&�ⱸ", L"Resources/Images/UI/MapUI/MiniMap/����&�ⱸ.png", 1008, 816);
    D2DMANAGER->loadImageD2D("��ֹ�1", L"Resources/Images/UI/MapUI/MiniMap/��ֹ�1.png", 1008, 768);
    D2DMANAGER->loadImageD2D("��ֹ�2", L"Resources/Images/UI/MapUI/MiniMap/��ֹ�2.png", 1008, 768);
    D2DMANAGER->loadImageD2D("��ֹ�3", L"Resources/Images/UI/MapUI/MiniMap/��ֹ�3.png", 1008, 768);
    D2DMANAGER->loadImageD2D("��ֹ�4", L"Resources/Images/UI/MapUI/MiniMap/��ֹ�4.png", 1008, 672);
    D2DMANAGER->loadImageD2D("��ֹ�5", L"Resources/Images/UI/MapUI/MiniMap/��ֹ�5.png", 1008, 768);
    D2DMANAGER->loadImageD2D("��ֹ�6", L"Resources/Images/UI/MapUI/MiniMap/��ֹ�6.png", 1008, 768);
    D2DMANAGER->loadImageD2D("��ֹ�7", L"Resources/Images/UI/MapUI/MiniMap/��ֹ�7.png", 1008, 672);
    D2DMANAGER->loadImageD2D("��ֹ�8", L"Resources/Images/UI/MapUI/MiniMap/��ֹ�8.png", 1008, 672);
    D2DMANAGER->loadImageD2D("��ֹ�9", L"Resources/Images/UI/MapUI/MiniMap/��ֹ�9.png", 1008, 672);
    D2DMANAGER->loadImageD2D("��ֹ�10", L"Resources/Images/UI/MapUI/MiniMap/��ֹ�10.png", 1008, 672);
    D2DMANAGER->loadImageD2D("��ֹ�11", L"Resources/Images/UI/MapUI/MiniMap/��ֹ�11.png", 1008, 672);
    D2DMANAGER->loadImageD2D("������", L"Resources/Images/UI/MapUI/MiniMap/������.png", 1104, 960);
    D2DMANAGER->loadImageD2D("�м�&�����", L"Resources/Images/UI/MapUI/MiniMap/�м�&�����.png",1008 , 672);
    D2DMANAGER->loadImageD2D("���ڹ�", L"Resources/Images/UI/MapUI/MiniMap/���ڹ�.png", 1008 , 672);
    D2DMANAGER->loadImageD2D("������", L"Resources/Images/UI/MapUI/MiniMap/������.png", 960,576 );

    D2DMANAGER->loadImageD2D("����������", L"Resources/Images/UI/PlayerUI/����������.png", 960, 384, 5, 2);
    D2DMANAGER->loadImageD2D("���������", L"Resources/Images/UI/PlayerUI/���������.png", 77, 17);
    D2DMANAGER->loadImageD2D("������������", L"Resources/Images/UI/PlayerUI/������������.png", 65, 5);
      
    D2DMANAGER->loadImageD2D("�����ǥ��ѹ�", L"Resources/Images/UI/commonUI/�����ǥ��ѹ�.png", 200, 29,10,1);

    D2DMANAGER->loadImageD2D("��Ʈ����Ʈ", L"Resources/Images/UI/commonUI/��Ʈ����Ʈ.png", 960, 768, 5, 4);

    D2DMANAGER->loadImageD2D("����ü�¹��", L"Resources/Images/UI/BossUI/����ü�¹��.png", 506, 32);
    D2DMANAGER->loadImageD2D("����ü�°�����", L"Resources/Images/UI/BossUI/����ü�°�����.png", 506, 32);

    D2DMANAGER->loadImageD2D("����ü�°�����", L"Resources/Images/UI/BossUI/����ü�°�����.png", 506, 32);


    D2DMANAGER->loadImageD2D("��۸ʹ��", L"Resources/Images/UI/MapUI/toggleMap/��۸ʹ��.png", 455, 317);
    D2DMANAGER->loadImageD2D("��۸ʹ�Ȯ�ι�", L"Resources/Images/UI/MapUI/toggleMap/��۸ʹ�Ȯ�ι�.png", 30, 30);
    D2DMANAGER->loadImageD2D("��۸ʹ�Ȯ�ξ�����", L"Resources/Images/UI/MapUI/toggleMap/��۸ʹ�Ȯ�ξ�����.png", 30, 30);
    D2DMANAGER->loadImageD2D("��۸�Ȯ�ι�", L"Resources/Images/UI/MapUI/toggleMap/��۸�Ȯ�ι�.png", 30, 30);
    D2DMANAGER->loadImageD2D("��۸ʺ�����", L"Resources/Images/UI/MapUI/toggleMap/��۸ʺ�����.png", 30, 30);
    D2DMANAGER->loadImageD2D("��۸ʻ��ڹ�", L"Resources/Images/UI/MapUI/toggleMap/��۸ʻ��ڹ�.png", 30, 30);
    D2DMANAGER->loadImageD2D("��۸ʻ�����", L"Resources/Images/UI/MapUI/toggleMap/��۸ʻ�����.png", 30, 30);
    D2DMANAGER->loadImageD2D("��۸ʽ��۹�", L"Resources/Images/UI/MapUI/toggleMap/��۸ʽ��۹�.png", 30, 30);
    D2DMANAGER->loadImageD2D("��۸�Ư����", L"Resources/Images/UI/MapUI/toggleMap/��۸�Ư����.png", 30, 30);
    D2DMANAGER->loadImageD2D("��۸ʸ�ǥ��", L"Resources/Images/UI/MapUI/toggleMap/��۸ʸ�ǥ��.png", 30, 30);
    D2DMANAGER->loadImageD2D("�����ǥ��", L"Resources/Images/UI/MapUI/toggleMap/�����ǥ��.png", 30, 30);
    
    
    D2DMANAGER->loadImageD2D("�ݵ����̽�", L"Resources/Images/UI/RoomUI/�ݵ����̽�.png", 300, 255);
    D2DMANAGER->loadImageD2D("1��", L"Resources/Images/UI/RoomUI/1��.png", 300, 255);
    D2DMANAGER->loadImageD2D("2��", L"Resources/Images/UI/RoomUI/2��.png", 300, 255);
    D2DMANAGER->loadImageD2D("3��", L"Resources/Images/UI/RoomUI/3��.png", 300, 255);


    D2DMANAGER->loadImageD2D("ŷ����������UI", L"Resources/Images/UI/BossUI/ŷ����������UI.png", 960, 540);
    D2DMANAGER->loadImageD2D("�ް��ö�������UI", L"Resources/Images/UI/BossUI/�ް��ö�������UI.png", 960, 540);
    D2DMANAGER->loadImageD2D("�ӽ�����������UI", L"Resources/Images/UI/BossUI/�ӽ�����������UI.png", 960, 540);



    D2DMANAGER->loadImageD2D("��UI", L"Resources/Images/UI/ItemUI/��UI.png", 32, 32);
    D2DMANAGER->loadImageD2D("ȰUI", L"Resources/Images/UI/ItemUI/ȰUI.png", 32, 32);
    D2DMANAGER->loadImageD2D("������UI", L"Resources/Images/UI/ItemUI/������UI.png", 32, 32);



    // �����Ƽ
    D2DMANAGER->loadImageD2D("��������â", L"Resources/Images/UI/ItemUI/��������â.png", 200, 60);

    D2DMANAGER->loadImageD2D("����", L"Resources/Images/UI/ItemUI/����.png", 32*RESIZE, 32 * RESIZE);
    D2DMANAGER->loadImageD2D("������", L"Resources/Images/UI/ItemUI/������.png", 32 * RESIZE, 32 * RESIZE);
    D2DMANAGER->loadImageD2D("�ż�������", L"Resources/Images/UI/ItemUI/�ż�������.png", 32 * RESIZE, 32 * RESIZE);




#pragma endregion





    //============����============
#pragma region ����

    D2DMANAGER->loadImageD2D("������Ż", L"Resources/Images/Object/������Ż.png", 960, 384, 5, 2);
    D2DMANAGER->loadImageD2D("����������Ż", L"Resources/Images/Object/����������Ż.png", 960, 960, 5, 5);

    D2DMANAGER->loadImageD2D("��-��", L"Resources/Images/Maps/Wall/��-��.png", 288, 327);
    D2DMANAGER->loadImageD2D("��-��", L"Resources/Images/Maps/Wall/��-��.png", 192, 144);
    D2DMANAGER->loadImageD2D("��-��", L"Resources/Images/Maps/Wall/��-��.png", 269, 458);
    D2DMANAGER->loadImageD2D("��-��", L"Resources/Images/Maps/Wall/��-��.png", 271, 476);

    // ���� �߰�
    SOUNDMANAGER->addSound("�ȱ�1", "Resources/audio/�ȱ�1.ogg", false, false);
    SOUNDMANAGER->addSound("�ȱ�2", "Resources/audio/�ȱ�2.ogg", false, false);
    SOUNDMANAGER->addSound("�޸���1", "Resources/audio/�޸���1.wav", false, false);
    SOUNDMANAGER->addSound("�޸���2", "Resources/audio/�޸���2.wav", false, false);
    SOUNDMANAGER->addSound("�޸���3", "Resources/audio/�޸���3.wav", false, false);
    SOUNDMANAGER->addSound("�޸���4", "Resources/audio/�޸���4.wav", false, false);
    SOUNDMANAGER->addSound("����ǰ���", "Resources/audio/����ǰ���.ogg", false, false);
    SOUNDMANAGER->addSound("����ΰ���", "Resources/audio/����ΰ���.ogg", false, false);
    SOUNDMANAGER->addSound("�޴�Ŭ��", "Resources/audio/�޴�Ŭ��.ogg", false, false);
    SOUNDMANAGER->addSound("�����ǰ���", "Resources/audio/�����ǰ���.ogg", false, false);
    SOUNDMANAGER->addSound("�������̵�1", "Resources/audio/�������̵�1.ogg", false, false);
    SOUNDMANAGER->addSound("�������̵�2", "Resources/audio/�������̵�2.ogg", false, false);
    SOUNDMANAGER->addSound("�������", "Resources/audio/�������.ogg", false, false);
    SOUNDMANAGER->addSound("��ų�ٶ��ǻ�ó", "Resources/audio/��ų�ٶ��ǻ�ó.ogg", false, false);
    SOUNDMANAGER->addSound("��ų�ϼ�1", "Resources/audio/��ų�ϼ�1.ogg", false, false);
    SOUNDMANAGER->addSound("��ų�ϼ�2", "Resources/audio/��ų�ϼ�2.ogg", false, false);
    SOUNDMANAGER->addSound("����Ŭ����", "Resources/audio/����Ŭ����.ogg", false, false);
    SOUNDMANAGER->addSound("�ͽ��÷���", "Resources/audio/�ͽ��÷���.ogg", false, false);
    SOUNDMANAGER->addSound("�����̱⺻����", "Resources/audio/�����̱⺻����.ogg", false, false);
    SOUNDMANAGER->addSound("����������", "Resources/audio/����������.wav", false, false);
    SOUNDMANAGER->addSound("ȸ��", "Resources/audio/ȸ��.ogg", false, false);
    SOUNDMANAGER->addSound("ȸ�ǰ���", "Resources/audio/ȸ�ǰ���.ogg", false, false);
    SOUNDMANAGER->addSound("�����ǰ���", "Resources/audio/�����ǰ���.ogg", false, false);
    SOUNDMANAGER->addSound("��ųĳ����", "Resources/audio/��ųĳ����.ogg", false, false);
    SOUNDMANAGER->addSound("�����ǰ���", "Resources/audio/�����ǰ���.ogg", false, false);
    SOUNDMANAGER->addSound("��1Ÿ", "Resources/audio/��1Ÿ.ogg", false, false);
    SOUNDMANAGER->addSound("��3Ÿ", "Resources/audio/��3Ÿ.ogg", false, false);
    SOUNDMANAGER->addSound("��5Ÿ", "Resources/audio/��5Ÿ.ogg", false, false);
    SOUNDMANAGER->addSound("���̽ý�����ũ", "Resources/audio/���̽ý�����ũ.ogg", false, false);
    SOUNDMANAGER->addSound("�����Ӱ���", "Resources/audio/�����Ӱ���.ogg", false, false);
    SOUNDMANAGER->addSound("�����Ӱ����غ�", "Resources/audio/�����Ӱ����غ�.ogg", false, false);
    SOUNDMANAGER->addSound("���ڿ���", "Resources/audio/���ڿ���.ogg", false, false);
    SOUNDMANAGER->addSound("�ö��Ӱ��û���", "Resources/audio/�ö��Ӱ��û���.ogg", false, false);
    SOUNDMANAGER->addSound("Ȱ�����Ҹ�", "Resources/audio/Ȱ�����Ҹ�.ogg", false, false);
    SOUNDMANAGER->addSound("������Ʈü��", "Resources/audio/������Ʈü��.ogg", false, false);
    SOUNDMANAGER->addSound("������Ʈ����", "Resources/audio/������Ʈ����.ogg", false, false);
    SOUNDMANAGER->addSound("�ö��ӵ��߻�", "Resources/audio/�ö��ӵ��߻�.ogg", false, false);
    SOUNDMANAGER->addSound("������&���", "Resources/audio/������&���.ogg", true, true);
    SOUNDMANAGER->addSound("�����ӻ��", "Resources/audio/�����ӻ��.ogg", false, false);
    SOUNDMANAGER->addSound("������ũ&�ö��ӻ��", "Resources/audio/������ũ&�ö��ӻ��.ogg", false, false);
    SOUNDMANAGER->addSound("�ӽ��ǰ���", "Resources/audio/�ӽ��ǰ���.ogg", false, false);
    SOUNDMANAGER->addSound("�ӽ��ǻ��", "Resources/audio/�ӽ��ǻ��.ogg", false, false);
    SOUNDMANAGER->addSound("������ũ����", "Resources/audio/������ũ����.ogg", false, false);
    SOUNDMANAGER->addSound("�̴Ϲ�������ī��Ʈ", "Resources/audio/�̴Ϲ�������ī��Ʈ.ogg", false, false);
    SOUNDMANAGER->addSound("������������", "Resources/audio/������������.ogg", false, false);
    SOUNDMANAGER->addSound("����������", "Resources/audio/����������.ogg", false, false);
    SOUNDMANAGER->addSound("��ų�ٶ��ǻ�ó", "Resources/audio/��ų�ٶ��ǻ�ó.ogg", false, false);
    SOUNDMANAGER->addSound("�����Ҹ�", "Resources/audio/�����Ҹ�.ogg", false, false);
    SOUNDMANAGER->addSound("������", "Resources/audio/������.ogg", false, false);
  
    SOUNDMANAGER->addSound("�������", "Resources/audio/semi-boss.ogg", false, false);
 

#pragma endregion

    //============����============
#pragma region ����
    D2DMANAGER->loadImageD2D("�����������Ʈ", L"Resources/Images/Effect/60FPS_AC3T026_Nova_02.png",
        960, 3840, 5, 20);
	IMAGEMANAGER->addFrameImage("ŷ������IDLE", "Resources/Images/Enemy/Boss/SlimeBoss/Page1/BossSlimeIdle.bmp",
		720, 1439,
		2, 4,
		true,
		RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ŷ������MOVE", "Resources/Images/Enemy/Boss/SlimeBoss/Page1/BossSlimeMove.bmp",
		1080, 1439,
		3, 4,
		true,
		RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ŷ������ATTACK", "Resources/Images/Enemy/Boss/SlimeBoss/Page1/BossSlimeAttack.bmp",
		1785, 1439,
		5, 4,
		true,
		RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ŷ������DIE", "Resources/Images/Enemy/Boss/SlimeBoss/Page1/BossSlimeDie.bmp",
		221, 94,
		1, 1,
		true,
		RGB(255, 0, 255));


    IMAGEMANAGER->addFrameImage("ŷ�����Ӻп�IDLE", "Resources/Images/Enemy/Boss/SlimeBoss/Page2/BossSlimePage2Idle.bmp",
        376, 766,
        2, 4,
        true,
        RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("ŷ�����Ӻп�MOVE", "Resources/Images/Enemy/Boss/SlimeBoss/Page2/BossSlimePage2Move.bmp",
        564, 766,
        3, 4,
        true,
        RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("ŷ�����Ӻп�ATTACK", "Resources/Images/Enemy/Boss/SlimeBoss/Page2/BossSlimePage2Attack1.bmp",
        564, 766,
        3, 4,
        true,
        RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("ŷ�����Ӻп�DIE", "Resources/Images/Enemy/Boss/SlimeBoss/Page2/BossSlimePage2Die.bmp",
        124, 56,
        1, 1,
        true,
        RGB(255, 0, 255));




    IMAGEMANAGER->addFrameImage("�ӽ�������IDLE", "Resources/Images/Enemy/Boss/MushmomBoss/BossMushmamIdle.bmp",
        287, 666,
        2, 4,
        true,
        RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("�ӽ�������MOVE", "Resources/Images/Enemy/Boss/MushmomBoss/BossMushmamMove.bmp",
        430, 666,
        3, 4,
        true,
        RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("�ӽ�������ATTACK1", "Resources/Images/Enemy/Boss/MushmomBoss/BossMushmamAttack1.bmp",
        861, 222,
        6, 1,
        true,
        RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("�ӽ�������ATTACK2", "Resources/Images/Enemy/Boss/MushmomBoss/BossMushmamAttack2.bmp",
        861, 222,
        6, 1,
        true,
        RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("�ӽ�������ATTACK3", "Resources/Images/Enemy/Boss/MushmomBoss/BossMushmamAttack3.bmp",
        861, 222,
        6, 1,
        true,
        RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("�ӽ�������DIE", "Resources/Images/Enemy/Boss/MushmomBoss/BossMushmamDie.bmp",
        102, 108,
        1, 1,
        true,
        RGB(255, 0, 255));




    IMAGEMANAGER->addFrameImage("�ް��ö���IDLE", "Resources/Images/Enemy/Boss/FlimeBoss/BossFlimeIdle.bmp",
        500, 775,
        2, 4,
        true,
        RGB(255, 0, 255));

    IMAGEMANAGER->addFrameImage("�ް��ö���ATTACK1", "Resources/Images/Enemy/Boss/FlimeBoss/BossFlimeAttack1.bmp",
        762, 775,
        3, 4,
        true,
        RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("�ް��ö���ATTACK2", "Resources/Images/Enemy/Boss/FlimeBoss/BossFlimeAttack2.bmp",
        762, 775,
        3, 4,
        true,
        RGB(255, 0, 255));

    IMAGEMANAGER->addFrameImage("�ް��ö���ATTACK3", "Resources/Images/Enemy/Boss/FlimeBoss/BossFlimeAttack1.bmp",
        762, 775,
        3, 4,
        true,
        RGB(255, 0, 255));

    IMAGEMANAGER->addFrameImage("�ް��ö���DIE", "Resources/Images/Enemy/Boss/FlimeBoss/BossFlimeDie.bmp",
        245, 134,
        1, 1,
        true,
        RGB(255, 0, 255));




    IMAGEMANAGER->addFrameImage("��IDLE", "Resources/Images/Enemy/Common/Snake/snakeIdle.bmp",
        88, 189,
        2, 4,
        true,
        RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("��MOVE", "Resources/Images/Enemy/Common/Snake/snakeMove.bmp",
        140, 189,
        3, 4,
        true,
        RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("��ATTACK", "Resources/Images/Enemy/Common/Snake/snakeAttack.bmp",
        135, 192,
        3, 4,
        true,
        RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("��DIE", "Resources/Images/Enemy/Common/Snake/snakeDie.bmp",
        38, 32,
        1, 1,
        true,
        RGB(255, 0, 255));




    IMAGEMANAGER->addFrameImage("������IDLE", "Resources/Images/Enemy/Common/Slime/SlimeIdle.bmp",
        76, 145,
        2, 4,
        true,
        RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("������MOVE", "Resources/Images/Enemy/Common/Slime/SlimeMove.bmp",
        115, 150,
        3, 4,
        true,
        RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("������ATTACK", "Resources/Images/Enemy/Common/Slime/SlimeAttack1.bmp",
        200, 160,
        5, 4,
        true,
        RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("������ATTACK2", "Resources/Images/Enemy/Common/Slime/SlimeAttack2.bmp",
        140, 150,
        3, 4,
        true,
        RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("������DIE", "Resources/Images/Enemy/Common/Slime/SlimeDie.bmp",
        38, 17,
        1, 1,
        true,
        RGB(255, 0, 255));





    IMAGEMANAGER->addFrameImage("�ӽ���IDLE", "Resources/Images/Enemy/Common/Mushmam/mushmamIdle.bmp",
        68, 212,
        2, 4,
        true,
        RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("�ӽ���MOVE", "Resources/Images/Enemy/Common/Mushmam/mushmamMove1.bmp",
        108, 203,
        3, 4,
        true,
        RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("�ӽ���ATTACK", "Resources/Images/Enemy/Common/Mushmam/mushmamAttack1.bmp",
        216, 50,
        6, 1,
        true,
        RGB(255, 0, 255));

    IMAGEMANAGER->addFrameImage("�ӽ���DIE", "Resources/Images/Enemy/Common/Mushmam/mushmamDie.bmp",
        34, 36,
        1, 1,
        true,
        RGB(255, 0, 255));


    IMAGEMANAGER->addFrameImage("��IDLE", "Resources/Images/Enemy/Common/Flime/FlimeIdle.bmp",
        161, 243,
        2, 4,
        true,
        RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("��ATTACK", "Resources/Images/Enemy/Common/Flime/FlimeAttack1.bmp",
        234, 230,
        3, 4,
        true,
        RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("��ATTACK2", "Resources/Images/Enemy/Common/Flime/FlimeAttack2.bmp",
        238, 243,
        3, 4,
        true,
        RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("��DIE", "Resources/Images/Enemy/Common/Flime/FlimeDie.bmp",
        79, 46,
        1, 1,
        true,
        RGB(255, 0, 255));


    D2DMANAGER->loadImageD2D("�����Ϲ�ź", L"Resources/Images/Enemy/Bullets/EnemySmallBullet.png", 32, 32);
    D2DMANAGER->loadImageD2D("ū�Ϲ�ź", L"Resources/Images/Enemy/Bullets/EnemyBigBullet.png", 48, 48);
    D2DMANAGER->loadImageD2D("����ź", L"Resources/Images/Enemy/Bullets/ESK_mushroom.png", 32, 32);
    D2DMANAGER->loadImageD2D("����", L"Resources/Images/Enemy/Bullets/bubble.png", 99, 99);
    D2DMANAGER->loadImageD2D("��ź", L"Resources/Images/Enemy/Bullets/FlimeAttack1.png", 200, 160, 5, 4);
    D2DMANAGER->loadImageD2D("����", L"Resources/Images/Enemy/Bullets/skill_flime2.png", 960, 576, 5, 3);
    D2DMANAGER->loadImageD2D("���ù̸�����", L"Resources/Images/Enemy/Bullets/skill_flime_skillLine.png", 64, 64);
    
    
    D2DMANAGER->loadImageD2D("���������Ʈ", L"Resources/Images/Effect/EnemyDie.png", 960, 2304, 5, 12);

    D2DMANAGER->loadImageD2D("�ɻѸ�ź", L"Resources/Images/Enemy/Bullets/skill_flime2.png", 960, 576, 5, 3);

   

    IMAGEMANAGER->addImage("�ʷ���ž", "Resources/Images/Enemy/Bullets/mGreen1.bmp",
        13, 13,
        true, RGB(255, 0, 255));

    IMAGEMANAGER->addImage("ū�ʷ���ž", "Resources/Images/Enemy/Bullets/mBossGreen1.bmp",
        43, 41,
        true, RGB(255, 0, 255));
    IMAGEMANAGER->addImage("ū������ž", "Resources/Images/Enemy/Bullets/mBossPurple1.bmp",
        43, 41,
        true, RGB(255, 0, 255));
    IMAGEMANAGER->addImage("ū��Ʈ��ž", "Resources/Images/Enemy/Bullets/mBossMint1.bmp",
        43, 41,
        true, RGB(255, 0, 255));




#pragma endregion






    //============����============
#pragma region ����







#pragma endregion






	return S_OK;
}
