#include "Span.hpp"
#include <iostream>

int main(void)
{
	{
		std::cout << "Copy Contructor Test" << std::endl;
		Span sp1 = Span(5);
		sp1.addNumber(6);
		sp1.addNumber(3);
		Span sp2(sp1);
		sp2.printElements();
	}

	{
		std::cout << "Copy Operator Test" << std::endl;
		Span sp1 = Span(5);
		sp1.addNumber(6);
		sp1.addNumber(3);
		sp1.addNumber(8);
		Span sp2(2);
		// sp2.addNumber(10);
		// sp2.addNumber(2);
		sp2 = sp1;
		sp2.printElements();
	}

	// Test Written in Subject
	{
		std::cout << "Test Written in Subject" << std::endl;
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "\t" << sp.shortestSpan() << std::endl;
		std::cout << "\t" << sp.longestSpan() << std::endl;
	}

	Span sp2(10);
	try
	{
		// Only One Element
		std::cout << "Test Nothing Element longestSpan()" << std::endl;
		std::cout << "\t" << sp2.longestSpan() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "Test Nothing Element shortestSpan()" << std::endl;
		std::cout << "\t" << sp2.shortestSpan() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "Test Only One Element longestSpan()" << std::endl;
		sp2.addNumber(100);
		std::cout << "\t" << sp2.longestSpan() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "Test Only One Element shorteestSpan()" << std::endl;
		std::cout << "\t" << sp2.shortestSpan() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "Test Same Elements longestSpan()" << std::endl;
		sp2.addNumber(100);
		std::cout << "\t" << sp2.longestSpan() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "Test Same Elements shortestSpan()" << std::endl;
		std::cout << "\t" << sp2.shortestSpan() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	{
		std::cout << "Advanced Test" << std::endl;
		Span sp(10000);
		sp.addRandomNumber();
		//sp.printElements();
		try
		{
			std::cout << "\tlongetSpan: " << sp.longestSpan() << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			std::cout << "\tshortestSpan: " << sp.shortestSpan() << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return 0;
}
