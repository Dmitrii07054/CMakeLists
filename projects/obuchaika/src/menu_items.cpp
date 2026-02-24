#include <iostream>
#include <cstdlib>
#include "menu_function.hpp"
#include "menu_items.hpp"
#include "menu.hpp"

const MDP::MenuItem MDP::RUSSIAN = {
	"1 - Русский язык", MDP::russian, &MDP::FIRST
};

const MDP::MenuItem MDP::LITERATURE = {
	"2 - Русская литература", MDP::literature, &MDP::FIRST
};

const MDP::MenuItem MDP::MATH = {
	"3 - Математика", MDP::math, &MDP::FIRST
};

const MDP::MenuItem MDP::SPORT = {
	"4 - Я люблю физкульутуру", MDP::sport, &MDP::FIRST
};

const MDP::MenuItem MDP::GO_BACK_1 = {
	"0 - Выйти в предыдущее меню", MDP::go_back_1, &MDP::FIRST
};



namespace {
	const MDP::MenuItem* const first_children[] = {
		&MDP::GO_BACK_1,
		&MDP::RUSSIAN,
		&MDP::LITERATURE,
		&MDP::MATH,
		&MDP::SPORT
	};
	const int first_children_size = sizeof(first_children) / sizeof(first_children[0]);
}








const MDP::MenuItem MDP::FIRST = {
	"1 - Изучать предметы 1-го класса", MDP::show_menu3, &MDP::STUDY, first_children, first_children_size
};

const MDP::MenuItem MDP::SECOND = {
	"2 - Изучать предметы 2-го класса", MDP::second, &MDP::STUDY
};

const MDP::MenuItem MDP::THIRD = {
	"3 - Изучать предметы 3-го класса", MDP::third, &MDP::STUDY
};

const MDP::MenuItem MDP::GO_BACK_MAIN = {
	"0 - Выйти в главное меню", MDP::go_back_main, &MDP::STUDY
};



namespace {
	const MDP::MenuItem* const study_children[] = {
		
		&MDP::GO_BACK_MAIN,
		&MDP::FIRST,
		&MDP::SECOND,
		&MDP::THIRD,
	};
	const int study_children_size = sizeof(study_children) / sizeof(study_children[0]);
}













const MDP::MenuItem MDP::STUDY = {
	"1 - Предметы какого класса школы вы хотите изучить?", MDP::show_menu2, &MDP::MAIN, study_children, study_children_size
};

const MDP::MenuItem MDP::EXIT = {
	"0 - Я уже закончил школу и всё знаю", MDP::exit, &MDP::MAIN
};




namespace {
	const MDP::MenuItem* const main_children[] = {
		
		&MDP::EXIT,
		&MDP::STUDY
	};
	const int main_children_size = sizeof(main_children) / sizeof(main_children[0]);
}


const MDP::MenuItem MDP::MAIN = {
	nullptr, MDP::show_menu1, nullptr, main_children, main_children_size
};


