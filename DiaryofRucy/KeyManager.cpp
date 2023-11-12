#include "KeyManager.h"

HRESULT KeyManager::init(void)
{
    // Ű ���� ���δ������� ���� ���·� �ʱ�ȭ
    for (int i = 0; i < KEY_MAX; i++)
    {
        this->setKeyUp(i, false);
        this->setKeyDown(i, false);
    }
    return S_OK;
    // bool b[20] = { true };  �̰� Ʈ��� �ʱ�ȭ �ȴ�
    // bool b[20] = { false };  �̰� �� ��
}

bool KeyManager::isOnceKeyDown(int key)
{

    /*    
    �� GetAsyncKeyState

     - � Ű�� �ԷµȰ��� üũ / ���α׷����� Ű�� �Է¹ް� ���� �� ����ϴ� API���� �Լ�

     - �⺻������ �޼��� ť�� �ִ� Ű�� ������ Ȯ�� �Ѵ�.

     - Ű�� ���� ������ üũ�ϱ� ���� &(AND) ������ ����ؼ� Ȯ���Ѵ�.

     0X0000 ������ x ȣ������� �ȴ���
     0X0001 ������ o ȣ������� �ȴ���
     0X8000 ������ x ȣ������� ����
     0X8001 ������ o ȣ������� ����
    */

    // ��Ʈ������ AND ������ �Ѵ�.
    //  �� �Ѵ� 1�� ���� ����� 1�̰� / �ƴ϶�� ����� 0

    if (GetAsyncKeyState(key) & 0x8000)
    {
        if (!this->getKeyDown()[key])
        {
            this->setKeyDown(key, true);
            return true;
        }
    }
    else
    {
        this->setKeyDown(key, false);
    }
    return false;
}

bool KeyManager::isOnceKeyUp(int key)
{
    if(GetAsyncKeyState(key) & 0x8000)
    {
        this->setKeyUp(key, true);
    }
    else
    {
        if (this->getKeyUp()[key])
        {
            this->setKeyUp(key, false);
            return true;
        }
    }
    return false;
}

bool KeyManager::isStayKeyDown(int key)
{
    if (GetAsyncKeyState(key) & 0x8000)
    {
        return true;
    }
    return false;
}

bool KeyManager::isToggleKey(int key)
{
    if (GetKeyState(key) & 0x0001)
    {
        return true;
    }
    return false;
}

bool KeyManager::checkMoveKeyDown(int key1, int key2, int key3, int key4)
{
    if (!isStayKeyDown(key1))
    {
        if (!isStayKeyDown(key2))
        {
            if (!isStayKeyDown(key3))
            {
                if (!isStayKeyDown(key4))
                {
                    return true;
                }
            }
        }
    }
    return false;

}
