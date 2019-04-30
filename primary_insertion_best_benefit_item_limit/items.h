#pragma once
#include <vector>
#include "knapsack_item.h"

class items
{
	std::vector<knapsack_item*>* unchecked_items_;
	std::vector<knapsack_item*>* not_inserted_items_;
public:
	items();

	void load(const std::string& weights_file, const std::string& prices_file) const;

	knapsack_item* get_item() const;
	knapsack_item* get_next_appropriate_item(int capacity) const;

	void print_unchecked() const;
	void print_not_inserted() const;
	static bool sort_knapsack_items_by_benefit(knapsack_item* item_1,knapsack_item* item_2);

	~items();
};

