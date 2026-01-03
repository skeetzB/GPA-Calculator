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
// Function 1: Convert total points (0-100) to grade (5.0 - 10.0)
double calculateGrade(int points) {
    if (points >= 90) return 10.0;
    else if (points >= 80) return 9.0;
    else if (points >= 70) return 8.0;
    else if (points >= 60) return 7.0;
    else if (points >= 50) return 6.0;
    else return 5.0;
}

// Function 2: Get textual evaluation based on grade
string getEvaluation(double grade) {
    if (grade >= 9.0) return "Shkelqyeshem";
    else if (grade >= 8.0) return "Shume mire";
    else if (grade >= 7.0) return "Mire";
    else if (grade >= 6.0) return "Kaluese";
    else return "Jo Kaluese";
}

// Function 3: Input evaluation components and earned points (without vector)
void inputEvaluationComponents(Subject& s) {
    cout << "  Sa lloje te vlerimit keni ne " << s.name << " : ";
    cin >> s.num_components;
    while (s.num_components <= 0 || s.num_components > MAX_COMPONENTS) {
        cout << "  Duhet te jete midis numrit 1 dhe " << MAX_COMPONENTS << "! Shkruaje prap: ";
        cin >> s.num_components;
    }
    cin.ignore(); // clear newline
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
int main() {
    const int NUM_SUBJECTS = 6;
    Subject subjects[NUM_SUBJECTS];

    double total_grade_points = 0.0;
    int passed_subjects = 0;

    cout << "=== Kalkulator i Notes finale (6 lende) ===\n";
    cout << "Per secilen lende, percaktoni komponentet e vleresimit, perqindjet e tyre,\n";
    cout << "dhe piket qe keni fituar ne secilen (out of 100).\n\n";

    for (int i = 0; i < NUM_SUBJECTS; ++i) {
        inputSubject(subjects[i], i + 1);

        subjects[i].grade = calculateGrade(subjects[i].total_points);
        subjects[i].evaluation = getEvaluation(subjects[i].grade);

        total_grade_points += subjects[i].grade;
        if (subjects[i].grade >= 6.0) {
            passed_subjects++;
        }
    }

    // Display results
    cout << "\n\n=== Rezultatet ===\n\n";
    for (int i = 0; i < NUM_SUBJECTS; ++i) {
        cout << subjects[i].name << "\n";
        cout << "  Ndarja e vleresimit dhe rezultatet tuaja:\n";
        for (int j = 0; j < subjects[i].num_components; ++j) {
            cout << "    - " << subjects[i].comp_description[j] << ": "
                << subjects[i].comp_percentage[j] << "%  ->  "
                << subjects[i].comp_earned[j] << "/100\n";
        }
        cout << "  piket perfundimtare : " << subjects[i].total_points << "/100\n";
        cout << "  Nota perfundimtare: " << subjects[i].grade << "\n";
        cout << "  Vleresimi: " << subjects[i].evaluation << "\n\n";
    }

    double average_grade = total_grade_points / NUM_SUBJECTS;
    cout << "Nota juaj mesatare : " << average_grade << "\n";
    cout << "Lendet e kaluara : " << passed_subjects << " nga 6\n";

    return 0;
}