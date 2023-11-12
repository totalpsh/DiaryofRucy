#include "Stdafx.h"
#include "INIData.h"

HRESULT INIData::init(void)
{
	return S_OK;
}

void INIData::release(void)
{
	// !do nothing
}

void INIData::addData(char* section, char* key, char* value)
{
	tagIniData iniData;
	iniData.section = section;
	iniData.key = key;
	iniData.value = value;

	arrIniData vIniData;
	vIniData.push_back(iniData);

	_vIniData.push_back(vIniData);
}

void INIData::iniSave(char* fileName, bool clear)
{
	char str[256];
	char dir[256];

	ZeroMemory(str, sizeof(str));
	ZeroMemory(dir, sizeof(dir));

	sprintf_s(dir, "\\IniData%s.ini", fileName);

	GetCurrentDirectory(256, str);

	strcat_s(str, dir);

	if (clear)
	{
		// ���� ���� ��� ������ ����
		for (int i = 0; i < _vIniData.size(); i++)
		{
			arrIniData vData = _vIniData[i];
			WritePrivateProfileString(vData[0].section, NULL, NULL, str);
		}
	}

	for (int i = 0; i < _vIniData.size(); i++)
	{
		arrIniData vData = _vIniData[i];

		WritePrivateProfileString(vData[0].section,	vData[0].key, vData[0].value, str); // ������ ������ ����. �ش� ���ǰ� Ű���� ������ �ڵ����� ������ ��Ų��.

		vData.clear();
	}

	_vIniData.clear();

}


char* INIData::loadDataString(char* fileName, char* section, char* key)
{
	char str[256];
	char dir[256];

	ZeroMemory(str, sizeof(str));
	ZeroMemory(dir, sizeof(dir));

	sprintf_s(dir, "\\IniData%s.ini", fileName);

	GetCurrentDirectory(256, str);
	strcat_s(str, dir);

	char data[64] = { NULL };

	GetPrivateProfileString
	(
		section,	// �о�� Value�� �ִ� ������ �̸�
		key,		// �о�� value�� �̸�
		"",			// ���� �̸��̳� Ű �̸��� ã�� ���ϸ� ����� ���ڿ�
		data,		// Ű������ ����Ű�� ���� ������ ����
		64,			// Ű���� ������ ����
		str
	);

	return nullptr;
}

int INIData::loadDataInteger(char* fileName, char* section, char* key)
{
	char str[256];
	char dir[256];

	ZeroMemory(str, sizeof(str));
	ZeroMemory(dir, sizeof(dir));

	sprintf_s(dir, "\\IniData%s.ini", fileName);

	GetCurrentDirectory(256, str);
	strcat_s(str, dir);


	return GetPrivateProfileInt(section, key, 0, str);
}
