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

class Queue
{
	linked_list *ll;
public:
	Queue()
	{
		ll = new linked_list();
	}
	~Queue()
	{
		delete ll;
	}
	void put_elem(int x)
	{
		ll->add_back(x);
	}
	int pop_elem()
	{
		int res = ll->get_head()->get_val();
		ll->set_head(ll->get_head()->get_next());
		return res;
	}
	int get_elem()
	{
		return ll->get_head()->get_val();
	}
	int get_size()
	{
		return ll->get_size();
	}
};

bool is_subsequence(int n, int *a, int m, int *b)
{
	Queue *q = new Queue();

	for(int i = 0; i < n; i++)
		q->put_elem(a[i]);
	for(int i = 0; i < m; i++)
	{
		if(q->get_elem() == b[i])
			q->pop_elem();
	}
	int sz = q->get_size();
	delete q;
	return (sz == 0);
}

int main()
{
	std::cout << "Input array size, array of integers, then another array size and array of integers" << std::endl;
	int n, m, *a, *b;
	std::cin >> n;
	a = new int[n];
	for(int i = 0; i < n; i++)
		std::cin >> a[i];
	std::cin >> m;
	b = new int[m];
	for(int i = 0; i < m; i++)
		std::cin >> b[i];

	if(is_subsequence(n, a, m, b))
		std::cout << "Is a subsequence";
	else
		std::cout << "Not a subsequence";
	std::cout << std::endl;

	delete[] a;
	delete[] b;
	return 0;
}