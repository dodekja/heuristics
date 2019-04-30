#pragma once
#include <vector>
#include "knapsack_item.h"

class knapsack
{
	int carrying_capacity_;
	int item_capacity_;
	int knapsack_price_;
	std::vector<knapsack_item*>* knapsack_;
public:
	knapsack(int carrying_capacity,int item_capacity);

	int get_carrying_capacity() const {return carrying_capacity_;}
	int get_item_capacity() const {return item_capacity_;}
	int get_number_of_inserted_items() const {return static_cast<int>(knapsack_->size());}

	std::string print_content() const;
	std::string to_string() const;
	bool try_add_item(knapsack_item* item);

	~knapsack();
};

