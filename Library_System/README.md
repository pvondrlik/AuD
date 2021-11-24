
# Bibliothek

Der vorgegebene Programmcode ist die Ausgabe für ein einfaches Bibliotheksverwaltungsprogramm.
### Library

    verwaltet Bücher & Spiele in einer Liste
    es gibtfolgende Operationen:
        void addBuch(string titel, string autor, int ejahr) (erstellt & fügt ein Buch hinzu)
        void addSpiel(string titel, int szahl, int alter) (erstellt & fügt ein Spiel hinzu)
        bool removeItem(int id) (Löscht ein bestimmtes LibraryItem)
        Suchen & Ausgabe mit bestimmten Kriterien:
            void sucheTitel(string titel)
            void sucheAutor(string autor)
            void sucheSpielerzahl(int szahl)
            void sucheID(int id)
        bool ausleihe(int id) (Leiht ein bestimmtes LibraryItem aus)
        bool rueckgabe(int id) (Gibt ein bestimmtes LibraryItem zurück)
        bool istGeliehen(int id) (prüft, ob ein bestimmtes LibraryItem ausgeliehen ist)
        void printInventar() (gibt alle in der Library gespeicherten LibraryItems aus)

### LibraryItem

    hat Variablen für folgende Eigenschaften:
        Art des LibraryItems (Buch oder Spiel)
        einmalige ID
        Titel des LibraryItems
        Autor (wird nur gesetzt, falls das LibraryItem ein Buch ist)
        Erscheinungsjahr (wird nur gesetzt, falls das LibraryItem ein Buch ist)
        Spieleranzahl (wird nur gesetzt, falls das LibraryItem ein Spiel ist)
        empfohlenes Alter (wird nur gesetzt, falls das LibraryItem ein Spiel ist)
        Ausleihstatus
    hat einen Konstruktor für ein neues Buch und ein neues Spiel
    hat eine toString-Operation, die erkennt, ob es sich um ein Buch oder ein Spiel handelt und nur die relevanten Informationen zurückgibt
    Erfüllt das Prinzip der Kapselung

