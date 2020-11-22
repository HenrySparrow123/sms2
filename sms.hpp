#ifndef __SMS
#define __SMS

#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <exception>

class Reseau;

class Telephone {
    std::string num;
    Reseau * r;
    int nbMess;

    public :
        Telephone();
        Telephone(std::string);
        std::string getNumero() const;
        void setNumero(std::string);
        Reseau * getReseau() const;
        void setReseau(Reseau *);
        int getNbMessages() const;

        void operator=(const Telephone& _tel)
        {
            num = _tel.getNumero();
            
        }
};

class Reseau {
    Telephone * membres;
    int nbTel;

    public :
        Reseau();
        std::string lister() const;
        void ajouter(std::string);
        Telephone& trouveTel(std::string) const;
};

class MauvaisNumero : public std::exception {
    public :
        virtual const char * what() const noexcept;
};

class Message {
    std::string expe;
    std::string dest;
    std::string date;
    int id;


    protected :
        static int cle;   

    public :
        Message(std::string, std::string, std::string);
        static int getCle();
        int getId() const;

};

class SMS : public Message {
    std::string texte;

    public :
        SMS(std::string,std::string,std::string);
        void setTexte(std::string);
        std::string afficher() const;
        std::string getTexte() const;
};



#endif