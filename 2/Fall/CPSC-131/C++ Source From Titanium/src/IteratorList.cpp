#include	<iostream>

using namespace std;

typedef	int	Elem;

struct Node
{
	Elem	elem;
	Node*	next;
	Node*	prev;
};

class	NodeList
{
	private:
		struct Node
		{
			Node() : elem(0), next(0), prev(0) { };
			Elem	elem;
			Node*	next;
			Node*	prev;
		};
	
	public:
		class	Iterator
		{
			public:
				Iterator() { };
				Elem&		operator*();
				bool		operator==(const Iterator& p) const;
				bool		operator!=(const Iterator& p) const;
				Iterator&	operator++();
				Iterator&	operator--();
				friend	class	NodeList;
			private:
				Node*	v;
				Iterator(Node* u);
		};

		NodeList();
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
		Node*	header;
		Node*	trailer;
};

int main (int argc, char * const argv[])
{
	NodeList			list;

	NodeList::Iterator	iterator;

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

NodeList::NodeList()
{
	n = 0;
	header = new Node;
	trailer = new Node;
	header->next = trailer;
	trailer->prev = header;
	
	return;
}

int	NodeList::size()
{
	return(n);
}

bool	NodeList::empty()
{
	return(n == 0);
}

NodeList::Iterator	NodeList::begin() const
{
	return(Iterator(header->next));
}

NodeList::Iterator	NodeList::end() const
{
	return(Iterator(trailer));
}

void	NodeList::insert(const Iterator& p, const Elem& e)
{
	Node*	w = p.v;
	Node*	u = w->prev;
	Node*	v = new Node;
	
	v->elem = e;
	v->next = w;
	w->prev = v;
	v->prev = u;
	u->next = v;
	++n;
}

void	NodeList::insertFront(const Elem& e)
{
	insert(begin(), e);

	return;
}

void	NodeList::insertBack(const Elem& e)
{
	insert(end(), e);
}

void	NodeList::erase(const Iterator& p)
{
	Node*	v = p.v;
	Node*	w = v->next;
	Node*	u = v->prev;
	
	u->next = w;
	w->prev = u;
}

void	NodeList::eraseFront()
{
	erase(begin());
}

void	NodeList::eraseBack()
{
	erase(end());
}

NodeList::Iterator::Iterator(Node* u)
{
	v = u;
}

Elem&	NodeList::Iterator::operator*()
{
	return(v->elem);
}

bool	NodeList::Iterator::operator==(const Iterator& p) const
{
	return(v == p.v);
}

bool	NodeList::Iterator::operator!=(const Iterator& p) const
{
	return(v != p.v);
}

NodeList::Iterator&	NodeList::Iterator::operator++()
{
	v = v->next;
	
	return(*this);
}

NodeList::Iterator&	NodeList::Iterator::operator--()
{
	v = v->prev;
	
	return(*this);
}