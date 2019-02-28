#include<iostream>
#include<memory>

class Parent;
class Child;

class Parent {
public:
	void setChild(std::shared_ptr<Child> child) {
		this->ChildPtr = child;
	}

	void doSomething() {
		//ʹ���µ�shared_ptr
		//weak_ptrͨ��lock�����ӱ��۲��shared_ptr���һ�����õ�shared_ptr��Դ
		//�����۲��shared_ptrָ���ѱ���������lock��������һ���洢��ָ���shared_ptr
		if (this->ChildPtr.lock()) {

		}
	}

	~Parent() {

	}
private:
	std::weak_ptr<Child> ChildPtr;
};

class Child {
public:
	void setParent(std::shared_ptr<Parent> parent) {
		this->ParentPtr = parent;
	}

	void doSomething() {
		//�������ü����жϴ˿��ڴ����Դ�Ƿ��ѱ��ͷ�
		if (this->ParentPtr.use_count()){

		}
	}

	~Child(){ 
	
	}

private:
	std::shared_ptr<Parent> ParentPtr;
};

int main() {
	std::weak_ptr<Parent> wpp;  //������weak_ptr������Ҫ�����Ǽ�� p��c������������ü���
	std::weak_ptr<Child> wpc;
	{
		std::shared_ptr<Parent> p(new Parent);
		std::shared_ptr<Child> c(new Child);
		p->setChild(c);
		c->setParent(p);
		wpp = p;
		wpc = c;
		std::cout << p.use_count() << std::endl;  //2
		std::cout << c.use_count() << std::endl;  //1
	}
	//����ջ����ȳ���ԭ��c�ȳ�����������c�����ô�����1Ϊ0����Դ���ͷ�
	//p��������򣬴���c����Դ�ѱ��ͷţ���p�����ô����Ѿ�Ϊ1�������������ټ�1��Ϊ0����Դ���ͷ�
	//�����������ѭ�����õú����Ǳ�����ʹ��weak_ptr�ö����ȳ���������Ϊweak_ptr�������ã�ֻ���ã�������

	std::cout << wpp.use_count() << std::endl;    //0
	std::cout << wpc.use_count() << std::endl;    //0

	int temp;
	std::cin >> temp;

	return 0;
}
