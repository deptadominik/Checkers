# Warcaby
## 1. Treść zadania
Napisać program do gry w warcaby. Gra rozgrywana jest na
planszy o rozmiarze 8 × 8 pól. Celem gry jest zbicie wszystkich
pionów przeciwnika (w tym damek) albo zablokowanie
wszystkich, które pozostają na planszy, pozbawiając przeciwnika
możliwości wykonania ruchu. Pionki mogą poruszać się o jedno
pole do przodu po przekątnej na wolne pola. Bicie pionkiem
następuje przez przeskoczenie sąsiedniego pionu (lub damki)
przeciwnika na pole znajdujące się tuż za nim po przekątnej (pole
to musi być wolne). Zbite piony są usuwane z planszy po
zakończeniu ruchu.

## 2. Analiza zadania
Rozgrywka odbywa się w konsoli, gdzie gracze podają
odpowiednie współrzędne - w pierwszej kolejności współrzędne
pionka, a w drugiej kolejności współrzędne miejsca, na które
pionek zostanie przemieszczony. Dla wygody i przejrzystości
interfejsu plansza ma współrzędne w postaci liter w pionie i cyfr
w poziomie, tak jak zostało to ukazane poniżej:

![Alt text](https://i.ibb.co/Y0xcZH8/plansza-FIN.png)

## 2.1 Struktury danych
Program składa się z 6 klas: _**GameBoard, Pawn, BasicPawn, QueenPawn,
Field**_ oraz _**Move**_. Klasa _**Pawn**_ to klasa bazowa, dziedziczą po
niej publicznie klasy _**BasicPawn**_ oraz _**QueenPawn**_. Wewnątrz klasy _**GameBoard**_
przy pomocy vectorów zostaje stworzona dwuwymiarowa tablica
obiektów typu _**Field**_.
## 2.2 Algorytmy
Algorytmy w tym programie wymagały wnikliwego
przemyślenia dozwolonych ruchów. Program sprawdza
poprawność wprowadzonych współrzędnych pionka oraz miejsca
docelowego, następnie sprawdza rodzaj ruchu do wykonania. W
zależności od spełnionych warunków wykonuje bicie, normalny
ruch lub nie dokonuje przemieszczenia powiadamiając o tym
fakcie gracza stosownym komunikatem.
## 3. Specyfikacja zewnętrzna
Program uruchamiany jest z poziomu środowiska
programistycznego. Plikiem
wyjściowym jest plik tekstowy - „output.txt”. Plik generowany jest
przy użyciu operatora strumienia po zakończeniu gry. Zawiera on
informację o wygranej danego gracza (black lub white) oraz
finalny wygląd planszy (po zakończeniu gry) - przykład:

![Alt text](https://i.ibb.co/BV4XSwC/output.png)
## 4. Diagram klas
![Alt text](https://i.ibb.co/pzGmkhd/diagram-Klas-FIN.png)
## 5. Testowanie
Program został przetestowany pod kątem niepoprawnych
współrzędnych pionka oraz docelowego miejsca przesunięcia.
Niepoprawne współrzędne (niebędące w układzie cyfra litera,
wychodzące poza zakres planszy) powodują zgłoszenie błędu.
Program został również sprawdzony pod kątem wycieków.
## 6. Wnioski
Projekt ten bardzo rozwinął moje umiejętności logicznego
myślenia oraz poszerzył moją wiedzę o bardziej zaawansowane
aspekty obiektowego programowania w języku C++.


