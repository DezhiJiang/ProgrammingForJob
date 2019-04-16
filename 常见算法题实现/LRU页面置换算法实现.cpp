#include<iostream>
#include<list>
#include<unordered_map>

using namespace std;

//LRU�����㷨Ҳ��LRUҳ���û��㷨����һ�־��䳣�õ�ҳ���û��㷨

//LRU�ĵ���ʵ����hash map + doubly linked list��˫���������ڴ洢���ݽ�㣬�������ǰ��ս�������ʹ�õ�ʱ�����洢�ġ�
//���һ����㱻�����ˣ������������������ڽ�������һ��ʱ�䱻���ʵĸ���Ҫ����������㡣���ǣ����ǰ����ŵ�˫�������ͷ����
//��������˫�����������һ����㣬����Ҳ�п��ܺܿ�ͻ�ʹ�õ�����ͬ���������뵽ͷ��������ʹ�����ַ�ʽ���ϵص�����˫����������β���Ľ����ȻҲ�������һ��ʱ�䣬���û��ʹ�õ��Ľ�㡣
//��ô�������ǵ�Cache���ˣ���Ҫ�滻���ľ���˫�������������Ǹ����
//���û�й�ϣ������Ҫ����ĳ����㣬����Ҫ˳���һ�����ң�ʱ�临�Ӷ���O(n)��ʹ�ù�ϣ�������������O(1)��ʱ���ҵ���Ҫ���ʵĽ�㣬���߷���δ�ҵ���

template<typename K, typename T>
struct Node {
	K key;
	T value;
	Node(K k, T v):key(k),value(v) {}
};

template<typename K, typename T>
class LRUCache
{
public:
	LRUCache(int c):capacity(c)  {}   //���캯��

	T get(K key)
	{
		_ASSERT(cacheMap.find(key) != cacheMap.end());

		//��key�Ƶ���һ����������cacheMap
		//��cacheMap[key]�ƶ���Ŀ��cacheList�Ŀ�ͷλ�ã���Ч�Ľ����ǲ��뵽Ŀ��list����cacheList��ɾ����
		cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);  
		cacheMap[key] = cacheList.begin();
		return cacheMap[key]->value;   //��������ָ��
	}

	void set(K key, T value)
	{
		if (cacheMap.find(key) == cacheMap.end())
		{
			//���ڻ����б��У���̭��������һ��Ԫ�أ�������Ԫ�ز���������
			if (cacheList.size() == capacity)
			{
				cacheMap.erase(cacheList.back().key);  //�ȴ�map��ɾ�����һ����ֵ
				cacheList.pop_back();    //�ٴ�list��ɾ����Ӧ��node
			}
			cacheList.push_front(Node<K, T>(key, value));
			cacheMap[key] = cacheList.begin();
		}
		else {
			//���½ڵ��ֵ��������ӵ���һ��λ��
			cacheMap[key]->value = value;
			cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
			cacheMap[key] = cacheList.begin();
		}
	}

private:
	int capacity;
	list<Node<K, T>> cacheList;
	unordered_map < K, typename list<Node<K, T>>::iterator> cacheMap;  
	//����iterator���������map����map�а�����һ��ģ�壬��û��ʵ������ʱ����ȷ�������͡�
    //��ʱ��һ��typenameǰ׺����
};

int main()
{
	int N = 10;
	LRUCache<int, int> lc(N);

	for (int i = 0; i < N; i++)
		lc.set(i,i);
	cout << "at the beginning: " << endl;
	for (int i = 0; i < N; i++)
		cout << lc.get(i) << " ";
	cout << endl;
	cout << "after inserting: " << endl;  //��0��Ԫ�ر�ɾ���ˣ�11�����˽�ȥ
	lc.set(N + 1, N + 1);	
	for (int i = 1; i < N; i++)
		cout << lc.get(i) << " ";
	cout << lc.get(N + 1);
	cout << endl;

	return 0;
}
