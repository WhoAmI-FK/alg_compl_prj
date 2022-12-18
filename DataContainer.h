#pragma once
#include <chrono>
#include <fstream>
#include <vector>

enum class SortType {
	NORMAL,
	SORTED,
	RANDOMVALS
};

struct DataContainer
{
	int len;
	std::chrono::nanoseconds INS;
	std::chrono::nanoseconds QUI;
	std::chrono::nanoseconds MER;
	std::chrono::nanoseconds HEP;

	std::chrono::nanoseconds INS_B;
	std::chrono::nanoseconds QUI_B;
	std::chrono::nanoseconds MER_B;
	std::chrono::nanoseconds HEP_B;

	void init();

	static void outputDataToFile(const std::vector<DataContainer>& cont, int div, SortType type);
};

