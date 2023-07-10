//���������� ������������� �������� ��������� - ������� ��
//������ ������ �� ������ ������������ �������� ���� ����������
//�������� ����� Adapter, �������������� ������ ������������� ������� � ���� �������

#include <iostream> 

// ���������, �������������� ������� �� 
class SiUnit {
public:
    virtual double getValue() const = 0;
};

// ������, �������������� ��������� ������� ��������� 

// ����� 
class InchUnit {
public:
    InchUnit(double value) : m_value(value) {}

    double getValue() const {
        return m_value;
    }

private:
    double m_value;
};

// ��������� 
class MillimeterUnit {
public:
    MillimeterUnit(double value) : m_value(value) {}

    double getValue() const {
        return m_value;
    }

private:
    double m_value;
};

// ������� ��� �������� ������ � ������� �� 
class InchAdapter : public SiUnit {
public:
    InchAdapter(const InchUnit& inchUnit) : m_inchUnit(inchUnit) {}

    double getValue() const {
        // ������� ������ � ����� (1 ���� = 0.0254 �����) 
        return m_inchUnit.getValue() * 0.0254;
    }

private:
    InchUnit m_inchUnit;
};

// ������� ��� �������� ����������� � ������� �� 
class MillimeterAdapter : public SiUnit {
public:
    MillimeterAdapter(const MillimeterUnit& mmUnit) : m_mmUnit(mmUnit) {}

    double getValue() const {
        // ������� ����������� � ����� (1 ��������� = 0.001 �����) 
        return m_mmUnit.getValue() * 0.001;
    }

private:
    MillimeterUnit m_mmUnit;
};
