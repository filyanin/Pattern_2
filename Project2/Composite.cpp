//Упакуем коробку в коробку, как это делают для того, чтобы подальше спрятать подарок


#include "vector"
class Component {						//интерфейс коробки, действия, которые можно произвести с любым объектом
public:
	virtual void OpenComponent(){}
	virtual void CloseComponent(){}
	virtual int GetNumberOfComponents(){}
};


class Composite : public Component{		//коробка с коробками
public:
	virtual void OpenComponent() {}
	virtual void CloseComponent() {}
	virtual int GetNumberOfComponents() {}
	void GetNextBox(){}
	void GetChildBox(){}
private:
	std::vector<int> listOfComponents;
};



class Leaf : public Component {			//конечная коробка
public:
	virtual void OpenComponent() {}
	virtual void CloseComponent() {}
	virtual int GetNumberOfComponents() {}
	void GetIsFound() {}
};