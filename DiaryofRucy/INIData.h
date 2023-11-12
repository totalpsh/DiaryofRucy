#pragma once
#include "SingletonBase.h"

struct tagIniData
{
	char* section;
	char* key;
	char* value;
};

class INIData : public SingletonBase<INIData>
{
private:
	typedef vector<tagIniData> arrIniData;
	typedef vector<arrIniData> arrIniDatas;

private:
	arrIniDatas _vIniData;

public:
	HRESULT init(void);
	void release(void);

	// ���� �߰�
	void addData(char* section, char* key, char* value);
	// INI���� ���丮�� ����
	void iniSave(char* fileName, bool clear = false);

	// ���ڿ�
	char* loadDataString(char* fileName, char* section, char* key);
	// ����
	int loadDataInteger(char* fileName, char* section, char* key);

	INIData() {}
	~INIData() {}
};

