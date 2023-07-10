// Легковес – это структурный паттерн проектирования, который позволяет вместить бóльшее количество объектов
//  в отведённую оперативную память.Легковес экономит память, разделяя общее состояние объектов между собой, 
//  вместо хранения одинаковых данных в каждом объекте.


// Допустим, в автосалоне нужно хранить информацию о представленных авто.


#include <iostream> 
#include <vector> 
#include <memory> 

// Интерфейс для хранения информации об автомобиле
class Car {
public:
    virtual void printDetails(const std::string& color) = 0;
    virtual std::string dynamicType(){return ""; }
};

// Реализация интерфейса, хранение информации об авто. 
class ConcreteCar : public Car {
private:
    std::string model;

public:
    ConcreteCar(const std::string& model) : model(model) {}
    //вывод информации: модель и цвет. Цвет не хранится в сущности
    void printDetails(const std::string& color) override {                  
        std::cout << "Model: " << model << ", Color: " << color << std::endl;
    }
    std::string dynamicType() {
        return this->model;
    }
};

// Фабрика легковесов
class CarFactory {
private:
    std::vector<std::unique_ptr<Car>> flyweights;

public:
    Car* getCar(const std::string& model) {
        //Проверка наличия заданной модели
        for (const auto& flyweight : flyweights) {
            if (flyweight->dynamicType() == model) {
                return flyweight.get();
            }
        }

        std::unique_ptr<Car> newCar = std::make_unique<ConcreteCar>(model);
        Car* rawPointer = newCar.get();
        flyweights.push_back(std::move(newCar));
        return rawPointer;
    }
};

int main() {
    CarFactory factory;

    // Создание новых машин с использованием фабрики
    Car* car1 = factory.getCar("Sedan");
    car1->printDetails("Red");

    Car* car2 = factory.getCar("SUV");
    car2->printDetails("Blue");

    Car* car3 = factory.getCar("Sedan"); // при появлении такого же авто, ссылка возвращается на первый созданный
    car3->printDetails("Black");

    return 0;
}