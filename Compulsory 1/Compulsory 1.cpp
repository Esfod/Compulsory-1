#include <iostream>
#include <string>
#include <vector>;

char numbs[9]{ '1','2','3','4','5','6','7','8','9' };
const char playerSymbol[2]{ 'X', 'O' };
std::vector<int> logg;

class call
{
public:
	void print(int win) //Does all the printiting to console
	{
		const std::string space = "--- --- ---";
		system("cls");
		std::cout << "XXXXXXX Tik Tak Toe XXXXXXX" << std::endl;
		std::cout << "\t " << numbs[0] << " : " << numbs[1] << " : " << numbs[2] << std::endl;
		std::cout << "\t" << space << std::endl;
		std::cout << "\t " << numbs[3] << " : " << numbs[4] << " : " << numbs[5] << std::endl;
		std::cout << "\t" << space << std::endl;
		std::cout << "\t " << numbs[6] << " : " << numbs[7] << " : " << numbs[8] << std::endl;
		if (!win == 0) 
			std::cout << "Player " << win << " has won!!!";
		else 
			std::cout << "Pick an number between 1 and 9.\n";
	}
	
	void setIn(int a, bool p) //puts inn players symbols for the numbers
	{

		int playerStatus;
		if (p) playerStatus = 0;
		else playerStatus = 1;
		numbs[a - 1] = playerSymbol[playerStatus];
		
	}
	
	int checkWin(bool p, int w) //checking all ways to win 
	{
		if (numbs[0] == numbs[1] == numbs[2] || numbs[3] == numbs[4] == numbs[5] || numbs[6] == numbs[7] == numbs[8]) //all horizontal
		{
			if (p)
				w = 1;
			else
				w = 2;
		}
		else if (numbs[0] == numbs[3] == numbs[6] || numbs[1] == numbs[4] == numbs[7] || numbs[2] == numbs[5] == numbs[8]) //all vertical
		{
			if (p)
				w = 1;
			else
				w = 2;
		}
		else if (numbs[0] == numbs[4] == numbs[8] || numbs[2] == numbs[4] == numbs[6]) //all "cross"
		{
			if (p)
				w = 1;
			else
				w = 2;
		}
		return w;
	}
	
	void restart(bool p) //restart the game 
	{
		for (int i = 0; i < 9; i++)
		{
			numbs[i] = i + 1;
		}
		p = true;
	}
};

int main()
{
	call function;
	int input;
	bool player = true; //if false it's player's 2 turn
	int win = 0;// if win = 1, player 1 won. if value 2 player 2 won
	do
	{
		function.print(win);
		std::cin >> input;
		function.setIn(input, player);
		logg.push_back(input);
		for (int i = 0; i < logg.size(); i++)
		{
			if (logg[i] == input) break;
			else
			{
				if (player)player = false; // player != player
				else if (!player) player = true;
			}	
		}
		
	} 
	while (function.checkWin(!player, win) == 0);
	function.checkWin(!player, win);
}
