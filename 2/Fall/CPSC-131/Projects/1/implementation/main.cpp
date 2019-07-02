#include <string>
#include <iostream>
#include "GroceryInventory.hpp"
#include "GroceryItem.hpp"

int main(){
	std::string name = "Food";
	GroceryItem item(name, 100, 10.09, true);
	GroceryInventory inventory;

	inventory.add_item(item);
	inventory.print_inventory();
	return 0;
}
