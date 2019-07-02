#pragma once
#include <vector>
#include "GroceryItem.hpp"
#include <iostream>

class GroceryInventory{
	public:
		void print_inventory();
		double potential_revenue();
		void add_item(GroceryItem item);
		double tax_revenue();
		double total_revenue();
	private:
		std::vector<GroceryItem> inventory;
};

void GroceryInventory::print_inventory(){
	for(auto item : inventory){
		std::cout << item.get_name() << std::endl;
	}
}

void GroceryInventory::add_item(GroceryItem item){ inventory.push_back(item); }

double GroceryInventory::potential_revenue(){
	int revenue = 0;
	for(auto product : inventory){
		revenue+=(product.get_price() * product.get_quantity());
	}
	return revenue;
}


double GroceryInventory::tax_revenue(){
	double rate = 0.08;
	double amount = 0.0;
	for(auto element : inventory){
		if(element.get_taxation()){
			amount+=(rate*element.get_price()*element.get_quantity());
		}
	}
	return amount;
}

double GroceryInventory::total_revenue(){
	return potential_revenue()+tax_revenue();
}
