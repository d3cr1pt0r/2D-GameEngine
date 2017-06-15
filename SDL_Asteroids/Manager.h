#pragma once
class Manager {

public:
	Manager* getInstance();

private:
	Manager();

private:
	static Manager* instance_;
};

