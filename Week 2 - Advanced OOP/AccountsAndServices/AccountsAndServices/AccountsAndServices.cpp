#include <iostream>
#include "Account.h"
#include "Server.h"

int main() {

	std::string username = "sasho";
	std::string password = "1234";

	Account::getInstance(username, password);
	Server* moodle = new Server();
	moodle->run();
}