// Name: Semin Jeon
// Date: 2018/11/19
//

#include <iostream>
#include "Data.h"

namespace sict {
  // answers outputs statistics for visual validation of data
	//
	void answers(const int* year, const int* population, const int* violentCrime,
		const double* violentCrimeRate, const int* grandTheftAuto, const int n) {
    std::cout << "Population change from 2000 to 2004 is " << std::fixed << std::setprecision(2)
      << static_cast<double>((population[4] - population[0])) / 1000000 << " million" << std::endl
      << "Violent Crime trend is down" << std::endl
      << "There are " << std::fixed << std::setprecision(2) << average(grandTheftAuto, n) / 1000000
      << " million Grand Theft Auto incidents on average a year" << std::endl
      << "The Minimum Violent Crime rate was " << static_cast<int>(min(violentCrimeRate, n)) << std::endl
      << "The Maximum Violent Crime rate was " << static_cast<int>(max(violentCrimeRate, n)) << std::endl;
	}
}
