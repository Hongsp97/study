#ifndef _NODE_H_
#define _NODE_H_

#include <string>
#include <vector>

class Node
{
public:
	Node(std::string _name, bool _is_dir, std::vector<Node*> _children) : name(_name), is_dir(_is_dir), children(_children) {}

public:
	std::string name;
	bool is_dir;
	std::vector<Node*> children;
};

#endif

