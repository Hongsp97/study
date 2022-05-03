#ifndef __NICKNAMECHECKMACHINE_H__
#define __NICKNAMECHECKMACHINE_H__

#include <string>
#include <regex>

class NickNameCheckMachine
{
public:
	NickNameCheckMachine();
	void run();
	void checkNickName(const std::string _string, std::regex _re);

};

#endif
