#pragma once
#include "SingletonBase.h"

// ������ ���� ���̺귯�� (���)
// �ð� or v���� -> PlaySound()
#include <mmsystem.h>
// ��Ƽ�̵����Ʈ���������̽�  api �� (��ġ�����ڿ� ����)
// mciSendString()�̶�� �Լ��� ����ϱ� ���� �߰�
#include <mciapi.h>
// mm ��Ƽ �̵���� ����
#pragma comment(lib, "Winmm.lib")
class TempSoundManager : public SingletonBase <TempSoundManager>
{

public:

	HRESULT init(void);
	// MP3
	void addMp3FileWithKey(string key, string fileName);
	// WAV
	void addWaveFileWithKey(string key, string fileName);
	// ȿ����
	void playEffectSoundWave(char* fileName);
	// MP3 ���
	void playSoundWithKey(string key);
	// MP3 ����
	void stopMp3WithKey(string key);

	
	TempSoundManager() {}
	~TempSoundManager() {}
};

