#pragma once
#include <iostream>
#include "Account.h"

class LoginServiceDelegate {
public:
	virtual void invalidUsername() = 0;
	virtual void invalidPassword() = 0;
	virtual void succesfulLogin() = 0;
};

class RegisterServiceDelegate {
public:
	virtual void existingAccount() = 0;
	virtual void succesfulRegister() = 0;
};

class LoginService {
private:
	LoginServiceDelegate* delegate;
public:
	LoginService(LoginServiceDelegate* del = nullptr) : delegate(del) {}

	void login_user(const std::string& username, const std::string& password) 
	{
		if (username != username) {
			delegate->invalidUsername();
			return;
		}
		
		if (Account::getInstance()->getUsername() != password) {
			delegate->invalidPassword();
			return;
		}
		
		delegate->succesfulLogin();
	}
};

class RegisterService {
private:
	RegisterServiceDelegate* delegate;
public:
	RegisterService(RegisterServiceDelegate* del = nullptr) : delegate(del){}

	void register_user() {
		if (Account::getInstance()->getRegisteredStatus()) {
			delegate->existingAccount();
			return;
		}
		delegate->succesfulRegister();
	}
};

class Server : LoginServiceDelegate, RegisterServiceDelegate {
private:
	LoginService* l_service;
	RegisterService* r_service;
public:
	Server() : l_service(nullptr),r_service(nullptr) {}

	void invalidUsername() {
		std::cout << "Wrong username!" << std::endl;
	}
	void invalidPassword() {
		std::cout << "Wrong password!" << std::endl;
	}
	void existingAccount() {
		std::cout << "Account with that username already exists!" << std::endl;
	}
	void succesfulRegister() {
		std::cout << "Succesful register!" << std::endl;
		l_service->login_user(Account::getInstance()->getUsername(),Account::getInstance()->getPassword());
	}
	void succesfulLogin() {
		std::cout << "Succesful login!" << std::endl;
	}

	void login(const std::string& username,const std::string& password) {
		l_service->login_user(username,password);
	}
	
	void reg() {
		r_service->register_user();
	}
};
