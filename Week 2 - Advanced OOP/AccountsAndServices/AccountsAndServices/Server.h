#pragma once
#include <iostream>
#include "Account.h"
#include <vector>

//class LoginServiceDelegate {
//public:
//	virtual void invalidUsername() = 0;
//	virtual void invalidPassword() = 0;
//	virtual void succesfulLogin() = 0;
//};
//
//class RegisterServiceDelegate {
//public:
//	virtual void existingAccount() = 0;
//	virtual void succesfulRegister() = 0;
//};

class SuccesfulRegisterObserver {
public:
	virtual void update() = 0;
};

class SuccesfulRegisterSubject {
private:
	std::vector<SuccesfulRegisterObserver*> observers;
public:
	void addObserver(SuccesfulRegisterObserver* observer) {
		this->observers.push_back(observer);
	}

	void notify() {
		for (SuccesfulRegisterObserver* observer : observers) {
			observer->update();
		}
	}
};

class Server {
private:
	SuccesfulRegisterSubject* succesfulReg;
public:
	//Server() : l_service(this),r_service(this) {}

	Server() {
		succesfulReg = new SuccesfulRegisterSubject();
	}
	//void invalidUsername() {
	//	std::cout << "Wrong username!" << std::endl;
	//}
	//void invalidPassword() {
	//	std::cout << "Wrong password!" << std::endl;
	//}
	//void existingAccount() {
	//	std::cout << "Account with that username already exists!" << std::endl;
	//}
	//void succesfulRegister() {
	//	std::cout << "Succesful register!" << std::endl;
	//	l_service.login_user(Account::getInstance()->getUsername(),Account::getInstance()->getPassword());
	//}
	//void succesfulLogin() {
	//	std::cout << "Succesful login!" << std::endl;
	//}

	//void login(const std::string& username,const std::string& password) {
	//	l_service.login_user(username,password);
	//}
	//
	void reg() {
		if (Account::getInstance()->getRegisteredStatus()) 
		{
			std::cout << "Account already exists :(\n";
			return;
		}
		Account::getInstance()->setRegisteredStatus(true);
		this->succesfulReg->notify();
	}

	void addObserverSuccesfulRegistration(SuccesfulRegisterObserver* observer) {
		this->succesfulReg->addObserver(observer);
	}
};
