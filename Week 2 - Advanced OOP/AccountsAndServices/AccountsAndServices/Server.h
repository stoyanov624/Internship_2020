#pragma once
#include "Account.h"
#include <iostream>
#include <vector>
#include <string>
#include <assert.h>

// Delegates
class LoginServiceDelegate {
public:
	virtual void wrongUsername() = 0;
	virtual void wrongPassword() = 0;
};

class RegisterServiceDelegate {
public:
	virtual void usernameTaken() = 0;
	virtual void successfullyRegistered() = 0;
};

// Observers
class RegisteredObserver {
public:
	virtual void update(const std::string& username, const std::string& password) = 0;
};

class RegisteredSubject {
	std::vector<RegisteredObserver*> observers;
	std::string username;
	std::string password;
public:
	void addObserver(RegisteredObserver* obs) {
		this->observers.push_back(obs);
	}

	void addCredentials(const std::string& username, const std::string& password) {
		this->username = username;
		this->password = password;
	}

	void notify() {
		for (RegisteredObserver* observer : observers) {
			observer->update(username, password);
		}
	}
};

class RegisterService {
	RegisteredSubject* subject;
public:
	RegisterService() {
		subject = new RegisteredSubject();
	}

	void addRegistrationObserver(RegisteredObserver* obs) {
		subject->addObserver(obs);
	}

	void _register() {
		// ....
		// if registration was successfull
		subject->addCredentials(Account::getInstance()->getUsername(), Account::getInstance()->getPassword());
		subject->notify();
		// ....
	}
};

class LoginService : public RegisteredObserver {
public:
	LoginService() {}

	void update(const std::string& username, const std::string& password) {
		std::cout << "Login service was notified for a correct registration!" << std::endl;
	}
};

class Server : public RegisteredObserver {
	LoginService* loginService;
	RegisterService* regService;
public:
	Server() {
		loginService = new LoginService();
		regService = new RegisterService();
		regService->addRegistrationObserver(this);
	}

	void update(const std::string& username, const std::string& password) {
		std::cout << "Succesfully registered new account!" << std::endl;
		std::cout << "Username entered: " << username << std::endl;
		std::cout << "Password entered: " << password << std::endl;
		loginService->update(username, password);
	}

	void run() {
		regService->_register();
	}
};