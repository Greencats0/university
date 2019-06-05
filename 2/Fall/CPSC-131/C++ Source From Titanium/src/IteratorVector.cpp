#include	<iostream>

using namespace std;

typedef	int	Elem;

class	Vector
{
	public:
		class	Iterator
		{
			public:
				Iterator() { };
				Elem		operator*();
				bool		operator==(const Iterator& p) const;
				bool		operator!=(const Iterator& p) const;
				Iterator&	operator++();
				Iterator&	operator--();
				friend	class	Vector;
			private:
				Elem*	v;
				Iterator(Elem* u);
		};

		Vector();
		int		size();
		bool	empty();
		Iterator	begin() const;
		Iterator	end() const;
		void		insertFront(const Elem& e);
		void		insertBack(const Elem& e);
		void		insert(const Iterator& p, const Elem& e);
		void		eraseFront();
		void		eraseBack();
		void		erase(const Iterator& p);

	private:
		int		n;
		Elem*	elem;
};

int main (int argc, char * const argv[])
{
	Vector			list;

	Vector::Iterator	iterator;

	list.insertBack(1);
	list.insertBack(2);
	list.insertBack(3);
	
	iterator = list.begin();
	while (iterator != list.end())
	{
		cout << *iterator << endl;
		++iterator;
	}

	return(0);
}

Vector::Vector()
{
	n = 0;
}

int	Vector::size()
{
	return(n);
}

bool	Vector::empty()
{
	return(n == 0);
}

Vector::Iterator	Vector::begin() const
{
	return(Iterator(elem));
}

Vector::Iterator	Vector::end() const
{
	return(Iterator(elem + n));
}

void	Vector::insert(const Iterator& p, const Elem& e)
{
	Elem*	newElem;
	
	Elem*	u;
	
	Elem*	v;
	
	if (n != 0)
	{
		Elem*	w = p.v;
		
		++n;
		newElem = new Elem[n];
		
		u = elem;
		v = newElem;
		while (u != w)
		{
			*v = *u;
			++u;
			++v;
		}

		*v = e;

		++v;
		while (u != w)
		{
			*v = *u;
			++u;
			++v;
		}
		
		elem = newElem;
		delete []newElem;
		
	}
	else
	{
		elem = new Elem[1];
		elem[0] = e;
		n = 1;
	}
}

void	Vector::insertFront(const Elem& e)
{
	insert(begin(), e);
}

void	Vector::insertBack(const Elem& e)
{
	insert(end(), e);
}

void	Vector::erase(const Iterator& p)
{
	Elem*	w = p.v + 1;
	
	while (w < &elem[n])
	{
		*(w - 1) = *w;
	}

	--n;
}

void	Vector::eraseFront()
{
	erase(begin());
}

void	Vector::eraseBack()
{
	erase(end());
}

Vector::Iterator::Iterator(Elem* u)
{
	v = u;
}

Elem	Vector::Iterator::operator*()
{
	return(*v);
}

bool	Vector::Iterator::operator==(const Iterator& p) const
{
	return(v == p.v);
}

bool	Vector::Iterator::operator!=(const Iterator& p) const
{
	return(v != p.v);
}

Vector::Iterator&	Vector::Iterator::operator++()
{
	++v;
	
	return(*this);
}

Vector::Iterator&	Vector::Iterator::operator--()
{
	--v;
	
	return(*this);
}