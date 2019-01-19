Ewelina Chmielewska, 283714


Specyfikacja problemu:
"Punkty symetryczne"
W uk³adzie wspó³rzêdnych XY znajduje siê n punktów o wspó³rzêdnych ca³kowitych.
Nale¿y znaleŸæ prostok¹t o bokach równoleg³ych do osi wspó³rzêdnych o najmniejszym
obwodzie, który zawiera wszystkie punkty lub ich odbicia symetryczne wzglêdem prostej
y = x. Jeœli prostok¹tów o najmniejszym obwodzie jest kilka, nale¿y wybraæ ten 
zawieraj¹cy wiêcej punktów oryginalnych (nie odbitych).


Uruchamianie:
Program uruchamiamy w konsoli œrodowiska Linux. Mo¿liwe tryby uruchomienia:
1. Dane pobierane ze standardowego wejœcia, wynik wysy³any na standardowe wyjœcie
• ./prog 1 <testFile.txt
• ./prog 1 <testFile.txt >resultFile.txt

2. Dane generowane automatycznie przez program
• ./prog 2 numberOfPoints
numberOfPoints - liczba punktow
• ./prog 2 numberOfPoints minX maxX minY maxY
numberOfPoints - liczba punktow
minX maxX minY maxY - ograniczenia liczbowe

3. Testowanie z pomiarem czasu dla zmiennej wielkoœci problemu
• ./prog 3 pointsInFirstTest numberOfTests stepSize testsPerStep
pointsInFirstTest – liczba punktów, jakie znajd¹ siê w pierwszych testach
numberOfTests – liczba testów, jakie musz¹ byæ wykonane dla ró¿nych wielkoœci problemu
stepSize – krok o jaki zwiêkszamy rozmiar problemu
testsPerStep – liczba testów, jakie zostan¹ wykonane dla danego rozmiaru problemu

4. Testowanie obu algorytmów (liniowego i brute force) dla 100 testów zapisanych w plikach projektu, w katalogu tests
• ./prog 4

5. Testowanie obu algorytmów (liniowego i brute force) dla zadanego pliku
• ./prog 5 testFIle.txt
testFIle.txt – plik testowy

6. Wyœwietlenie komunikatu zalecaj¹cego zapoznaæ siê z README.txt
• ./prog


Konwencja wejœæ i wyjœæ:
Dane wejœciowe powinny byæ zestawem liczb ca³kowitych oddzielonych spacjami.
Kolejne pary okreœlaj¹ wspó³rzêdne jednego punktu na p³aszczyŸnie 2D.

W plikach testowych przyjelam konwencje, ze w jednym wierszu zapisuje wspolrzedne jednego punktu, w postaci: x y
gdzie x i y s¹ liczbami ca³kowitymi. Tak¹ te¿ konwencjê pisania testów zalecam (ze wzglêdu na prostotê i czytelnoœæ)

Format wyjœcia zale¿ny jest od trybu:
• tryb 1 - wypisywane s¹ wspó³rzêdne punktów, z których sk³ada siê prostok¹t. W danej linii znajduje siê tylko jeden punkt.
• tryb 2 - analogicznie jak w trybie 1
• tryb 3 - w pierwszej linii zostaje wyœwietlony komunikat o asymptocie. W kolejnych liniach znajduj¹ siê 3 wartoœci oddzielone spacjami:
  - wielkoœæ problemu (liczba punktów)
  - czas œredni czas trwania obliczeñ
  - stosunek czasu trwania obliczen do przewidywanego czasu trwania obliczeñ (q)
• tryb 4
  - w pierwszej linijce zostaje wyœwietlone "Test n:", gdzie n to numer testu (od 1 do 99).
  - w drugiej linijce zostaje wyswietlone "Algorytm wlasny:"
  - w dwóch kolejnych linijkach zapisane s¹ dwa punkty w formacie (x, y), gdzie x i y to wspó³rzêdne punktu
  - w kolejnej linijce zostaje wyswietlone "Brute force:"
  - w dwóch kolejnych linijkach zapisane s¹ dwa punkty w formacie (x, y), gdzie x i y to wspó³rzêdne punktu
  Wyniki tego trybu moga sluzyc do szybkiego sprawdzenia poprawnosci algorytmu - raczej nie nadaja sie do budowania wykresow
• tryb 5
  - w pierwszej linijce zostaje wyswietlone "Algorytm wlasny:"
  - w dwóch kolejnych linijkach zapisane s¹ dwa punkty w formacie (x, y), gdzie x i y to wspó³rzêdne punktu
  - w kolejnej linijce zostaje wyswietlone "Brute force:"
  - w dwóch kolejnych linijkach zapisane s¹ dwa punkty w formacie (x, y), gdzie x i y to wspó³rzêdne punktu


Krótki opis algorytmu:
Wyliczamy prostok¹ty pomocnicze. Na ich podstawie wyznaczamy podstawowe przypadki testowe. Jeœli wartoœæ obwodu dla podstawowego
przypadku testowego bêdzie mniejsza lub równa aktualnej najmniejszej, to wykonujemy dodatkowe testy - permutujemy wspó³rzêdne punktów,
sprawdzamy czy prostok¹t siê nadaje (mo¿e pomieœciæ wszystkie punkty odbite lub orginalne), a jeœli tak, to analizujemy go tak jak
podstaowy przypadek testowy, ale ju¿ bez dalszych permutacji.

Zastosowane struktury danych: Punkt2D (w³asna), std::vector<>
Zastosowane algorytmy: pomniejsze algorytmy w³asne, algorytm rekurencyjny wyznaczania permutacji


Informacje o dekompozycji:
Czêœæ realizuj¹ca interfejs u¿ytkownika
• UserInterface (.cpp, .hpp)– zbiór metod odpowiadaj¹cych za wykonywanie i wyœwietlanie wyników testów 
Czêœæ realizuj¹ca algorytmy i struktury danych
• MyAlgorithm (.cpp, .hpp) – implementacja opisanego powy¿ej pomys³u na wyznaczanie minimalnego prostok¹ta. Z za³o¿eniu jest to algorytm o z³o¿onoœci liniowej
• BruteForceAlgorithm (.cpp, .hpp) – implementacja algorytmu wyznaczaj¹cego minimalny prostok¹t w sposób brutalny. Zaimplementowany w celu przetestowania poprawnoœci dzia³ania algorytmu liniowego
• RectangleFunctions (.cpp, .hpp) – zbiór funkcji wykorzystywanych miêdzy innymi w implementacji obu algorytmów – brutalnego i liniowego
• Point2D (.cpp, .hpp) – implementacja wykorzystywanej w projekcie struktury danych – punktu w przestrzeni 2D.
Jako ¿e w projekcie korzystam ze struktury wektora (std::vector<>), to ¿adne inne, dodatkowe struktury nie s¹ potrzebne
Czêœæ wspomagaj¹ca:
• TestGenerator (.cpp, .hpp) – implementacja modu³u odpowiadaj¹cego za generowanie testów
• TestReader (.cpp, .hpp) – implementacja modu³u odpowiadaj¹cego za wczytywanie gotowych testów – tworzenie wektorów bêd¹cych „przypadkami testowymi”


Informacje dodatkowe:
Uruchamianie programu do generowania testow:
• ./generateTests
  generowanie domyœlnej liczby testów o ograniczeniach domyœlnych
• ./generateTests numberOfTests
  numberOfTests - liczba testów
• ./generateTests numberOfTests pointsPerTest
  numberOfTests - liczba testów
  pointsPerTest - liczba punktów w teœcie
• ./generateTests numberOfTests pointsPerTest minX maxX minY maxY
  numberOfTests - liczba testów
  pointsPerTest - liczba punktów w teœcie
  minX maxX minY maxY - kolejne ograniczenia wartoœci losowanych
  
-
