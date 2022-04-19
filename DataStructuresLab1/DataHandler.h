#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

class DataHandler
{
private:
	std::vector<int> nValues;
	std::vector<long long> times;

	std::string filename;

public:
	DataHandler(std::string name);

	void push(int n, long long time);
	void write();

};

