#ifndef _INPUT_VALIDATION_HPP
#define _INPUT_VALIDATION_HPP


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
	
}


#endif /* _INPUT_VALIDATION_HPP */
