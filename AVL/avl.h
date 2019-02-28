/*
	�ļ�����avl.h
	����������AVL�����ʵ�֣�AVL��������ƽ�������Ĳ��Ҷ�������ƽ������Ϊÿ���ڵ�����������߶Ȳ����1��
	�޸�ʱ�䣺2019/2/28
	�޸��ˣ�hao
*/
#pragma once
#ifndef _AVL_H_
#define _AVL_H_
#include <iostream>
#include<time.h>
template<typename Comparable>
class AVL
{
public:
	AVL();
	AVL(const AVL & avl);
	AVL(AVL && avl);
	~AVL();
	AVL & operator=(const AVL & avl);
	AVL & operator=(AVL && avl);
	
	bool isin(const Comparable & c);
	bool isin(Comparable && c);
	bool isEmpty();
	void empty();
	void insert(const Comparable & c);
	void insert(Comparable && c);
	void remove(const Comparable & c);
	void remove(Comparable && c);
	void printtree();
	Comparable findmax();
	Comparable findmin();
	void randomTree(long size);
	Comparable getsize()const;
	void check();
	void test(int x);
	
private:
/*
	���ڵ�ṹ
	������Ա����ǰ�ڵ�洢����content
			  ָ�����������Ľڵ�ָ��left��right��Ĭ��Ϊnullptr
			  ��ǰ�ڵ�߶ȣ�Ĭ��Ϊ0��ƽ�������ж����ݣ�
*/
	struct Node
	{
		Comparable content;
		Node * left;
		Node * right;
		int height;
		Node(const Comparable & c = NULL, Node * l = nullptr, Node * r = nullptr, int h = 0) :content{ c }, left{ l }, right{ r }, height{h} {};
		Node(Comparable && c,Node * l = nullptr, Node * r = nullptr, int h = 0) :content{ std::move(c) }, left{ l }, right{ r }, height{ h } {};
	};
	Node * root = nullptr;
	int sizeoftree;

	bool isin(const Comparable & c,Node * & t)const;
	bool isin(Comparable && c, Node * & t);
	bool isEmpty(Node * & t)const;
	void empty(Node * & t);
	void insert(const Comparable & c, Node * & t);
	void insert(Comparable && c, Node * & t);
	void remove(const Comparable & c, Node * & t);
	void remove(Comparable && c, Node * & t);
	void printtree(Node * & t)const;
	Comparable findmax(Node * & t)const;
	Comparable findmin(Node * & t)const;
	void randomTree(long size,Node * & t);
	void balance(Node * & t);
	int getheight(Node * & t)const;
	void leftrotate(Node * & t1);
	void rightrotate(Node * & t1);
	void leftdoublerotate(Node * & t1);
	void rightdoublerotate(Node * & t1);
	void test(int x, Node * & t);
};

template<typename Comparable>
AVL<Comparable>::AVL()
{
	root = new Node();
	sizeoftree = 0;
}

template<typename Comparable>
AVL<Comparable>::AVL(const AVL & avl)
{
	root = avl.root;
}

template<typename Comparable>
AVL<Comparable>::AVL(AVL && avl)
{
	root = std::move(avl.root);
}

/*
	��������
	����ʱ����������нڵ�
*/
template<typename Comparable>
AVL<Comparable>::~AVL()
{
	empty(root);
}

template<typename Comparable>
AVL<Comparable> & AVL<Comparable>::operator=(const AVL & avl)
{
	AVL copy = avl;
	std::swap(*this, copy);
	return *this;
}

template<typename Comparable>
AVL<Comparable> & AVL<Comparable>::operator=(AVL && avl)
{
	std::swap(root, std::move(avl.root));
	return this;
}

/*
	�Ӵ�����126-196Ϊ��˽�з����Ĺ��е��ýӿڣ������ⲿ�����ڵ�ָ���ֱ�Ӳ���
*/
template<typename Comparable>
bool AVL<Comparable>::isin(const Comparable & c)
{
	return isin(c, root);
}

template<typename Comparable>
bool AVL<Comparable>::isin(Comparable && c)
{
	return isin(std::move(c), root);
}

template<typename Comparable>
bool AVL<Comparable>::isEmpty() 
{
	return isEmpty(root);
}

template<typename Comparable>
void AVL<Comparable>::empty()
{
	empty(root);
}

template<typename Comparable>
void AVL<Comparable>::insert(const Comparable & c)
{
	insert(c, root);
}

template<typename Comparable>
void AVL<Comparable>::insert(Comparable && c)
{
	insert(std::move(c), root);
}

template<typename Comparable>
void AVL<Comparable>::remove(const Comparable & c)
{
	remove(c, root);
}

template<typename Comparable>
void AVL<Comparable>::remove(Comparable && c)
{
	remove(std::move(c), root);
}

template<typename Comparable>
void AVL<Comparable>::printtree()
{
	printtree(root);
}

template<typename Comparable>
Comparable AVL<Comparable>::findmax()
{
	return findmax(root);
}

template<typename Comparable>
Comparable AVL<Comparable>::findmin()
{
	return findmin(root);
}

template<typename Comparable>
void AVL<Comparable>::randomTree(long size)
{
	randomTree(size, root);
}

/*
	��ȡ����ǰ�Ľڵ���
*/
template<typename Comparable>
Comparable AVL<Comparable>::getsize()const
{
	return sizeoftree;
}

/*
	���������AVL��
*/
template<typename Comparable>
void AVL<Comparable>::randomTree(long size,Node * & t)
{
	sizeoftree = 0;
	srand(time(0));
	for (long x = 0; x < size; x++)
	{
		insert(rand());
	}
}

/*
	�������Ƿ��Ѵ洢Ŀ�����ݣ���ֵ���ð汾
*/
template<typename Comparable>
bool AVL<Comparable>::isin(const Comparable & c, Node * & t)const
{
	if (t != nullptr)
	{
		if (c < t->content)
		{
			return isin(c, t->left);
		}
		else if (c > t->content)
		{
			return isin(c, t->right);
		}
		else
		{
			std::cout << "not&&" << std::endl;
			return true;
		}
	}
	else
	{
		return false;
	}
}

/*
	�������Ƿ��Ѵ洢Ŀ�����ݣ���ֵ���ð汾
*/
template<typename Comparable>
bool AVL<Comparable>::isin(Comparable && c, Node * & t)
{
	if (t != nullptr)
	{
		if (c < t->content)
		{
			return isin(std::move(c), t->left);
		}
		else if (c > t->content)
		{
			return isin(std::move(c), t->right);
		}
		else
		{
			std::cout << "&&" << std::endl;
			return true;
		}
	}
	else
	{
		return false;
	}
}

/*
	�������Ƿ�Ϊ����
*/
template<typename Comparable>
bool AVL<Comparable>::isEmpty(Node * & t)const
{
	if (t == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*
	��������нڵ�
*/
template<typename Comparable>
void AVL<Comparable>::empty(Node * & t)
{
	if (t = nullptr)
	{
		if (t->left != nullptr)
		{
			empty(t->left);
		}
		if (t->right != nullptr)
		{
			empty(t->right);
		}
		delete t;
		t = nullptr;
		sizeoftree--;
	}
}

/*
	��������Ŀ�����ݣ���ֵ���ð汾
*/
template<typename Comparable>
void AVL<Comparable>::insert(const Comparable & c, Node * & t)
{
	if (t != nullptr)
	{
		if (t == root && t->content == NULL)
		{
			root->content = c;
			sizeoftree++;
		}
		else if (c < t->content)
		{
			insert(c, t->left);
		}
		else if (c > t->content)
		{
			insert(c, t->right);
		}
		else
		{ }
	}
	else
	{
		t = new Node(c);
		sizeoftree++;
	}
	balance(t);
}

/*
	��������Ŀ�����ݣ���ֵ���ð汾
*/
template<typename Comparable>
void AVL<Comparable>::insert(Comparable && c, Node * & t)
{
	if (t != nullptr)
	{
		if (t == root && t->content == NULL)
		{
			root->content = std::move(c);
		}
		else if (c < t->content)
		{
			insert(std::move(c), t->left);
		}
		else if (c > t->content)
		{
			insert(std::move(c), t->right);
		}
		else
		{
		}
	}
	else
	{
		t = new Node(std::move(c));
		sizeoftree++;
	}
	balance(t);
}

/*
	ɾ�����е�ָ�����ݣ���ֵ���ð汾
*/
template<typename Comparable>
void AVL<Comparable>::remove(const Comparable & c, Node * & t)
{
	if (t != nullptr)
	{
		if (c < t->content)
		{
			remove(c, t->left);
		}
		else if (c > t->content)
		{
			remove(c, t->right);
		}
		else
		{
			if (t->left != nullptr && t->right != nullptr)
			{
				t->content = findmax(t->left);
				remove(t->content, t->left);
			}
			else
			{
				Node * old = t;
				t = (t->left == nullptr) ? t->right : t->left;
				delete old;
				sizeoftree--;
			}
		}
		balance(t);
	}
}

/*
	ɾ�����е�ָ�����ݣ���ֵ���ð汾
*/
template<typename Comparable>
void AVL<Comparable>::remove(Comparable && c, Node * & t)
{
	if (t != nullptr)
	{
		if (c < t->content)
		{
			remove(std::move(c), t->left);
		}
		else if (c > t->content)
		{
			remove(std::move(c), t->right);
		}
		else
		{
			if (t->left != nullptr && t->right != nullptr)
			{
				t->content = findmax(t->left);
				remove(t->content, t->left);
			}
			else
			{
				Node * old = t;
				t = (t->left == nullptr) ? t->right : t->left;
				delete old;
				sizeoftree--;
			}
		}
		balance(t);
	}
}

/*
	��ӡ�������нڵ�����
*/
template<typename Comparable>
void AVL<Comparable>::printtree(Node * & t)const
{
	if (t != nullptr)
	{
		if (t->left != nullptr)
		{
			printtree(t->left);
			std::cout << t->content << std::endl;
		}
		else
		{
			std::cout << t->content << std::endl;
		}
		if (t->right != nullptr)
		{
			printtree(t->right);
		}
	}
}

/*
	���������е����Ԫ��
*/
template<typename Comparable>
Comparable AVL<Comparable>::findmax(Node * & t)const
{
	if (t->right != nullptr)
	{
		return findmax(t->right);
	}
	else
	{
		return t->content;
	}
}

/*
	���������е���СԪ��
*/
template<typename Comparable>
Comparable AVL<Comparable>::findmin(Node * & t)const
{
	if (t->left != nullptr)
	{
		return findmin(t->left);
	}
	else 
	{
		return t->content;
	}
}

/*
	�������в����ɾ�����޸Ĳ���ʱ������ƽ��������������ƽ��
*/
template<typename Comparable>
void AVL<Comparable> ::balance(Node * & t)
{
	if (t != nullptr)
	{
		if(t->left == nullptr && t->right == nullptr)
		{ }
		else
		{
			if (getheight(t->left) - getheight(t->right) > 1)
			{
				if (getheight(t->left->left) >= getheight(t->left->right) )
				{
					leftrotate(t);
				}
				else
				{
					leftdoublerotate(t);
				}
			}
			else if (getheight(t->right) - getheight(t->left) > 1)
			{
				if (getheight(t->right->right) >= getheight(t->right->left))
				{
					rightrotate(t);
				}
				else
				{
					rightdoublerotate(t);
				}
			}
			t->height = (getheight(t->left) >= getheight(t->right) ? getheight(t->left) : getheight(t->right)) + 1;
		}
	}
}

/*
	��ȡ�ڵ�߶ȣ����������ж�ƽ������
*/
template<typename Comparable>
int AVL<Comparable> ::getheight(Node * & t)const
{
	return (t != nullptr ? t->height : -1);
}

/*
	��������ƽ��Ĳ�����һ������
	��ʧ��ڵ���������߶ȱ��������߶ȸߣ��Ҹýڵ����������������߶ȱȸýڵ����������������ĸ߶ȸ�ʱ����
*/
template<typename Comparable>
void AVL<Comparable>::leftrotate(Node * & t1) 
{
	Node * t2 = t1->left;
	t1->left = t2->right;
	t2->right = t1;
	t1->height = (getheight(t1->left) >= getheight(t1->right) ? getheight(t1->left) : getheight(t1->right)) + 1;
	t2->height = (getheight(t2->left) >= getheight(t1) ? getheight(t2->left) : getheight(t1)) + 1;
	t1 = t2;
}

/*
	��������ƽ��Ĳ�����һ������
	��ʧ��ڵ���������߶ȱ��������߶ȸߣ��Ҹýڵ����������������߶ȱȸýڵ����ӵ����������ĸ߶ȸ�ʱ����
*/
template<typename Comparable>
void AVL<Comparable>::rightrotate(Node * & t1)
{
	Node * t2 = t1->right;
	t1->right = t2->left;
	t2->left = t1;
	t1->height = (getheight(t1->left) >= getheight(t1->right) ? getheight(t1->left) : getheight(t1->right)) + 1;
	t2->height = (getheight(t1) >= getheight(t2->right) ? getheight(t1) : getheight(t2->right)) + 1;
	t1 = t2;
}

/*
	��������ƽ��Ĳ�������������
	��ʧ��ڵ���������߶ȱ��������߶ȸߣ��Ҹýڵ����������������߶ȱȸýڵ����������������ĸ߶ȵ�ʱ����
*/
template<typename Comparable>
void AVL<Comparable>::leftdoublerotate(Node * & t1)
{
	rightrotate(t1->left);
	leftrotate(t1);
}

/*
	��������ƽ��Ĳ�������������
	��ʧ��ڵ���������߶ȱ��������߶ȸߣ��Ҹýڵ����������������߶ȱȸýڵ����ӵ����������ĸ߶ȵ�ʱ����
*/
template<typename Comparable>
void AVL<Comparable>::rightdoublerotate(Node * & t1)
{
	leftrotate(t1->right);
	rightrotate(t1);
}

/*
	�����÷�����ͨ�����ڵ�����������߶��Ƿ�����ƽ���������������Ƿ�ƽ��
	������÷���test�������ϵ��ã��ж�����ƽ������
*/
template<typename Comparable>
void AVL<Comparable>::check()
{
	std::cout << "left height" << getheight(root->left) << std::endl;
	std::cout << "right height" << getheight(root->right) << std::endl;
}

template<typename Comparable>
void AVL<Comparable>::test(int x)
{
	test(x, root);
}

/*
	�����÷�����ɾ��������Ϊx�ı����Ľڵ�
	������÷���check�������ϵ��ã��ж�����ƽ������
*/
template<typename Comparable>
void AVL<Comparable>::test(int x,Node * & t)
{
	if (t != nullptr)
	{
		if (t->left != nullptr)
		{
			test(x, t->left);
		}
		if (t->right != nullptr)
		{
			test(x, t->right);
		}
		if (t->content%x == 0)
		{
			remove(t->content, t);
		}
	}
}
#endif