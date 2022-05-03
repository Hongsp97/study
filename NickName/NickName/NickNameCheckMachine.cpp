#include "NickNameCheckMachine.h"

#include <iostream>

NickNameCheckMachine::NickNameCheckMachine()
{
	run();
}

void NickNameCheckMachine::run()
{
	std::regex re("([a-zA-Z]){4,16}|([°¡-ÆR]){2,8}");
	int isRun = 1;
	while (isRun)
	{
		std::string NickName;
		std::cout << "´Ð³×ÀÓÀ» Àû¾îÁÖ¼¼¿ä" << std::endl;
		std::cin >> NickName;
		std::cout << std::endl;

		checkNickName(NickName, re);

		std::cout << "Á¾·áÇÏ½Ã°Ú½À´Ï±î? Yes : 0   No : 1" << std::endl;
		std::cin >> isRun;

	}
}

void NickNameCheckMachine::checkNickName(const std::string _string, std::regex _re)
{
	if (std::regex_match(_string, _re))
	{
		std::cout << "»ç¿ë °¡´É" << std::endl;
	}
	else
	{
		std::cout << "»ç¿ë ºÒ°¡´É" << std::endl;
	}
}

