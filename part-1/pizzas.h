// Doina Bein
// dbein@fullerton.edu
// @dbein
// Partners: @kevinwortman, @mshafae
//
// Object-oriented Pizza class.
//

#ifndef PIZZAS_H
#define PIZZAS_H

#include <string>
#include <vector>

std::vector<std::vector<std::string>> ReadCSV(const std::string& csv_filename,
                                              int columns);

class Pizza {
 public:
  Pizza(std::string pizza_id, double price, int calories);
  Pizza();
  std::string PizzaID() const;
  double Price() const;
  int Calories() const;
  double PricePer2000Calories() const;

 private:
  std::string pizza_id_;
  double price_;
  int calories_;
};

std::vector<Pizza> ReadPizzas(const std::string& csv_filename);

#endif  // PIZZAS_H_
