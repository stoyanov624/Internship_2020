#pragma once
#include <iostream>
#include <string>

class Account {
private:
	std::string username;
	std::string password;
	bool registered;
	static Account* singleton;
	
	Account(const std::string& _username, const std::string& _password, bool registered);
public:
	Account(const Account& other_account) = delete;
	Account& operator=(const Account& other_account) = delete;

	static Account* getInstance(const std::string& _username = "", const std::string& _password = "", bool _registered = false);
	void setUsername(const std::string& _username);
	void setPassword(const std::string& _password);
	void setRegisteredStatus(bool registered_status);
	const std::string& getUsername() const;
	const std::string& getPassword() const;
	bool getRegisteredStatus() const;

};

