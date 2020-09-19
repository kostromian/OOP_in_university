#pragma once
#include "Helper.h"

class	Kostromin_student : public CObject
{
public:
	CString name;
	CString surname;
	unsigned short int age;

	Kostromin_student();
	virtual void	Serialize(CArchive& ar);
	virtual void	cons_os();
	virtual void	cons_is();
protected:
	DECLARE_SERIAL(Kostromin_student)
};

