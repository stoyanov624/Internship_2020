#pragma once
#include "Server.h"

class RegisterService : public SuccesfulRegisterObserver {
private:
	Server* server;
	//RegisterServiceDelegate* delegate;
public:
	RegisterService() : server(nullptr) {}
	void update() {
		std::cout << "Register service updated a succesful registration\n";
	}

	void addServer(Server* server) {
		this->server = server;
	}
	
	void register_user() {
		server->reg();
	}
};