#include "CircularInt.hpp"

CircularInt::CircularInt(int _min, int _max)
{
	min=_min;
	max=_max;
	range=max-min+1;
	num=min;
}
CircularInt::CircularInt()
{
	min=0;
	max=0;
	range=0;
	num=0;
}

ostream& operator<< (ostream& os, const CircularInt& c)
{
	os<<c.num;
	return os;
}
void CircularInt::operator=(const CircularInt& another)
{
	num=another.num;
	min=another.min;
	max=another.max;
	range=another.range;
}

void CircularInt::operator--(int tmp)
{
	if(num==min) num=max;
	else num--; 
}
void CircularInt::operator++(int tmp)
{
	if(num==max)num=min;
	else num++;
}
void CircularInt::operator--()
{
	if(num==min) num=max;
	else num--; 
}
void CircularInt::operator++()
{
	if(num==max)num=min;
	else num++;
}
int operator+(CircularInt& first, CircularInt& sec)
{
	return (first.num + sec.num) % first.range + first.min-1;
}

CircularInt& CircularInt::operator*=(int tmp)
{
	int temp=(num-min+1)*tmp;
	temp=temp%range;
	*this+=temp;
}
CircularInt& CircularInt::operator+=(int tmp)
{
	tmp=tmp%range;
	if(tmp>=0)
		for(int i=0;i<tmp;i++) ++*this;
	else *this-=(-tmp);
}
CircularInt& operator *(int tmp,const CircularInt& c)
{
	CircularInt c1=c;
	int temp=(c1.num-c1.min+1)*tmp;
	temp=temp%c1.range;
	c1.num=c1.max;//treat temp%range=0
	c1+=temp;
	return c1;
}
 int operator/(const CircularInt& c, int tmp)
{
	/*for(int i=min;i<=max;i++)
	{
		if((i*tmp) % range+min==num) {num=i;return;}
	}*/
	CircularInt c1=c;
	if(false)
		throw string("fdfd");
	else
	{
		c1.num=c1.num/3;
		
	}
	return 3;
}
CircularInt& CircularInt::operator-=(int tmp)
{
	tmp=tmp%range;
	if(tmp>=0)
		for(int i=0;i<tmp;i++) --*this;
	else *this+=-tmp;
}
CircularInt& operator-(const CircularInt& c)
{
	CircularInt c1=c;
	int tmp=c.num-c.min+1;
	c1.num=c1.max;
	for(int i=0;i<tmp;i++)
	{
		c1--;
	}
	return c1;
}
CircularInt& operator-(int tmp, const CircularInt& c)
{
	CircularInt c1=-c;
	c1+=tmp;
	return c1;
}
bool CircularInt::operator ==(const CircularInt& c)
{
	if(min==c.min && max==c.max && range==c.range && num==c.num) return true;
	return false;	
}

