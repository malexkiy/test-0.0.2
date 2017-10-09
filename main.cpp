#include <utility>

//BidirectionalIterator
template <typename Iterator, typename T>
auto find_two_elements_with_sum(Iterator first, Iterator last, T c)->std::pair<bool, std::pair<Iterator, Iterator>>
{
	std::pair<bool, std::pair<Iterator, Iterator>> found_pair;

	while (*first < *last)
	{
		T sum = *first + *last;
		if (sum == c)
		{
			found_pair.first = true;
			found_pair.second.first = first;
			found_pair.second.second = last;

			return found_pair;
		}
		else
		{
			if (sum < c) first++;
			else last--;
		}
	}

	return found_pair;
}

int main()
{
	int arr[] = { -6, -4, 0, 2, 5, 7, 8, 8, 13, 17 };

	auto found_pair = find_two_elements_with_sum(arr, arr + sizeof(arr)/sizeof(arr[0]) - 1, 5);

	return 0;
}
