#include <exception>
#include <string>
 
class Error: public std::exception
{
public:
    Error(int number=0, std::string const& text="", int level=0) throw()
         :m_number(number),m_text(text),m_level(level)
    {}
 
     virtual const char* what() const throw()
     {
         return m_text.c_str();
     }
     
     int getNumber() const throw()
     {
          return m_number;
     }
    
    virtual ~Error() throw()
    {}
 
private:
    int m_number;               //Numéro de l'erreur
    std::string m_text;            //Description de l'erreur
    int m_level;               //Niveau de l'erreur
};