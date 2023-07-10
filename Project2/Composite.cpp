//������� ������� � �������, ��� ��� ������ ��� ����, ����� �������� �������� �������


#include "vector"
class Component {						//��������� �������, ��������, ������� ����� ���������� � ����� ��������
public:
	virtual void OpenComponent(){}
	virtual void CloseComponent(){}
	virtual int GetNumberOfComponents(){}
};


class Composite : public Component{		//������� � ���������
public:
	virtual void OpenComponent() {}
	virtual void CloseComponent() {}
	virtual int GetNumberOfComponents() {}
	void GetNextBox(){}
	void GetChildBox(){}
private:
	std::vector<int> listOfComponents;
};



class Leaf : public Component {			//�������� �������
public:
	virtual void OpenComponent() {}
	virtual void CloseComponent() {}
	virtual int GetNumberOfComponents() {}
	void GetIsFound() {}
};