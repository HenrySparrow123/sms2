#include "sms.hpp"


int Message::cle = 0;

///TELEPHONE///

Telephone::Telephone() : num(""), r(nullptr), nbMess(0)
{}

Telephone::Telephone(std::string defNum) : num(defNum), r(nullptr), nbMess(0)
{}

std::string Telephone::getNumero() const
{
    return num;
}

void Telephone::setNumero(std::string defNum)
{
    num = defNum;
}

Reseau * Telephone::getReseau() const
{
    return r;
}

void Telephone::setReseau(Reseau * reseau)
{
    r = reseau;
}

int Telephone::getNbMessages() const
{
    return nbMess;
}


const char * MauvaisNumero::what() const noexcept
{
    return "mauvais numero";
}

///RESEAU///

Reseau::Reseau() : nbTel(0), membres(nullptr)
{}

std::string Reseau::lister() const
{
    std::ostringstream oss("");
    
    for (int i = 0; i<nbTel; i++) 
    {
        oss << (membres+i)->getNumero() << "\n";
    }
    return oss.str();
}

void Reseau::ajouter(std::string numAAjouter)
{
    nbTel ++;

    Telephone * newTab = new Telephone[nbTel];
    memcpy(newTab, membres, (nbTel-1)*sizeof(Telephone));
    membres = newTab;

    membres[nbTel-1] = Telephone(numAAjouter);
    membres[nbTel-1].setReseau(this);
}

Telephone& Reseau::trouveTel(std::string tel) const
{
    int i = 0;
    bool trouve = false;
    Telephone& res = new Telephone;

    while ( (i<nbTel) && (!trouve))
    {
        if (membres[i].getNumero() == tel)
        {
            res = membres[i];
            trouve = true;
        }
        i++;
    }

    if (i >= nbTel) throw std::invalid_argument("Numero existe pas!");
    else return res; 
}

///Message///

   
Message::Message(std::string e,std::string d,std::string dat) : expe(e),dest(d),date(dat), id(cle)
{
   cle ++;
}

int Message::getCle()
{
    return cle;
}

int Message::getId() const
{
    return id;
}

///SMS///

SMS::SMS(std::string e,std::string d,std::string dat) : Message(e,d,dat)
{}

std::string SMS::afficher() const
{
    return texte;
}

std::string SMS::getTexte() const
{
    return texte;
}

void SMS::setTexte(std::string message)
{
    texte = message;
}