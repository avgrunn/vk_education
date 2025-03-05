#include <iostream>

class node
{
	int val;
	node *next;
public:
	node(int x = 0)
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
		if(head == NULL)
			return;

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
	node *set_head(node *new_node)
	{
		head = new_node;
		return head;
	}
	node *set_tail(node *new_node)
	{
		tail = new_node;
		return tail;
	}
	friend std::ostream &operator<<(std::ostream &output, const linked_list &ll);
	int get_size()
	{
		int res = 0;
		node *curr = head;
		while(curr != NULL)
		{
			res++;
			curr = curr->get_next();
		}
		return res;
	}
};
std::ostream &operator<<(std::ostream &output, const linked_list &ll)
{
	node *curr_node = ll.head;
	while (curr_node != NULL)
	{
		output << curr_node->get_val() << ' ';
		curr_node = curr_node->get_next();
	}
	return output;
}

void merge_lists(linked_list *ll1, linked_list *ll2)
{
	if(ll1->get_head()->get_val() > ll2->get_head()->get_val())
		std::swap(ll1, ll2);
	node *i1 = ll1->get_head(), *i1_prev = NULL, *i2 = ll2->get_head(), *i2_prev = NULL;
	while(i1 != NULL && i2 != NULL)
	{
		std::cout << i1->get_val() << ' ' << i2->get_val() << std::endl;
		if(i2->get_val() < i1->get_val())
		{
			// insert before i1
			i1_prev->set_next(i2);
			i2_prev = i2;
			i2 = i2->get_next();
			i2_prev->set_next(i1);

			i2_prev = NULL;
			i1_prev = i2_prev;
		}
		else
		{
			i1_prev = i1;
			i1 = i1->get_next();
		}
	}
	if(i2 != NULL)
	{
		ll1->get_tail()->set_next(i2);
		ll1->set_tail(ll2->get_tail());
	}
}

int main()
{
	std::cout << "Input array size and a sorted array of integers, then another array size and a sorted array of integers" << std::endl;
	int n, m;
	linked_list *ll1 = new linked_list(), *ll2 = new linked_list();
	std::cin >> n;
	for(int i = 0; i < n; i++)
	{
		int x;
		std::cin >> x;
		ll1->add_back(x);
	}
	std::cin >> m;
	for(int i = 0; i < m; i++)
	{
		int x;
		std::cin >> x;
		ll2->add_back(x);
	}

	merge_lists(ll1, ll2);
	std::cout << "Merged lists:" << std::endl;
	std::cout << *ll1 << std::endl;

	delete ll1;
	return 0;
}