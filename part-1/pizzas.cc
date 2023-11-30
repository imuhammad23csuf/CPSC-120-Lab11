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

// TODO(imuhammad23): complete the definition of this constructor.
// Since this is a constructor, it should use a member initialization
// list to initialize data members.
// When you are done, delete this comment.
Pizza::Pizza(std::string pizza_id, double price, int calories)
    : pizza_id_(std::move(pizza_id)), price_(price), calories_(calories) {}

// TODO(imuhammad23): complete the definition of this constructor.
// Since this is a constructor, it should use a member initialization list
// to initialize data members.
// When you are done, delete this comment.
Pizza::Pizza() : price_(0.0), calories_(0) {}

// TODO(imuhammad23): write statements to implement this function, and delete
// this comment.
// Hint: This is a simple accessor function. The function definition only
// needs to be a single statement.
std::string Pizza::PizzaID() const { return pizza_id_; }

// TODO(imuhammad23): write statements to implement this function, and delete
// this comment.
// Hint: This is a simple accessor function. The function definition
// only needs to be a single statement.
double Pizza::Price() const { return price_; }

// TODO(imuhammad23): write statements to implement this function, and delete
// this comment.
// Hint: This is a simple accessor function. The function definition
// only needs to be a single statement.
int Pizza::Calories() const { return calories_; }

// TODO(imuhammad23): write statements to implement this function, and delete
// this comment.
// Hint: the price-per-2000 calories is the ratio between the
// price of that pizza and its number of calories it has,
// multiplied by 2000.
double Pizza::PricePer2000Calories() const {
  return (price_ / calories_) * 2000;
}

// TODO(imuhammad23): write statements to implement this function, and delete
// this comment.
std::vector<Pizza> ReadPizzas(const std::string& csv_filename) {
  // Create an empty vector of Pizzas
  std::vector<Pizza> pizzas;

  // Call ReadCSV to create a 2D vector of strings
  std::vector<std::vector<std::string>> pizza_data = ReadCSV(csv_filename, 4);

  // Loop through each row of the CSV but skip the header row
  for (size_t j = 1; j < pizza_data.size(); ++j) {
    // Read the vector of strings at row j
    std::vector<std::string> pizza_row = pizza_data[j];

    // Retrieve the pizza_id (as a string) from column 1
    std::string pizza_id = pizza_row[0];

    // Retrieve the price (as a string) from column 3
    double price = std::stod(pizza_row[2]);

    // Retrieve the calories (as a string) from column 4
    int calories = std::stoi(pizza_row[3]);

    // Create an object of class Pizza with the data from columns 1, 3, and 4
    Pizza pizza(pizza_id, price, calories);

    // Add the object with push_back to the vector of objects of class Pizza
    pizzas.push_back(pizza);
  }

  // TODO(imuhammad23): delete the return statement below
  return pizzas;
  // and replace it with one that actually works, which is the
  // vector of pizzas
}