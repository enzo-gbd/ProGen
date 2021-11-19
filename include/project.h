#ifndef NEW_PROJECT
#define NEW_PROJECT

#include <string>

namespace lang
{
    enum project_lang
    {
        C = 1,
        Cpp = 2
    };
}

class Project
{
    public:
        Project();
        Project(int lang, std::string name, std::string link, std::string vs);
        void Generate();
        void Open();
        ~Project();

    private:
        lang::project_lang m_project_lang;
        std::string m_name;
        std::string m_link;
        std::string m_vs;
        int m_lang;
};

#endif