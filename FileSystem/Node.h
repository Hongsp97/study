#ifndef _NODE_H_
#define _NODE_H_

#include <string>
#include <vector>

class Node
{
public:
	Node(std::string _name, bool _is_dir, Node*_parent, std::vector<Node*> _children) : name(_name), is_dir(_is_dir),parent(_parent) ,children(_children) {}

public:
	std::string name;
	bool is_dir;
	Node* parent;
	std::vector<Node*> children;
};

#endif

