#include "sms.hpp"

int Message::cle = 0;

const char * MauvaisNumero::what() const noexcept
{
    return "mauvais numero";
}


void Telephone::setNumero(std::string _num)
{
    num = _num;
}

int Telephone::getNbMessages() const
{
    return nbMess;
}

    
std::string Telephone::getNumero() const
{
    return num;
}

Reseau * Telephone::getReseau() const
{
    return r;
}

void Telephone::setReseau(Reseau * _r)
{
    r = _r;
}

Telephone::Telephone() : num(""), r(nullptr), nbMess(0)
{}

void Telephone::reception()
{
    nbMess++;
}


Telephone::Telephone(std::string _num) : num(_num), r(nullptr), nbMess(0)
{}

void Reseau::ajouter(std::string _num)
{
    abonnes.push_back(Telephone(_num));
    abonnes.at(abonnes.size()-1).setReseau(this);
}

std::string Reseau::lister()
{
    if(abonnes.size() != 0)
    {
        std::stringstream ss;
        for (std::vector<Telephone>::iterator i = abonnes.begin();i!=abonnes.end(); i++)
            ss << i->getNumero() << std::endl;
        return ss.str();
    }
    else return "";
}

bool Reseau::possede(std::string _num)
{
    bool res = false;
    for (std::vector<Telephone>::iterator i = abonnes.begin();i != abonnes.end();i++)
    {
        if (i->getNumero() == _num) res = true;
    }

    return res;
}


void Telephone::textoter(std::string _num,std::string _message)
{
    if (getReseau()->possede(_num))
    {
        getReseau()->trouveTel(_num).reception();
    }
    reception();
}


Telephone& Reseau::trouveTel(std::string _num)
{
    bool in = false;
    std::vector<Telephone>::iterator i = abonnes.begin();

    while ( (in == false) &&   (i!=abonnes.end()) )
    {
        if (i->getNumero() == _num) in = true;
        else i++;
    }

    if (in) return *i;
    else throw MauvaisNumero();

}

MauvaisNumero::MauvaisNumero() : std::invalid_argument("mauvais numero")
{}

SMS::SMS(std::string _num1, std::string _num2, std::string _num3) : Message(_num1,_num2,_num3)
{}

void SMS::setTexte(std::string _text)
{
    text = _text;
}

std::string SMS::getTexte() const
{
    return text;
}

std::string SMS::afficher() const
{
    return text;
}

Message::Message(std::string _num1, std::string _num2, std::string _num3) : id(Message::cle)
{
    Message::cle ++;
}

int Message::getCle()
{
    return cle;
}

int Message::getId() const
{
    return id;
}

std::string MMS::getTexte() const
{
    return text;
}

void MMS::setTexte(std::string _text)
{
    text = _text;
}

MMS::MMS(std::string _num1, std::string _num2, std::string _num3) : Message(_num1,_num2,_num3)
{}

void MMS::joindre(Media* _med)
{
    objets.push_back(_med);
}

std::string MMS::afficher()
{
    std::stringstream ss;
    ss << getTexte();
    for (std::vector<Media *>::iterator i = objets.begin(); i != objets.end(); i++)
        ss << (*i)->afficher();
    
    return ss.str();
}

std::string Video::afficher()
{
    return "[[video]]";
}

std::string Son::afficher(){
    return "[[son]]";
}


std::string Image::afficher(){
    return "[[image]]";
}


