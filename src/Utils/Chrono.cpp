//
// Created by Elyas EL IDRISSI on 11/03/2021.
//

#include "Chrono.h"

Chrono::Chrono()
{

}

void Chrono::start()
{
	m_start = std::chrono::high_resolution_clock::now();
}

void Chrono::stop()
{
	m_end = std::chrono::high_resolution_clock::now();
}

std::chrono::duration<double> Chrono::getDuration()
{
	std::chrono::duration<double> diff = m_end-m_start;
	return diff;
}
