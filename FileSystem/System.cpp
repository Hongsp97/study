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
			std::cout << "현재 경로는 "<< pwd() << "입니다." << std::endl;
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
	std::cout << "변경 디렉토리 이름 > ";
	std::cin >> changeName;
	if (changeName == "..")
	{
		fs->cwd = fs->cwd->parent;
		std::cout << "현재 디렉토리를 " << "/" << "로 이동합니다.\n";
	}
	else
	{
		fs->change_dir(changeName);
	}
	
}

void System::mkdir()
{
	std::string make_dir;
	std::cout << "생성 디렉토리 이름> ";
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
	std::cout << "생성 파일 이름> ";
	std::cin >> make_vi;
	fs->add(make_vi, false);
}

void System::help()
{
	std::cout << "명령어 목록 \n" << "1. ls - 현재 디렉토리에 포함된 디렉토리, 파일 출력.\n" << "2. cd - 현재 디렉토리 변경\n" << "3. mkdir - 디렉토리 생성\n" << "4. pwd - 현재 경로 출력\n" << "5. vi - 파일 생성\n" << "6. exit - 종료\n";
}

void System::exit()
{
	std::cout << "시스템을 종료합니다.";
	is_systemOn = false;
	delete(fs);
}
