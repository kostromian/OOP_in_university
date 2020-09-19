#pragma once
#include "Helper.h"
#include "Kostromin_student.h"


class Kostromin_starosta : public Kostromin_student
{
public:
	CString	mid_name;
	int		part_time;

	Kostromin_starosta();
	virtual void	Serialize(CArchive& ar);
	virtual void	cons_os();
	virtual void	cons_is();
protected:
	DECLARE_SERIAL(Kostromin_starosta)
};

