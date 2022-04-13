#ifndef _NODE_H_
#define _NODE_H_

#include <string>
#include <vector>

class Node
{
public:
	Node(std::string _name, bool _is_dir, std::vector<Node*> _children) : name(_name), is_dir(_is_dir), children(_children) {}
	std::string getName() const { return name; }
	bool getDir() const { return is_dir; }
	std::vector<Node*> getChildren() const { return children; }
private:
	std::string name;
	bool is_dir;
	std::vector<Node*> children;
};

#endif

