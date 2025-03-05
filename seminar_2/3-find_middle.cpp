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

node *middle_node(linked_list *ll)
{
	node *slow = ll->get_head();
	node *fast = ll->get_head();
	while(fast != NULL && fast->get_next() != NULL)
	{
		slow = slow->get_next();
		fast = fast->get_next()->get_next();
	}
	return slow;
}

int main()
{
	std::cout << "Input array size, array of integers" << std::endl;
	int n;
	std::cin >> n;
	linked_list *ll = new linked_list();
	for(int i = 0; i < n; i++)
	{
		int x;
		std::cin >> x;
		ll->add_back(x);
	}

	std::cout << "Median value:" << std::endl;
	std::cout << middle_node(ll)->get_val() << std::endl;

	delete ll;
	return 0;
}