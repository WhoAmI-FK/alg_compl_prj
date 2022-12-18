#include "DataContainer.h"
#include <fstream>
#include <sstream>

void DataContainer::init()
{
	INS = std::chrono::nanoseconds(0);
	QUI = std::chrono::nanoseconds(0);
	MER = std::chrono::nanoseconds(0);
	HEP = std::chrono::nanoseconds(0);
	INS_B = std::chrono::nanoseconds(0);
	QUI_B = std::chrono::nanoseconds(0);
	MER_B = std::chrono::nanoseconds(0);
	HEP_B = std::chrono::nanoseconds(0);
}

void DataContainer::outputDataToFile(const std::vector<DataContainer>& cont, int div, SortType type)
{
	std::ofstream outSorted;
	std::ofstream out;
	switch (type)
	{
	case SortType::NORMAL:
		out.open("results.txt", std::ios::out | std::ios::trunc);
		out << "size insert merge quick heap" << std::endl;
		for (const auto& v : cont)
		{
			out << v.len << " "
				<< v.INS.count() / div << " "
				<< v.MER.count() / div << " "
				<< v.QUI.count() / div << " "
				<< v.HEP.count() / div << " "
				<< std::endl;
		}
		break;
	case SortType::SORTED:
		out.open("resultsSorted.txt", std::ios::out | std::ios::trunc);
		out << "size insert merge quick heap" << std::endl;
		for (const auto& v : cont)
		{
			out << v.len << " "
				<< v.INS_B.count() / div << " "
				<< v.MER_B.count() / div << " "
				<< v.QUI_B.count() / div << " "
				<< v.HEP_B.count() / div << " "
				<< std::endl;
		}
		break;
	}
}

