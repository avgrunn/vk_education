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

class Stack
{
	linked_list *ll;
public:
	Stack()
	{
		ll = new linked_list();
	}
	~Stack()
	{
		delete ll;
	}
	void put_elem(int x)
	{
		ll->add_back(x);
	}
	int pop_elem()
	{
		int res = ll->get_tail()->get_val();
		if(ll->get_head() == ll->get_tail())
		{
			delete ll->get_tail();
			ll->set_head(NULL);
			ll->set_tail(NULL);
			return res;
		}

		node *curr = ll->get_head();
		node *prev = curr;
		while(curr != ll->get_tail())
		{
			prev = curr;
			curr = curr->get_next();
		}
		prev->set_next(NULL);
		ll->set_tail(prev);
		delete curr;
		return res;
	}
	int get_elem()
	{
		return ll->get_tail()->get_val();
	}
	int get_size()
	{
		return ll->get_size();
	}
};

bool is_palindrome(int n, int *a)
{
	Stack *s = new Stack();

	for(int i = 0; i < n; i++)
		s->put_elem(a[i]);
	for(int i = 0; i < n; i++)
	{
		if(a[i] != s->pop_elem())
			return 0;
	}
	delete s;
	return 1;
}

int main()
{
	std::cout << "Input array size and an array of integers" << std::endl;
	int n, *a;
	std::cin >> n;
	a = new int[n];
	for(int i = 0; i < n; i++)
		std::cin >> a[i];

	if(is_palindrome(n, a))
		std::cout << "Is a palindrome";
	else
		std::cout << "Not a palindrome";
	std::cout << std::endl;

	delete[] a;
	return 0;
}