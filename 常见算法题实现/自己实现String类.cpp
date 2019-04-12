#include<iostream>
#include<cstring>

//vs׼������strcpy�ģ���ȫ�Խϵͣ�����΢���ṩ��strcpy_s�����棬
//��������ʹ��strcpy�ģ�������mainǰ�������һ��
#pragma warning(disable:4996) 
//#define _CRT_SECURE_NO_WARNINGS   //��һ��Ҳ���Խ���������⣬���ǹر����о���ģ������ǹر�ĳһ�־���

//strcpy_s(str, strlen(str1) + 1, str1);  strcpy_s����Ҫ���������ģ��м���Ҫ���� Ҫ���Ƶ��ַ����ĳ���+1 �Ĳ���

using namespace std;

//������
class String
{
public:
	String(const char* str = NULL);   //ͨ�����캯��
	String(const String& s);          //�������캯��
	~String();     //��������

	String operator+(const String &str) const;    //����+
	String& operator=(const String &str);         //����=
	String& operator+=(const String &str);        //����+=
	bool operator==(const String &str) const;     //����==
	char& operator[](int n) const;                //����[]

	size_t size() const;       //��ȡ����
	const char* c_str() const; //��ȡC�ַ���

	friend istream& operator>>(istream &is, String &str); //����
	friend ostream& operator<<(ostream &os, String &str); //���

private:
	char* data;     //����
	int length;   //����
};

String::String(const char *str)
{
	if (!str)
	{
		length = 0;
		data = new char[1];
		*data = '\0';
	}
	else {
		length = strlen(str);
		data = new char[length+1];
		strcpy_s(data, str);
	}
}

String::String(const String& str)
{
	length = str.size();
	data = new char[length + 1];
	strcpy(data, str.c_str());
}

String::~String()
{
	delete[] data;
	length = 0;
}

String String::operator+(const String& str) const
{
	String newString;
	newString.length = length + str.length;
	newString.data = new char[newString.length + 1];
	strcpy(newString.data, data);
	strcat(newString.data, str.data);
	return newString;
}

String& String::operator=(const String &str)
{
	if (this == &str)
		return *this;

	delete[] data;
	length = str.length;
	data = new char[length + 1];
	strcpy(data, str.c_str());
	return *this;
}

String& String::operator+=(const String &str)
{
	length += str.length;
	char *newData = new char[length + 1];
	strcpy(newData, data);
	strcat(newData, str.data);
	delete[] data;
	data = newData;
	return *this;
}

inline bool String::operator==(const String &str) const
{
	if (length != str.length)
		return false;
	return strcmp(data, str.data) ? false : true;
}

inline char& String::operator[](int n) const
{
	if (n >= length)
	{
		return data[length - 1];
	}
	else {
		return data[n];
	}
}

inline size_t String::size() const
{
	return length;
}

istream& operator>>(istream& is, String &str)
{
	char tem[1000];
	is >> tem;
	str.length = strlen(tem);
	str.data = new char[str.length + 1];
	strcpy(str.data, tem);
	return is;
}

ostream& operator<<(ostream &os, String &str) //���
{
	os << str.data;
	return os;
}

inline const char* String::c_str() const
{
	return data;
}

//����
int main()
{
	String s;
	cin >> s;
	cout << s << ": " << s.size() << endl;

	char a[] = "hello", b[] = "World!";
	String s1(a), s2(b);
	cout << s1 << "+" << s2 << "=" << s1 + s2 << endl;

	String s3 = s1 + s2;
	if (s1 == s3) cout << "First: s1 == s3" << endl;
	s1 += s2;
	if (s1 == s3) cout << "Second: s1 == s3" << endl;
}