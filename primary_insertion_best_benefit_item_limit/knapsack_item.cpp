#include "pch.h"
#include <sstream>
#include "knapsack_item.h"

knapsack_item::knapsack_item(const unsigned int price,const unsigned int weight): price_(price), weight_(weight)
{
}

int knapsack_item::get_price() const
{
	return price_;
}

int knapsack_item::get_weight() const
{
	return weight_;
}

double knapsack_item::get_benefit() const
{
	return price_ / static_cast<double>(weight_);
}

std::string knapsack_item::to_string() const
{
	std::stringstream ss;
	ss << "price: " << std::to_string(price_) << " weight: " << std::to_string(weight_) << " coefficient: " << get_benefit() << std::endl;
	return ss.str();
}

knapsack_item::~knapsack_item()
= default;
