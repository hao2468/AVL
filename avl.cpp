#include"avl.h"
template<typename Comparable>
AVL::AVL() 
{
	
}

template<typename Comparable>
AVL::AVL(const AVL & avl)
{}

template<typename Comparable>
AVL(const AVL && avl)
{

}

template<typename Comparable>
AVL::~AVL()
{
	this.empty(this.root);
}

bool isin(Comparable & c)const
{}
bool isEmpty()const {
	
}
template<typename Comparable>
AVL AVL::empty()
{}
AVL insert(const Comparable & c)
{}
AVL insert(Comparable && c)
{}
AVL remove(const Comparable & c)
{}
void printtree()const
{}
Comparable findmax()const
{}
Comparable findmin()const
{}
AVL & operator=(const AVL & avl)
{}
AVL & operator=(AVL && avl)
{}
void setroot()
{}

void setroot(const Comparable & c, Node * t)
{}
bool isin(Comparable & c, Node * t)const
{}
bool isEmpty(Node * t)const
{}
AVL empty(Node * t)
{}
AVL insert(const Comparable & c, Node * t)
{}
AVL insert(Comparable && c, Node * t)
{}
AVL remove(const Comparable & c, Node * t)
{}
void printtree(Node * t)const
{}
Comparable findmax(Node * t)const
{}
Comparable findmin(Node * t)const
{}
