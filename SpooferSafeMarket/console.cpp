#include "console.h";



void Success(std::string ptr) {
	std::cout << "[ " << termcolor::green << "+" << termcolor::reset << " ] > " << ptr << std::endl;
}

void Warning(std::string ptr) {
	std::cout << "[ " << termcolor::yellow << "!" << termcolor::reset << " ] > " << ptr << std::endl;
}

void Error(std::string ptr) {
	std::cout << "[ " << termcolor::red << "/" << termcolor::reset << " ] > " << ptr << std::endl;
}

void Header() {


	std::cout << termcolor::yellow << R"(                https://safemarket.xyz | https://safemarket.xyz/discord
__| |_____________________________________________________________________________| |__
__   _____________________________________________________________________________   __
  | |                                                                             | |  
  | | ____     _     _____  _____      __  __     _     ____   _  __ _____  _____ | |  
  | |/ ___|   / \   |  ___|| ____|    |  \/  |   / \   |  _ \ | |/ /| ____||_   _|| |  
  | |\___ \  / _ \  | |_   |  _|      | |\/| |  / _ \  | |_) || ' / |  _|    | |  | |  
  | | ___) |/ ___ \ |  _|  | |___     | |  | | / ___ \ |  _ < | . \ | |___   | |  | |  
  | ||____//_/   \_\|_|    |_____|    |_|  |_|/_/   \_\|_| \_\|_|\_\|_____|  |_|  | |  
__| |_____________________________________________________________________________| |__
__   _____________________________________________________________________________   __
  | |                                                                             | |  
)" << termcolor::reset << std::endl;
}