#include "CircularInt.hpp"
#include <string>
/*
*constructor
*/
CircularInt::CircularInt(int _min, int _max)
{
	min=_min;
	max=_max;
	range=max-min+1;
	num=min;
}
/*
*constructor
*/
CircularInt::CircularInt()
{
	min=0;
	max=0;
	range=0;
	num=0;
}
/*
*destructor
*/
CircularInt::~CircularInt(){}
/*
*calculate num into range
*/
void CircularInt::norm()
{
	while(num>max)num=num-range;
	while(num<min)num=num+range;
}
////////////////////////////////////////////
////////////////////////////////////////////
/*
*increament decreament functions
*/

CircularInt& CircularInt::operator--(int)
{
	if(num==min)num=max;
	else num--;
	return *this;
}
CircularInt& CircularInt::operator++(int)
{
	if(num==max)num=min;
	else num++;
	return *this;
}
CircularInt& CircularInt::operator--()
{
	if(num==min)num=max;
	else num--;
	return *this;
}
CircularInt& CircularInt::operator++()
{
	if(num==max)num=min;
	else num++;
	return *this;
}
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////

/*
*diffrence functions
*/
CircularInt operator -(const CircularInt& c1,const CircularInt& c2)
{
	CircularInt c{c1.min,c1.max};
	c.num=c1.num-c2.num;
	c.norm();
	return c;
}
CircularInt operator -(int i,const CircularInt& c)
{
	CircularInt c1{c.min,c.max};
	c1.num=i-c.num;
	c1.norm();
	return c1;
}
CircularInt operator -(const CircularInt& c,int i)
{
	CircularInt c1{c.min,c.max};
	c1.num=c.num-i;
	c1.norm();
	return c1;
}
CircularInt operator -(const CircularInt& c)
{
	CircularInt c1{c.min,c.max};
	c1.num=-c.num;
	c1.norm();
	return c1;
}
CircularInt& CircularInt::operator-=(int i)
{
	this->num-=i;
	this->norm();
	return *this;
}
CircularInt& CircularInt::operator-=(const CircularInt& c)
{
	this->num-=c.num;
	this->norm();
	return *this;
}
///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////


/*
*sum functions
*/
CircularInt operator+(CircularInt& c1, CircularInt& c2)
{
	CircularInt c{c1.min,c1.max};
	c.num=c1.num+c2.num;
	c.norm();
	return c;
}
CircularInt operator +(const CircularInt& c,int i)
{
	CircularInt c1{c.min,c.max};
	c1.num=c.num+i;
	c1.norm();
	return c1;
}
CircularInt operator +(int i,const CircularInt& c)
{
	CircularInt c1{c.min,c.max};
	c1.num=c.num+i;
	c1.norm();
	return c1;
}
CircularInt& CircularInt::operator+=(int i)
{
	this->num+=i;
	this->norm();
	return *this;
}
CircularInt& CircularInt::operator+=(const CircularInt& c)
{
	this->num+=c.num;
	this->norm();
	return *this;
}
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

/*
*multiply functions
*/
CircularInt operator *(int i,const CircularInt& c)
{
	CircularInt c1{c.min,c.max};
	c1.num=c.num*i;
	c1.norm();
	return c1;
}
CircularInt operator *(const CircularInt& c,int i)
{
	CircularInt c1{c.min,c.max};
	c1.num=c.num*i;
	c1.norm();
	return c1;
}
CircularInt operator*(CircularInt& c1, CircularInt& c2)
{
	CircularInt c{c1.min,c1.max};
	c.num=c1.num*c2.num;
	c.norm();
	return c;
}
CircularInt& CircularInt::operator*=(int i)
{
	this->num*=i;
	this->norm();
	return *this;
}
CircularInt& CircularInt::operator*=(const CircularInt& c)
{
	this->num*=c.num;
	this->norm();
	return *this;
}
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

/*
*divide functions
*/
CircularInt operator/(const CircularInt& c, int i)
{
	CircularInt c1=c;
	if(c.num%i!=0||i==0)throw string("error");
        c1.num=(c.num/i);
	c1.norm();
        return c1;
}
CircularInt operator/(int i,const CircularInt& c)
{
	CircularInt c1{c.min,c.max};
	if(c.num==0||i%c.num!=0)throw string("division error");
	c1.num=i/c.num;
	c1.norm();
	return c1;
}
CircularInt& CircularInt::operator/=(int i)
{
	if(num%i!=0||i==0)throw string("error");
        num=num/i;
	this->norm();
        return *this;
}
/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////

/*
*placement functions
*/
void CircularInt::operator=(int i)
{
	this->num=i;
	this->norm();
}
void CircularInt::operator=(const CircularInt& c)
{
	this->num=c.num;
	this->norm();
}
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

/*
*comparison functions
*/
bool CircularInt::operator ==(const CircularInt& c)
{
	return(num==c.num);
}
bool CircularInt::operator ==(int i)
{
	return(num==i);
}
bool operator==(int i, CircularInt& c)
{
	return(c.num==i);
}
bool CircularInt::operator !=(const CircularInt& c)
{
	return(num!=c.num);
}
bool operator!=(int i, CircularInt& c)
{
	return(i!=c.num);
}
bool operator!=(CircularInt& c,int i)
{
	return(i!=c.num);
}
bool CircularInt::operator >(int i)
{
	return(num>i);
}
bool operator>(int i, CircularInt& c)
{
	return(i>c.num);
}
bool CircularInt::operator >(const CircularInt& c)
{
	return(num>c.num);
}
bool CircularInt::operator >=(int i)
{
	return(num>=i);
}	
bool CircularInt::operator >=(const CircularInt& c)
{
	return(num>=c.num);
}
bool operator>=(int i, CircularInt& c)
{
	return(i>=c.num);
}
bool CircularInt::operator <(int i)
{
	return(num<i);
}
bool CircularInt::operator <(const CircularInt& c)
{
	return (num<c.num);
}
bool operator<(int i, CircularInt& c)
{
	return (i<c.num);
}
bool CircularInt::operator <=(int i)
{
	return (num<=i);
}
bool CircularInt::operator <=(const CircularInt& c)
{
	return (num<=c.num);
}
bool operator<=(int i, CircularInt& c)
{
	return (i<=c.num);
}
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////


/*
*ostream istream functions
*/
CircularInt& CircularInt::operator>> (const CircularInt& c)
{
	CircularInt *temp=new CircularInt (min,max);
        temp->num = (num>>c.num);
	temp->norm();
        return *temp;
}
ostream& operator<< (ostream& os, const CircularInt& c)
{
	os<<c.num;
	return os;
}

istream& operator>> (istream& is, CircularInt& c)
{
	 int x;
         is>> x;
         c.num = x;
	 c.norm();
         return is;
}
