#include<iostream>

using namespace std;

class CircularInt
{
	public:
		int min;
		int max;
		int range;
		int num;
	
		CircularInt(int min, int max);
		CircularInt();
		friend int operator+(CircularInt& first, CircularInt& sec);
		friend CircularInt& operator -(int,const CircularInt&);
		friend CircularInt& operator -(const CircularInt&);
		friend CircularInt& operator *(int,const CircularInt&);
		//friend void operator/(int);
		void operator--(int);
		void operator++(int);
		void operator--();
		void operator++();
		friend int operator/(const CircularInt&, int);
		CircularInt& operator*=(int);	
		CircularInt& operator+=(int);
		CircularInt& operator-=(int);
		void operator=(const CircularInt&);
		friend ostream& operator<< (ostream& os, const CircularInt& c);
		friend istream& operator>> (istream& is, CircularInt& c);
		bool operator ==(const CircularInt&);
};
