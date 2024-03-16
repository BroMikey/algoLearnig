#include<string>
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main()
{
	/*c++内置的哈希表*/
	unordered_map<int, string> map;

	/*添加操作*/
	map[12836] = "小哈";
	map[15937] = "小啰";
	map[16750] = "小算";
	map[13276] = "小法";
	map[10583] = "小鸭";

	/*查询操作*/
	string name = map[12836];

	/*删除操作*/
	map.erase(10583);

	/*遍历键值对*/
	for (auto kv : map)
	{
		cout << kv.first << " -> " << kv.second << endl;
	}

	/*使用迭代器遍历*/
	for (auto iter = map.begin(); iter != map.end(); iter++)
	{
		cout << iter->first << " -> " << iter->second << endl;
	}


}


/*封装一个键值对类*/
struct Pair
{
public:
	int key;
	string val;
	Pair(int key, string val)
	{
		this->key = key;
		this->val = val;
	}
};

/*基于数组实现的哈希表*/
class ArrayHashMap
{
private:
	vector<Pair* >buckets;
public:
	
};