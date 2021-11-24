#ifndef LIBRARYITEM_HPP
#define LIBRARYITEM_HPP

#include <iostream>
#include <string>

using namespace std;
    
class LibraryItem{

    private: 

        string artikelart;
        int id;
        string titel;
        string autor;
        int ejahr;
        int szahl;
        int alter;
        bool geliehen;

    public:

        LibraryItem(){}

        // 1/2 LibraryItem-Objekten, dieses ist für ein Buch.
        //Es werden Attribute aufgenommen, die dann übernommen werden.
        LibraryItem(string titel, string autor, int ejahr, int id){

            artikelart = "buch";

            this->id = id;
            this->titel = titel;
            this->autor = autor;
            this->ejahr = ejahr;

            geliehen = false;


        }

        // 2/2 LibraryItem-Objekten, dieses ist für ein Spiel.
        // Selbes Prinzip wie beim anderen Objekt.
        LibraryItem(string titel, int alter, int szahl, int id){

            artikelart = "spiel";

            this->id = id;
            this->titel = titel;
            this->alter = alter;
            this->szahl = szahl;
            geliehen = false;

        }

        // Die Folgenden Methoden geben die entsprechenden Variablen aus.
        int getID() {
            return id;
        }

        string getArtikelart() {
            return artikelart;
        }

        string getTitel() {
            return titel;
        }

        string getAutor() {
            return autor;
        }

        int getEjahr() {
            return ejahr;
        }

        int getSzahl() {
            return szahl;
        }

        int getAlter() {
            return alter;
        }
    
        bool getGeliehen() {
            return geliehen;
        }
        
        // Die beiden nächsten Methoden werden benötigt, um den Ausleihstatus zu ändern.
        void ausleihen() {
            geliehen = true;
        }
        
        void rueckgabe() {
            geliehen = false;
        }
        
        // Diese Methode gibt alle für das Objekt relevanten Informationen aus.
        void toString() {
                if (artikelart == "buch") {
                    cout<< "Buch:" << '\n'
                        << "Titel: " << titel << '\n'
                        << "Autor: " << autor << '\n'
                        << "Erscheinungsjahr: " << ejahr << '\n'
                        << "ID: " << id << '\n'
                        << "Ausleihstatus: " << geliehen << "\n \n";
                } else {
                    cout<< "Spiel:" << '\n'
                        << "Titel: " << titel << '\n'
                        << "Empfohlenes Alter: " << alter << '\n'
                        << "Spielerzahl: " << szahl << '\n'
                        << "ID: " << id << '\n'
                        << "Ausleihstatus: " << geliehen << "\n \n";
            }
        }
};
#endif