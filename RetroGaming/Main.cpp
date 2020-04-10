/*
	This file is part of {{ RetroGaming }}.

	Copyright [2019] [Justin LeCheminant]

	Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

	http://www.apache.org/licenses/LICENSE-2.0

	Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

 */

#include <vector>
#include <iostream>

#include "GuessTheNumber.h"
#include "HangMan.h"
#include "BeerRun.h"
#include "BlackJack.h"
#include "Psuedonym.h"
#include "Palindromes.h"
#include "Anagrams.h"
#include "NullCipher.h"
#include "MonsterRats.h"
#include "MontyHall.h"
#include "Substitution.h"
#include "RailFence.h"

using namespace std;

vector<shared_ptr<GameBase>> GetGames();
void PrintNames(vector<shared_ptr<GameBase>> games);
shared_ptr<GameBase> GetGameToPlay();


int main()
{
	auto gameToPlay = GetGameToPlay();
	
	cout << endl << endl;

	gameToPlay->play();

	return 0;

}


// FUNCTIONS
vector<shared_ptr<GameBase>> GetGames()
{
	vector<shared_ptr<GameBase>> games;

	// TODO: Find a way to load these in a DI like manner

	auto guessTheNumber = make_shared<GuessTheNumber>();
	games.push_back(std::move(guessTheNumber));

	auto hangman = make_shared<HangMan>();
	games.push_back(std::move(hangman));

	auto beerrun = make_shared<BeerRun>();
	games.push_back(std::move(beerrun));

	auto blackjack = make_shared<BlackJack>();
	games.push_back(std::move(blackjack));

	auto psuedonyme = make_shared<Psuedonym>();
	games.push_back(std::move(psuedonyme));

	auto palindromes = make_shared<Palindromes>();
	games.push_back(std::move(palindromes));

	auto anagrams = make_shared<Anagrams>();
	games.push_back(std::move(anagrams));

	auto null_cipher = make_shared<NullCipher>();
	games.push_back(std::move(null_cipher));

	auto rats = make_shared<MonsterRats>();
	games.push_back(std::move(rats));

	auto montyHall = make_shared<MontyHall>();
	games.push_back(std::move(montyHall));

	auto substitution = make_shared<Substitution>();
	games.push_back(std::move(substitution));

	auto fence = make_shared<RailFence>();
	games.push_back(std::move(fence));

	return games;

}

void PrintNames(vector<shared_ptr<GameBase>> games)
{
	auto counter = 1;

	cout << "Select a game" << endl << endl;
	
	for(const auto& game: games)
	{
		cout << "(" << counter++ << ") " << game->getName() << endl;
	}
}

shared_ptr<GameBase> GetGameToPlay()
{
	auto games = GetGames();

	auto maxIndex = games.size();
	auto index = decltype(maxIndex){};
	
	auto validChoice = true;

	do
	{
		PrintNames(games);

		cout << endl << "Selection: ";
		cin >> index;

		if (cin.fail() || index <= 0 || index > maxIndex )
		{
			validChoice = false;
			cin.clear();
			cin.ignore();
			cout << "Invalid Selection" << endl << endl;
		}
		else
		{
			validChoice = true;
		}
	} while (!validChoice);
	
	return games[index - 1];

}