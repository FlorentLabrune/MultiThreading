#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <unistd.h>
#include <sys/select.h>
#include <thread>

#include "Server.hpp"

using namespace std;
string key = "";

void keyPressed() {
	cout << "press enter to stop the captor" << endl;
	cin.get();
	key = "q";
}

int main(int argc, char const *argv[])
{
	Server s;
	s.start();
	thread first (keyPressed);
	while (key.compare(""))
	{
		s.sendToAll(to_string((rand()%100)).c_str(), 6);
		sleep(1);
	}
	first.join();
	s.stop();
    return 0;
}