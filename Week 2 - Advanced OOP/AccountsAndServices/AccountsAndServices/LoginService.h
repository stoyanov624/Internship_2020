#pragma once
#include "Server.h"

class LoginService : public SuccesfulRegisterObserver {
private:
	//LoginServiceDelegate* delegate;
public:
	//LoginService(LoginServiceDelegate* del) : delegate(del) {}

	void update() {
		std::cout << "Login service notified a succesful registration!\n";
	}

	void login_user(const std::string& username, const std::string& password)
	{
		if (Account::getInstance()->getUsername() != username) {
			//delegate->invalidUsername();
			return;
		}

		if (Account::getInstance()->getPassword() != password) {
			//delegate->invalidPassword();
			return;
		}

		//delegate->succesfulLogin();
	}
};