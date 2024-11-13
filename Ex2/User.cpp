#include "User.h"

void User::init(const unsigned int id, const std::string username, const unsigned int age)
{
	this -> _id = id;
	_username = username;
	_age = age;
	_devices.init();
}

void User::clear()
{
	_devices.clear();
}

unsigned int User::getID() const
{
	return _id;
}

std::string User::getUserName() const
{
	return this->_username;
}

unsigned int User::getAge() const
{
	return _age;
}

DevicesList& User::getDevices()
{
	return _devices;
}

void User::addDevice(const  Device newDevice)
{
	// calls the add method of DeviceList class
	_devices.add(newDevice);
}

bool User::checkIfDevicesAreOn()const
{
	DeviceNode* device = _devices.get_first();
	bool on = true;
	while (device != nullptr && on)
	{
		if (!(device->get_data().isActive()))
		{
			on = false;
		}
		device = device->get_next();
	}
	return on;
}

