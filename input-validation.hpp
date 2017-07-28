
/** Input Validation Module
 *  Author: Jose Lopez
 *
 *  Description:
 *  	Header-only runtime input validation
 *
 *	Input Validation:
 *
 * 		The caller specifies the required input
 * 		type in the function call as follows:
 *
 * 		auto userResponse = IO::get<[TYPE]>();
 *
 * 		Example:
 * 		auto age  = IO::get<int>();
 * 		auto name = IO::get<std::string>();
 *
 *
 *    Contributors:
 *    Daniel Jour (https://codereview.stackexchange.com/users/20977/daniel-jour)
 *    Loki Astari (https://codereview.stackexchange.com/users/507/loki-astari)
 */

#ifndef _INPUT_VALIDATION_HPP
#define _INPUT_VALIDATION_HPP


#include <iostream>
#include <limits>
#include <typeinfo>


// TODO: Fix module "half-checks"


namespace IO {
	
	template <typename T>
	T get()
	{
		auto IO_status_flag = false;
		
		T response;
		std::cin >> response;
		
		do {
			if (std::cin.fail()) {
					
				std::cout << "[Error] Please enter a valid response: ";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				
				std::cin >> response;
			} else {
				IO_status_flag = true;
			}
		} while (IO_status_flag != true);
		
		return response;
	}
	
}


#endif /* _INPUT_VALIDATION_HPP */
