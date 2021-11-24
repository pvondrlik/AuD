#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#include <list>
#include <iostream>
#include <string>
// LibraryItem wird included.
#include "LibraryItem.hpp"


class Library{

    private: 
      
        // Dieser pointer wird später benötigt, um die Objekte in eine Liste einzufügen.
        LibraryItem *pointer = nullptr;
        string artikelart;
        string titel;
        string autor;
        int jahr;
        int szahl;
        int alter;
        int id;
        int idzaehler = 0;
        bool geliehen;
    
        // Die Liste, in die die Objekte eingefügt werden.
        list <LibraryItem*> liste = list <LibraryItem*> ();


    public:

        Library() {}
        
        // Methode, um ein Buch hinzuzufügen. Nimmt Attribute auf, weist eine ID zu und erstellt und speichert das Objekt in der Liste.
        void addBuch(string titel, string autor, int ejahr) {
            idzaehler++;
            id = idzaehler;
            pointer = new LibraryItem(titel, autor, ejahr, id);

            liste.push_back(pointer);
                                        
        }
                                        
        // Selbes Prinzip wie bei der Methode addBuch(), bloß für ein Spiel mit teilweise unterschiedlichen Attributen.
        void addSpiel(string titel, int szahl, int alter) {
            idzaehler++;
            id = idzaehler;
            pointer = new LibraryItem(titel, szahl, alter, id);

            liste.push_back(pointer);
        }
    
        // Methode, um ein Objekt zu löschen. Es wird ein Iterator zum Löschen erstellt und einer mit dem die ID abgerufen wird.
        bool removeItem(int id) {
            
           auto it = liste.begin();
            
           for (LibraryItem *i : liste) {
                 
               if( i->getID() == id) {
                   liste.erase(it);
                    
                   return true;
               }
               it++;
           }
           return false;
        }

        // Die Folgenden Methoden verlaufen alle nach dem selben Prinzip: Es wird ein Iterator erstellt, der die Liste durchläuft.
        // Sobald an der Stelle des Iterators in der Liste das passende Objekt sein sollte, wird das Objekt ausgegeben.
        void sucheTitel(string titel) {
        
            for (LibraryItem* i : liste ) {
            
                if ( i->getTitel() == titel ) {
                    i->toString();
                }
            }
        }

        void sucheAutor(string autor) {
            for ( LibraryItem* i : liste ) {

                if ( i->getAutor() == autor ) {
                    i->toString();
                }
            }
        }

        void sucheSpielerzahl(int szahl) {
            for ( LibraryItem* i : liste ) {
            
                if ( i->getSzahl() == szahl ) {
                    i->toString();
                }
            }
        }


        void sucheID(int id) {
            for ( LibraryItem* i : liste ) {
            
                if ( i->getID() == id ) {
                    
                    i->toString();     
                }
            }
        }

        // In dieser Methode wird nach der gewünschten ID mittels eines Iterators gesucht und sobald dieses gefunden wurde,
        // wird der Ausleihstatus entsprechend geändert.
        bool ausleihe(int id) {
            for (LibraryItem* i : liste) {
                if( i->getID() == id) {
                    i->ausleihen();
                    return true;
                }
            }
            return false;
        }
        
        // Es wird eine ID aufgenommen und der Ausleihstatus des Objekts mit der etsprechenden ID wird dargestellt.
        bool istGeliehen(int id) {
            for (LibraryItem* i : liste) {
                if (i->getGeliehen() == false) {
                    return true;
                } 
            }
            return false;
        }
        
        // In dieser Methode wird nach der gewünschten ID mittels eines Iterators gesucht und sobald dieses gefunden wurde,
        // wird der Ausleihstatus entsprechend geändert.
        bool rueckgabe(int id) {
            for (LibraryItem* i : liste) {
                if( i->getID() == id) {
                    i->rueckgabe();
                    return true;
                }
            }
            return false;
        }
        
        // Die Liste wird duchlaufen und jedes Objekt wird mit den relevanten Informationen ausgegeben.
        void printInventar() {
            
            for (LibraryItem* i : liste) {
                i->toString();
                
            }
        }   
};  
#endif