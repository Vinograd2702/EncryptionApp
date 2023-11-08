#include <iostream>
#include "User.h"

#pragma once
using namespace std;

void ChatByRSA(User u1, User u2)
{
    int p, q;
    int choice;
    string message;



    // передача сообщения

    cout << "Кто будет отправлять сообщение?" << endl
        << "1) " << u1.GetUserName() << endl
        << "2) " << u2.GetUserName() << endl;

    cin >> choice;

    switch (choice)
    {
    case 1:
        //создание секретного ключа
        cout << "Введите p и q для определения ключей RSA (при p=3 и q=5 получается защифровать до 6 букв алфавита, при большем колличестве происходит переполнение переменной)" << endl
            << "p = ";

        cin >> p;

        cout << "q = ";

        cin >> q;

        u2.SetParametersRSA(p, q);

        cout << u2.GetUserName() << " составил для себя ключи:" << endl
            << "открытый ключ = (" << u2.GetEilerNumberRSA() << ", " << u2.GetModulRSA() << ")" << endl
            << "закрытый ключ = (" << u2.GetReversEilerNumberRSA() << ", " << u2.GetModulRSA() << ")" << endl;

        u1.SetOpenKeyRSA(u2.GetEilerNumberRSA(), u2.GetModulRSA());
        cout << u1.GetUserName() << " получил от " << u2.GetUserName() << " открытый ключ и сохранил его" << endl
            << "открытый ключ = (" << u1.GetEilerNumberRSA() << ", " << u1.GetModulRSA() << ")" << endl;

        cout << u1.GetUserName() << " отправляет сообщение -> " << u2.GetUserName() << endl
            << "Введите сообщение (только буквы английского алфавита b-g без пробелов и не более 100 символов)" << endl
            << u1.GetUserName() << ": ";
        cin >> message;
        u1.SetOriginalMessageToSend(message);
        message = u1.SendEncryptedMessageByRSA();
        cout << u1.GetUserName() << " зашифровал и отправил сообщение -> " << u2.GetUserName() << ": " << message << endl;
        u2.ReceiveEncryptedMessageByRSA(message);
        message = u2.GetOriginalMessageByRSA();//отладить почему половина символов не появляются, большие цифры?
        cout << u2.GetUserName() << " расшифровал сообщение от -> " << u1.GetUserName() << ": " << message << endl;
        break;
    case 2:
        //создание секретного ключа
        cout << "Введите p и q для определения ключей RSA (при p=3 и q=5 получается защифровать до 6 букв алфавита, при большем колличестве происходит переполнение переменной)" << endl
            << "p = ";

        cin >> p;

        cout << "q = ";

        cin >> q;

        u1.SetParametersRSA(p, q);

        cout << u1.GetUserName() << " составил для себя ключи:" << endl
            << "открытый ключ = (" << u1.GetEilerNumberRSA() << ", " << u1.GetModulRSA() << ")" << endl
            << "закрытый ключ = (" << u1.GetReversEilerNumberRSA() << ", " << u1.GetModulRSA() << ")" << endl;

        u2.SetOpenKeyRSA(u1.GetEilerNumberRSA(), u1.GetModulRSA());
        cout << u2.GetUserName() << " получил от " << u1.GetUserName() << " открытый ключ и сохранил его" << endl
            << "открытый ключ = (" << u2.GetEilerNumberRSA() << ", " << u2.GetModulRSA() << ")" << endl;

        cout << u2.GetUserName() << " отправляет сообщение -> " << u1.GetUserName() << endl
            << "Введите сообщение (только буквы английского алфавита b-g без пробелов и не более 100 символов)" << endl
            << u2.GetUserName() << ": ";
        cin >> message;
        u2.SetOriginalMessageToSend(message);
        message = u2.SendEncryptedMessageByRSA();
        cout << u2.GetUserName() << " зашифровал и отправил сообщение -> " << u1.GetUserName() << ": " << message << endl;
        u1.ReceiveEncryptedMessageByRSA(message);
        message = u1.GetOriginalMessageByRSA();//отладить почему половина символов не появляются, большие цифры?
        cout << u1.GetUserName() << " расшифровал сообщение от -> " << u1.GetUserName() << ": " << message << endl;
        break;
    default:
        cout << "Ошибка" << endl;
        break;
    }
}

void ChatByCaesar(User u1, User u2)
{
    int closeKeyCaesar;
    int choice;
    string message;
    //создание секретного ключа
    cout << "Введите ключ для шифрования Цезаря" << endl
        << "Ключ = ";

    cin >> closeKeyCaesar;
    
    u1.SetCloseKeyCaesar(closeKeyCaesar);
    u2.SetCloseKeyCaesar(closeKeyCaesar);

    // передача сообщения

    cout << "Кто будет отправлять сообщение?" << endl
        << "1) " << u1.GetUserName() << endl
        << "2) " << u2.GetUserName() << endl;

    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << u1.GetUserName() << " отправляет сообщение -> " << u2.GetUserName() << endl
            << "Введите сообщение (только малые буквы английского алфавита без пробелов и не более 100 символов)" << endl
            << u1.GetUserName() << ": ";
        cin >> message;
        u1.SetOriginalMessageToSend(message);
        message = u1.SendEncryptedMessageByCaesar();
        cout << u1.GetUserName() << " зашифровал и отправил сообщение -> " << u2.GetUserName() << ": " << message << endl;
        u2.ReceiveEncryptedMessageByCaesar(message);
        message = u2.GetOriginalReceivedMessageByCaesar();
        cout << u2.GetUserName() << " расшифровал сообщение от -> " << u1.GetUserName() << ": " << message << endl;
        break;
    case 2:
        cout << u2.GetUserName() << " отправляет сообщение -> " << u1.GetUserName() << endl
            << "Введите сообщение (только малые буквы английского алфавита без пробелов и не более 100 символов)" << endl
            << u2.GetUserName() << ": ";
        cin >> message;
        u2.SetOriginalMessageToSend(message);
        message = u2.SendEncryptedMessageByCaesar();
        cout << u2.GetUserName() << " зашифровал и отправил сообщение -> " << u1.GetUserName() << ": " << message << endl;
        u1.ReceiveEncryptedMessageByCaesar(message);
        message = u1.GetOriginalReceivedMessageByCaesar();
        cout << u1.GetUserName() << " расшифровал сообщение от -> " << u2.GetUserName() << ": " << message << endl;
        break;
    default:
        cout << "Ошибка" << endl;
        break;
    }
}

void ChatByXOR(User u1, User u2)
{
    int closeKeyXOR;
    int choice;
    unsigned int number;

    //создание секретного ключа
    cout << "Введите ключ для шифрования XOR" << endl
        << "Ключ = ";

    cin >> closeKeyXOR;

    u1.SetCloseKeyXOR(closeKeyXOR);
    u2.SetCloseKeyXOR(closeKeyXOR);

    // передача сообщения

    cout << "Кто будет отправлять число?" << endl
        << "1) " << u1.GetUserName() << endl
        << "2) " << u2.GetUserName() << endl;

    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << u1.GetUserName() << " отправляет число -> " << u2.GetUserName() << endl
            << "Введите целое неотрицательное число" << endl
            << u1.GetUserName() << ": ";
        cin >> number;
        u1.SetOriginalNumberToSend(number);
        number = u1.SendEncryptedNumberByXOR();
        cout << u1.GetUserName() << " зашифровал и отправил число -> " << u2.GetUserName() << ": " << number << endl;
        u2.ReceiveEncryptedNumberByXOR(number);
        number = u2.GetOriginalReceivedNumberByXOR();
        cout << u2.GetUserName() << " расшифровал сообщение от -> " << u1.GetUserName() << ": " << number << endl;
        break;
    case 2:
        cout << u2.GetUserName() << " отправляет число -> " << u1.GetUserName() << endl
            << "Введите целое неотрицательное число" << endl
            << u2.GetUserName() << ": ";
        cin >> number;
        u2.SetOriginalNumberToSend(number);
        number = u2.SendEncryptedNumberByXOR();
        cout << u2.GetUserName() << " зашифровал и отправил число -> " << u1.GetUserName() << ": " << number << endl;
        u1.ReceiveEncryptedNumberByXOR(number);
        number = u1.GetOriginalReceivedNumberByXOR();
        cout << u1.GetUserName() << " расшифровал сообщение от -> " << u2.GetUserName() << ": " << number << endl;
        break;
    default:
        cout << "Ошибка" << endl;
        break;
    }
}

void ChatByVigenere(User u1, User u2)
{
    string closeKeyVigenere;
    int choice;
    string message;
    //создание секретного ключа
    cout << "Введите ключ-слово для шифрования Вижинера (только малые английские буквы не более 100 символов)" << endl
        << "Ключ = ";

    cin >> closeKeyVigenere;

    u1.SetCloseKeyVigenere(closeKeyVigenere);
    u2.SetCloseKeyVigenere(closeKeyVigenere);

    // передача сообщения

    cout << "Кто будет отправлять сообщение?" << endl
        << "1) " << u1.GetUserName() << endl
        << "2) " << u2.GetUserName() << endl;

    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << u1.GetUserName() << " отправляет сообщение -> " << u2.GetUserName() << endl
            << "Введите сообщение (только малые буквы английского алфавита без пробелов и не более 100 символов)" << endl
            << u1.GetUserName() << ": ";
        cin >> message;
        u1.SetOriginalMessageToSend(message);
        message = u1.SendEncryptedMessageByVigenere();
        cout << u1.GetUserName() << " зашифровал и отправил сообщение -> " << u2.GetUserName() << ": " << message << endl;
        u2.ReceiveEncryptedMessageByVigenere(message);
        message = u2.GetOriginalReceivedMessageByVigenere();
        cout << u2.GetUserName() << " расшифровал сообщение от -> " << u1.GetUserName() << ": " << message << endl;
        break;
    case 2:
        cout << u2.GetUserName() << " отправляет сообщение -> " << u1.GetUserName() << endl
            << "Введите сообщение (только малые буквы английского алфавита без пробелов и не более 100 символов)" << endl
            << u2.GetUserName() << ": ";
        cin >> message;
        u2.SetOriginalMessageToSend(message);
        message = u2.SendEncryptedMessageByVigenere();
        cout << u2.GetUserName() << " зашифровал и отправил сообщение -> " << u1.GetUserName() << ": " << message << endl;
        u1.ReceiveEncryptedMessageByVigenere(message);
        message = u1.GetOriginalReceivedMessageByVigenere();
        cout << u1.GetUserName() << " расшифровал сообщение от -> " << u2.GetUserName() << ": " << message << endl;
        break;
    default:
        cout << "Ошибка" << endl;
        break;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int choice;

    User Vlad("Влад");  // первый пользователь
    User Dima("Дима");  // второй пользователь

    while (true)
    {
        cout << "Выберете алгоритм шифрования" << endl
            << "1) Шифрование RSA" << endl
            << "2) Шифрование Цезаря" << endl
            << "3) Шифрование Виженера" << endl
            << "4) Шифрование XOR" << endl;
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

