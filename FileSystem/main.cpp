#include <iostream>

#include "File_System.h"


int main()
{
	File_System* fs = new File_System();
	fs->add("usr", true);
	fs->add("etc", true);
	fs->add("var", true);
	fs->add("tmp_file", false);
	
	std::cout << "\"/\"�� ����/���丮 ���:" << std::endl;
	fs->show_path("/");

	std::cout << std::endl;
	fs->change_dir("usr");
	fs->add("gilbut", true);
	fs->add("gilbut/Downloads", true);
	fs->add("gilbut/Downloads/newFile.cpp", false);

	std::cout << "���� ���丮���� usr�� ����/���丮 ���: " << std::endl;
	fs->show_path("usr"); // 

	std::cout << "\"/usr\"�� ����/���丮 ���:" << std::endl;
	fs->show_path("/usr");

	std::cout << "\"/usr/gilbut/Downloads\"�� ����/���丮 ���" << std::endl;
	fs->show_path("/usr/gilbut/Downloads");

	return 0;
}