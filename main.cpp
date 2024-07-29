#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

#ifdef unix
const char *clear = "clear";
#endif
#ifdef _WIN32
const char *clear = "cls";
#endif

#define MAX_TRIES 6

#define MAX_WORDS 8
const std::string words[MAX_WORDS] = {"hello",     "world",       "computer",
                                      "science",   "mathematics", "physics",
                                      "chemistry", "programming"};

int randnum() {
  // pass unix epoch as a seed to rand()
  srand(time(NULL));
  return rand() % (MAX_WORDS - 1);
}

void print_logo() {
  std::cout
      << " _____                    _____ _           _    _               _ \n"
      << "|  __ \\                  |_   _| |         | |  | |             | "
         "|\n"
      << "| |  \\/_   _  ___  ___ ___ | | | |__   ___ | |  | | ___  _ __ __| "
         "|\n"
      << "| | __| | | |/ _ \\/ __/ __|| | | '_ \\ / _ \\| |/\\| |/ _ \\| '__/ "
         "_` |\n"
      << "| |_\\ \\ |_| |  __/\\__ \\__ \\| | | | | |  __/\\  /\\  / (_) | | | "
         "(_| |\n"
      << " \\____/\\__,_|\\___||___/___/\\_/ |_| |_|\\___| \\/  \\/ \\___/|_|  "
         "\\__,_|\n\n\n";
}

void play() {
  char player_guess;
  std::string word = words[randnum()];
  bool win = false;
  std::string whole_guess;

  std::string guessed = std::string(word.length(), '_');

  for (int tries = 1; tries <= MAX_TRIES; tries++) {
    system(clear);

    print_logo();
    std::cout << "Word: " << guessed << "\n"
              << "Tries: " << tries << "/" << MAX_TRIES << "\n"
              << "$ to Skip" << "\n\n"
              << "Enter a Letter: ";

    std::cin >> player_guess;

    if (player_guess == '$') {
      break;
    }

    for (int i = 0; i < word.length(); i++) {
      if (word[i] == player_guess) {
        guessed[i] = player_guess;
      }
    }
    if (guessed == word) {
      win = true;
      break;
    }
  }

  if (!win) {
    std::cout << "Enter the Whole Word: ";
    std::cin >> whole_guess;
  }

  std::cout << "\nThe word was: " << word << "\n";
  if ((whole_guess == word) || guessed == word) {
    std::cout << "\nYou Win :)\n";
  } else {
    std::cout << "\nYou Lose :(\n";
  }
}

int main() {
  int choice = 0;

  while (choice != 2) {
    system(clear);
    print_logo();
    std::cout << "1. Play\n"
              << "2. Exit\n";

    std::cout << "\nChoose Option: ";
    std::cin >> choice;

    switch (choice) {
    case 1:
      play();
      break;
    case 2:
      return 0;
    default:
      std::cout << "\nInvalid Option";
      break;
    }

    // press enter to continue
    std::cout << "\n\nPress Enter to Continue...";
    std::cin.ignore();
    std::cin.get();
  }
}
