#include <Windows.h>
#include "Section.h"

/* --- DECLARATIONS --- */

__declspec(dllexport) void make_empty(Section& section);

__declspec(dllexport) bool is_empty_section(Section& section);

__declspec(dllexport) void set(Section& section, double a, double b);

__declspec(dllexport) Section* intersect(Section& first, Section& second);


/* --- DEFINITIONS --- */

__declspec(dllexport) void make_empty(Section& section) { section.empty = true; }

__declspec(dllexport) bool is_empty_section(Section& section) { return section.empty; }

__declspec(dllexport) void set(Section& section, double a, double b) { section.a = a; section.b = b; }

__declspec(dllexport) Section* intersect(Section& first, Section& second)
{
	if (first.b < second.a || second.b < first.a || first.empty && second.empty) return NULL;
	Section* result = new Section;
	result->empty = false;
	if (first.empty) set(*result, second.a, second.b);
	else if (second.empty) set(*result, first.a, first.b);
	else set(*result, max(first.a, second.a), min(first.b, second.b));
	return result;
}
