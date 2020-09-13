#pragma once
#include "Header.h"
#include "Kostromin_starosta.h"
class Kostromin_starosta : public Kostromin_student
{
public:
	string	mid_name;
	int		part_time;
	virtual void	cons_os();
	virtual void	file_os(ofstream& os);
	virtual void	cons_is();
	virtual void	file_is(istream& is);
};

