#include <iostream>

class node
{
	int val;
	node *next;
public:
	node(int x)
	{
		val = x;
		next = NULL;
	}
	node *get_next()
	{
		return next;
	}
	node *set_next(node *new_next)
	{
		next = new_next;
		return new_next;
	}
	int get_val()
	{
		return val;
	}
};

class linked_list
{
	node *head;
	node *tail;
public:
	linked_list()
	{
		head = NULL;
		tail = NULL;
	}
	~linked_list()
	{
		while(head != tail)
		{
			node *prev_node = head;
			head = head->get_next();
			delete prev_node;
		}
		delete tail;
		head = NULL;
		tail = NULL;
	}
	void add_back(int x)
	{
		node *new_node = new node(x);
		if(tail == NULL)
			head = tail = new_node;
		else
			tail = tail->set_next(new_node);
	}
	node *get_head()
	{
		return head;
	}
	node *get_tail()
	{
		return tail;
	}
	node *operator [](int i)
	{
		node *res = head;
		while(i--)
			res = res->get_next();
		return res;
	}
};

bool detect_cycle(linked_list *ll)
{
	node *slow = ll->get_head();
	node *fast = ll->get_head();
	do
	{
		if(fast->get_next() == NULL || fast->get_next()->get_next() == NULL)
			return 0;
		fast = fast->get_next()->get_next();
		slow = slow->get_next();
	} while(slow != fast);

	return 1;
}

int main()
{
	std::cout << "Input array size, array of integers and an index to cycle" << std::endl;
	int n, ind;
	std::cin >> n;
	linked_list *ll = new linked_list();
	for(int i = 0; i < n; i++)
	{
		int x;
		std::cin >> x;
		ll->add_back(x);
	}
	std::cin >> ind;
	ll->get_tail()->set_next((*ll)[ind]);

	if(detect_cycle(ll))
		std::cout << "Cycle detected";
	else
		std::cout << "No cycle";
	std::cout << std::endl;

	delete ll;
	return 0;
}