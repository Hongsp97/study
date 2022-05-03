#include "NickNameCheckMachine.h"

#include <iostream>

NickNameCheckMachine::NickNameCheckMachine()
{
	run();
}

void NickNameCheckMachine::run()
{
	std::regex re("([a-zA-Z]){4,16}|([��-�R]){2,8}");
	int isRun = 1;
	while (isRun)
	{
		std::string NickName;
		std::cout << "�г����� �����ּ���" << std::endl;
		std::cin >> NickName;
		std::cout << std::endl;

		checkNickName(NickName, re);

		std::cout << "�����Ͻðڽ��ϱ�? Yes : 0   No : 1" << std::endl;
		std::cin >> isRun;

	}
}

void NickNameCheckMachine::checkNickName(const std::string _string, std::regex _re)
{
	if (std::regex_match(_string, _re))
	{
		std::cout << "��� ����" << std::endl;
	}
	else
	{
		std::cout << "��� �Ұ���" << std::endl;
	}
}

