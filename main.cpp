
#include "abstractFactory.h"
#include "builder.h"


#include "facade.h"
#include "flyweight.hpp"


#include "chain_of_responsobility.h"
#include "template_method.h"
#include "observer.h"

int main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;

	/////////////////////////////////////////////////
	////////////////// ПОРОЖДАЮЩИЕ //////////////////
	/////////////////////////////////////////////////


	// Паттерн Абстрактная фабрика
	// https://refactoring.guru/ru/design-patterns/abstract-factory
	std::cout << "Client: Testing client code with the first factory type:\n";
	ConcreteFactory1 *f1 = new ConcreteFactory1();
	ClientCode(*f1);
	delete f1;
	std::cout << std::endl;
	std::cout << "Client: Testing the same client code with the second factory type:\n";
	ConcreteFactory2 *f2 = new ConcreteFactory2();
	ClientCode(*f2);
	delete f2;


	// Паттерн Строитель
	// https://refactoring.guru/ru/design-patterns/builder

	Director* director= new Director();
	ClientCode(*director);
	delete director;


	/////////////////////////////////////////////////
	////////////////// Структурные //////////////////
	/////////////////////////////////////////////////


	// Паттерн Легковес
	// https://refactoring.guru/ru/design-patterns/flyweight
	FlyweightFactory *factory = new FlyweightFactory({{"Chevrolet", "Camaro2018", "pink"}, {"Mercedes Benz", "C300", "black"}, {"Mercedes Benz", "C500", "red"}, {"BMW", "M5", "red"}, {"BMW", "X6", "white"}});
	factory->ListFlyweights();
	AddCarToPoliceDatabase(*factory,"CL234IR","James Doe","BMW","M5","red");
	AddCarToPoliceDatabase(*factory,"CL234IR","James Doe","BMW","X1","red");
	factory->ListFlyweights();
	delete factory;


	// Паттерн Фасад
	// https://refactoring.guru/ru/design-patterns/facade
	Subsystem1 *subsystem1 = new Subsystem1;
	Subsystem2 *subsystem2 = new Subsystem2;
	Facade *facade = new Facade(subsystem1, subsystem2);
	ClientCode(facade);
	delete facade;



	/////////////////////////////////////////////////
	////////////////// Поведенческие ////////////////
	/////////////////////////////////////////////////

	// Паттерн Цепочка обязанностей
	// https://refactoring.guru/ru/design-patterns/facade

	MonkeyHandler *monkey = new MonkeyHandler;
	SquirrelHandler *squirrel = new SquirrelHandler;
	DogHandler *dog = new DogHandler;
	monkey->SetNext(squirrel)->SetNext(dog);

	/**
	   * Клиент должен иметь возможность отправлять запрос любому обработчику, а не
	   * только первому в цепочке.
	   */
	std::cout << "Chain: Monkey > Squirrel > Dog\n\n";
	ClientCode(*monkey);
	std::cout << "\n";
	std::cout << "Subchain: Squirrel > Dog\n\n";
	ClientCode(*squirrel);

	delete monkey;
	delete squirrel;
	delete dog;

	// Паттерн Шаблонный метод
	// https://refactoring.guru/ru/design-patterns/template-method

	std::cout << "Same client code can work with different subclasses:\n";
	ConcreteClass1 *concreteClass1 = new ConcreteClass1;
	ClientCode(concreteClass1);
	std::cout << "\n";
	std::cout << "Same client code can work with different subclasses:\n";
	ConcreteClass2 *concreteClass2 = new ConcreteClass2;
	ClientCode(concreteClass2);
	delete concreteClass1;
	delete concreteClass2;

	// Паттерн Наблюдатель // Pattern Observer
	//https://refactoring.guru/ru/design-patterns/observer

	Observer::ClientCode();

	std::cout << std::endl;
	return 0;
}
