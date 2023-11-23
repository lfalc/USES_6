#ifndef	_HFDP_CPP_OBSERVER_OBSERVER_HPP_
#define _HFDP_CPP_OBSERVER_OBSERVER_HPP_

#include "WeatherStation.hpp"

namespace HeadFirstDesignPatterns 
{
	namespace Observer 
	{

		class Observer 
		{
			public: virtual ~Observer()
			{
				std::cout << "Observer::~Observer" << std::endl;
			}

			friend class WeatherData;


			protected: virtual void update(float temp, float humidity, float pressure) = 0;
		};
	} // namespace Observer
} // namespace HeadFirstDesignPatterns

#endif