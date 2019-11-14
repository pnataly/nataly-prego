#include "mu_test.h"
#include "Server.h"

using namespace smarthome;


UNIT(server)
	string configFile = "configFile.txt";
	
	Server server;
	server.Start(configFile);
	server.Run();
	
END_UNIT 


TEST_SUITE(C Unit Test Demo for mu_test!) 
	TEST(server)
END_SUITE

