#include <iostream>
#include "User.h"

#pragma once
using namespace std;

void ChatByRSA(User u1, User u2)
{
    int p, q;
    int choice;
    string message;



    // �������� ���������

    cout << "��� ����� ���������� ���������?" << endl
        << "1) " << u1.GetUserName() << endl
        << "2) " << u2.GetUserName() << endl;

    cin >> choice;

    switch (choice)
    {
    case 1:
        //�������� ���������� �����
        cout << "������� p � q ��� ����������� ������ RSA (��� p=3 � q=5 ���������� ����������� �� 6 ���� ��������, ��� ������� ����������� ���������� ������������ ����������)" << endl
            << "p = ";

        cin >> p;

        cout << "q = ";

        cin >> q;

        u2.SetParametersRSA(p, q);

        cout << u2.GetUserName() << " �������� ��� ���� �����:" << endl
            << "�������� ���� = (" << u2.GetEilerNumberRSA() << ", " << u2.GetModulRSA() << ")" << endl
            << "�������� ���� = (" << u2.GetReversEilerNumberRSA() << ", " << u2.GetModulRSA() << ")" << endl;

        u1.SetOpenKeyRSA(u2.GetEilerNumberRSA(), u2.GetModulRSA());
        cout << u1.GetUserName() << " ������� �� " << u2.GetUserName() << " �������� ���� � �������� ���" << endl
            << "�������� ���� = (" << u1.GetEilerNumberRSA() << ", " << u1.GetModulRSA() << ")" << endl;

        cout << u1.GetUserName() << " ���������� ��������� -> " << u2.GetUserName() << endl
            << "������� ��������� (������ ����� ����������� �������� b-g ��� �������� � �� ����� 100 ��������)" << endl
            << u1.GetUserName() << ": ";
        cin >> message;
        u1.SetOriginalMessageToSend(message);
        message = u1.SendEncryptedMessageByRSA();
        cout << u1.GetUserName() << " ���������� � �������� ��������� -> " << u2.GetUserName() << ": " << message << endl;
        u2.ReceiveEncryptedMessageByRSA(message);
        message = u2.GetOriginalMessageByRSA();//�������� ������ �������� �������� �� ����������, ������� �����?
        cout << u2.GetUserName() << " ����������� ��������� �� -> " << u1.GetUserName() << ": " << message << endl;
        break;
    case 2:
        //�������� ���������� �����
        cout << "������� p � q ��� ����������� ������ RSA (��� p=3 � q=5 ���������� ����������� �� 6 ���� ��������, ��� ������� ����������� ���������� ������������ ����������)" << endl
            << "p = ";

        cin >> p;

        cout << "q = ";

        cin >> q;

        u1.SetParametersRSA(p, q);

        cout << u1.GetUserName() << " �������� ��� ���� �����:" << endl
            << "�������� ���� = (" << u1.GetEilerNumberRSA() << ", " << u1.GetModulRSA() << ")" << endl
            << "�������� ���� = (" << u1.GetReversEilerNumberRSA() << ", " << u1.GetModulRSA() << ")" << endl;

        u2.SetOpenKeyRSA(u1.GetEilerNumberRSA(), u1.GetModulRSA());
        cout << u2.GetUserName() << " ������� �� " << u1.GetUserName() << " �������� ���� � �������� ���" << endl
            << "�������� ���� = (" << u2.GetEilerNumberRSA() << ", " << u2.GetModulRSA() << ")" << endl;

        cout << u2.GetUserName() << " ���������� ��������� -> " << u1.GetUserName() << endl
            << "������� ��������� (������ ����� ����������� �������� b-g ��� �������� � �� ����� 100 ��������)" << endl
            << u2.GetUserName() << ": ";
        cin >> message;
        u2.SetOriginalMessageToSend(message);
        message = u2.SendEncryptedMessageByRSA();
        cout << u2.GetUserName() << " ���������� � �������� ��������� -> " << u1.GetUserName() << ": " << message << endl;
        u1.ReceiveEncryptedMessageByRSA(message);
        message = u1.GetOriginalMessageByRSA();//�������� ������ �������� �������� �� ����������, ������� �����?
        cout << u1.GetUserName() << " ����������� ��������� �� -> " << u1.GetUserName() << ": " << message << endl;
        break;
    default:
        cout << "������" << endl;
        break;
    }
}

void ChatByCaesar(User u1, User u2)
{
    int closeKeyCaesar;
    int choice;
    string message;
    //�������� ���������� �����
    cout << "������� ���� ��� ���������� ������" << endl
        << "���� = ";

    cin >> closeKeyCaesar;
    
    u1.SetCloseKeyCaesar(closeKeyCaesar);
    u2.SetCloseKeyCaesar(closeKeyCaesar);

    // �������� ���������

    cout << "��� ����� ���������� ���������?" << endl
        << "1) " << u1.GetUserName() << endl
        << "2) " << u2.GetUserName() << endl;

    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << u1.GetUserName() << " ���������� ��������� -> " << u2.GetUserName() << endl
            << "������� ��������� (������ ����� ����� ����������� �������� ��� �������� � �� ����� 100 ��������)" << endl
            << u1.GetUserName() << ": ";
        cin >> message;
        u1.SetOriginalMessageToSend(message);
        message = u1.SendEncryptedMessageByCaesar();
        cout << u1.GetUserName() << " ���������� � �������� ��������� -> " << u2.GetUserName() << ": " << message << endl;
        u2.ReceiveEncryptedMessageByCaesar(message);
        message = u2.GetOriginalReceivedMessageByCaesar();
        cout << u2.GetUserName() << " ����������� ��������� �� -> " << u1.GetUserName() << ": " << message << endl;
        break;
    case 2:
        cout << u2.GetUserName() << " ���������� ��������� -> " << u1.GetUserName() << endl
            << "������� ��������� (������ ����� ����� ����������� �������� ��� �������� � �� ����� 100 ��������)" << endl
            << u2.GetUserName() << ": ";
        cin >> message;
        u2.SetOriginalMessageToSend(message);
        message = u2.SendEncryptedMessageByCaesar();
        cout << u2.GetUserName() << " ���������� � �������� ��������� -> " << u1.GetUserName() << ": " << message << endl;
        u1.ReceiveEncryptedMessageByCaesar(message);
        message = u1.GetOriginalReceivedMessageByCaesar();
        cout << u1.GetUserName() << " ����������� ��������� �� -> " << u2.GetUserName() << ": " << message << endl;
        break;
    default:
        cout << "������" << endl;
        break;
    }
}

void ChatByXOR(User u1, User u2)
{
    int closeKeyXOR;
    int choice;
    unsigned int number;

    //�������� ���������� �����
    cout << "������� ���� ��� ���������� XOR" << endl
        << "���� = ";

    cin >> closeKeyXOR;

    u1.SetCloseKeyXOR(closeKeyXOR);
    u2.SetCloseKeyXOR(closeKeyXOR);

    // �������� ���������

    cout << "��� ����� ���������� �����?" << endl
        << "1) " << u1.GetUserName() << endl
        << "2) " << u2.GetUserName() << endl;

    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << u1.GetUserName() << " ���������� ����� -> " << u2.GetUserName() << endl
            << "������� ����� ��������������� �����" << endl
            << u1.GetUserName() << ": ";
        cin >> number;
        u1.SetOriginalNumberToSend(number);
        number = u1.SendEncryptedNumberByXOR();
        cout << u1.GetUserName() << " ���������� � �������� ����� -> " << u2.GetUserName() << ": " << number << endl;
        u2.ReceiveEncryptedNumberByXOR(number);
        number = u2.GetOriginalReceivedNumberByXOR();
        cout << u2.GetUserName() << " ����������� ��������� �� -> " << u1.GetUserName() << ": " << number << endl;
        break;
    case 2:
        cout << u2.GetUserName() << " ���������� ����� -> " << u1.GetUserName() << endl
            << "������� ����� ��������������� �����" << endl
            << u2.GetUserName() << ": ";
        cin >> number;
        u2.SetOriginalNumberToSend(number);
        number = u2.SendEncryptedNumberByXOR();
        cout << u2.GetUserName() << " ���������� � �������� ����� -> " << u1.GetUserName() << ": " << number << endl;
        u1.ReceiveEncryptedNumberByXOR(number);
        number = u1.GetOriginalReceivedNumberByXOR();
        cout << u1.GetUserName() << " ����������� ��������� �� -> " << u2.GetUserName() << ": " << number << endl;
        break;
    default:
        cout << "������" << endl;
        break;
    }
}

void ChatByVigenere(User u1, User u2)
{
    string closeKeyVigenere;
    int choice;
    string message;
    //�������� ���������� �����
    cout << "������� ����-����� ��� ���������� �������� (������ ����� ���������� ����� �� ����� 100 ��������)" << endl
        << "���� = ";

    cin >> closeKeyVigenere;

    u1.SetCloseKeyVigenere(closeKeyVigenere);
    u2.SetCloseKeyVigenere(closeKeyVigenere);

    // �������� ���������

    cout << "��� ����� ���������� ���������?" << endl
        << "1) " << u1.GetUserName() << endl
        << "2) " << u2.GetUserName() << endl;

    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << u1.GetUserName() << " ���������� ��������� -> " << u2.GetUserName() << endl
            << "������� ��������� (������ ����� ����� ����������� �������� ��� �������� � �� ����� 100 ��������)" << endl
            << u1.GetUserName() << ": ";
        cin >> message;
        u1.SetOriginalMessageToSend(message);
        message = u1.SendEncryptedMessageByVigenere();
        cout << u1.GetUserName() << " ���������� � �������� ��������� -> " << u2.GetUserName() << ": " << message << endl;
        u2.ReceiveEncryptedMessageByVigenere(message);
        message = u2.GetOriginalReceivedMessageByVigenere();
        cout << u2.GetUserName() << " ����������� ��������� �� -> " << u1.GetUserName() << ": " << message << endl;
        break;
    case 2:
        cout << u2.GetUserName() << " ���������� ��������� -> " << u1.GetUserName() << endl
            << "������� ��������� (������ ����� ����� ����������� �������� ��� �������� � �� ����� 100 ��������)" << endl
            << u2.GetUserName() << ": ";
        cin >> message;
        u2.SetOriginalMessageToSend(message);
        message = u2.SendEncryptedMessageByVigenere();
        cout << u2.GetUserName() << " ���������� � �������� ��������� -> " << u1.GetUserName() << ": " << message << endl;
        u1.ReceiveEncryptedMessageByVigenere(message);
        message = u1.GetOriginalReceivedMessageByVigenere();
        cout << u1.GetUserName() << " ����������� ��������� �� -> " << u2.GetUserName() << ": " << message << endl;
        break;
    default:
        cout << "������" << endl;
        break;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int choice;

    User Vlad("����");  // ������ ������������
    User Dima("����");  // ������ ������������

    while (true)
    {
        cout << "�������� �������� ����������" << endl
            << "1) ���������� RSA" << endl
            << "2) ���������� ������" << endl
            << "3) ���������� ��������" << endl
            << "4) ���������� XOR" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            ChatByRSA(Vlad, Dima);
            break;
        case 2:
            ChatByCaesar(Vlad, Dima);
            break;
        case 3:
            ChatByVigenere(Vlad, Dima);
            break;
        case 4:
            ChatByXOR(Vlad, Dima);
            break;
        default:
            break;
        }
    }
}

