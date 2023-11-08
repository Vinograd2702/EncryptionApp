#include "User.h"


User::User(std::string userName)
{
    this->userName = userName;
    alphabet[0] = 'a';
    alphabet[1] = 'b';
    alphabet[2] = 'c';
    alphabet[3] = 'd';
    alphabet[4] = 'e';
    alphabet[5] = 'f';
    alphabet[6] = 'g';
    alphabet[7] = 'h';
    alphabet[8] = 'i';
    alphabet[9] = 'j';
    alphabet[10] = 'k';
    alphabet[11] = 'l';
    alphabet[12] = 'm';
    alphabet[13] = 'n';
    alphabet[14] = 'o';
    alphabet[15] = 'p';
    alphabet[16] = 'q';
    alphabet[17] = 'r';
    alphabet[18] = 's';
    alphabet[19] = 't';
    alphabet[20] = 'u';
    alphabet[21] = 'v';
    alphabet[22] = 'w';
    alphabet[23] = 'x';
    alphabet[24] = 'y';
    alphabet[25] = 'z';
}

User::~User()
{
}

std::string User::GetUserName()
{
    return userName;
}

void User::SetOriginalMessageToSend(std::string originalMessageToSend)
{
	this->originalMessageToSend = originalMessageToSend;
}

void User::SetCloseKeyCaesar(int closeKeyCaesar)
{
    if (closeKeyCaesar >= 0)
    {
        this->closeKeyCaesar = closeKeyCaesar % 26;
    }
    else
    {
        this->closeKeyCaesar = 26 - (closeKeyCaesar%26);
    }
}

std::string User::SendEncryptedMessageByCaesar()
{
    int arrEncryptedMessage[100];

    for (int i = 0; i < originalMessageToSend.size(); i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (originalMessageToSend[i] == alphabet[j])
            {
                arrEncryptedMessage[i] = j;
                break;
            }
        }
    }

    for (int i = 0; i < 100; i++)
    {
        if (arrEncryptedMessage[i] >= 0)
        {
            arrEncryptedMessage[i] = (arrEncryptedMessage[i] + closeKeyCaesar) % 26;
        }
        else
        {
            break;
        }
    }

    for (int i = 0; i < 100; i++)
    {
        if (arrEncryptedMessage[i] >= 0)
        {
            encryptedMessageToSend += alphabet[arrEncryptedMessage[i]];
        }
    }

    return encryptedMessageToSend;
}

void User::ReceiveEncryptedMessageByCaesar(std::string encryptedReceivedMessage)
{
    this->encryptedReceivedMessage = encryptedReceivedMessage;
}

std::string User::GetOriginalReceivedMessageByCaesar()
{
    {
        int arrEncryptedMessage[100];

        for (int i = 0; i < encryptedReceivedMessage.size(); i++)
        {
            for (int j = 0; j < 26; j++)
            {
                if (encryptedReceivedMessage[i] == alphabet[j])
                {
                    arrEncryptedMessage[i] = j;
                    break;
                }
            }
        }

        for (int i = 0; i < 100; i++)
        {
            if (arrEncryptedMessage[i] >= 0)
            {
                if (arrEncryptedMessage[i] - closeKeyCaesar >= 0)
                {
                    arrEncryptedMessage[i] = (arrEncryptedMessage[i] - closeKeyCaesar) % 26;
                }
                else
                {
                    arrEncryptedMessage[i] = arrEncryptedMessage[i] + 26 - closeKeyCaesar;
                }
            }
            else
            {
                break;
            }
        }

        for (int i = 0; i < 100; i++)
        {
            if (arrEncryptedMessage[i] >= 0)
            {
                originalReceivedMessage += alphabet[arrEncryptedMessage[i]];
            }
        }

        return originalReceivedMessage;
    }
}

void User::SetOriginalNumberToSend(unsigned int originalNumberToSend)
{
    this->originalNumberToSend = originalNumberToSend;
}

void User::SetCloseKeyXOR(unsigned int closeKeyXOR)
{
    int buff = closeKeyXOR;
    for (int i = 31; i >= 0; i--)
    {
        bCloseKeyXOR[i] = buff % 2;
        buff /= 2;
    }
}

int User::SendEncryptedNumberByXOR() 
{
    encryptedNumberToSend = 0;
    int buff = originalNumberToSend;
    bool bOriginalNumberToSend[32];
    //переводим число в битовый массив
    for (int i = 31; i >= 0; i--)
    {
        bOriginalNumberToSend[i] = buff % 2;
        buff /= 2;
    }
    //шифруем маской
    for (int i = 0; i < 32; i++)
    {
        encryptedNumberToSend += ((bOriginalNumberToSend[i] + bCloseKeyXOR[i])%2) * pow(2,(31-i));
    }

    return encryptedNumberToSend;
}

void User::ReceiveEncryptedNumberByXOR(unsigned int encryptedReceivedNumber)
{
    this->encryptedReceivedNumber = encryptedReceivedNumber;
}

int User::GetOriginalReceivedNumberByXOR()
{
    originalReceivedNumber = 0;
    int buff = encryptedReceivedNumber;
    bool bEncryptedReceivedNumber[32];
    //переводим число в битовый массив
    for (int i = 31; i >= 0; i--)
    {
        bEncryptedReceivedNumber[i] = buff % 2;
        buff /= 2;
    }
    //шифруем маской
    for (int i = 0; i < 32; i++)
    {
        originalReceivedNumber += ((bEncryptedReceivedNumber[i] + bCloseKeyXOR[i]) % 2) * pow(2, (31 - i));
    }

    return originalReceivedNumber;
}

void User::SetCloseKeyVigenere(std::string closeKeyVigenere) 
{
    this->closeKeyVigenere = closeKeyVigenere;
}

std::string User::SendEncryptedMessageByVigenere()
{
    int arrEncryptedMessage[100];// зашифрованное сообщение в формате массива int
    int completedCloseKeyVigenere[100]; //дополненное ключевое слово совпадающее с длинной шифруемого слова
    
    //// заполн€ю массив незначищими -1
    //for (int i = 0; i < 100; i++)
    //{
    //    completedCloseKeyVigenere[i] = -1;
    //}
    //дополн€ю ключевое слово до длинны слова шифруемого
    for (int i = 0; i < originalMessageToSend.size(); i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (closeKeyVigenere[i % closeKeyVigenere.size()] == alphabet[j])
            {
                completedCloseKeyVigenere[i] = j;
                break;
            }
        }
    }

    // перевожу слово в int массисв по алфавиту
    for (int i = 0; i < originalMessageToSend.size(); i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (originalMessageToSend[i] == alphabet[j])
            {
                arrEncryptedMessage[i] = j;
                break;
            }
        }
    }

    // шифрую сообщеие
    for (int i = 0; i < 100; i++)
    {
        if (arrEncryptedMessage[i] >= 0)
        {
        arrEncryptedMessage[i] = (arrEncryptedMessage[i] + completedCloseKeyVigenere[i]) % 26;
        }
        else
        {
        break;
        }
    }

    // фрмирую зашифрованное слово
    for (int i = 0; i < 100; i++)
    {
        if (arrEncryptedMessage[i] >= 0)
        {
            encryptedMessageToSend += alphabet[arrEncryptedMessage[i]];
        }
    }

    return encryptedMessageToSend;
}

void User::ReceiveEncryptedMessageByVigenere(std::string encryptedReceivedMessage)
{
    this->encryptedReceivedMessage = encryptedReceivedMessage;
}

std::string User::GetOriginalReceivedMessageByVigenere()
{
    {
        int arrEncryptedMessage[100];
        int completedCloseKeyVigenere[100]; //дополненное ключевое слово совпадающее с длинной шифруемого слова

        //дополн€ю ключевое слово до длинны слова шифруемого
        for (int i = 0; i < encryptedReceivedMessage.size(); i++)
        {
            for (int j = 0; j < 26; j++)
            {
                if (closeKeyVigenere[i % closeKeyVigenere.size()] == alphabet[j])
                {
                    completedCloseKeyVigenere[i] = j;
                    break;
                }
            }
        }

        // перевожу слово в int массисв по алфавиту
        for (int i = 0; i < encryptedReceivedMessage.size(); i++)
        {
            for (int j = 0; j < 26; j++)
            {
                if (encryptedReceivedMessage[i] == alphabet[j])
                {
                    arrEncryptedMessage[i] = j;
                    break;
                }
            }
        }

        // шифрую сообщеие
        for (int i = 0; i < 100; i++)
        {
            if (arrEncryptedMessage[i] >= 0)
            {
                if (arrEncryptedMessage[i] - completedCloseKeyVigenere[i] >= 0)
                {
                    arrEncryptedMessage[i] = (arrEncryptedMessage[i] - completedCloseKeyVigenere[i]) % 26;
                }
                else
                {
                    arrEncryptedMessage[i] = arrEncryptedMessage[i] + 26 - completedCloseKeyVigenere[i];
                }
            }
            else
            {
                break;
            }
        }

        for (int i = 0; i < 100; i++)
        {
            if (arrEncryptedMessage[i] >= 0)
            {
                originalReceivedMessage += alphabet[arrEncryptedMessage[i]];
            }
        }

        return originalReceivedMessage;
    }
}

bool User::SimpleNumberChek(int n)
{
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void User::SetParametersRSA(int p, int q)
{
    this->simpleP_RSA = p;
    this->simpleQ_RSA = q;
    modulRSA = simpleP_RSA * simpleQ_RSA;
    eilerFunctionRSA = (simpleP_RSA - 1) * (simpleQ_RSA - 1);

    std::vector<int> simpleNumbers;

    //дл€ всех числе от 2 до ф
    for (int i = 2; i < eilerFunctionRSA; i++)
    {
        //если число простое
        if (SimpleNumberChek(i))
        {
            //если число взаимно простое с ф
            if (eilerFunctionRSA % i != 0)
            {
                //добавл€ем его в вектор
                simpleNumbers.push_back(i);
            }
        }
    }
    //берем любое число из вектора
    eilerNumberRSA = simpleNumbers[rand() % simpleNumbers.size()];
    int var = 0;
    for (int i = 0; i < 100000; i++)
    {

        if ((i * eilerNumberRSA) % eilerFunctionRSA == 1)
        {
            var++;
            if (var == 2)
            {
                reversEilerNumberRSA = i;
                break;
            }
            
        }

    }
}

int User::GetEilerNumberRSA()
{
    return eilerNumberRSA;
}

int User::GetModulRSA()
{
    return modulRSA;
}

int User::GetReversEilerNumberRSA()
{
    return reversEilerNumberRSA;
}

void User::SetOpenKeyRSA(int eilerNumberRSA, int modulRSA)
{
    this->eilerNumberRSA = eilerNumberRSA;
    this->modulRSA = modulRSA;
}

std::string User::SendEncryptedMessageByRSA()
{
    int arrEncryptedMessage[100];
    //переведи сообщение по алфавиту
    for (int i = 0; i < originalMessageToSend.size(); i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (originalMessageToSend[i] == alphabet[j])
            {
                arrEncryptedMessage[i] = j;
                break;
            }
        }
    }
    //зашифровали обычным ключем
    for (int i = 0; i < 100; i++)
    {
        if (arrEncryptedMessage[i] >= 0)
        {
            //arrEncryptedMessage[i] = pow(arrEncryptedMessage[i], this->eilerNumberRSA) % modulRSA;
            unsigned long long dummy = pow(arrEncryptedMessage[i], this->eilerNumberRSA);
            arrEncryptedMessage[i] = dummy % modulRSA;
        }
        else
        {
            break;
        }
    }
    //получил слово и отправил 
    for (int i = 0; i < 100; i++)
    {
        if (arrEncryptedMessage[i] >= 0)
        {
            encryptedMessageToSend += alphabet[arrEncryptedMessage[i]];
        }
    }

    return encryptedMessageToSend;
}

void User::ReceiveEncryptedMessageByRSA(std::string encryptedReceivedMessage)
{
    this->encryptedReceivedMessage = encryptedReceivedMessage;
}

std::string User::GetOriginalMessageByRSA()
{
    int arrEncryptedMessage[100];
    //переведи кодированное сообщение по алфавиту
    for (int i = 0; i < encryptedReceivedMessage.size(); i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (encryptedReceivedMessage[i] == alphabet[j])
            {
                arrEncryptedMessage[i] = j;
                break;
            }
        }
    }
    //расшифровали закрытым ключем
    for (int i = 0; i < 100; i++)
    {
        if (arrEncryptedMessage[i] >= 0)
        {
            unsigned long long dummy = pow(arrEncryptedMessage[i], this->reversEilerNumberRSA);
            arrEncryptedMessage[i] = dummy % modulRSA;
        }
        else
        {
            break;
        }
    }
    //преобразовали обратно в текст
    for (int i = 0; i < 100; i++)
    {
        if (arrEncryptedMessage[i] >= 0)
        {
            originalReceivedMessage += alphabet[arrEncryptedMessage[i]];
        }
    }

    return originalReceivedMessage;
}