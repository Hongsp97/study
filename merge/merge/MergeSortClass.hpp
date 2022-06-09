#ifndef __MERGESORTCLASS_HPP__
#define __MERGESORTCLASS_HPP__

#include <vector>
#include <iostream>

template <typename T>
class MergeSortClass
{
public:
	MergeSortClass(std::vector<T> _beforeVec):beforeSortVec(_beforeVec), sort_historyVec(_beforeVec)
	{
		depth = 0;
	}

	void print_vector(std::vector<T> _vec) const;
	std::vector<T> merge_sort(std::vector<T> arr, int beginIndex = 0, int endIndex = 0);

private:
	std::vector<T> merge(std::vector<T>& arr1, std::vector<T>& arr2);
	
public:
	std::vector<T> getBeforeSortVec() const
	{
		return this->beforeSortVec;
	}
	std::vector<T> getAfterSortVec() const
	{
		return this->afterSortVec;
	}
	void setAfterSortVec(std::vector<T> _vec)
	{
		afterSortVec = _vec;
	}

private:
	std::vector<T> beforeSortVec;
	std::vector<T> afterSortVec;
	std::vector<T> sort_historyVec;
	int depth;
};

template<typename T>
void MergeSortClass<T>::print_vector(std::vector<T> _vec) const
{
	for (auto i : _vec)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;
}

template<typename T>
std::vector<T> MergeSortClass<T>::merge(std::vector<T>& arr1, std::vector<T>& arr2)
{
	std::vector<T> merged;

	auto iter1 = arr1.begin();
	auto iter2 = arr2.begin();

	while (iter1 != arr1.end() && iter2 != arr2.end())
	{
		
		if (*iter1 < *iter2)
		{
			merged.emplace_back(*iter1);
			iter1++;
		}
		else
		{
			merged.emplace_back(*iter2);
			iter2++;
		}
	}

	if (iter1 != arr1.end())
	{
		for (; iter1 != arr1.end(); iter1++)
		{
			merged.emplace_back(*iter1);
		}
	}
	else
	{
		for (; iter2 != arr2.end(); iter2++)
		{
			merged.emplace_back(*iter2);
		}
	}


	return merged;
}

template<typename T>
std::vector<T> MergeSortClass<T>::merge_sort(std::vector<T> arr, int beginIndex, int endIndex)
{
	endIndex = arr.size() - 1 + beginIndex;
	if (arr.size() > 1)
	{
		auto mid = arr.size() % 2 == 1 ? size_t(arr.size() / 2 + 1) : size_t(arr.size() / 2);
		auto left_half = merge_sort(std::vector<T>(arr.begin(), arr.begin() + mid),beginIndex,beginIndex + mid);
		auto right_half = merge_sort(std::vector<T>(arr.begin() + mid, arr.end()), beginIndex + mid, endIndex);

		auto merged = this->merge(left_half, right_half);

		for (int i = beginIndex; i <= endIndex; i++)
		{
			sort_historyVec[i] = merged[i - beginIndex];
		}

		this->print_vector(sort_historyVec);
		return merged;
	}
	return arr;
}



#endif
