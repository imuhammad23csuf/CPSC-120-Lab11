# Pizza Class

The purpose of this exercise is for you to write code dealing with an object-oriented class.
The given code includes a program in `main.cc` that uses a class called `Pizza`.
The bodies of `Pizza`'s member functions are TODOs. Your task is to fill in the function definitions so that the program works properly.

## What to Do

1. With your partner, edit the `states.cc` source file using VS Code. Add the required header. Replace all the TODO comments with working code.
1. Compile your program with the `$ make` shell command. Use the **debug compile error** procedure to debug any compile errors.
1. Run your program with the `$ ./judge` shell command.
1. Test that your program passes all unit tests with the `$ make unittest` command. If your program suffers a runtime error, use the **debug runtime error** procedure to debug the error. If your program does not produce the expected output, use the **debug logic error** procedure to debug the error.
1. Test your program against automated test with the `$ make test` command. Debug any runtime errors or logic errors using the same procedures.
1. Check your header with the `$ make header` shell command. Correct any errors.
1. Check for format errors with the `$ make format` shell command. Correct any errors.
1. Check for lint errors with the `$ make lint` shell command. Correct any errors.
1. After your program passes all of these tests and checks, push your code to GitHub. Use the usual trio of commands: `git add`, `git commit`, and `git push`.

## Introduction

As [explained in learncpp.com section 2.11](https://www.learncpp.com/cpp-tutorial/header-files/),
source modules should be divided into two linked files, a `.h` *header file* and `.cc` *source file.*
This lab is following this practice. The `Pizza` class is declared in the header file `pizzas.h`, and
the function definitions go in the source file `pizzas.cc`.

This program is divided into several files:
1. `pizzas.h` is a header file that declares the `Pizza` class.  **Do not change this file.**
1. `pizzas.cc` is a source file that defines the member functions of the `Pizza` class. Your work is to add working function bodies to this file (and a header comment).
1. `main.cc` defines a `main` function that uses the class `Pizza`. **Do not change this file.**
1. `pizzas_unittest.cc` defines unit tests for the functions of `pizzas.h`.  **Do not change this file.**
1. `pizza_types.csv` is a CSV data file used by the program. **Do not change this file.**

The program is intended to:
1. Read from the [SPizza Types CSV File](https://www.kaggle.com/datasets/doinabein/pizza-calories-and-prices).
1. Create a `std::vector` of `Pizza` objects. Each `Pizza` object represents one type of pizza, that includes the name of the pizza and the size. Each `Pizza` object has data members for the pizza_id, price in US dollars, and number of calories. The information for each pizza comes from the CSV data.
1. Loop through the `Pizza`s to find the pizza with the highest and the lowest price-per-2000 calories. The price-per-2000 calories is the ratio between the price of that pizza and its number of calories it has, multiplied by 2000. The idea is that, let's say that you want to eat 2000 calories of some type of pizza, and you need to know how much you will have to pay.
1. Print out the pizza ID and price per calories of the pizzas with the highest and lowest price-per-2000 calories.

The `main` function in `main.cc` is provided, and implements this algorithm:

```C++
int main(int argc, char* argv[]) {
  std::vector<Pizza> states{ReadPizzas("pizza_types.csv")};

  Pizza highest{pizzas.front()};
  Pizza lowestest{pizzas.front()};
  for (Pizza& pizza : pizzas) {
    if (pizza.PricePer2000Calories() > highest.PricePer2000Calories()) {
      highest = pizza;
    }
    if (pizza.PricePer2000Calories() < lowest.PricePer2000Calories()) {
      lowest = pizza;
    }
  }

  std::cout << "The highest price per 2000 calories pizza is " <<
      highest.PizzaID() << " (" << highest.PricePer2000Calories() << ")\n";

  std::cout << "The lowest price per 2000 calories pizza is " <<
      lowest.PizzaID() << " (" << lowest.PricePer2000Calories() << ")\n";

  return 0;
}
```

## Example Input and Output

```
$ ./pizzas
The highest price per 2000 calories pizza is four_cheese_s (33.6195)
The lowest price per 2000 calories pizza is pepperoni_l (11.2132)
```


## Test Cases

This program does not have manual test cases. Instead, test your function definitions with `$ make unittest` and test your entire program behavior with `$ make test`.



## Next Steps

After you have pushed your code, move on to part 2.
