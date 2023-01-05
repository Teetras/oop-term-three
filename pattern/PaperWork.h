#pragma once
#include"Document.h"


class PaperWork {
public:
	virtual Document* makeDoc() = 0;
	virtual unique_ptr<PaperWork> clone() = 0;
};
class MakingRentContract : public PaperWork {
public:
  Description* makeDoc() { return new Description; }
	unique_ptr<PaperWork> clone() { return  unique_ptr<PaperWork>(new MakingRentContract(*this)); }
};
class MakingEmpoloymentContract : public PaperWork {
public:
	Format* makeDoc() { return new Format; }
	unique_ptr<PaperWork> clone() { return unique_ptr<PaperWork>(new MakingEmpoloymentContract(*this)); }
};
