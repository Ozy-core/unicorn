#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Unicorn
{
    private:
        string name;
        vector<string> uniName;
    public:

    Unicorn ( const string& unicorn_name )
    {

        auto it = find(uniName.begin(), uniName.end(), unicorn_name);
        if ( it != uniName.end() )
        {
            throw runtime_error("Unicorn name must be unique. This unicorn name already exists");
        }
        name = unicorn_name;
        uniName.push_back(unicorn_name);      
    }

    ~Unicorn()
    {
        uniName.erase(remove(uniName.begin(), uniName.end(), name), uniName.end());
        cout << "Bye bye Unicorn: " << name << endl;
    }


};

int main()
{
    try
    {
        Unicorn u1("Twighlight");
        Unicorn u2("Buttercup");
        Unicorn u3("Rainbow Sparkles"); 
        Unicorn u4("Buttercup");
    }
    catch ( const exception& e )
    {
        cerr << "Exception: " << e.what() << endl;
    }

    return 0;

}