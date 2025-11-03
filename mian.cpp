#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

class Unicorn
{
private:
    string name;
    static vector<string> uniName;

public:
    Unicorn(const string& unicorn_name)
    {
        auto it = find(uniName.begin(), uniName.end(), unicorn_name);
        if (it != uniName.end())
        {
            throw runtime_error("Unicorn name must be unique. This unicorn name already exists");
        }

        name = unicorn_name;
        uniName.push_back(unicorn_name);
        cout << "Hello Unicorn: " << name << endl;
    }

    ~Unicorn()
    {
        uniName.erase(remove(uniName.begin(), uniName.end(), name), uniName.end());
        cout << "Bye bye Unicorn: " << name << endl;
    }

    static void listUnicorns()
    {
        if (uniName.empty())
        {
            cout << "No unicorns currently alive." << endl;
        }
        else
        {
            cout << "✨ Current unicorns: ";
            for_each(uniName.begin(), uniName.end(), [](const string& n) {
                cout << n << "\n";
            });
            cout << endl;
        }
    }
};


vector<string> Unicorn::uniName;

int main()
{
    try
    {
        Unicorn u1("Sparkle");
        Unicorn::listUnicorns();

        Unicorn u2("Rainbow");
        Unicorn::listUnicorns();

        // Throws here because "Sparkle" already exists
        Unicorn u3("Sparkle");
        Unicorn::listUnicorns();
    }
    catch (const exception& e)
    {
        cerr << "Exception: " << e.what() << endl;
    }

    return 0;
}
