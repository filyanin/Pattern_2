//¬ квартире есть 4 счетчика: электроэнерги€, холодна€ и гор€ча€ вода, газ.
//—оздадим фасад дл€ сн€ти€ даннных сразу с четырех предложенных сущностей

#include <iostream>
class Electricity {					//Ёлектроэнерги€
public:
	Electricity() {					//создание счетчика
		this->counter = 0;
		this->isWorking = true;
	}
	int getCounter() {				//получение показателей
		return this->counter;
	}
private:
	bool isWorking;
	int counter;
};

class Water {
public:
	Water() {						//создание счетчика
		this->coldWaterCounter = 0;
		this->hotWaterCounter = 0;
		this->isWorking = true;
	}
	int gethotWaterCounter() {		//получение показателей
		return this->hotWaterCounter;
	}
	int getcoldWaterCounter() {		//получение показателей
		return this->coldWaterCounter;
	}

private:
	bool isWorking;
	int hotWaterCounter;
	int coldWaterCounter;
};

class Gas {
public:
	Gas() {							//создание счетчика
		this->counter = 0;
		this->isWorking = true;
	}
	int getcounter() {				//получение показателей
		return this->counter;
	}

private:
	bool isWorking;
	int counter;
};

class HousekeeperFacade {
public:
	HousekeeperFacade() {			//создание счетчиков
		this->electicity = new Electricity();
		this->gas = new Gas();
		this->water = new Water();
	}
	void GetCounters() {			//получение сразу со всех сущностей
		std::cout << "Ёлектричество: " << this->electicity->getCounter();
		std::cout << "√аз: " << this->gas->getcounter();
		std::cout << "’олодна€ вода: " << this->water->getcoldWaterCounter();
		std::cout << "√ор€ча€ вода: " << this->water->gethotWaterCounter();
	}
private:
	Electricity* electicity;
	Water* water;
	Gas* gas;
};