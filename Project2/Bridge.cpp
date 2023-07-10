//���� - ����������� ������� ��������������, ������� ��������� ���� ��� ��������� ������� �� ��� ��������� 
//�������� � ���������� � ����������, �������� �������� �� ���������� ���� �� �����.

//� �������� ������� ���������� �������� ���������� ���������. ��� ����� ���� ���������� �� ����� � � ���, � ��� �� ���� �������� ��� �������������.

#include <iostream> 
#include <string> 

//��������� �������� ��������
class MessageSender {               
public:
    virtual void sendMessage(const std::string& message) = 0;
};

//�������� ��������� �� �����
class EmailSender : public MessageSender {
public:
    void sendMessage(const std::string& message) override {
        std::cout << "Sending email: " << message << std::endl;
    }
};

//�������� ��������� � ���
class SMSSender : public MessageSender {
public:
    void sendMessage(const std::string& message) override {
        std::cout << "Sending SMS: " << message << std::endl;
    }
};

//���������� ���������
class Message {
protected:
    MessageSender* sender;

public:
    void setSender(MessageSender* sender) {
        this->sender = sender;
    }

    virtual void send(const std::string& message) = 0;
};

//��������� ���������
class TextMessage : public Message {
public:
    void send(const std::string& message) override {
        std::cout << "Text Message: " << message << std::endl;
        sender->sendMessage(message);
    }
};

//������������� ���������
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
