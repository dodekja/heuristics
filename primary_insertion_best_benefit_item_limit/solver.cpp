#include "pch.h"
#include "solver.h"
#include <iostream>
#include <fstream>


bool solver::load()
{
	std::cout << "Weights file: ";
	std::cin >> weights_filename_;

	std::cout << "Prices file: ";
	std::cin >> prices_filename_;

	return solver::validate_files(weights_filename_, prices_filename_);
}

solver::solver()
{
	while (!load())
	{
		load();
	}

	std::cout << "Knapsack weight capacity: ";
	std::cin >> carrying_capacity_;

	std::cout << "Knapsack item capacity: ";
	std::cin >> item_capacity_;

	knapsack_ = new knapsack(carrying_capacity_,item_capacity_);
	items_ = new items();
	items_->load(weights_filename_,prices_filename_);
}

bool solver::validate_files(const std::string& weights_file, const std::string& prices_file)
{
	std::ifstream weights(weights_file);
	std::ifstream prices(prices_file);
	const bool validity = weights.good() && prices.good();
	if (!validity)
	{
		std::cout << "Invalid file names!";
	}
	weights.close();
	prices.close();
    return validity;
}

void solver::solve() const
{
	auto item = items_->get_next_appropriate_item(knapsack_->get_carrying_capacity());
	while (knapsack_->try_add_item(item))
	{
		item = items_->get_next_appropriate_item(knapsack_->get_carrying_capacity());
		if (item == nullptr)
		{
			break;
		}
	}
	std::cout << std::endl;
	std::cout << knapsack_->to_string();
	std::cout << std::endl;
	std::cout << "Contents of the knapsack:" << std::endl;
	std::cout << knapsack_->print_content();
}

void solver::print_solution() const
{
	std::ofstream file;
	file.open("solution.txt");
	file << knapsack_->to_string() << std::endl << "List of items in knapsack:" << std::endl << knapsack_->print_content();
}


solver::~solver()
{
	delete knapsack_;
	knapsack_ = nullptr;
	delete items_;
	items_ = nullptr;
}
