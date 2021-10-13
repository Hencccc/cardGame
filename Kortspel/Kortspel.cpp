#include <iostream>
#include <ctime>
#include <string>

int randomizeSuit() {
	return rand() % 4 + 1;
}

int randomizeCard() {
	int collectionOfCards[13] = { 1,2,3,4,5,6,7,8,9,10,11,12,13 };
	return collectionOfCards[rand() % 12 + 0];
}

std::string drawCards(std::string suits[]) {


	int playerCard = randomizeCard();
	int comCard = randomizeCard();


	printf("Player has drawn a %i \n", playerCard);
	printf("Com has drawn a %i \n", comCard);
	int playerSuit = 0, comSuit = 0;

	if (playerCard == comCard) {
		playerSuit = randomizeSuit();
		comSuit = randomizeSuit();

		while (playerSuit == comSuit) {
			comSuit = randomizeSuit();
		}
		std::cout << "Players suit is: " << suits[playerSuit - 1] << std::endl;
		std::cout << "Coms suit is: " << suits[comSuit - 1] << std::endl;

		if (playerSuit > comSuit) {
			return "playerWins";
		}
		else {
			return "comWins";
		}
	}

	if (playerCard > comCard) {
		return "playerWins";
	}
	else if (comCard > playerCard) {
		return "comWins";
	}
	else {
		return "lika";
	}
}

int main()
{
	srand(time(NULL));
	std::string suit[4] = { "Clubs","Diamonds" ,"Hearts", "Spades" };
	int playerPoints = 0, comPoints = 0, totalPlayerPoints=0, totalComPoints=0;
	bool gameLoop = true;
	printf("Welcome to the card game!\n");

	while (gameLoop) {
		while (true) {
			printf("\nPress enter to draw cards!\n");
			std::cin.get();
			std::string result = drawCards(suit);

			if (result == "playerWins") {
				playerPoints++;
				printf("The player now has %i points!\n", playerPoints);
			}
			else if (result == "comWins") {
				comPoints++;
				printf("The computer now has %i points!\n",comPoints);
			}
			else {
				std::cout << "Tie round, no points given!\n";
			}

			if (playerPoints == 2) {
				printf("\nplayer won with %i - %i\n", playerPoints, comPoints);
				totalPlayerPoints++;
				break;
			}
			else if (comPoints == 2) {
				printf("\nCom won with %i - %i\n", playerPoints, comPoints);
				totalComPoints++;
				break;
			}
		}

		while (true) {
			std::cout << "\n\nPlay again? Press A\nStop playing? Press S\n";
			char response;																																					
			std::cin >> response;
			if (response=='A' || response =='a') {
				playerPoints = 0;
				comPoints = 0;
				break;
			}
			else if (response == 'S' || response == 's') {
				std::cout << "\nThanks for playing!\n Total points are:\nPlayer: " << totalPlayerPoints << "\nComputer: " << totalComPoints << std::endl;
				gameLoop = false;
				break;
			}
			else {
				std::cout << "Bad input, try again\n";
			}
		}
	}

	std::cin.ignore();

}
