//� �������� ���� 4 ��������: ��������������, �������� � ������� ����, ���.
//�������� ����� ��� ������ ������� ����� � ������� ������������ ���������

#include <iostream>
class Electricity {					//��������������
public:
	Electricity() {					//�������� ��������
		this->counter = 0;
		this->isWorking = true;
	}
	int getCounter() {				//��������� �����������
		return this->counter;
	}
private:
	bool isWorking;
	int counter;
};

class Water {
public:
	Water() {						//�������� ��������
		this->coldWaterCounter = 0;
		this->hotWaterCounter = 0;
		this->isWorking = true;
	}
	int gethotWaterCounter() {		//��������� �����������
		return this->hotWaterCounter;
	}
	int getcoldWaterCounter() {		//��������� �����������
		return this->coldWaterCounter;
	}

private:
	bool isWorking;
	int hotWaterCounter;
	int coldWaterCounter;
};

class Gas {
public:
	Gas() {							//�������� ��������
		this->counter = 0;
		this->isWorking = true;
	}
	int getcounter() {				//��������� �����������
		return this->counter;
	}

private:
	bool isWorking;
	int counter;
};

class HousekeeperFacade {
public:
	HousekeeperFacade() {			//�������� ���������
		this->electicity = new Electricity();
		this->gas = new Gas();
		this->water = new Water();
	}
	void GetCounters() {			//��������� ����� �� ���� ���������
		std::cout << "�������������: " << this->electicity->getCounter();
		std::cout << "���: " << this->gas->getcounter();
		std::cout << "�������� ����: " << this->water->getcoldWaterCounter();
		std::cout << "������� ����: " << this->water->gethotWaterCounter();
	}
private:
	Electricity* electicity;
	Water* water;
	Gas* gas;
};