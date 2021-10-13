#include <iostream>
#include <ctime>
#include <string>

//returnerar ett slumpat tal 1-4
int randomizeSuit() {
	return rand() % 4 + 1;
}
//returnerar ett slumpat värde ur arrayen via index mellan 0-12
int randomizeCard() {
	int collectionOfCards[13] = { 1,2,3,4,5,6,7,8,9,10,11,12,13 };
	return collectionOfCards[rand() % 12 + 0];
}

//Huvudfunktionen som returnerar resultatet från en runda, antingen lika eller vinst för dator/spelare
std::string drawCards(std::string suits[]) {

	//slumpar ett kort för spelaren och datorn
	int playerCard = randomizeCard();
	int comCard = randomizeCard();

	//utskrift av spelarnas kort
	printf("Player has drawn a %i \n", playerCard);
	printf("Com has drawn a %i \n", comCard);
	int playerSuit = 0, comSuit = 0;

	//ifall korten har samma värde slumpas även deras färg nedan
	if (playerCard == comCard) {
		playerSuit = randomizeSuit();
		comSuit = randomizeSuit();

		/*Om deras färg även slumpades till samma slumpas det på nytt för datorns färg tills det inte är samma som spelarens,
		eftersom det i koden är spelarens färg som slumpas först*/
		while (playerSuit == comSuit) {
			comSuit = randomizeSuit();
		}
		//Utskrift av spelarens och datorns färg på korten
		std::cout << "Players suit is: " << suits[playerSuit - 1] << std::endl;
		std::cout << "Coms suit is: " << suits[comSuit - 1] << std::endl;

		//avgör vinnare av färg
		if (playerSuit > comSuit) {
			return "playerWins";
		}
		else {
			return "comWins";
		}
	}

	//avgör vinnare av endast kortvärde
	if (playerCard > comCard) {
		return "playerWins";
	}
	else if (comCard > playerCard) {
		return "comWins";
	}
}

int main()
{
	//Deklarering av variablar samt stringarray med kortens färger
	srand(time(NULL));
	std::string suit[4] = { "Clubs", "Diamonds", "Hearts", "Spades" };
	int playerPoints = 0, comPoints = 0, totalPlayerPoints = 0, totalComPoints = 0;
	bool gameLoop = true;
	printf("Welcome to the card game!\n");

	//Stor loop som sköter spelet
	while (gameLoop) {
		//Loop som sköter omgångarna i spelet
		while (true) {
			/*Utskrift att man ska trycka enter för att dra korten.
			Funktionen drawCards() körs och skickar med stringarrayen suit som parameter.
			Resultatet sparas i stringen "result".*/
			printf("\nPress enter to draw cards!\n");
			std::cin.get();
			std::string result = drawCards(suit);

			/*Om värdet på "result" är "playerWins" har spelaren vunnit och spelaren får poäng och utskrift av detta.
			Är värdet "comWins" har datorn vunnit och får poäng och utskrift av detta sker.*/
			if (result == "playerWins") {
				playerPoints++;
				printf("The player now has %i points!\n", playerPoints);
			}
			else if (result == "comWins") {
				comPoints++;
				printf("The computer now has %i points!\n", comPoints);
			}

			/*Ifall spelaren eller datorn uppnått 2 poäng har denna vunnit. Totalpoäng adderas med 1 till vinnaren och
			koden breakar ut ifrån loopen för omgångar i spelet.*/
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

		//Loop som sköter fortsättning/avslutning av spelet
		while (true) {
			/*Utskrift ges att ifall man vill spela igen ska man mata in A och vill man sluta matar man in S.
			Inmatningen sparas som en karaktär i "response".*/
			std::cout << "\n\nPlay again? Press A\nStop playing? Press S\n";
			char response;
			std::cin >> response;
			/*Är response=A eller response=a resetas spelarnas omgångspoäng och koden breakar ur loopen som kontrollerar avslutet/fortsättningen.
			Eftersom gameLoop fortfarande är true körs spelet igen.*/
			if (response == 'A' || response == 'a') {
				playerPoints = 0;
				comPoints = 0;
				break;
			}
			/*Om response=S eller response=s ges en utskrift av dem totala poängen, gameLoop sätts till false och koden breakar ut ifrån loopen
			för avslutet/fortsättningen*/
			else if (response == 'S' || response == 's') {
				std::cout << "\nThanks for playing!\n Total points are:\nPlayer: " << totalPlayerPoints << "\nComputer: " << totalComPoints << std::endl;
				gameLoop = false;
				break;
			}
			//Vid felaktig inmatning får man försöka igen.
			else {
				std::cout << "Bad input, try again\n";
			}
		}
	}

	std::cin.ignore();

}
