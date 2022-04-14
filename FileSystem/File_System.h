#ifndef __FILE_SYSTEM_H__
#define __FILE_SYSTEM_H__

#include <string>

class Node;
class File_System
{
public:
	File_System();
	Node* find(const std::string& path);
	bool add(const std::string& path, bool is_dir);
	bool change_dir(const std::string& path);
	void show_path(const std::string& path);
public:
	Node* root;
	Node* cwd;
private:
	Node* find_impl(Node* directory, const std::string& path);
	bool add_impl(Node* directory, const std::string& path, bool is_dir);

};

#endif

