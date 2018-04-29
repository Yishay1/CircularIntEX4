#include "CircularInt.hpp"
#include <string>
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

CircularInt& CircularInt::operator--(int tmp)
{
	if(num==min) num=max;
	else num--; 
	return *this;
}
CircularInt& CircularInt::operator++(int tmp)
{
	if(num==max)num=min;
	else num++;
	return *this;
}
CircularInt& CircularInt::operator--()
{
	if(num==min) num=max;
	else num--; 
	return *this;
}
CircularInt& CircularInt::operator++()
{
	if(num==max)num=min;
	else num++;
	return *this;
}
CircularInt operator+(CircularInt& first, CircularInt& sec)
{
	CircularInt c1=first;
	c1.num= (first.num + sec.num) % first.range + first.min-1;
	return c1;
}
CircularInt operator +(const CircularInt& c,int tmp)
{
	tmp =tmp%c.range;
	CircularInt c1=c;
	c1+=tmp;
	return c1;
}
CircularInt operator +(int tmp,const CircularInt& c)
{
	tmp =tmp%c.range;
	CircularInt c1=c;
	c1+=tmp;
	return c1;
}
CircularInt& CircularInt::operator*=(int tmp)
{
	int temp=(num-min+1)*tmp;
	temp=temp%range;
	this->num=temp;
	return *this;
}
CircularInt& CircularInt::operator+=(int tmp)
{
	tmp=tmp%range;
	if(tmp>=0)
		for(int i=0;i<tmp;i++) ++*this;
	else *this-=(-tmp);
	return *this;
}
CircularInt operator *(int tmp,const CircularInt& c)
{
	CircularInt c1=c;
	int temp=(c1.num-c1.min+1)*tmp;
	temp=temp%c1.range;
	c1.num=c1.max;//treat temp%range=0
	c1+=temp;
	return c1;
}
CircularInt operator/(const CircularInt& c, int tmp)
{
	for(int i=c.min;i<=c.max;i++)
	{
		if(((i-c.min+1)*tmp) % c.range+c.min-1==c.num) 
		{
			CircularInt c1=c;
			c1.num=i;
			return c1;
		}
	}
	std::string s="There is no number x in {"+to_string(c.min)+','+to_string(c.max)+"} such that x*"+to_string(tmp)+'='+to_string(c.num);
	throw string(s);
	
}
CircularInt operator/ (int i, const CircularInt& c){
         CircularInt temp=c;
         if(c.num==0||i%c.num!=0)throw string("division error");
         temp.num=i/c.num;
         return temp;
     }
 CircularInt& CircularInt::operator-=(int tmp)
{
	tmp=tmp%range;
	if(tmp>=0)
		for(int i=0;i<tmp;i++) --*this;
	else *this+=-tmp;
	return *this;
}
CircularInt& CircularInt::operator/=(int i)
{
	if(i==0||num%i!=0)throw string("error");
        this->num=num/i+min-1;
        return *this;
}
CircularInt CircularInt:: operator-()
{
	CircularInt c1;
	c1.min=min;
	c1.max=max;
	c1.range=range;
	int tmp=1;
	c1.num=c1.max;
	cout<<num<<"gg"<<endl;
	for(int i=0;i<tmp;i++)
	{
		c1--;
	}
	
	return c1;
}
CircularInt operator-(const CircularInt& c)
{
	CircularInt c1;
	c1.min=c.min;
	c1.max=c.max;
	c1.range=c.range;
	int tmp=c.num-c.min+1;
	c1.num=c1.max;
	for(int i=0;i<tmp;i++)
	{
		c1--;
	}
	return c1;
}

CircularInt operator-(const CircularInt& c1,const CircularInt& c2)
{
	int tmp1=c1.num-c1.min+1;
	int tmp2=c2.num-c2.min+1;
	int res=tmp1-tmp2;
	CircularInt c=c1;
	c.num=c.min-1+res;
	if(c.num<c.min) c.num+=c.range;
	return c;
}

CircularInt operator-(int tmp, const CircularInt& c)
{
	CircularInt c1=-c;
	c1+=tmp;
	return c1;
}

CircularInt operator-(const CircularInt& c,int tmp)
{
	CircularInt c1=c;
	c1-=tmp;
	return c1;
}
bool CircularInt::operator ==(const CircularInt& c)
{
	if(min==c.min && max==c.max && range==c.range && num==c.num) return true;
	return false;	
}

bool CircularInt::operator ==(int i)
{
	if(this->num==i)return true;
	return false;
}
bool operator==(int i, CircularInt& c)
{
	if(i==c.num)return true; 
	return false;
}
bool CircularInt::operator !=(const CircularInt& c)
{
	if(this->num==c.num) return false;
	return true;
}
bool operator!=(CircularInt& c,int i)
{
	if(c.num!=i)return true;
	return false;
}
bool operator!=(int i,CircularInt& c)
{
	if(c.num!=i)return true;
	return false;
}
bool CircularInt::operator >(int i)
{
	if(this->num > i)return true;
	return false;
}
bool CircularInt::operator >(const CircularInt& c)
{
	if(this->num > c.num) return true;
	return false;
}
bool operator>(int i, CircularInt& c)
{
	if(i>c.num)return true;
	return false;
}
bool CircularInt::operator >=(int i)
{
	if(this->num >= i) return true;
	return false;
}
bool operator>=(int i, CircularInt& c)
{
	if(i>=c.num)return true;
	return false;
}
bool CircularInt::operator >=(const CircularInt& c)
{
	if(this->num >= c.num) return true;
	return false;
}
bool CircularInt::operator <(int i)
{
	if(this->num < i) return true;
	return false;
	
}
bool CircularInt::operator <(const CircularInt& c)
{
	if(this->num < c.num) return true;
	return false;
}
bool operator<(int i, CircularInt& c)
{
	if(i<c.num) return true;
	return false;
}
bool CircularInt::operator <=(int i)
{
	if(this->num <= i) return true;
	return false;
}
bool CircularInt::operator <=(const CircularInt& c)
{
	if(this->num <= c.num)return true;
	return false;
}
bool operator<=(int i, CircularInt& c)
{
	if(i<=c.num) return true;
	return false;
}
CircularInt& CircularInt::operator-=(const CircularInt& c)
{
	*this-=c.num;
	return *this;
}
CircularInt& CircularInt::operator+=(const CircularInt& c)
{
	*this+=c.num;
	return *this;
}
void CircularInt::operator=(int i)
{
	this->num=(i%range)+min-1;
}
CircularInt& CircularInt::operator*=(const CircularInt& c)
{
	*this*=c.num;
	return *this;	
}
CircularInt operator*(CircularInt& first, CircularInt& sec)
{
	CircularInt c=first;
	c*=sec.num;
	return c;
}
CircularInt operator *(const CircularInt& c,int i)
{
	return i*c;
}
 CircularInt& CircularInt::operator>> (const CircularInt& c){
        CircularInt *temp=new CircularInt (c.min,c.max);
        temp->num>>(c.num);
        return *temp;
    }
