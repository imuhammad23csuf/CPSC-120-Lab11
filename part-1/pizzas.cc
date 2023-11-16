// TODO add a header

#include <fstream>
#include <iostream>

#include "pizzas.h"

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

// TODO: complete the definition of this constructor.
// Since this is a constructor, it should use a member initialization
// list to initialize data members.
// When you are done, delete this comment.
Pizza::Pizza(std::string pizza_id, double price, int calories) {}

// TODO: complete the definition of this constructor.
// Since this is a constructor, it should use a member initialization list
// to initialize data members.
// When you are done, delete this comment.
Pizza::Pizza() {}

// TODO: write statements to implement this function, and delete
// this comment.
// Hint: This is a simple accessor function. The function definition only
// needs to be a single statement.
std::string Pizza::PizzaID() const {
  // TODO: delete the return statement below
  return "";
}

// TODO: write statements to implement this function, and delete
// this comment.
// Hint: This is a simple accessor function. The function definition
// only needs to be a single statement.
double Pizza::Price() const {
  // TODO: delete the return statement below
  return 0.0;
}

// TODO: write statements to implement this function, and delete
// this comment.
// Hint: This is a simple accessor function. The function definition
// only needs to be a single statement.
int Pizza::Calories() const {
  // TODO: delete the return statement below
  return 0;
}

// TODO: write statements to implement this function, and delete
// this comment.
// Hint: the price-per-2000 calories is the ratio between the
// price of that pizza and its number of calories it has,
// multiplied by 2000.
double Pizza::PricePer2000Calories() const {
  // TODO: delete the return statement below
  return 0;
}

// TODO: write statements to implement this function, and delete
// this comment.
std::vector<Pizza> ReadPizzas(const std::string& csv_filename) {
  // Create an empty vector of Pizzas
  // Call ReadCSV to create a 2D vector of strings
  // Loop through each row of the CSV but skip the header row
  // which is the first row, that contains the names of the
  // columns, i.e. do not read the first row
  // - Read the vector of strings at row j
  // - Retrieve the pizza_id (as a string) from column 1
  // - Retrieve the price (as a string) from column 3
  // - Retrieve the calories (as a string) from column 4
  // - Convert the string at column 3 into a double
  // - Convert the string at column 4 into an integer
  // - Create an object of class Pizza with the data from columns 1, 3, and 4
  // - Add the object with push_back to the vector of objects of class Pizza
  // TODO: delete the return statement below
  return std::vector<Pizza>{};
  // and replace it with one that actually works, which is the
  // vector of pizzas
}