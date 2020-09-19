#pragma once
#include "Helper.h"
#include "Kostromin_starosta.h"
#include "Kostromin_student.h"

class Kostromin_group : public CObject
{
public:
	list<shared_ptr<Kostromin_student>> students;
	int									num_students;
	void								Cons_os();
	void								Add();
	void								Add_starosta();
	virtual void						Serialize(CArchive& archive);
	void								Ser_from_file();
	void								Deser_from_file();
	Kostromin_group();
protected:
	DECLARE_SERIAL(Kostromin_group)
};
