#include "Harl.hpp"

void Harl::debug( void ) {
	std::cout << "[ DEBUG ]\n";
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger.\n";
	std::cout << "I really do!\n\n";
}

void Harl::info( void ) {
	std::cout << "[ INFO ]\n";
	std::cout << "I cannot believe adding extra bacon costs more money.\n";
	std::cout << "You didn’t put enough bacon in my burger!\n";
	std::cout << "If you did, I wouldn’t be asking for more!\n\n";
}

void Harl::warning( void ) {
	std::cout << "[ WARNING ]\n";
	std::cout << "I think I deserve to have some extra bacon for free.\n";
	std::cout << "I’ve been coming for years whereas you started working here since last month.\n\n";
}

void Harl::error( void ) {
	std::cout << "[ ERROR ]\n";
	std::cout << "This is unacceptable, I want to speak to the manager now.\n\n";
}

void Harl::complain( std::string level ) {
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*funcPtr[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	int caseNum;

	for (caseNum = 0; caseNum < 4; caseNum++) {
		if (levels[caseNum] == level) {
			break ;
		}
	}

	switch (caseNum) {
	case 0:
		(this->*funcPtr[0])();
		// fall through
	case 1:
		(this->*funcPtr[1])();
		// fall through
	case 2:
		(this->*funcPtr[2])();
		// fall through
	case 3:
		(this->*funcPtr[3])();
		break ;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]\n";
	}
}
