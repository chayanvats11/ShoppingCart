#include<bits/stdc++.h>
using namespace std;

//Product,Item and Cart
class Item;
class Cart;

class Product
{
	int id;
	string name;
	int price;

public:
	Product()
	{

	}

	Product(int uid, string name, int price)
	{
		id = uid;
		this->name = name;
		this->price = price;
	}

	string getDisplayName()
	{
		return name + " : Rs " + to_string(price) + "\n";
	}

	string getShortName()
	{
		return name.substr(0, 1); // return first letter of the product
	}

	friend class Item;
	friend class Cart;
};


class Item
{
	Product product;
	int quantity;

public:
	Item()
	{

	}

	//Constructor using a Init List
	Item(Product p, int q): product(p), quantity(q) {}

	int getItemPrice()
	{
		return quantity * product.price; // price is accessed using making Item as friend class in Product class
	}

	string getItemInfo()
	{
		return to_string(quantity) + " X " + product.name + " = Rs " + to_string(quantity * product.price) + '\n';
	}

	friend class Cart;
};

class Cart
{
	unordered_map<int, Item> items;

public:
	void addProduct(Product product)
	{
		if (items.count(product.id) == 0)
		{
			Item newItem(product, 1);
			items[product.id] = newItem;
		}

		else
		{
			items[product.id].quantity += 1;
		}
	}

	int getTotal()
	{
		int total = 0;
		for (auto itemPair : items)
		{
			auto item = itemPair.second;
			total += item.getItemPrice();
		}

		return total;
	}

	string viewCart()
	{
		if (items.empty())
		{
			return "Cart is empty !";
		}

		string itemizedList;
		int cart_total = getTotal();

		for (auto itemPair : items)
		{
			auto item = itemPair.second;
			itemizedList.append(item.getItemInfo());
		}

		return itemizedList + "\nTotal Amount : Rs " + to_string(cart_total) + '\n';
	}

	bool isEmpty()
	{
		return items.empty();
	}
};