#include <iostream>
#include <cstdlib>
#include "menu_function.hpp"
namespace {
	const MDP::MenuItem* show_menu(const MDP::MenuItem* current) {
		for (int i = 1; i < current->children_count; i++) {
			std::cout << current->children[i]->title << std::endl;
		}
		std::cout << current->children[0]->title << std::endl;
		
		int user;
		std::cin>>user;
		std::cout << std::endl;
		
		return current->children[user];
	}
}





const MDP::MenuItem* MDP::show_menu1(const MenuItem* current) {
	
	std::cout << "Главное меню: " << std::endl << std::endl;
	return show_menu(current);
}


const MDP::MenuItem* MDP::show_menu3(const MenuItem* current) {
	
	std::cout << "Третий уровень 1-го класса: " << std::endl << std::endl;
	return show_menu(current);
}



const MDP::MenuItem* MDP::show_menu2(const MenuItem* current) {
	
	std::cout << "Второй уровень меню: " << std::endl << std::endl;
	return show_menu(current);
}








const MDP::MenuItem* MDP::exit(const MenuItem* current) {
	std::exit(0);
}
	
	
	
const MDP::MenuItem* MDP::first(const MenuItem* current) {
	
	std::cout << "Изучать предметы 1-го класса" << std::endl << std::endl;
	return current->parent;
}
	
	
const MDP::MenuItem* MDP::second(const MenuItem* current) {
	
	std::cout << "Изучать предметы 2-го класса" << std::endl << std::endl;
	return current->parent;
}


const MDP::MenuItem* MDP::third(const MenuItem* current) {
	
	std::cout << "Изучать предметы 3-го класса" << std::endl << std::endl;
	return current->parent;
}

const MDP::MenuItem* MDP::go_back_main(const MenuItem* current) {
	
	std::cout << "Выйти в главное меню" << std::endl << std::endl;
	return current->parent->parent;
}
	






const MDP::MenuItem* MDP::russian(const MenuItem* current) {
	
	std::cout << "Русский язык" << std::endl << std::endl;
	return current->parent;
}	
	
const MDP::MenuItem* MDP::literature(const MenuItem* current) {
	
	std::cout << "Литература" << std::endl << std::endl;
	return current->parent;
}	
	
const MDP::MenuItem* MDP::math(const MenuItem* current) {
	
	std::cout << "Математика" << std::endl << std::endl;
	return current->parent;
}		
	
const MDP::MenuItem* MDP::sport(const MenuItem* current) {
	
	std::cout << "Я люблю физкульутуру" << std::endl << std::endl;
	return current->parent;
}	
	

const MDP::MenuItem* MDP::go_back_1(const MenuItem* current) {
	
	std::cout << "Выйти в предыдущее меню" << std::endl << std::endl;
	return current->parent->parent;
}
