#include <iostream>
#include "Account.h"
#include "Server.h"
#include "LoginService.h"
#include "RegisterService.h"
int main() {

	std::string username = "sasho";
	std::string password = "1234";

	Account::getInstance(username, password);
	Server* moodle = new Server();
	RegisterService reg_s;
	LoginService* log_s = new LoginService();

	moodle->addObserverSuccesfulRegistration(&reg_s);
	reg_s.addServer(moodle);
	moodle->addObserverSuccesfulRegistration(log_s);

	reg_s.register_user();
	reg_s.register_user();
	reg_s.register_user();
	
}