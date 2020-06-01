#include <iostream>
using namespace std;
struct tree
{
	int a, b, c;
	tree* mid, * right, * left,*tmp,*prev;
};

int main()
{
	int a;
	tree* tr=NULL;
	while (true)
	{
		cout << "Введите число: ";
		cin >> a;
		if (a == 0)
			break;
		if (tr == NULL)
			tr=newtree(a, tr);
		else
		{

		}
	}

}

tree* newtree(int a, tree* tr)
{
	tr = new tree;
	tr->a = a;
	tr->b = 0;
	tr->c = 0;
	tr->left = tr->mid = tr->right = tr->prev = tr->tmp = NULL;
	return tr;
}
tree* addelem(int a, tree* tr)
{
	bool checkstart=0;
	tree* p;
	p = tr;
	while (true)
	{
		if ((a == p->a) || (a == p->b))
		{
			cout << "Данное число уже существует в дереве\n"; 
			break;
		}
		if ((p->right == NULL) && (p->left == NULL) && (p->mid == NULL))
		{
			p=inkey(a, p);
			p = sort(p);
			


		}
	}
}

tree* inkey(int a, tree* p)
{
	if (p->a == 0)
	{
		p->a = a;
		return p;
	}
	if (p->b == 0)
	{
		p->b = a;
		return p;
	}
	else
	{
		p->c = a;
		return p;
	}
}

tree* split(tree * p)
{
	while ((p->a != 0) && (p->b != 0) && (p->c != 0))
	{
		if (p->prev == NULL)
		{
			p->prev = new tree;
			p->prev->prev = p->prev->tmp = p->prev->mid = NULL;
			p->prev->a = p->b;
			p->prev->b = p->prev->c = 0;
			p->prev->left = p;
			p->prev->right = new tree;
			p->prev->right->tmp = p->prev->right->mid = NULL;
			p->prev->right->prev = p->prev;
			p->prev->right->left = p->right;
			p->prev->right->right = p->tmp;
			p->prev->right->a = p->c;
			p->prev->right->b = p->prev->right->c = 0;
			p->b = 0;
			p->c = 0;
			p->right = p->mid;
			p->mid = NULL;
			p->tmp = NULL;
			p = p->prev;
		}
		else
		{
			if (p->prev->b == 0)
			{
				p->prev->b = p->b;
				p->b = 0;
				p->prev->mid = new tree;
				p->prev->mid->b = p->prev->mid->c = 0;
				p->prev->mid->prev = p->prev;
				p->prev->mid->mid = p->prev->mid->tmp = NULL;
				if (p == p->prev->left)
				{
					p->prev->mid->a = p->c;
					p->prev->mid->left = p->right;
					p->prev->mid->right = p->tmp;
					p->c = 0;
					p->right = p->mid;
					p->mid = p->tmp = NULL;
				}
				else
				{
					p->prev->mid->a = p->a;
					p->prev->mid->right = p->mid;
					p->prev->mid->left = p->left;
					p->a = p->c;
					p->c = 0;
					p->left = p->right;
					p->right = p->tmp;
					p->mid = p->tmp = NULL;
				}
			
				p = p->prev;
			}
			else
			{
				if (p == p->prev->left)
				{
					p->prev->tmp = p->prev->right;
					p->prev->right = p->prev->mid;
					p->prev->c = p->b;
					p->prev->mid = new tree;
					p->prev->mid->prev = p->prev;
					p->prev->mid->mid = p->prev->mid->tmp = NULL;
					p->prev->mid->a = p->c;
					p->prev->mid->b = 0;
					p->prev->mid->c = 0;
					p->prev->mid->left = p->right;
					p->prev->mid->right = p->tmp;
					p->right = p->mid;
					p->mid = p->tmp = NULL;
					p->c = p->b = 0;
					p = p->prev;
				}
				else
				{
					if (p == p->prev->right)
					{

					}
				}

			}
		}
	}
}

tree* sort(tree* p)
{
	int a, b;
	if (p->a > p->b)
	{
		a = p->a;
		p->a = p->b;
		p->b=a;
	}
	if (p->c < p->b)
	{
		a = p->c;
		p->c = p->b;
		p->b=a;
	}
}