#include "System.h"

#include <iostream>
#include <string>

#include "File_System.h"
#include "Node.h"

System::System()
{
	fs = new File_System();
	is_systemOn = true;
	systemOn();
}


void System::systemOn()
{
	while (is_systemOn)
	{
		std::string select = "";
		std::cout << pwd() << "> ";
		std::cin >> select;
		
		if (select == "ls")
		{
			ls();
		}
		if (select == "cd")
		{
			cd();
		}
		if (select == "mkdir")
		{
			mkdir();
		} 
		if (select == "pwd")
		{
			std::cout << "���� ��δ� "<< pwd() << "�Դϴ�." << std::endl;
		}
		if (select == "vi")
		{
			vi();
		}
		if (select == "exit")
		{
			exit();
		}
		if (select == "help")
		{
			help();
		}
	}
}

void System::ls()
{
	fs->show_path(pwd());
}

void System::cd()
{
	std::string changeName;
	std::cout << "���� ���丮 �̸� > ";
	std::cin >> changeName;
	if (changeName == "..")
	{
		fs->cwd = fs->cwd->parent;
		std::cout << "���� ���丮�� " << "/" << "�� �̵��մϴ�.\n";
	}
	else
	{
		fs->change_dir(changeName);
	}
	
}

void System::mkdir()
{
	std::string make_dir;
	std::cout << "���� ���丮 �̸�> ";
	std::cin >> make_dir;
	fs->add(make_dir, true);
}

std::string System::pwd()
{
	auto tempNode = fs->cwd;
	std::string current_address = tempNode->name;
	if (tempNode->parent != NULL)
	{
		while (tempNode->parent != NULL)
		{
			std::string temp;
			if (tempNode->parent->name == "/")
			{
				temp = tempNode->parent->name + current_address;
			}
			else
			{
				temp = tempNode->parent->name + "/" + current_address;
			}
			current_address = temp;
			tempNode = tempNode->parent;
		}
	}
	return current_address;
}

void System::vi()
{
	std::string make_vi;
	std::cout << "���� ���� �̸�> ";
	std::cin >> make_vi;
	fs->add(make_vi, false);
}

void System::help()
{
	std::cout << "��ɾ� ��� \n" << "1. ls - ���� ���丮�� ���Ե� ���丮, ���� ���.\n" << "2. cd - ���� ���丮 ����\n" << "3. mkdir - ���丮 ����\n" << "4. pwd - ���� ��� ���\n" << "5. vi - ���� ����\n" << "6. exit - ����\n";
}

void System::exit()
{
	std::cout << "�ý����� �����մϴ�.";
	is_systemOn = false;
	delete(fs);
}
