#ifndef	_HFDP_CPP_OBSERVER_CURRENT_CONDITIONS_DISPLAY_HPP_
#define _HFDP_CPP_OBSERVER_CURRENT_CONDITIONS_DISPLAY_HPP_

#include "WeatherStation.hpp"

namespace HeadFirstDesignPatterns 
{
	namespace Observer 
	{

		class CurrentConditionsDisplay : private Observer, private DisplayElement 
		{

		private: Subject* _weatherData;
		private: float _temperature;
		private: float _humidity;
		private: float _pressure;


		private: CurrentConditionsDisplay( const CurrentConditionsDisplay& ); // Disable copy constructor
		private: void operator=( const CurrentConditionsDisplay& ); // Disable assignment operator

		public: explicit CurrentConditionsDisplay( Subject* weatherData ) : 
			_weatherData( weatherData ), _temperature( 0.0 ), _humidity( 0.0 ), _pressure(0.0)
			{ 
				assert( weatherData );
				_weatherData->registerObserver( this );
			}

		public: ~CurrentConditionsDisplay() 
				{
					_weatherData->removeObserver( this );
				}

		public: void update( float temperature, float humidity, float pressure ) 
				{
					_temperature = temperature;
					_humidity = humidity;
					_pressure = pressure;
					display();
				}
		};
	} // namespace Observer
} // namespace HeadFirstDesignPatterns

#endif