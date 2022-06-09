#include "MergeSortClass.hpp"

#include <vector>
int main()
{
	std::vector<int> arr;
	int size = 0;
	std::cin >> size;

	for (int i = 0; i < size; i++)
	{
		int x;
		std::cin >> x;
		arr.push_back(x);
	}

	MergeSortClass<int>* msc1 = new MergeSortClass<int>(arr);
	msc1->setAfterSortVec(msc1->merge_sort(msc1->getBeforeSortVec()));

	return 0;
}