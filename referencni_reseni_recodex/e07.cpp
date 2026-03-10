#include <iostream>
#include <string>
using namespace std;
struct student {
    string jmeno;
    string prijmeni;
    double znamka;
};

bool readStudent(student& s) {
    return bool(cin >> s.jmeno >> s.prijmeni >> s.znamka);
}
student nejlepsi(student studenti[100], int size) {
    double ref = 6.0;
    int return_index = -1;
    for (int i = 0; i < size; i++) {
        if (studenti[i].znamka < ref) {
            return_index = i;
            ref = studenti[i].znamka;
        }
    }
    return studenti[return_index];
}
unsigned int slabyProspech(student studenti[100], student slaby[100], int count) {
    unsigned int j = 0;
    for (int i = 0; i < count; i++) {
        if (studenti[i].znamka > 4.0) {
            slaby[j++] = studenti[i];
        }
    }
    return j;
}
void printStudent(student s) {
    cout << s.jmeno << " " << s.prijmeni << endl;

}
int main() {
    student studenti[100] = {};
    student slaby[100] = {};
    int count;
    cin >> count;
    if (count < 0 || count > 100) return 1;
    for (int i = 0; i < count; i++) {
        if (!readStudent(studenti[i])) return 1;
        if (studenti[i].znamka < 0.0 || studenti[i].znamka > 5.0) return 2;
    }
    cout << "Nejlepsi:" << endl;
    printStudent(nejlepsi(studenti, count));
    unsigned int count_slaby = slabyProspech(studenti, slaby, count);
    if (count_slaby > 0) {
        cout << "Slaby prospech:" << endl;
    }
    else {
        cout << "Slaby prospech:\nnikdo" << endl;
    }
    for (int i = 0; i < count_slaby; i++) {
        printStudent(slaby[i]);
    }
}