#include"avl.h"
#include<iostream>
int main()
{
	AVL<int> avl1;
	avl1.randomTree(50);
	//avl1.printtree();
	std::cout << "max" << avl1.findmax() << std::endl;
	std::cout << "min" << avl1.findmin() << std::endl;
	std::cout << avl1.getsize() << std::endl;
	avl1.check();

	//avl1.remove(95);
	//avl1.printtree();
	std::cout << "size" << avl1.getsize() << std::endl;
	
	//avl1.printtree();
	avl1.check();
	//avl1.insert(83);
	avl1.test(2);
	//avl1.printtree();
	avl1.check();
	std::cout << "size" << avl1.getsize() << std::endl;

	if (avl1.isin(27))
	{
		std::cout << "yes" << std::endl;
	}
	else
	{
		std::cout << "no" << std::endl;
	}
	if (avl1.isEmpty())
	{
		std::cout << "empty" << std::endl;
	}
	else
	{
		std::cout << "not empty" << std::endl;
	}
	AVL<int> avl2 = avl1;
	avl1.empty();
	//avl1.printtree();
	if (avl1.isEmpty())
	{
		std::cout << "empty" << std::endl;
	}
	else
	{
		std::cout << "not empty" << std::endl;
	}
	/*avl2.printtree();
	avl1.printtree();*/

	AVL<int> avl3;
	avl3.insert(10);
	avl3.insert(20);
	avl3.printtree();
	return 0;
}