//Мост - структурный паттерн проектирования, который разделяет один или несколько классов на две отдельные 
//иерархии – абстракцию и реализацию, позволяя изменять их независимо друг от друга.

//В качестве примера рассмотрим отправку текстового сообщения. Оно может быть отправлено по почте и в смс, а так же быть открытым или зашифрованным.

#include <iostream> 
#include <string> 

//Интерфейс отправки соощения
class MessageSender {               
public:
    virtual void sendMessage(const std::string& message) = 0;
};

//Отправка сообщения по почте
class EmailSender : public MessageSender {
public:
    void sendMessage(const std::string& message) override {
        std::cout << "Sending email: " << message << std::endl;
    }
};

//Отправка сообщения в смс
class SMSSender : public MessageSender {
public:
    void sendMessage(const std::string& message) override {
        std::cout << "Sending SMS: " << message << std::endl;
    }
};

//Абстракция сообщения
class Message {
protected:
    MessageSender* sender;

public:
    void setSender(MessageSender* sender) {
        this->sender = sender;
    }

    virtual void send(const std::string& message) = 0;
};

//Текстовое сообщение
class TextMessage : public Message {
public:
    void send(const std::string& message) override {
        std::cout << "Text Message: " << message << std::endl;
        sender->sendMessage(message);
    }
};

//Зашифрованное сообщение
class EncryptedMessage : public Message {
public:
    void send(const std::string& message) override {
        std::cout << "Encrypted Message: " << message << std::endl;
        sender->sendMessage(encryptMessage(message));
    }

    std::string encryptMessage(const std::string& message) {
        // Perform encryption logic 
        return "Encrypted: " + message;
    }
};
