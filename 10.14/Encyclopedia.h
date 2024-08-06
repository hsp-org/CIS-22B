#ifndef ENCYCLOPEDIAH
#define ENCYCLOPEDIAH

#include "Book.h"

class Encyclopedia : public Book
{
public:

    void SetEdition(string edition);

    void SetNumPages(int pages);

    string GetEdition() const;
    int GetNumPages() const;

    void PrintInfo() const;

private:
    int pages;
    string edition;
};

#endif