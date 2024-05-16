#include <iostream>
#include <string>

using namespace std;

class Snack
{
public:
	
	string get_name()
	{
		return m_name;
	}

protected:
	string m_name;
	string m_factory_name;
};

class Candy : public Snack
{
public:
	string m_flavor;
	int m_price;

	Candy(string flavor, string name)
	{
		this->m_flavor = flavor;
		this->m_name = name;
	}

};

class Chocolate : public Snack
{
public:
	string m_shape;
	int m_price;

	Chocolate(string shape , string name)
	{
		this->m_shape = shape;
		this->m_name = name;
	}

};

void main()
{
	Candy candy1("grape","∫∞ªÁ≈¡");
	Candy candy2("orange","æÀªÁ≈¡");
	Chocolate chocolate1("circle","∞°≥™");
	Chocolate chocolate2("triangle","æ∆∏Ù∂Û");
	
	Snack snackBasket[4];
	snackBasket[0] = candy1;
	snackBasket[1] = candy2;
	snackBasket[2] = chocolate1;
	snackBasket[3] = chocolate2;

	for (int i = 0; i < 4; i++)
	{
		cout << snackBasket[i].get_name() << endl;
	}

	

}