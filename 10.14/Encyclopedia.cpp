#include "Encyclopedia.h"
#include <iostream>

using std::cout;
using std::endl;

void Encyclopedia::SetEdition(string edition)
{
    this->edition = edition;
}

void Encyclopedia::SetNumPages(int pages)
{
    this->pages = pages;
}


string Encyclopedia::GetEdition() const
{
    return edition;
}

int Encyclopedia::GetNumPages() const
{
    return pages;
}



void Encyclopedia::PrintInfo() const
{
    cout << "Book Information: " << endl;
    cout << "   Book Title: " << title << endl;
    cout << "   Author: " << author << endl;
    cout << "   Publisher: " << publisher << endl;
    cout << "   Publication Date: " << publicationDate << endl;
    cout << "   Edition: " << edition << endl;
    cout << "   Number of Pages: " << pages << endl;
}