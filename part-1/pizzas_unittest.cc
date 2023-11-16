// Doina Bein
// dbein@fullerton.edu
// @dbein
//
// Lab 11-01
// Partners: kevinwortman
//
// Object-oriented Pizza class.
//

/* Do not edit below this line. */
/* Do not edit below this line. */
/* Do not edit below this line. */

#include "pizzas.h"

#include <gtest/gtest.h>

TEST(PizzaTest, ReadCSV) {
  std::vector<std::vector<std::string>> csv{ReadCSV("pizza_types.csv", 9)};
  ASSERT_FALSE(csv.empty());
  ASSERT_EQ(67, csv.size());

  ASSERT_EQ(9, csv.at(0).size());
  EXPECT_EQ("pizza_type", csv.at(0).at(0));
  EXPECT_EQ("ingredients", csv.at(0).at(8));

  ASSERT_EQ(9, csv.at(1).size());
  EXPECT_EQ("bbq_ckn", csv.at(1).at(0));
  EXPECT_EQ(
      "Barbecued Chicken, Red Peppers, Green Peppers, Tomatoes, Red Onions, "
      "Barbecue Sauce",
      csv.at(1).at(8));

  ASSERT_EQ(9, csv.at(66).size());
  EXPECT_EQ("veggie_veg", csv.at(66).at(0));
  EXPECT_EQ(
      "Mushrooms, Tomatoes, Red Peppers, Green Peppers, Red Onions, Zucchini, "
      "Spinach, Garlic",
      csv.at(66).at(8));
}

TEST(PizzaTest, DefaultConstructor) {
  Pizza def;
  EXPECT_EQ("", def.Name());
  EXPECT_DOUBLE_EQ(0.0, def.Price());
  EXPECT_EQ(0, def.Calories());
}

TEST(PizzaTest, ConstructorAndName) {
  Pizza spizza_bbq{"bbq_ckn_s", 12.75, 1478};
  Pizza spizza_veg{"veggie_veg_s", 12.00, 1139};
  EXPECT_EQ("bbq_ckn_s", spizza_bbq.PizzaID());
  EXPECT_EQ("veggie_veg_s", spizza_veg.PizzaID());
}

TEST(PizzaTest, ConstructorAndPopulation) {
  Pizza spizza_bbq{"bbq_ckn_s", 12.75, 1478};
  Pizza spizza_veg{"veggie_veg_s", 12.00, 1139};
  EXPECT_DOUBLE_EQ(12.75, spizza_bbq.Price());
  EXPECT_DOUBLE_EQ(12.00, spizza_veg.Price());
}

TEST(PizzaTest, ConstructorAndLandArea) {
  Pizza spizza_bbq{"bbq_ckn_s", 12.75, 1478};
  Pizza spizza_veg{"veggie_veg_s", 12.00, 1139};
  EXPECT_EQ(1478, spizza_bbq.Calories());
  EXPECT_EQ(1139, spizza_veg.Calories());
}

TEST(PizzaTest, PricePer2000Calories) {
  Pizza spizza_bbq{"bbq_ckn_s", 12.75, 1478};
  Pizza spizza_veg{"veggie_veg_s", 12.00, 1139};
  EXPECT_NEAR(17.253, spizza_bbq.PricePer2000Calories(), .1);
  EXPECT_NEAR(21.071, spizza_veg.PricePer2000Calories(), .1);
}

TEST(PizzaTest, ReadStatesFailure) {
  std::vector<Pizza> pizzas{ReadPizzas("NONEXISTENT.csv")};
  EXPECT_TRUE(pizzas.empty());
}

TEST(PizzaTest, ReadPizzasSuccess) {
  std::vector<pizza> pizzas{ReadPizzas("pizza_types.csv")};
  ASSERT_FALSE(pizzas.empty());
  ASSERT_EQ(66, pizzas.size());

  EXPECT_EQ("bbq_ckn_s", pizzas.at(0).PizzaID());
  EXPECT_DOUBLE_EQ(12.75, pizzas.at(0).Price());
  EXPECT_EQ(1478, pizzas.at(0).Calories());

  EXPECT_EQ("cali_ckn_s", pizzas.at(10).PizzaID());
  EXPECT_DOUBLE_EQ(12.75, pizzas.at(10).Price());
  EXPECT_EQ(900, pizzas.at(10).Calories());

  EXPECT_EQ("classic_dlx_m", pizzas.at(20).PizzaID());
  EXPECT_DOUBLE_EQ(16.00, pizzas.at(20).Price());
  EXPECT_EQ(2320, pizzas.at(20).Calories());

  EXPECT_EQ("green_garden_l", pizzas.at(30).PizzaID());
  EXPECT_DOUBLE_EQ(20.25, pizzas.at(30).Price());
  EXPECT_EQ(2480, pizzas.at(30).Calories());

  EXPECT_EQ("mediterraneo_s", pizzas.at(40).PizzaID());
  EXPECT_DOUBLE_EQ(12.00, pizzas.at(40).Price());
  EXPECT_EQ(1260, pizzas.at(40).Calories());

  EXPECT_EQ("pep_msh_pep_m", pizzas.at(50).PizzaID());
  EXPECT_DOUBLE_EQ(14.50, pizzas.at(50).Price());
  EXPECT_EQ(1790, pizzas.at(50).Calories());

  EXPECT_EQ("prsc_argla_l", pizzas.at(60).PizzaID());
  EXPECT_DOUBLE_EQ(20.75, pizzas.at(60).Price());
  EXPECT_EQ(1694, pizzas.at(60).Calories());
}
