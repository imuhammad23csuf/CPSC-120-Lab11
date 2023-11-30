// Ibraheem Muhammad
// imuhammad23@csu.fullerton.edu
// @imuhammad23csuf
// Partners: @erusselbrown

#include "hilo.h"

#include "rng.h"

GameState::GameState(int secret) : secret_{secret}, guesses_left_{4} {
  // DONE: complete the definition of this constructor.

  // Since this is a constructor, it should use a member initialization list

  // to initialize data members.

  // When you are done, delete this comment.
}

int GameState::Secret() const {
  // DONE: complete the definition of this function.

  // Since this is a constructor, it should use a member initialization list

  // to initialize data members.

  // When you are done, delete this comment.

  return secret_;  // DONE: replace this return statement with one that actually

  // works
}

int GameState::GuessesLeft() const {
  // DONE: write statements to implement this function, and delete this comment

  // Hint: This is a simple accessor function. The function definition only

  // needs to be a single statement.

  return guesses_left_;
}

bool GameState::GuessCorrect(int guess) const {
  // DONE: write statements to implement this function, and delete this comment

  // Hint: Use an if statement.

  if (guess == secret_) {
    return true;

  } else {
    return false;

  }  // DONE: replace this return statement with one that actually

  // works
}

bool GameState::GuessTooBig(int guess) const {
  // DONE: write statements to implement this function, and delete this comment

  // Hint: Use an if statement.

  if (guess > secret_) {
    return true;

  } else {
    return false;
  }
}

bool GameState::GuessTooSmall(int guess) const {
  // DONE: write statements to implement this function, and delete this comment

  // Hint: Use an if statement.

  if (guess < secret_) {
    return true;

  } else {
    return false;
  }
}

void GameState::CountGuess() {
  guesses_left_ =

      (guesses_left_ - 1);  // DONE: write statements to implement this

  // function, and delete this comment
}

bool GameState::GameOver() const {
  // DONE: write statements to implement this function, and delete this comment

  if (guesses_left_ == 0) {
    return true;

  } else {
    return false;

  }  // DONE: replace this return statement with one that actually

  // works
}

int RandomSecretNumber() {
  // DONE: write statements to implement this function, and delete this comment

  // Hint: first seed the random number generator

  // then generate a random number between 1 and 10

  // finally return that random number

  RandomNumberGenerator rng(1, 10);

  return static_cast<int>(rng.Next());

  ;  // DONE: replace this return statement with one that actually works
}