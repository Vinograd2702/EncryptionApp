#include <iostream>
#include <stdlib.h>
#include <string>
#include <cmath>
#include <vector>


#pragma once
class User
{
private:
	std::string userName; // имя пользователя
	char alphabet[26];	// алфавит (Цезарь, Виженер)

	int closeKeyCaesar;	// секретный ключ для Цезаря
	std::string closeKeyVigenere;	// секретный ключ для Виженера

	std::string originalMessageToSend;		// сообщение до шифрования, которое хотим зашифровать (Цезарь, Виженер)
	std::string encryptedMessageToSend;		// сообщение зашифрованное (Цезарь, Виженер)
	std::string encryptedReceivedMessage;	// полученное сообщение в зашифрованном виде (Цезарь, Виженер)
	std::string originalReceivedMessage;	// полученное сообщение в расшифрованном виде (Цезарь, Виженер)

	bool bCloseKeyXOR[32];			// секретный ключ для XOR
	int originalNumberToSend;		// цифра до шифрования, которое хотим зашифровать (XOR)
	int encryptedNumberToSend;		// цифра зашифрованная (XOR)
	int encryptedReceivedNumber;	// полученная цифра в зашифрованном виде (XOR)
	int originalReceivedNumber;		// полученная цифра в расшифрованном виде (XOR)

	int simpleP_RSA;			// первое простое число для подготовки ключей RSA
	int simpleQ_RSA;			// второе простое число для подготовки ключей RSA
	int modulRSA;				// модуль p×q (RSA) (вторая часть открытого и закрытого ключа)
	int eilerFunctionRSA;		// число по формуле эйлера (p-1)×(q-1) (RSA)
	int eilerNumberRSA;			// выбраное число e	(i) оно должно быть простое, 
								//					(ii) оно должно быть меньше φ
								//					(iii) оно должно быть взаимно простое с φ
								// первая часть открытого ключа
	int reversEilerNumberRSA;	// число - обратное к e (первая чась закрытого ключа)
	
	bool SimpleNumberChek(int n);		// проверка что число простое


public:
	User(std::string userName);
	~User();
	std::string GetUserName();	// получить имя пользователя
	void SetOriginalMessageToSend(std::string originalMessageToSend); // создание пользователем сообщения для отправки
	void SetOriginalNumberToSend(unsigned int originalNumberToSend);	// создание пользователем числа для отправки

	//Методы Цезаря
	void SetCloseKeyCaesar(int closeKeyCaesar);	// установить пользователью ключ Цезаря
	std::string SendEncryptedMessageByCaesar(); // отправка зашифрованного сообщения Цезарем
	void ReceiveEncryptedMessageByCaesar(std::string encryptedReceivedMessage);	// получить зашифрованное сообщение Цезарем
	std::string GetOriginalReceivedMessageByCaesar();	// перевести полученное слово Цезарем

	//Методы XOR
	void SetCloseKeyXOR(unsigned int closeKeyXOR);	// установить пользователю ключ XOR
	int SendEncryptedNumberByXOR();					// отправка зашифрованного сообщения алгоритмом XOR
	void ReceiveEncryptedNumberByXOR(unsigned int encryptedReceivedNumber);	// получение зашифрованного сообщения алгоритмом XOR
	int GetOriginalReceivedNumberByXOR();	// расшифровка полученного сообщения алгоритмом XOR

	//Методы Виженера
	void SetCloseKeyVigenere(std::string closeKeyVigenere);	// установить пользователью ключ-слово Виженера
	std::string SendEncryptedMessageByVigenere();			// отправка зашифрованного сообщения Виженером
	void ReceiveEncryptedMessageByVigenere(std::string encryptedReceivedMessage);	// получить зашифрованное сообщение Виженером
	std::string GetOriginalReceivedMessageByVigenere();		// перевести полученное слово Виженером

	//Методы RSA
	void SetParametersRSA(int p, int q);	// установка параметров RSA
	int GetEilerNumberRSA();	// передача первой части открытого ключа
	int GetModulRSA();			// второй части открытого ключа
	int GetReversEilerNumberRSA(); //демонстрация вычисленного закрытого ключа, при реальном обмене данных нельзя сообщать
	void SetOpenKeyRSA(int eilerNumberRSA, int modulRSA); // получение открытого ключа для шифрования
	std::string SendEncryptedMessageByRSA();
	void ReceiveEncryptedMessageByRSA(std::string encryptedReceivedMessage);

	std::string GetOriginalMessageByRSA();//отладить метод
};

