#ifndef __SYSTEM_H__
#define __SYSTEM_H__

#include <string>

class File_System;
class System
{
public:
	System();
	void systemOn();
	void ls();
	void cd();
	void mkdir();
	std::string pwd();
	void vi();
	void help();
	void exit();

private:
	bool is_systemOn;
	File_System* fs;

};

#endif 