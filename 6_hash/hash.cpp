#include<string>
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main()
{
	/*c++���õĹ�ϣ��*/
	unordered_map<int, string> map;

	/*��Ӳ���*/
	map[12836] = "С��";
	map[15937] = "С��";
	map[16750] = "С��";
	map[13276] = "С��";
	map[10583] = "СѼ";

	/*��ѯ����*/
	string name = map[12836];

	/*ɾ������*/
	map.erase(10583);

	/*������ֵ��*/
	for (auto kv : map)
	{
		cout << kv.first << " -> " << kv.second << endl;
	}

	/*ʹ�õ���������*/
	for (auto iter = map.begin(); iter != map.end(); iter++)
	{
		cout << iter->first << " -> " << iter->second << endl;
	}


}


/*��װһ����ֵ����*/
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

/*��������ʵ�ֵĹ�ϣ��*/
class ArrayHashMap
{
private:
	vector<Pair* >buckets;
public:
	
};