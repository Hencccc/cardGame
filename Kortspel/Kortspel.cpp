#include <iostream>
#include <ctime>
#include <string>

//returnerar ett slumpat tal 1-4
int randomizeSuit() {
	return rand() % 4 + 1;
}
//returnerar ett slumpat v�rde ur arrayen via index mellan 0-12
int randomizeCard() {
	int collectionOfCards[13] = { 1,2,3,4,5,6,7,8,9,10,11,12,13 };
	return collectionOfCards[rand() % 12 + 0];
}

//Huvudfunktionen som returnerar resultatet fr�n en runda, antingen lika eller vinst f�r dator/spelare
std::string drawCards(std::string suits[]) {

	//slumpar ett kort f�r spelaren och datorn
	int playerCard = randomizeCard();
	int comCard = randomizeCard();

	//utskrift av spelarnas kort
	printf("Player has drawn a %i \n", playerCard);
	printf("Com has drawn a %i \n", comCard);
	int playerSuit = 0, comSuit = 0;

	//ifall korten har samma v�rde slumpas �ven deras f�rg nedan
	if (playerCard == comCard) {
		playerSuit = randomizeSuit();
		comSuit = randomizeSuit();

		/*Om deras f�rg �ven slumpades till samma slumpas det p� nytt f�r datorns f�rg tills det inte �r samma som spelarens,
		eftersom det i koden �r spelarens f�rg som slumpas f�rst*/
		while (playerSuit == comSuit) {
			comSuit = randomizeSuit();
		}
		//Utskrift av spelarens och datorns f�rg p� korten
		std::cout << "Players suit is: " << suits[playerSuit - 1] << std::endl;
		std::cout << "Coms suit is: " << suits[comSuit - 1] << std::endl;

		//avg�r vinnare av f�rg
		if (playerSuit > comSuit) {
			return "playerWins";
		}
		else {
			return "comWins";
		}
	}

	//avg�r vinnare av endast kortv�rde
	if (playerCard > comCard) {
		return "playerWins";
	}
	else if (comCard > playerCard) {
		return "comWins";
	}
}

int main()
{
	//Deklarering av variablar samt stringarray med kortens f�rger
	srand(time(NULL));
	std::string suit[4] = { "Clubs", "Diamonds", "Hearts", "Spades" };
	int playerPoints = 0, comPoints = 0, totalPlayerPoints = 0, totalComPoints = 0;
	bool gameLoop = true;
	printf("Welcome to the card game!\n");

	//Stor loop som sk�ter spelet
	while (gameLoop) {
		//Loop som sk�ter omg�ngarna i spelet
		while (true) {
			/*Utskrift att man ska trycka enter f�r att dra korten.
			Funktionen drawCards() k�rs och skickar med stringarrayen suit som parameter.
			Resultatet sparas i stringen "result".*/
			printf("\nPress enter to draw cards!\n");
			std::cin.get();
			std::string result = drawCards(suit);

			/*Om v�rdet p� "result" �r "playerWins" har spelaren vunnit och spelaren f�r po�ng och utskrift av detta.
			�r v�rdet "comWins" har datorn vunnit och f�r po�ng och utskrift av detta sker.*/
			if (result == "playerWins") {
				playerPoints++;
				printf("The player now has %i points!\n", playerPoints);
			}
			else if (result == "comWins") {
				comPoints++;
				printf("The computer now has %i points!\n", comPoints);
			}

			/*Ifall spelaren eller datorn uppn�tt 2 po�ng har denna vunnit. Totalpo�ng adderas med 1 till vinnaren och
			koden breakar ut ifr�n loopen f�r omg�ngar i spelet.*/
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

		//Loop som sk�ter forts�ttning/avslutning av spelet
		while (true) {
			/*Utskrift ges att ifall man vill spela igen ska man mata in A och vill man sluta matar man in S.
			Inmatningen sparas som en karakt�r i "response".*/
			std::cout << "\n\nPlay again? Press A\nStop playing? Press S\n";
			char response;
			std::cin >> response;
			/*�r response=A eller response=a resetas spelarnas omg�ngspo�ng och koden breakar ur loopen som kontrollerar avslutet/forts�ttningen.
			Eftersom gameLoop fortfarande �r true k�rs spelet igen.*/
			if (response == 'A' || response == 'a') {
				playerPoints = 0;
				comPoints = 0;
				break;
			}
			/*Om response=S eller response=s ges en utskrift av dem totala po�ngen, gameLoop s�tts till false och koden breakar ut ifr�n loopen
			f�r avslutet/forts�ttningen*/
			else if (response == 'S' || response == 's') {
				std::cout << "\nThanks for playing!\n Total points are:\nPlayer: " << totalPlayerPoints << "\nComputer: " << totalComPoints << std::endl;
				gameLoop = false;
				break;
			}
			//Vid felaktig inmatning f�r man f�rs�ka igen.
			else {
				std::cout << "Bad input, try again\n";
			}
		}
	}

	std::cin.ignore();

}
