#include <iostream>
#include <string>

using namespace std;

const int MAX_COMPONENTS = 10;  // Maximum components per subject

struct Subject {
    string name;
    string comp_description[MAX_COMPONENTS];  // Descriptions of components
    double comp_percentage[MAX_COMPONENTS];   // Percentages
    int comp_earned[MAX_COMPONENTS];          // Points earned in each
    int num_components;                       // How many components this subject has
    int total_points;                         // Final weighted points (0-100)
    double grade;                             // 5.0 - 10.0
    string evaluation;                        // Excellent, Very Good, etc.
};
