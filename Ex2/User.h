#pragma once
#include "DeviceList.h"
#include <string>

class User
{
public:
	void init(const unsigned int id, const std::string username, const unsigned int age);
	void clear();

	unsigned int getID() const;
	std::string getUserName() const;
	unsigned int getAge() const;
	DevicesList& getDevices();

	void addDevice(const  Device newDevice);
	bool checkIfDevicesAreOn()const;

private:

	unsigned int _id;
	std::string _username;
	unsigned int _age;
	DevicesList _devices;
};