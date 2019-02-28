#include<iostream>
#include<memory>

template<typename T>
class SmartPointer {
public:
	SmartPointer(T* ptr = nullptr) :_ptr(ptr) {
		if (_ptr) {
			_count = new size_t(1);
		}
		else {
			_count = new size_t(0);
		}
	}

	SmartPointer(const SmartPointer& ptr) {
		if (this != &ptr) {
			this->_ptr = ptr._ptr;
			this->_count = ptr._count;
			(*this->_count)++;
		}
	}

	SmartPointer& operator=(const SmartPointer& ptr) {
		if (this->_ptr == ptr._ptr) {
			return *this;
		}

		//�Ⱥ���ֵ���ü�1���Ⱥ��ұ����ü�1
		if (this->_ptr) {
			(*this->_count)--; 
			if (this->_count == 0) {
				delete this->_ptr;
				delete this->_count;
			}
		}

		//����ֵ��ֵ����ֵ�����ô�����1
		this->_ptr = ptr._ptr;
		this->_count = ptr._count;
		(*this->_count)++;

		return *this;
	}

	T& operator*() {
		assert(this->_ptr == nullptr);
		return this->_ptr;
	}

	~SmartPointer() {
		(*this->_count)--;
		if(*this->_count == 0){
			delete this->_ptr;
			delete this->_count;
		}
	}
	
	size_t use_count() {
		return *this->_count;
	}

private:
	T* _ptr;
	size_t* _count;
};

int main() {
	{
		SmartPointer<int> sp(new int(10));
		SmartPointer<int> sp2(sp);
		SmartPointer<int> sp3(new int(20));
		std::cout << sp.use_count() << std::endl;   //2
		std::cout << sp2.use_count() << std::endl;  //2
		// ����֮ǰ��sp2�����ü�����sp��ͬ
		sp2 = sp3;
		//����֮��sp2�����ü�����sp3��ͬ
		std::cout << sp.use_count() << std::endl;   //1
		std::cout << sp2.use_count() << std::endl;  //2
		std::cout << sp3.use_count() << std::endl;  //2
	}
	//�ͷ��ڴ�

	int temp;
	std::cin >> temp;

	return 0;
}