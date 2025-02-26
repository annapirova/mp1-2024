#pragma once


class Temperature {
	private:
		double celsius;
	
	public:
		Temperature(double cels);
		void set_celsius();
		void get_celsius();
		void get_kelvin();
		void get_fahrenheit();		
		void get_rankin();
};

