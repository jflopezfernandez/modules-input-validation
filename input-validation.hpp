
/** Input Validation Module
 *  Author: Jose Fernando Lopez Fernandez
 *  Date: 	10-JUL-2017
 *
 *  Description:
 *  	Header-only template input validation. The caller specifies
 *  	the required input type in the function call as follows:
 *
 * 		auto userResponse = IO::get<[TYPE]>();
 *
 * 		Examples:
 * 		auto age  = IO::get<int>();
 * 		auto name = IO::get<std::string>();
 *
 */

#ifndef _INPUT_VALIDATION_HPP
#define _INPUT_VALIDATION_HPP

/** Required STL Header Files for this module:
 *  #include <iostream>
 *  #include <limits>
 *  #include <typeinfo>
 *
 */


namespace IO {

	template <typename T>
	void print(const T& input)
	{
		std::cout << input << ' ';
	}


	template <typename T, typename... Types>
	void print(const T& firstArg, const Types&... arguments)
	{
		std::cout << firstArg << ' ';
		print(arguments...);
	}

	
	template <typename T>
	void println(const T& input)
	{
		std::cout << input << std::endl;
	}
	
	
	template <typename T, typename... Types>
	void println(const T& firstArg, const Types&... arguments)
	{
		std::cout << firstArg << std::endl;
		println(arguments...);
	}
	
	
	template <typename T>
	T get()
	{
		auto IO_status_flag = false;
		
		T response;
		std::cin >> response;
		
		do {
			if (std::cin.fail()) {
					
				IO::print("[Error] Please enter a valid response:");
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
