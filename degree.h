#pragma once
#include <string>
/*
Task C: Define an enumerated data type DegreeProgram for the degree
programs containing the data type values SECURITY, NETWORK, and SOFTWARE.
*/

enum DegreeProgram { SECURITY, NETWORK, SOFTWARE };

static const std::string degreeProgramString[] = { "SECURITY", "NETWORK", "SOFTWARE" };