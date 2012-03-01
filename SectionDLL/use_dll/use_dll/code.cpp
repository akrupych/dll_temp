#include <Windows.h>
#include <iostream>
#include "Section.h"

using namespace std;

__declspec(dllimport) void make_empty(Section& section);

__declspec(dllimport) bool is_empty_section(Section& section);

__declspec(dllimport) void set(Section& section, double a, double b);

__declspec(dllimport) Section* intersect(Section& first, Section& second);


void main()
{
	Section s1;
	s1.empty = false;
	set(s1, 1, 2);
	cout << s1.a << endl << s1.b << endl << s1.empty << endl << endl;

	Section s2;
	s2.empty = false;
	set(s2, 1.5, 3);
	cout << s2.a << endl << s2.b << endl << s2.empty << endl << endl;

	Section* s3 = intersect(s1, s2);
	if (s3 != NULL) cout << s3->a << endl << s3->b << endl << s3->empty << endl << endl;

	cin.get();
}