#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <queue>
#include <list>
#include <forward_list>
#include <C:\прога\Таймер\Timer.hpp>



void PrintTimer(Timer& a)
{

	std::cout << a.getName() << ": sorted by " << a.getMc() << std::endl;
}

int main()
{
	std::array<int, 1000> array;
	std::vector<int> vector(1000);
	std::deque<int> deque(1000);
	std::list<int> list = { };
	std::forward_list<int> forward_list = { };

	for (auto i = 0; i < 1000; i++)
	{
		array[i] = 1000-i;
	}
	for (auto i = 0; i < 1000; i++)
	{
		vector[i] = array[i];
		deque[i] = array[i];
		list.push_back(array[i]);
		forward_list.push_front(array[999 - i]);
	}

	std::vector<std::pair<std::string, std::chrono::microseconds>> Score; // вектор, в котором хранятся вид конт. и время его работы

	// ///////////////////////////////////////////////

	Timer t_array("sort_array");
	std::sort(std::begin(array), std::end(array));
	t_array.Pause();
	std::pair<std::string, std::chrono::microseconds> tarray (t_array.getName(), t_array.getMc());
	Score.push_back(tarray);

	// ///////////////////////////////////////////////
	 
	Timer t_vector("sort_vector");
	std::sort(std::begin(vector), std::end(vector));
	t_vector.Pause();
	std::pair<std::string, std::chrono::microseconds> tvector(t_vector.getName(), t_vector.getMc());
	Score.push_back(tvector);

	// ///////////////////////////////////////////////

	Timer t_deque("sort_deque");
	std::sort(std::begin(deque), std::end(deque));
	t_deque.Pause();
	std::pair<std::string, std::chrono::microseconds> tdeque(t_deque.getName(), t_deque.getMc());
	Score.push_back(tdeque);

	// ///////////////////////////////////////////////

	Timer t_list("sort_list");
	list.sort();
	t_list.Pause();
	std::pair<std::string, std::chrono::microseconds> tlist(t_list.getName(), t_list.getMc());
	Score.push_back(tlist);

	// ///////////////////////////////////////////////

	Timer t_forward_list("sort_forward_list");
	forward_list.sort();
	t_forward_list.Pause();
	std::pair<std::string, std::chrono::microseconds> tforward_list(t_forward_list.getName(), t_forward_list.getMc());
	Score.push_back(tforward_list);

	// ////////////////////////////////////////////////
	
	std::sort(std::begin(Score), std::end(Score), [](auto a, auto b)
		{
			return a.second < b.second;
		});

	std::cout << "Sorted by sort speed:" << std::endl;

	for (auto element : Score)
	{
		std::cout << element.first<<" : "<<(element.second).count()<<' '<<std::endl;
	}
	std::cout << std::endl;

	std::cout << "DS"<<std::endl;
	return 0;
}