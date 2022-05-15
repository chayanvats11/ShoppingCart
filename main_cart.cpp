#include<bits/stdc++.h>
#include "datamodel.h"
using namespace std;

vector<Product> allProducts = {
	Product(1, "apple", 82),
	Product(3, "mango", 31),
	Product(2, "guava", 43),
	Product(4, "banana", 14),
	Product(5, "strawberry", 110),
	Product(6, "pineapple", 56),
};

Product* chooseProduct()
{
	//Display the list of Products
	string productList;
	cout << "Available Products : " << endl;

	for (auto product : allProducts)
	{
		productList.append(product.getDisplayName());
	}

	cout << productList << endl;
	cout << "-----------------------------------" << endl;

	string choice;
	cin >> choice;

	for (int i = 0; i < allProducts.size(); i++)
	{
		if (allProducts[i].getShortName() == choice)
			return &allProducts[i];
	}

	cout << "Product NOT found !" << endl;
	return NULL;
}

bool checkout(Cart &cart)
{
	if (cart.isEmpty())
	{
		return false;
	}

	int total = cart.getTotal();
	cout << "Pay in Cash : ";

	int paid;
	cin >> paid;

	if (paid >= total)
	{
		cout << "Change = Rs " << paid - total << endl;
		cout << "Thank You for Shopping with us ! Visit Again...";
		return true;
	}
	else
	{
		cout << "NOT enough Cash !";
		return false;
	}
}

int main()
{
	char action;
	Cart cart;
	while (true)
	{
		cout << "Select an action - (a)dd item, (v)iew cart, (c)heckout" << endl;
		cin >> action;

		if (action == 'a')
		{
			//Add to Cart
			//View All Products + Choose Product + Add to Cart
			Product* product = chooseProduct();
			if (product != NULL)
			{
				cout << "Added to Cart " << product->getDisplayName() << endl;
				cart.addProduct(*product);
			}
		}
		else if (action == 'v')
		{
			//View the Cart
			cout << "--------------------" << endl;
			cout << cart.viewCart();
			cout << "--------------------" << endl;
		}
		else
		{
			//Checkout
			cart.viewCart();
			if (checkout(cart))
			{
				break;
			}
		}
	}

	return 0;
}