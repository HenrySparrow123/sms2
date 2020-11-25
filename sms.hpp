#ifndef __SMS
#define __SMS

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <exception>

class Reseau;

class Telephone
{
    std::string num;
    Reseau * r;
    int nbMess;

    public :
        Telephone();
        Telephone(std::string);
        void setNumero(std::string);
        std::string getNumero() const;
        Reseau * getReseau() const;
        void setReseau(Reseau *);
        int getNbMessages() const;
        void textoter(std::string,std::string);
        void reception();

};

class Reseau
{
    std::vector<Telephone> abonnes;

    public :
        void ajouter(std::string);
        std::string lister();
        Telephone& trouveTel(std::string);
        bool possede(std::string);

};

class MauvaisNumero : public std::invalid_argument
{
    public :
        MauvaisNumero();
        virtual const char * what() const noexcept;
};

class Message
{
    protected :
        static int cle;
        int id;

    public :
        Message(std::string, std::string, std::string);
        static int getCle();
        int getId() const;
};

class SMS : public Message
{
    std::string text;
    
    public:
        SMS(std::string,std::string,std::string);
        void setTexte(std::string _texte);
        std::string getTexte() const;
        std::string afficher() const;
};

class Media;

class MMS : public SMS
{
    std::string text;
    std::vector<Media*> objets;

    
    public:
        MMS(std::string,std::string,std::string);
        void setTexte(std::string _texte);
        std::string getTexte() const;
        std::string afficher() ;
        void joindre(Media *);
};

class Media
{
    public :
        virtual std::string afficher() = 0;
};

class Image : public Media
{
    public :
        virtual std::string afficher();
};

class Son : public Media
{
    public :
        virtual std::string afficher();
};

class Video : public Media
{
    public :
        virtual std::string afficher();
};
#endif