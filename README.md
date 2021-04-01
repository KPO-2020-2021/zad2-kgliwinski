# Projekt 2 - Arytmetyka liczb zespolonych

## Cel ćwiczenia
Wykształcenie umiejętności definiowania przeciążeń operatorów arytmetycznych dwuargumentowych i jednoargumentowych dla własnych struktur danych oraz operatora porównania. Przećwiczenie podstawowych operacji na strumieniach plikowych.  Nabycie umiejętności definiowania przeciążeń operacji na strumieniach.

## Opis zadania programowego
Należy napisać program, który umożliwia wykonanie prostego sprawdzianu z arytmetyki liczb zespolonych.  Sprawdzian ma dotyczyć operacji dodawania, odejmowania, mnożenia i dzielenia. Zakłada się, ̇ze są dostępne co najmniej dwa zestawy pytań. Dla uproszczenia zakładamy, ̇ze liczby zespolone będą wyświetlane w nawiasach. W tej formie będą również wprowadzane. Przykładowy zapis wyrażeń podany jest poniżej.

	(4.2+2i)+(0+2i)
	(3-0i)*(-1+2.1i)
	(0-4i)/(3-1i)

W zapisie tym dla ułatwienia zachowanych jest kilka reguł:
* każda liczba zespolona zawsze zapisywana jest w nawiasach półokrągłych,
* zawsze występuje liczba oznaczająca część rzeczywistą, niezależnie od tego czy jest ona różna od zera, czy też równa jest zeru,
* zawsze  występuje  liczba  oznaczająca  część urojoną, niezależnie od tego czy jest ona różna od zera, czy też równa jest zeru,
* zestaw pytań zakończony jest znakiem kropki.

W trakcie realizacji testu program wyświetla kolejne wyrażenie i pyta użytkownika o wyniko peracji.  Udzieloną odpowiedź sprawdza z poprawnym wynikiem.  W przypadku poprawnej odpowiedzi, potwierdza ten fakt, zaś w przypadku błędnej odpowiedzi stwierdza ten fakt i podaje odpowiedź właściwą.  Po zakończeniu testu podawana jest statystyka błędnych i poprawnych odpowiedzi.


## Struktura repozytorium
Repozytorium z zalążkiem do zadania ma następującą strukturę:

&nbsp;&nbsp; [src](src/) - folder z plikami źródłowymi\
&nbsp;&nbsp; [inc](inc/)-- folder z plikami nagłówkowymi\
&nbsp;&nbsp; [tests](tests/) - zawiera pliki źródłowe testów oraz biblioteki doctest\
&nbsp;&nbsp; ├── bin - pliki binarne testów\
&nbsp;&nbsp; └── doctest - pliki źródłowe dla biblioteki odpowiedzialnej za testy\
&nbsp;&nbsp; [man](man/) - instrukcje do zadania oraz inne pomoce naukowe\
&nbsp;&nbsp; Makefile - plik z dyrektywami do automatycznej kompilacji\
&nbsp;&nbsp; .gitignore  - plik określający, które pliki mają być ignorowane przez Gita\

## Odnośniki do źródeł
[Strona kursu z Programowania Obiektowego](https://kcir.pwr.edu.pl/~kreczmer/po/)

## Sprawozdanie / zrealizowane zadania

Program test_arytm_zesp został wyposażony zgodnie ze specyfikacja zadania w funkcje:

	-Wczytywania i wypisywania liczb zespolonych (poprzez przeciazenie operatorow >> i <<)
	-Wczytania i wypisywania wyrazen zespolonych (poprzez przeciazenie operatorow >> i <<)
	-Liczenia wyrazen zespolonych (poprzez przeciazenia operatorow arytmetycznych +,-,/,*)
	-Modul statystyki, lacznie z przeciazonym operatorem wyjscia wypisujacym w odpowiedni sposob wyniki
	-Trudna wersje testu
	
	-Funkcje zostaly przeciazone oraz zamienione na metody dla struktur LZespolona, WyrazenieZesp, Statystyki
	-Kod programu jest napisany zgodnie z zalozeniami OOP
	-Funkcje posiadaja asercje pilnujace przed blednym wpisywaniem liczb zespolonych lub dzieleniem przez 0
	-program posiada dwie opcje testow: latwy i trudny, dla ktorych dziala poprawnie

Testy:

Testy programu (od test0.cpp do test6.cpp) sprawdzaja wymagana funkcjonalnosc programu

test0.cpp:
	-sprawdza przeciazenie operatora rownosci (==) dla rownosci i nierownosci
	-sprawdza dla malych liczb dzialanie operatora
		
		*UWAGA* testy 5 i 6 z test0.cpp prezentuja BLEDNE dzialanie operatora 
		dla liczb mniejszych lub rownych od 0.0001,
		jest to spowodowane uzyciem funkcji rownosci poprzez porownanie dla bardzo malych wartosci
		Wypisanie bledu przez test powoduje ze reszta testow sie nie wykonuje, 
		dlatego postanowilem ze test bedzie sprawdzal czy funkcja "nie dziala"
		i przez to test nie zwraca bledu, a reszta testow moze sie wykonac

test1.cpp:
		-sprawdza dzialanie sumy i roznicy liczb zespolonych
		-zawiera testy dla przypadkow granicznych, oraz malych wielkosci

test2.cpp:
		-sprawdza dzialanie mnozenia i dzielenia liczb zespolonych oraz dzielenia liczby zespolonej przez skalar
		-podobnie, zawiera testy dla przypadkow granicznych i malych wielkosci
		-sprawdza asercje w przypadku dzielenia przez 0

test3.cpp:
		-sprawdza dzialanie sprzezenia i kwadratu modulu dla liczb zespolonych
		-posiada przypadki graniczne, sprzezenia dla liczby o zerowej czesci urojonej, dla malych liczb

test4.cpp:
		-sprawdza wyswietlanie i wczytywanie liczb i wyrazen zespolonych
		-obsluguje zaokraglenia (np. dla 2.0/3.0 = 0.667), funkcja wypisujaca zaokragla do 4 miejsca po przecinku
		-sprawdza dzialanie dla malych liczb
		-sprawdza asercje w przypadku zlego wejscia (np. 0+0i) (brak nawiasu z przodu) , 
			(1+1) (brak i) i.t.p.) dla liczb zespolonych
		-sprawdza asercje w przypadku zlego wejscia (np. podobnie jak wyzej, + brak operatora matematycznego) 
			dla wyrazen zespolonych
		-przy wykonywaniu niektorych testow zostaja wypisane komunikaty "Blad zapisu liczby zespolonej. Sprobuj jeszcze raz."
			zamierzeniem tej funkcji bylo wypisywanie tego komunikatu dla uzytkownika podczas testu, 
			jesli wpisywal liczbe zespolona w blednym formacie.
			Funkcja w programie dziala poprawnie, jednak podczas testow wystepuje taki skutek uboczny, 
			co jednak nie problemem w ich realizacjis
	test5.cpp:
		-sprawdza funkcje liczenia wyrazen zespolonych (dla wszystkich operatorow matematycznych)
		-sprawdza asercje w przypadku dzielenia przez 0
		-sprawdza dzialanie dla malych liczb, zaokraglen

	test6.cpp
		-sprawdza funkcje liczenia statystyki oraz przeciazenie operatora wyjscia <<
		-sprawdza asercje jesli nie podano zadnych odpowiedzi

	test7.cpp
		-sprawdza dodane funkcje w 3 tygodniu zajec (jako dodatkowa modyfikacja programu)
		-sprawdza dzialanie sumy z przypisaniem (przeciazenia operatora +=) dla LZespolonej
		-sprawdza dzialanie sumy z przypisaniem (przeciazenia operatora /=) dla LZespolonej
		-w obydwoch przypadkach bierze pod uwage i sprawdza czy wynik dzialania jest przypisywany do pierwszej zmiennej
		-sprawdza dzialanie funkcji arg() zwracajacej argument glowny LZespolonej

Wnioski z testow:
	-jedyna zle dzialajaca funkcja to operator == dla liczb rzedu 10^(-4) co jest spowodowane taka definicja operatora == w LZespolona.cpp
	-reszta funkcji dziala w pelni poprawnie, zgodnie ze specyfikacja zadania oraz ich przeznaczeniem