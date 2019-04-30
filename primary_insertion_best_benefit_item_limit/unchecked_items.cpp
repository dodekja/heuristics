#include "pch.h"
#include "items"
#include <fstream>
#include <string>
#include <algorithm>
#include <iostream>


unchecked_items::unchecked_items()
{
	unchecked_items_ = new std::vector<knapsack_item*>();
	not_inserted_items_ = new std::vector<knapsack_item*>();
}

void unchecked_items::load() const
{
	std::fstream weights("H5_a.txt");
	std::fstream prices("H5_c.txt");
	unsigned int price;
	unsigned int weight;
	while (weights >> weight && prices >> price)
	{
		unchecked_items_->push_back(new knapsack_item(price,weight));
	}
	std::sort(unchecked_items_->begin(),unchecked_items_->end(),sort_knapsack_items_by_benefit);
}


knapsack_item* unchecked_items::get_item() const
{
	const auto item = unchecked_items_->at(unchecked_items_->size() - 1);
	unchecked_items_->pop_back();
	return item;
}

knapsack_item* unchecked_items::get_next_appropriate_item(const unsigned int capacity) const
{
	auto item = get_item();
	while (!unchecked_items_->empty())
	{
		if (item->get_weight() <= capacity)
		{
			break;	
		}
		not_inserted_items_->push_back(item);
		item = get_item();
	}

	if (unchecked_items_->empty())
	{
		return nullptr;
	}
	return item;

}

void unchecked_items::print_unchecked() const
{
	for (auto item : *unchecked_items_)
	{
		std::cout << item->to_string();
	}
}

void unchecked_items::print_not_inserted() const
{
	for (auto item : *not_inserted_items_)
	{
		std::cout << item->to_string();
	}
}

bool unchecked_items::sort_knapsack_items_by_benefit(knapsack_item* item_1, knapsack_item* item_2)
{
	return item_1->get_benefit() < item_2->get_benefit();
}

unchecked_items::~unchecked_items()
{
	for (auto item : *unchecked_items_)
	{
		delete item;
	}
	delete unchecked_items_;
	unchecked_items_ = nullptr;
	for (auto item : *not_inserted_items_)
	{
		delete item;
	}
	delete not_inserted_items_;
	not_inserted_items_ = nullptr;
}
