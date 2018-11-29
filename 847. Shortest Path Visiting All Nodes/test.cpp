#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

struct KEY
{
	int first;
	int second;
	int third;

	KEY(int f, int s, int t) : first(f), second(s), third(t){}
};

struct HashFunc
{
	std::size_t operator()(const KEY &key) const
	{
		using std::size_t;
		using std::hash;

		return ((hash<int>()(key.first)
			^ (hash<int>()(key.second) << 1)) >> 1)
			^ (hash<int>()(key.third) << 1);
	}
};

struct EqualKey
{
	bool operator()(const KEY &lhs, const KEY &rhs) const
	{
		return lhs.first  == rhs.first
			&& lhs.second == rhs.second
			&& lhs.third  == rhs.third;
	}
};

int main()
{
	unordered_map<KEY, string, HashFunc, EqualKey> hashmap =
	{
		{ { 01, 02, 03 }, "one" },
		{ { 11, 12, 13 }, "two" },
		{ { 21, 22, 23 }, "three" },
	};
 
	KEY key(11, 12, 13);
 
	auto it = hashmap.find(key);
	
 	if (it != hashmap.end())
 	{
 		cout << it->second << endl;
 	}

	unordered_set<KEY, HashFunc, EqualKey> hashset =
	{
		{ 01, 02, 03 },
		{ 11, 12, 13 },
		{ 21, 22, 23 },
	};

    auto itt = hashset.find(key);
    if (itt != hashset.end()) {
        cout << itt->second << endl;
    }
 
	return 0;
}

