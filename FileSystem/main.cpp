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

	return 0;
}