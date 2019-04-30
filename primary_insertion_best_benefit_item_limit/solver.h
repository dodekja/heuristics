#pragma once
#include "items.h"
#include "knapsack.h"

class solver
{
	items* items_;
	knapsack* knapsack_;
	std::string prices_filename_;
	std::string weights_filename_;
	int carrying_capacity_;
	int item_capacity_;
	bool load();
	bool validate_files(const std::string& weights_file, const std::string& prices_file);
public:
	solver();
	void solve() const;
	void print_solution() const;
	~solver();
};

