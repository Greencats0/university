#pragma once
#include <string>

class GroceryItem{
	private:
		std::string item_name;
		int quantity;
		double price;
		bool taxable;
	public:
		GroceryItem(std::string name, int item_quantity, double item_price, bool taxation){
			item_name = name;
			quantity = item_quantity;
			price = item_price;
			taxable = taxation;
		}
		std::string get_name();
		int get_quantity();
		double get_price();
		bool get_taxation();
};

std::string GroceryItem::get_name(){ return item_name; }

int GroceryItem::get_quantity(){ return quantity; }

double GroceryItem::get_price() { return price; }

bool GroceryItem::get_taxation() { return taxable; }
