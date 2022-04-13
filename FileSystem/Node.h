#ifndef _NODE_H_
#define _NODE_H_

#include <string>
#include <vector>

class Node
{
public:
	Node();
	
private:
	std::string name;
	bool is_dir;
	std::vector<Node*> children;
};

#endif

