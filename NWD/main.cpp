#include <iostream>
using namespace std;

size_t &funkcja(size_t &liczba_a, size_t &liczba_b) {
    size_t temp = liczba_b;
    liczba_b = liczba_a % liczba_b;
    liczba_a = temp;

    if (liczba_b == 0) {
        return liczba_a;
    }
    funkcja(liczba_a, liczba_b);
}

int main()
{
    int ilosc_liczb;
    cin >> ilosc_liczb;

    size_t *tab = new size_t[ilosc_liczb];
    for (int i = 0; i < ilosc_liczb; i++) {
        cin >> tab[i];
    }

    while (cin.get() != '\n')
        continue;

    size_t wynik = funkcja(tab[0], tab[1]);
    for (int i = 2; i < ilosc_liczb; i++) {
        wynik = funkcja(wynik, tab[i]);
    }

    cout << wynik << endl;
    delete[] tab;
    cin.get();
}
