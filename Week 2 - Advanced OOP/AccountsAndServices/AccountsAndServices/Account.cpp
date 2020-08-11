#include "Account.h"

Account::Account(const std::string& _username, const std::string& _password, bool registered) : username(_username), password(_password), registered(false) {}

void Account::setUsername(const std::string& _username) {
	username = _username;
}

void Account::setPassword(const std::string& _password) {
	password = _password;
}

void Account::setRegisteredStatus(bool _registered) {
	registered = _registered;
}

const std::string& Account::getUsername() const {
	return username;
}

const std::string& Account::getPassword() const {
	return password;
}

bool Account::getRegisteredStatus() const {
	return registered;
}

Account* Account::getInstance(const std::string& _username, const std::string& _password, bool _registered) {
	if (Account::singleton == nullptr) {
		Account::singleton = new Account(_username, _password, _registered);
	}
	return Account::singleton;
}

Account* Account::singleton = nullptr;

