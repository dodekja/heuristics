#pragma once
#include <vector>
#include "knapsack_item.h"

class unchecked_items
{
	std::vector<knapsack_item*>* unchecked_items_;
	std::vector<knapsack_item*>* not_inserted_items_;
public:
	unchecked_items();
	void load() const;

	knapsack_item* get_item() const;
	knapsack_item* get_next_appropriate_item(unsigned int capacity) const;

	void print_unchecked() const;
	void print_not_inserted() const;
	static bool sort_knapsack_items_by_benefit(knapsack_item* item_1,knapsack_item* item_2);

	~unchecked_items();
};

