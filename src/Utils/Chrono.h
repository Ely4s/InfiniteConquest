//
// Created by Elyas EL IDRISSI on 11/03/2021.
//

#ifndef INFINITECONQUEST_CHRONO_H
#define INFINITECONQUEST_CHRONO_H

#include <chrono>
#include <time.h>

class Chrono
{

public:
	
	Chrono();
	
	void start();
	void stop();
	std::chrono::duration<double> getDuration();
	
private:
	
	std::chrono::time_point<std::chrono::high_resolution_clock> m_start;
	std::chrono::time_point<std::chrono::high_resolution_clock> m_end;
};


#endif //INFINITECONQUEST_CHRONO_H
