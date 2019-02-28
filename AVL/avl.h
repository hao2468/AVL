/*
	文件名：avl.h
	类描述：对AVL树类的实现（AVL树：具有平衡条件的查找二叉树，平衡条件为每个节点的左右子树高度差不大于1）
	修改时间：2019/2/28
	修改人：hao
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
	树节点结构
	包含成员：当前节点存储内容content
			  指向左右子树的节点指针left和right，默认为nullptr
			  当前节点高度，默认为0（平衡条件判断依据）
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
	析构函数
	调用时清空树的所有节点
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
	从代码行126-196为各私有方法的公有调用接口，避免外部对树节点指针的直接操作
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
	获取树当前的节点数
*/
template<typename Comparable>
Comparable AVL<Comparable>::getsize()const
{
	return sizeoftree;
}

/*
	生成随机的AVL树
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
	检索树是否已存储目标内容，右值引用版本
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
	检索树是否已存储目标内容，左值引用版本
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
	检索树是否为空树
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
	清空树所有节点
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
	向树插入目标内容，右值引用版本
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
	向树插入目标内容，左值引用版本
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
	删除树中的指定内容，右值引用版本
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
	删除树中的指定内容，左值引用版本
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
	打印树的所有节点内容
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
	检索出树中的最大元素
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
	检索出树中的最小元素
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
	对树进行插入或删除等修改操作时，根据平衡条件对树进行平衡
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
	获取节点高度，被调用于判断平衡条件
*/
template<typename Comparable>
int AVL<Comparable> ::getheight(Node * & t)const
{
	return (t != nullptr ? t->height : -1);
}

/*
	对树进行平衡的操作：一次左旋
	当失衡节点的左子树高度比右子树高度高，且该节点左子树的左子树高度比该节点左子树的右子树的高度高时调用
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
	对树进行平衡的操作：一次右旋
	当失衡节点的右子树高度比左子树高度高，且该节点右子树的右子树高度比该节点右子的树左子树的高度高时调用
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
	对树进行平衡的操作：二次左旋
	当失衡节点的左子树高度比右子树高度高，且该节点左子树的左子树高度比该节点左子树的右子树的高度低时调用
*/
template<typename Comparable>
void AVL<Comparable>::leftdoublerotate(Node * & t1)
{
	rightrotate(t1->left);
	leftrotate(t1);
}

/*
	对树进行平衡的操作：二次右旋
	当失衡节点的右子树高度比左子树高度高，且该节点右子树的右子树高度比该节点右子的树左子树的高度低时调用
*/
template<typename Comparable>
void AVL<Comparable>::rightdoublerotate(Node * & t1)
{
	leftrotate(t1->right);
	rightrotate(t1);
}

/*
	测试用方法：通过根节点的左右子树高度是否满足平衡条件，检验树是否平衡
	与测试用方法test（）联合调用，判断树的平衡性能
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
	测试用方法：删除树内容为x的倍数的节点
	与测试用方法check（）联合调用，判断树的平衡性能
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