//Существует международный стандарт измерений - система СИ
//Однако данные не всегда представлены согласно этим стандартам
//Создадим класс Adapter, представляющий данные разрозненного формата в этой системе

#include <iostream> 

// Интерфейс, представляющий систему СИ 
class SiUnit {
public:
    virtual double getValue() const = 0;
};

// Классы, представляющие различные единицы измерения 

// Дюймы 
class InchUnit {
public:
    InchUnit(double value) : m_value(value) {}

    double getValue() const {
        return m_value;
    }

private:
    double m_value;
};

// Милиметры 
class MillimeterUnit {
public:
    MillimeterUnit(double value) : m_value(value) {}

    double getValue() const {
        return m_value;
    }

private:
    double m_value;
};

// Адаптер для перевода дюймов в систему СИ 
class InchAdapter : public SiUnit {
public:
    InchAdapter(const InchUnit& inchUnit) : m_inchUnit(inchUnit) {}

    double getValue() const {
        // Перевод дюймов в метры (1 дюйм = 0.0254 метра) 
        return m_inchUnit.getValue() * 0.0254;
    }

private:
    InchUnit m_inchUnit;
};

// Адаптер для перевода миллиметров в систему СИ 
class MillimeterAdapter : public SiUnit {
public:
    MillimeterAdapter(const MillimeterUnit& mmUnit) : m_mmUnit(mmUnit) {}

    double getValue() const {
        // Перевод миллиметров в метры (1 миллиметр = 0.001 метра) 
        return m_mmUnit.getValue() * 0.001;
    }

private:
    MillimeterUnit m_mmUnit;
};
