// Ibraheem Muhammad
// imuhammad23@csu.fullerton.edu
// @imuhammad23csuf
// Partners: @erusselbrown

#include "pizzas.h"

#include <fstream>
#include <iostream>

std::vector<std::vector<std::string>> ReadCSV(const std::string& csv_filename,

                                              int columns) {
  std::vector<std::vector<std::string>> table;

  std::ifstream file(csv_filename);

  // read each row

  while (file.good()) {
    std::vector<std::string> row;

    // read each column

    for (int i = 0; i < columns; ++i) {
      std::string cell;

      file.ignore(1, '"');  // leading quote

      std::getline(file, cell, '"');

      if (i < (columns - 1)) {
        file.ignore(1, ',');  // comma
      }

      row.push_back(cell);
    }

    if (file.good()) {
      table.push_back(row);
    }
  }

  // Return the vector of strings that contains the data from the CSV file

  return table;
}

Pizza::Pizza(std::string pizza_id, double price, int calories)

    : pizza_id_(std::move(pizza_id)), price_(price), calories_(calories) {}

Pizza::Pizza() : pizza_id_(" "), price_(0.0), calories_(0) {}

std::string Pizza::PizzaID() const { return pizza_id_; }

double Pizza::Price() const { return price_; }

int Pizza::Calories() const { return calories_; }

double Pizza::PricePer2000Calories() const {
  return (price_ / calories_) * 2000;
}

std::vector<Pizza> ReadPizzas(const std::string& csv_filename) {
  std::vector<Pizza> pizzas;

  std::vector<std::vector<std::string>> pizza_table = ReadCSV(csv_filename, 9);

  int cout{2};

  for (int i = 1; i < pizza_table.size(); ++i) {
    std::string string_pizza_id{pizza_table[i][1]};

    std::string string_pizza_price{pizza_table[i][3]};

    std::string string_pizza_calories{pizza_table[i][4]};

    double price = std::stod(string_pizza_price);

    int calories = std::stoi(string_pizza_calories);

    Pizza new_pizza(string_pizza_id, price, calories);

    std::cout << cout << std::endl;

    std::cout << "Name: " << new_pizza.PizzaID() << std::endl;

    std::cout << "Price: " << new_pizza.Price() << std::endl;

    std::cout << "Calories: " << new_pizza.Calories() << std::endl;

    pizzas.push_back(new_pizza);
  }

  return pizzas;
}