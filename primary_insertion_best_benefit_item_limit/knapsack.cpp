#include "pch.h"
#include <iostream>
#include <sstream>
#include "knapsack_item.h"
#include "knapsack.h"

knapsack::knapsack(int const carrying_capacity,const int item_capacity):
carrying_capacity_(carrying_capacity),
item_capacity_(item_capacity),
knapsack_price_(0)
{
	knapsack_ = new std::vector<knapsack_item*>();
}

std::string knapsack::print_content() const
{
	std::string contents;
	for (auto item : *knapsack_)
	{
		contents += item->to_string();
	}

	return contents;
}

std::string knapsack::to_string() const
{
	std::stringstream ss;
	ss << "Free carrying capacity: " << carrying_capacity_ << std::endl << "Free item capacity: " << item_capacity_ << std::endl <<
		"Price of items in knapsack: " << knapsack_price_ << std::endl;
	return ss.str();
}

bool knapsack::try_add_item(knapsack_item* item)
{
	if (item_capacity_ - 1 <= 0 || carrying_capacity_ < static_cast<int>(item->get_weight()))
	{
		return false;
	}
	knapsack_->push_back(item);
	item_capacity_--;
	knapsack_price_ += item->get_price();
	carrying_capacity_ -= item->get_weight();
	return true;
}

knapsack::~knapsack()
{
	for (auto item : *knapsack_)
	{
		delete item;
		item = nullptr;
	}
	delete knapsack_;
	knapsack_ = nullptr;

	carrying_capacity_ = 0;
	item_capacity_ = 0;
	knapsack_price_ = 0;
}
