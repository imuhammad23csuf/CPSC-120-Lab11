// Doina Bein
// dbein@fullerton.edu
// @dbein
// Partners: @kevinwortman
//
// Object-oriented Pizza class.
//

#include <iostream>
#include <string>
#include <vector>

#include "pizzas.h"

int main(int argc, char* argv[]) {
  std::vector<Pizza> pizzas{ReadPizzas("pizza_types.csv")};
  Pizza highest{pizzas.front()};
  Pizza lowest{pizzas.front()};
  for (Pizza& pizza : pizzas) {
    if (pizza.PricePer2000Calories() > highest.PricePer2000Calories()) {
      highest = pizza;
    }
    if (pizza.PricePer2000Calories() < lowest.PricePer2000Calories()) {
      lowest = pizza;
    }
  }

  std::cout << "The highest price per 2000 calories pizza is "
            << highest.PizzaID() << " (" << highest.PricePer2000Calories()
            << ")\n";

  std::cout << "The lowest price per 2000 calories pizza is "
            << lowest.PizzaID() << " (" << lowest.PricePer2000Calories()
            << ")\n";

  return 0;
}
