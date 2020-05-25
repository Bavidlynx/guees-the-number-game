#include<string>
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<vector>
#include<fstream>

void save_score(int count)
{
    std::ifstream input("best_scores.txt");

    if(!input.is_open())
    {
        std::cout << "Unable to read file\n";
        return;
    }

    int best_scores;
    input >> best_scores;

    std::ofstream output("best_scores.txt");


    if(!output.is_open())
    {
        std::cout << "Unable to read file\n";
        return;
    }

    if(count < best_scores)
    {
        output << count;
    }
    else
    {
        output << best_scores;
    }
}

void print_vector(std::vector<int> vector)
{
    for(int i = 0;i < vector.size(); i++)
    {
        std::cout << vector[i] << "\t";
    }
    std::cout << "\n";
}

void play_game()
{
    std::vector<int> guesses;

    int count = 0;

    int random = rand() % 251;

    std::cout<< random <<std::endl;
    std::cout << "guess a number" << std::endl;
    while(true)
    {
        int guess;
        std::cin >> guess;
        count++;

        guesses.push_back(guess);

        if(guess == random)
        {
            std::cout << "YOU WIN\n" << std::endl;
            break;
        }
        else if (guess < random)
        {
            std::cout << "too low\n"<<std::endl;
        }
        else
        {
            std::cout << "too high" << std::endl;
        }
    }

    save_score(count);

    print_vector(guesses);
}

int main()
{
    srand(time(NULL));
    int choice;
    do
    {
        std::cout << "0. QUIT" << std::endl << "1. Play Game\n";
        std::cin >>choice;

        switch(choice)
        {
            case 0:
                std::cout << "Thanks for nothing\n";
                return 0;
            case 1:
                play_game();
                break;
        }
    }
    while (choice != 0);
}
