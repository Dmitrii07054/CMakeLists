#pragma once

#include "menu.hpp"

namespace MDP {
	const MenuItem* exit(const MenuItem* current);
	
	const MenuItem* show_menu1(const MenuItem* current);
	const MenuItem* show_menu2(const MenuItem* current);
	const MenuItem* show_menu3(const MenuItem* current);
	
	const MenuItem* first(const MenuItem* current);
	const MenuItem* second(const MenuItem* current);
	const MenuItem* third(const MenuItem* current);
	
	const MenuItem* go_back_main(const MenuItem* current);
	
	const MenuItem* russian(const MenuItem* current);
	const MenuItem* literature(const MenuItem* current);
	const MenuItem* math(const MenuItem* current);
	const MenuItem* sport(const MenuItem* current);
	const MenuItem* go_back_1(const MenuItem* current);
}




