#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

class DataHandler
{
private:
	std::vector<int> nValues;
	std::vector<float> times;

	std::string filename;

public:
	DataHandler(std::string name);

	void push(int n, float time);
	void write();

};

