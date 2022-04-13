#include "File_System.h"

#include <iostream>

#include "Node.h"

File_System::File_System()
{
	root = new Node("/", true, {});
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
	if (found && found->getDir())
	{
		cwd = found;
		std::cout << "현재 디렉토리를 " << cwd->getName() << "로 이동합니다." << std::endl;
		return true;
	}

	std::cout << path << "경로를 찾을 수 없습니다." << std::endl;
	return false;
}

void File_System::show_path(const std::string& path)
{
	auto found = find(path);
	if (!found)
	{
		std::cout << path << " 경로가 존재하지 않습니다." << std::endl;
		return;
	}

	if (found->getDir())
	{
		for (auto child : found->getChildren())
		{
			std::cout << (child->getDir() ? "d" : "- ") << child->getName() << std::endl;
		}
	}
	else
	{
		std::cout << "- " << found->getName() << std::endl;
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
	auto found = std::find_if(directory->getChildren().begin(), directory->getChildren().end(), [&](const Node* child)
		{
			return child->getName() == current_path;
		});
	if (found != directory->getChildren().end())
	{
		return find_impl(*found, rest_path);
	}
	return NULL;

}

bool File_System::add_impl(Node* directory, const std::string& path, bool is_dir)
{
	if (!directory->getDir())
	{
		std::cout << directory->getName() << "은(는) 파일입니다." << std::endl;
		return false;
	}

	auto sep = path.find('/');

	if (sep == std::string::npos)
	{
		auto found = std::find_if(directory->getChildren().begin(), directory->getChildren().end(), [&](const Node* child)
			{
				return child->getName() == path;
			});
		if (found != directory->getChildren().end())
		{
			std::cout << directory->getName() << "에 이미 " << path << " 이름의 파일/디렉토리가 있습니다." << std::endl;
			return false;
		}

		directory->getChildren().push_back(new Node(path, is_dir, {}));
		return true;
	}
	
	std::string next_dir = path.substr(0, sep);
	auto found = std::find_if(directory->getChildren().begin(), directory->getChildren().end(), [&](const Node* child)
		{
			return child->getName() == next_dir && child->getDir();
		});
	
	if (found != directory->getChildren().end())
	{
		return add_impl(*found, path.substr(sep + 1), is_dir);
	}

	std::cout << directory->getName() << "에 " << next_dir << "이름의 디렉토리가 없습니다." << std::endl;
	return false;

}
