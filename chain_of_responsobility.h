#ifndef CHAIN_OF_RESPONSOBILITY_H
#define CHAIN_OF_RESPONSOBILITY_H

#include <iostream>
#include <vector>

/**
 * Интерфейс Обработчика объявляет метод построения цепочки обработчиков. Он
 * также объявляет метод для выполнения запроса.
 */
class Handler {
public:
	virtual Handler *SetNext(Handler *handler) = 0;
	virtual std::string Handle(std::string request) = 0;
};
/**
 * Поведение цепочки по умолчанию может быть реализовано внутри базового класса
 * обработчика.
 */
class AbstractHandler : public Handler {
	/**
   * @var Handler
   */
private:
	Handler *next_handler_;

public:
	AbstractHandler() : next_handler_(nullptr) {
	}
	Handler *SetNext(Handler *handler) override {
		this->next_handler_ = handler;
		// Возврат обработчика отсюда позволит связать обработчики простым способом,
		// вот так:
		// $monkey->setNext($squirrel)->setNext($dog);
		return handler;
	}
	std::string Handle(std::string request) override {
		if (this->next_handler_) {
			return this->next_handler_->Handle(request);
		}

		return {};
	}
	virtual ~AbstractHandler() {}
};
/**
 * Все Конкретные Обработчики либо обрабатывают запрос, либо передают его
 * следующему обработчику в цепочке.
 */
class MonkeyHandler : public AbstractHandler {
public:
	std::string Handle(std::string request) override {
		if (request == "Banana") {
			return "Monkey: I'll eat the " + request + ".\n";
		} else {
			return AbstractHandler::Handle(request);
		}
	}
};
class SquirrelHandler : public AbstractHandler {
public:
	std::string Handle(std::string request) override {
		if (request == "Nut") {
			return "Squirrel: I'll eat the " + request + ".\n";
		} else {
			return AbstractHandler::Handle(request);
		}
	}
};
class DogHandler : public AbstractHandler {
public:
	std::string Handle(std::string request) override {
		if (request == "MeatBall") {
			return "Dog: I'll eat the " + request + ".\n";
		} else {
			return AbstractHandler::Handle(request);
		}
	}
};
/**
 * Обычно клиентский код приспособлен для работы с единственным обработчиком. В
 * большинстве случаев клиенту даже неизвестно, что этот обработчик является
 * частью цепочки.
 */
void ClientCode(Handler &handler) {
	std::vector<std::string> food = {"Nut", "Banana", "Cup of coffee"};
	for (const std::string &f : food) {
		std::cout << "Client: Who wants a " << f << "?\n";
		const std::string result = handler.Handle(f);
		if (!result.empty()) {
			std::cout << "  " << result;
		} else {
			std::cout << "  " << f << " was left untouched.\n";
		}
	}
}
/**
 * Другая часть клиентского кода создает саму цепочку.
 */

#endif // CHAIN_OF_RESPONSOBILITY_H
