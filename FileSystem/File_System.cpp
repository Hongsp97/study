#include "File_System.h"

#include <iostream>

#include "Node.h"

File_System::File_System()
{
	root = new Node("/", true, NULL, {});
	cwd = root;
}

Node* File_System::find(const std::string& path)
{
	if (path[0] == '/')
	{
		return find_impl(root, path.substr(1));
	}
	else
	{
		return find_impl(cwd, path);
	}
}


bool File_System::add(const std::string& path, bool is_dir)
{
	if (path[0] == '/')
	{
		return add_impl(root, path.substr(1), is_dir);
	}
	else
	{
		return add_impl(cwd, path, is_dir);
	}
}

bool File_System::change_dir(const std::string& path)
{
	auto found = find(path);
	if (found && found->is_dir)
	{
		cwd = found;
		std::cout << "���� ���丮�� " << path << "�� �̵��մϴ�.\n";
		return true;
	}
	if (found && !found->is_dir)
	{
		std::cout << "�����̶� �̵��� �� �����ϴ�." << std::endl;
	}

	std::cout << path << "��θ� ã�� �� �����ϴ�." << std::endl;
	return false;
}

void File_System::show_path(const std::string& path)
{
	auto found = find(path);
	if (!found)
	{
		std::cout << path << " ��ΰ� �������� �ʽ��ϴ�." << std::endl;
		return;
	}

	if (found->is_dir)
	{
		for (auto child : found->children)
		{
			std::cout << (child->is_dir ? "d " : "- ") << child->name << std::endl;
		}
	}
	else
	{
		std::cout << "- " << found->name << std::endl;
	}
}


Node* File_System::find_impl(Node* directory, const std::string& path)
{
	if (path.empty())
	{
		return directory;
	}
	auto sep = path.find('/');
	std::string current_path = sep == std::string::npos ? path : path.substr(0, sep);
	std::string rest_path = sep == std::string::npos ? "" : path.substr(sep + 1);
	auto found = std::find_if(directory->children.begin(), directory->children.end(), [&](const Node* child)
		{
			return child->name == current_path;
		});
	if (found != directory->children.end())
	{
		return find_impl(*found, rest_path);
	}
	return NULL;

}

bool File_System::add_impl(Node* directory, const std::string& path, bool is_dir)
{
	if (!directory->is_dir)
	{
		std::cout << directory->name << "��(��) �����Դϴ�." << std::endl;
		return false;
	}

	auto sep = path.find('/');

	if (sep == std::string::npos)
	{
		auto found = std::find_if(directory->children.begin(), directory->children.end(), [&](const Node* child)
			{
				return child->name == path;
			});
		if (found != directory->children.end())
		{
			std::cout << directory->name << "�� �̹� " << path << " �̸��� ����/���丮�� �ֽ��ϴ�." << std::endl;
			return false;
		}

		directory->children.push_back(new Node(path, is_dir,directory, {}));
		return true;
	}
	
	std::string next_dir = path.substr(0, sep);
	auto found = std::find_if(directory->children.begin(), directory->children.end(), [&](const Node* child)
		{
			return child->name == next_dir && child->is_dir;
		});
	
	if (found != directory->children.end())
	{
		return add_impl(*found, path.substr(sep + 1), is_dir);
	}

	std::cout << directory->name << "�� " << next_dir << "�̸��� ���丮�� �����ϴ�." << std::endl;
	return false;

}
