#include <iostream>
#include <string>
#include <list>
#include "Library.hpp"
using namespace std;

Library lib = Library();
int eingabe;
string titel;
string autor;
int jahr;
int szahl;
int alter;
int id;
bool geliehen;
bool funktioniert;

do {
    cout << endl;
    cout << "Bitte wählen Sie eine Aktion:" << endl;
    cout << "1: ein Item hinzufügen" << endl;
    cout << "2: ein Item löschen" << endl;
    cout << "3: ein Item suchen" << endl;
    cout << "4: Ausleihstatus prüfen" << endl;
    cout << "5: ein Item ausleihen" << endl;
    cout << "6: ein Item zurücknehmen" << endl;
    cout << "7: das Inventar der Bibliothek ansehen" << endl;
    cout << "8: beenden" << endl;
    cout << endl;

    cin >> eingabe;

    cout << endl;

    switch(eingabe) {
        case 1: {
            char auswahl;
            cout << "Möchten Sie ein Buch(b) oder ein Spiel(s) hinzufügen?" << endl;
            do {
                cin >> auswahl;
            } while(auswahl != 's' && auswahl != 'b');

            cout << endl;

            switch(auswahl) {
                case 's':

                    cout << "Bitte Spezifikationen des Spiels eingeben:" << endl;

                    cout << "Titel:" << endl;
                    do {
                        cin >> titel;
                    } while(titel.length() < 1);

                    cout << endl;
                    cout << "Spieleranzahl:" << endl;
                    do{
                        cin >> szahl;
                    } while(szahl < 1);

                    cout << endl;
                    cout << "empfohlenes Alter:" << endl;
                    do{
                        cin >> alter;
                    } while(alter < 0 || alter > 100);

                    lib.addSpiel(titel, szahl, alter);

                    cout << endl;
                    cout << "Spiel hinzugefügt!";
                    cout << endl;

                    break;

                case 'b':

                    cout << "Bitte Spezifikationen des Buches eingeben:" << endl;

                    cout << endl;
                    cout << "Titel:" << endl;
                    do {
                        cin >> titel;
                    } while(titel.length() < 1);

                    cout << endl;
                    cout << "Autor:" << endl;
                    do {
                        cin >> autor;
                    } while(autor.length() < 1);

                    cout << endl;
                    cout << "Erscheinungsjahr:" << endl;
                    do{
                        cin >> jahr;
                    } while(jahr > 2020);

                    lib.addBuch(titel, autor, jahr);

                    cout << endl;
                    cout << "Buch hinzugefügt!";
                    cout << endl;

                    break;

                default:
                    cout << endl;
                    cout << "Fehler, hinzufügen gescheitert!" << endl;
                    cout << endl;

                    break;
            }; break;
        }

        case 2: {

            cout << endl;
            cout << "Bitte die ID des zu löschenden Items eingeben:" << endl;
            do{
                cin >> id;
            } while(id < 0);

            funktioniert = lib.removeItem(id);

            cout << endl;
            if(funktioniert) {
                cout << "Item gelöscht!" << endl;
            } else {
                cout << "Fehler, löschen gescheitert!" << endl;
            }
            cout << endl;

            break;
        }

        case 3: {

            char auswahl;
            cout << "Möchten Sie nach einem Titel(t), einem Autor(a), einer Spieleranzahl(s) oder einer ID(i) suchen?" << endl;
            do {
                cin >> auswahl;
            } while(auswahl != 't' && auswahl != 'a' && auswahl != 's' && auswahl != 'i');

            cout << endl;

            switch(auswahl) {
                case 't':

                    cout << "Bitte den Titel des Items eingeben:" << endl;

                    do {
                        cin >> titel;
                    } while(titel.length() < 1);

                    lib.sucheTitel(titel);

                    cout << endl;

                    break;

                case 'a':

                    cout << "Bitte den Autoren des Items eingeben:" << endl;

                    do {
                        cin >> autor;
                    } while(autor.length() < 1);

                    lib.sucheAutor(autor);

                    cout << endl;

                    break;

                case 's':

                    cout << "Bitte die Spieleranzahl des Items eingeben:" << endl;

                    do {
                        cin >> szahl;
                    } while(szahl < 0);

                    lib.sucheSpielerzahl(szahl);

                    cout << endl;

                    break;

                case 'i':

                    cout << "Bitte die ID des Items eingeben:" << endl;

                    do {
                        cin >> id;
                    } while(id < 0);

                    lib.sucheID(id);

                    cout << endl;

                    break;

                default:
                    cout << endl;
                    cout << "Fehler, hinzufügen gescheitert!" << endl;
                    cout << endl;

                    break;
            }; break;
        }

        case 4: {

            cout << endl;
            cout << "Bitte die ID des zu prüfenden Items eingeben:" << endl;
            do{
                cin >> id;
            } while(id < 0);

            geliehen = lib.istGeliehen(id);

            cout << endl;
            if(geliehen) {
                cout << "Item ist verliehen!" << endl;
            } else {
                cout << "Item ist nicht verliehen!" << endl;
            }
            cout << endl;

            break;
        }

        case 5: {

            cout << endl;
            cout << "Bitte die ID des auzuleihenden Items eingeben:" << endl;
            do{
                cin >> id;
            } while(id < 0);

            geliehen = lib.ausleihe(id);

            if(geliehen) {
                cout << endl;
                cout << "Das Item wurde ausgeliehen!" << endl;
                cout << endl;
            } else {
                cout << endl;
                cout << "Fehler!" << endl;
                cout << endl;
            }

            break;
        }

        case 6: {

            cout << endl;
            cout << "Bitte die ID des zurückzugebenden Items eingeben:" << endl;
            do{
                cin >> id;
            } while(id < 0);

            geliehen = lib.rueckgabe(id);

            if(geliehen) {
                cout << endl;
                cout << "Das Item wurde zurückgenommen!" << endl;
                cout << endl;
            } else {
                cout << endl;
                cout << "Fehler!" << endl;
                cout << endl;
            }

            break;
        }

        case 7: {

            cout << "Es sind aktuell folgende Bücher & Spiele verfügbar:" << endl << endl;

            lib.printInventar();

            cout << endl;

            break;
        }

        case 8: {
            break;
        }

        default: {
            cout << "Fehler, bitte korrekte Eingabe!" << endl;
            break;
        }
    }

} while (eingabe != 8);
