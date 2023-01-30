// #include <iostream>
// #include <time.h>


// // Emulates the Win32 API call
// uint32_t gettickcount()
// {
//         struct timespec ts;

//         clock_gettime(CLOCK_MONOTONIC, &ts);
//         return (1000 * ts.tv_sec + ts.tv_nsec / 1000000);
// }
// using namespace std;
// char buf[4100];  //Simple Memory Pool 

// class CTestClass
// {
//     char m_chBuf[4096];
// public:    
//     void *operator new(long unsigned int uiSize)
//     {
//         return (void *)buf;
//     }
//     void  operator delete(void *p)
//     {
//     }
// };

// int main()
// {
//     uint32_t count = gettickcount();    
    
//     for(unsigned int i=0; i<0x5fffff; i++)
//     {
//         CTestClass *p = new CTestClass;
//         //buf[0]=1;
//         //buf[1]=2;
//         //cout << "buf= " << buf[0]  << endl << buf[1] << endl;
    
//         delete p;
//     }
    
//     cout << "Interval = " << gettickcount()-count << " ms" << endl;
    
//     return 0;

// }
// CPP program to demonstrate
// Global overloading of
// new and delete operator
// #include<iostream>
// #include<stdlib.h>

// using namespace std;
// void * operator new(size_t size)
// {
// 	cout << "New operator overloading " << size<< endl;
// 	void * p = malloc(size);
// 	return p;
// }

// void operator delete(void * p)
// {
// 	cout << "Delete operator overloading " << endl;
// 	free(p);
// }

// int main()
// {
// 	int n = 8, i;
// 	int * p = new int[n];

// 	for (i = 0; i<n; i++)
// 	p[i]= i;

// 	cout << "Array: ";
// 	for(i = 0; i<n; i++)
// 		cout << p[i] << " ";
		
// 	cout << endl;

// 	delete [] p;
// }
// CPP program to demonstrate
// Overloading new and delete operator
// for a specific class
#include<iostream>
#include<stdlib.h>

using namespace std;
class student
{
	string name;
	int age;
    string family;
public:
	student()
	{
		cout<< "Constructor is called\n" ;
	}
	student(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
	void display()
	{
		cout<< "Name:" << name << endl;
		cout<< "Age:" << age << endl;
	}
	void * operator new(size_t size)
	{
		cout<< "Overloading new operator with size: " << size << endl;
		void * p = ::operator new(size);
		//void * p = malloc(size); will also work fine
	
		return p;
	}

	void operator delete(void * p)
	{
		cout<< "Overloading delete operator " << endl;
		free(p);
	}
};

int main()
{
	student * p = new student("Yash", 24);
    cout << sizeof(string);
	p->display();
	delete p;
}
