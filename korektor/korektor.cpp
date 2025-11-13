// zde implementovat tridu pro opravovani testu
// Zadam pocet testu pro libovolny program, pole vstupu a pole ocekavanych vystupu, adresar, kde budou vypracovani
// Program vsechny zkusi a vrati csv s vysledky
// compile cmd: clang++ -std=c++17 korektor.cpp -o korektor
#include <iostream>
#include <list>
#include <fstream>
#include <filesystem>
#include <unistd.h>
#include <sys/wait.h>
#include <vector>
using namespace std;
namespace fs = std::filesystem;

class Test
{
public:
    list<string> input;
    list<string> expected_Output;
    Test(list<string> i, list<string> o)
    {
        input = i;
        expected_Output = o;
    }
};
class TestResult
{
public:
    string filename;
    bool success;
    Test *result_of;
    TestResult(){}
    TestResult(string f, bool r, Test *of)
    {
        filename = f;
        success = r;
        result_of = of;
    }
};
class ResultSet
{
public:
    list<TestResult> results;
    string filename;
};
class Corrector
{

public:
    string directory;
    list<Test> tests;
    list<string> files;
    list<ResultSet> results;
    Corrector(string x, list<Test> t)
    {
        directory = x;
        tests = t;
    }

    void GetFilesFromDirectory()
    {
        for (const auto &entry : fs::directory_iterator(directory))
        {
            if (entry.is_regular_file())
            {
                auto p = entry.path();
                if (p.extension() == ".cpp" || p.extension() == ".cc")
                {
                    files.push_back(p.string());
                }
            }
        }
    }

    list<ResultSet> RunTests()
    {
        list<ResultSet> res;
        for (string filepath : files)
        {
            ResultSet s;
            cout << endl << endl << "Filepath: " << filepath << endl << "==============================" << endl << endl;
            s.filename = filepath;
            int index = 1;
            for (Test t : tests)
            {
                cout << "Test " << index << endl;
                index++;
                TestResult r;
                r.filename = filepath;
                r.result_of = &t;
                string command = "g++ -O2 " + filepath + " -o child_program";
                system(command.c_str());

                int in_pipe[2];  // parent -> child (stdin)
                int out_pipe[2]; // child -> parent (stdout)

                pipe(in_pipe);
                pipe(out_pipe);

                pid_t pid = fork();

                if (pid == 0)
                {
                    // --- CHILD PROCESS ---

                    // Redirect stdin
                    dup2(in_pipe[0], STDIN_FILENO);
                    // Redirect stdout
                    dup2(out_pipe[1], STDOUT_FILENO);

                    close(in_pipe[1]);
                    close(out_pipe[0]);

                    execl("./child_program", "./child_program", nullptr);
                    perror("execl failed");
                    exit(1);
                }

                // --- PARENT PROCESS ---

                close(in_pipe[0]);
                close(out_pipe[1]);

                // Write to child's stdin
                std::string input = "";
                for(string s : t.input){
                    input.append(s);
                    input.append("\n");
                }
                cout << "Input:" << input;
                write(in_pipe[1], input.c_str(), input.size());
                close(in_pipe[1]); // tell child "no more input"

                // Read child's output
                std::string child_output;
                char buffer[256];
                ssize_t count;

                while ((count = read(out_pipe[0], buffer, sizeof(buffer))) > 0)
                {
                    child_output.append(buffer, count);
                }
                if(child_output.at(child_output.length() - 1) == '\n'){
                    child_output.pop_back();
                }
                string expected_output = "";
                for(string s : t.expected_Output){
                    expected_output.append(s);
                    expected_output.append("\n");
                }
                expected_output.pop_back();
                r.success = child_output == expected_output;
                cout << endl << "Given output:\n" << child_output << endl;
                cout << endl << "Expected output:\n" << expected_output << endl;
                cout << endl << "Vysledek:\t" << (r.success ? "Spravne" : "Spatne" ) << endl << endl;
                close(out_pipe[0]);

                // Wait for child to finish
                waitpid(pid, nullptr, 0);
                s.results.push_back(r);
            }
            res.push_back(s);
        }
        return res;
    }
    void ExportCSV(const list<ResultSet>& all_results, const string& filename)
{
    ofstream out(filename);

    if (!out.is_open())
    {
        cerr << "Cannot open CSV file for writing: " << filename << endl;
        return;
    }

    // Write header
    out << "Filepath";
    int test_num = 1;
    for (auto& t : tests)
    {
        out << ";Test " << test_num++;
    }
    out << "\n";

    // Write each student's results
    for (const auto& rs : all_results)
    {
        out << rs.filename;

        for (const auto& r : rs.results)
        {
            out << ";" << (r.success ? "Spravne" : "Spatne");
        }

        out << "\n";
    }

    out.close();
    cout << "\nCSV export created: " << filename << endl;
}
};
// g++ main.cpp -I/opt/homebrew/include -L/opt/homebrew/lib -lboost_system

int main()
{
    int testcount;
    cout << "Zadej pocet testu:\t";
    cin >> testcount;
    int total = testcount;
    list<Test> t;
    for (; testcount > 0; testcount--)
    {
        cout << endl << "Test " << total - testcount + 1 << endl << "===========" << endl << endl;
        cout << "Zadej pole vstupu, posledni zadej \"konec\":\n";
        string x = "";
        list<string> input;
        while (x != "konec")
        {
            getline(cin, x);
            if(x == "konec") break;
            input.push_back(x);
        }
        cout << endl << "Zadej pole vystupu, posledni zadej \"konec\":\n";
        x = "";
        list<string> output;
        while (x != "konec")
        {
            getline(cin, x);
            if(x == "konec") break;
            output.push_back(x);
        }
        t.push_back(Test(input, output));
    }
    Corrector c = Corrector(string("./DDU"), t);
    c.GetFilesFromDirectory();
    c.results = c.RunTests();
    c.ExportCSV(c.results, "results.csv");
}