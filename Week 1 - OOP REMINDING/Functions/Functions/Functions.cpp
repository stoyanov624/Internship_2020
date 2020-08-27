#include <iostream>
#include <functional>
#include <vector>

/*template <class T>
std::function<T(T)> maximizing(const T& argument,const std::vector<std::function<T(T)>>& functions)
{
	size_t max_index = 0;
	for (size_t i = 1, SIZE = functions.size(); i < SIZE; i++)
	{
		if (functions[max_index](argument) < functions[i](argument)) 
		{
			max_index = i;
		}
	}
	std::cout << "RETURNING FUNCTION #" << max_index + 1 << std::endl;
	return functions[max_index];
} */

template <class T>
std::function<T(T)> extreme(const T& argument, const std::vector<std::function<T(T)>>& functions,const std::function<bool(T,T)>& comparator)
{
	size_t max_index = 0;
	for (size_t i = 1, SIZE = functions.size(); i < SIZE; i++)
	{
		if (comparator(functions[max_index](argument),functions[i](argument)))
		{
			max_index = i;
		}
	}

	std::cout << "RETURNING FUNCTION #" << max_index + 1 << std::endl;
	return functions[max_index];
}

template <class T>
std::function<T(T)> maximizing(const T& argument, const std::vector<std::function<T(T)>>& functions)
{
	std::function<bool(T, T)> lessThan = [](T left, T right) { return left < right; };
	return extreme(argument, functions, lessThan);
}

template <class T>
std::function<T(T)> minimizing(const T& argument, const std::vector<std::function<T(T)>>& functions)
{
	std::function<bool(T, T)> greaterThan = [](T left, T right) { return left > right; };
	return extreme(argument, functions, greaterThan);
}

int main()
{
	std::function<int(int)>  f1 = [](int n) {return n*n; };
	std::function<int(int)>  f2 = [](int n) {return n - 10; };
	std::function<int(int)>  f3 = [](int n) {return n + 20; };

	std::function<bool(int, int)> lessThan = [](int left, int right){ return left < right; };
	std::function<bool(int, int)> greaterThan = [](int left, int right){ return left > right; };

	std::function<double(double)>  f4 = [](double n) {return n * n; };
	std::function<double(double)>  f5 = [](double n) {return n - 1.5; };
	std::function<double(double)>  f6 = [](double n) {return n + 1; };

	std::vector<std::function<int(int)>> functions_i = { f1,f2,f3 };
	std::vector<std::function<double(double)>> functions_d = { f4,f5,f6 };
    
	std::cout << maximizing(2, functions_i)(2) << std::endl;
	std::cout << minimizing(2, functions_i)(2) << std::endl;
	std::cout << maximizing(2.5, functions_d)(2.5) << std::endl;
	std::cout << minimizing(2.5, functions_d)(2.5) << std::endl;

	//std::cout << extreme(2, functions_i,lessThan)(2) << std::endl;
	//std::cout << extreme(2, functions_i,greaterThan)(2) << std::endl;
	//std::cout << maximizing(2.2, functions_d)(2.2) << std::endl;
}
