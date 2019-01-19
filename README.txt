Ewelina Chmielewska, 283714


Specyfikacja problemu:
"Punkty symetryczne"
W uk�adzie wsp�rz�dnych XY znajduje si� n punkt�w o wsp�rz�dnych ca�kowitych.
Nale�y znale�� prostok�t o bokach r�wnoleg�ych do osi wsp�rz�dnych o najmniejszym
obwodzie, kt�ry zawiera wszystkie punkty lub ich odbicia symetryczne wzgl�dem prostej
y = x. Je�li prostok�t�w o najmniejszym obwodzie jest kilka, nale�y wybra� ten 
zawieraj�cy wi�cej punkt�w oryginalnych (nie odbitych).


Uruchamianie:
Program uruchamiamy w konsoli �rodowiska Linux. Mo�liwe tryby uruchomienia:
1. Dane pobierane ze standardowego wej�cia, wynik wysy�any na standardowe wyj�cie
� ./prog 1 <testFile.txt
� ./prog 1 <testFile.txt >resultFile.txt

2. Dane generowane automatycznie przez program
� ./prog 2 numberOfPoints
numberOfPoints - liczba punktow
� ./prog 2 numberOfPoints minX maxX minY maxY
numberOfPoints - liczba punktow
minX maxX minY maxY - ograniczenia liczbowe

3. Testowanie z pomiarem czasu dla zmiennej wielko�ci problemu
� ./prog 3 pointsInFirstTest numberOfTests stepSize testsPerStep
pointsInFirstTest � liczba punkt�w, jakie znajd� si� w pierwszych testach
numberOfTests � liczba test�w, jakie musz� by� wykonane dla r�nych wielko�ci problemu
stepSize � krok o jaki zwi�kszamy rozmiar problemu
testsPerStep � liczba test�w, jakie zostan� wykonane dla danego rozmiaru problemu

4. Testowanie obu algorytm�w (liniowego i brute force) dla 100 test�w zapisanych w plikach projektu, w katalogu tests
� ./prog 4

5. Testowanie obu algorytm�w (liniowego i brute force) dla zadanego pliku
� ./prog 5 testFIle.txt
testFIle.txt � plik testowy

6. Wy�wietlenie komunikatu zalecaj�cego zapozna� si� z README.txt
� ./prog


Konwencja wej�� i wyj��:
Dane wej�ciowe powinny by� zestawem liczb ca�kowitych oddzielonych spacjami.
Kolejne pary okre�laj� wsp�rz�dne jednego punktu na p�aszczy�nie 2D.

W plikach testowych przyjelam konwencje, ze w jednym wierszu zapisuje wspolrzedne jednego punktu, w postaci: x y
gdzie x i y s� liczbami ca�kowitymi. Tak� te� konwencj� pisania test�w zalecam (ze wzgl�du na prostot� i czytelno��)

Format wyj�cia zale�ny jest od trybu:
� tryb 1 - wypisywane s� wsp�rz�dne punkt�w, z kt�rych sk�ada si� prostok�t. W danej linii znajduje si� tylko jeden punkt.
� tryb 2 - analogicznie jak w trybie 1
� tryb 3 - w pierwszej linii zostaje wy�wietlony komunikat o asymptocie. W kolejnych liniach znajduj� si� 3 warto�ci oddzielone spacjami:
  - wielko�� problemu (liczba punkt�w)
  - czas �redni czas trwania oblicze�
  - stosunek czasu trwania obliczen do przewidywanego czasu trwania oblicze� (q)
� tryb 4
  - w pierwszej linijce zostaje wy�wietlone "Test n:", gdzie n to numer testu (od 1 do 99).
  - w drugiej linijce zostaje wyswietlone "Algorytm wlasny:"
  - w dw�ch kolejnych linijkach zapisane s� dwa punkty w formacie (x, y), gdzie x i y to wsp�rz�dne punktu
  - w kolejnej linijce zostaje wyswietlone "Brute force:"
  - w dw�ch kolejnych linijkach zapisane s� dwa punkty w formacie (x, y), gdzie x i y to wsp�rz�dne punktu
  Wyniki tego trybu moga sluzyc do szybkiego sprawdzenia poprawnosci algorytmu - raczej nie nadaja sie do budowania wykresow
� tryb 5
  - w pierwszej linijce zostaje wyswietlone "Algorytm wlasny:"
  - w dw�ch kolejnych linijkach zapisane s� dwa punkty w formacie (x, y), gdzie x i y to wsp�rz�dne punktu
  - w kolejnej linijce zostaje wyswietlone "Brute force:"
  - w dw�ch kolejnych linijkach zapisane s� dwa punkty w formacie (x, y), gdzie x i y to wsp�rz�dne punktu


Kr�tki opis algorytmu:
Wyliczamy prostok�ty pomocnicze. Na ich podstawie wyznaczamy podstawowe przypadki testowe. Je�li warto�� obwodu dla podstawowego
przypadku testowego b�dzie mniejsza lub r�wna aktualnej najmniejszej, to wykonujemy dodatkowe testy - permutujemy wsp�rz�dne punkt�w,
sprawdzamy czy prostok�t si� nadaje (mo�e pomie�ci� wszystkie punkty odbite lub orginalne), a je�li tak, to analizujemy go tak jak
podstaowy przypadek testowy, ale ju� bez dalszych permutacji.

Zastosowane struktury danych: Punkt2D (w�asna), std::vector<>
Zastosowane algorytmy: pomniejsze algorytmy w�asne, algorytm rekurencyjny wyznaczania permutacji


Informacje o dekompozycji:
Cz�� realizuj�ca interfejs u�ytkownika
� UserInterface (.cpp, .hpp)� zbi�r metod odpowiadaj�cych za wykonywanie i wy�wietlanie wynik�w test�w 
Cz�� realizuj�ca algorytmy i struktury danych
� MyAlgorithm (.cpp, .hpp) � implementacja opisanego powy�ej pomys�u na wyznaczanie minimalnego prostok�ta. Z za�o�eniu jest to algorytm o z�o�ono�ci liniowej
� BruteForceAlgorithm (.cpp, .hpp) � implementacja algorytmu wyznaczaj�cego minimalny prostok�t w spos�b brutalny. Zaimplementowany w celu przetestowania poprawno�ci dzia�ania algorytmu liniowego
� RectangleFunctions (.cpp, .hpp) � zbi�r funkcji wykorzystywanych mi�dzy innymi w implementacji obu algorytm�w � brutalnego i liniowego
� Point2D (.cpp, .hpp) � implementacja wykorzystywanej w projekcie struktury danych � punktu w przestrzeni 2D.
Jako �e w projekcie korzystam ze struktury wektora (std::vector<>), to �adne inne, dodatkowe struktury nie s� potrzebne
Cz�� wspomagaj�ca:
� TestGenerator (.cpp, .hpp) � implementacja modu�u odpowiadaj�cego za generowanie test�w
� TestReader (.cpp, .hpp) � implementacja modu�u odpowiadaj�cego za wczytywanie gotowych test�w � tworzenie wektor�w b�d�cych �przypadkami testowymi�


Informacje dodatkowe:
Uruchamianie programu do generowania testow:
� ./generateTests
  generowanie domy�lnej liczby test�w o ograniczeniach domy�lnych
� ./generateTests numberOfTests
  numberOfTests - liczba test�w
� ./generateTests numberOfTests pointsPerTest
  numberOfTests - liczba test�w
  pointsPerTest - liczba punkt�w w te�cie
� ./generateTests numberOfTests pointsPerTest minX maxX minY maxY
  numberOfTests - liczba test�w
  pointsPerTest - liczba punkt�w w te�cie
  minX maxX minY maxY - kolejne ograniczenia warto�ci losowanych
  
-
