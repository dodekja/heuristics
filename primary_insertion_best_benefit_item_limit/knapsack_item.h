#pragma once
#include <string>

class knapsack_item
{
	const int price_;
	const int weight_;
public:
	knapsack_item(unsigned int price,unsigned int weight);

	int get_price() const;
	int get_weight() const;
	
	double get_benefit() const;

	std::string to_string() const;

	~knapsack_item();
};

