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
double total_percent = 0.0;
int weighted_sum = 0;

for (int i = 0; i < s.num_components; ++i) {
    cout << "  Vlermsimi " << (i + 1) << " pershkrim (e.g., Kollokfiumi 1, Projekt): ";
    getline(cin, s.comp_description[i]);

    cout << "  Perqindja per noten finale " << s.comp_description[i] << " (%): ";
    cin >> s.comp_percentage[i];
    while (s.comp_percentage[i] < 0 || s.comp_percentage[i] > 100) {
        cout << "  Peqindje e gabuar shkruane prap!: ";
        cin >> s.comp_percentage[i];
    }

    cout << "  Piket e marrur " << s.comp_description[i] << " (out of 100): ";
    cin >> s.comp_earned[i];
    while (s.comp_earned[i] < 0 || s.comp_earned[i] > 100) {
        cout << "  Pike jo valide shenoni prap (0-100): ";
        cin >> s.comp_earned[i];
    }

    weighted_sum += s.comp_earned[i] * s.comp_percentage[i];
    total_percent += s.comp_percentage[i];

    cin.ignore(); // clear newline after last input
}

// Calculate final points out of 100
if (total_percent > 0) {
    s.total_points = static_cast<int>(weighted_sum / total_percent);
    if (s.total_points > 100) s.total_points = 100;
}
else {
    s.total_points = 0;
}

if (total_percent != 100.0) {
    cout << "  Shenim: piket jane : " << total_percent
        << "%, Piket finale jane rregulluar.\n";
}
}

// Function 4: Input full subject data
void inputSubject(Subject& s, int number) {
    cout << "\nLenda " << number << ":" << endl;

    cout << " Emri i Lendes: ";
    getline(cin, s.name);

    inputEvaluationComponents(s);

    cin.ignore(); // safety for next subject
}