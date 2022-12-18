#include <iostream>
//#include <conio.h>
#include <cmath>

using namespace std;

int x[51];
int k, n, nsol;
bool buna;

bool ConditiiContinuare(int k)
{
    // aici testam ca tura k sa nu se atace 
    // pe linie sau pe diagonala cu vreuna 
    // din turele dinaintea sa
    bool atac = false;
    int i = 1;
    while (!atac && i < k)
        if (x[i] == x[k])
            atac = true;
        else i++;
    return !atac;
}

void ScrieSolutia()
{
    nsol++;
    cout << "Solutie " << nsol << " este:\n";
    for (int i = 1; i <= n; i++)
        cout << "  Asezati tura nr. " << i << " pe linia "
        << x[i] << " si coloana " << i << "\n";
    getchar();
}

int main()
{
    cout << "Problema turelor\n";
    n = 8;
    k = 1; // plecam cu prima tura
    x[k] = 0; // asezam tura aceasta sub tabla
    nsol = 0; // numarul de solutii
    if (n != 8)
    {
        cout << "Numar incompatibil de turnuri" << endl;
        exit(1);
    }
    while (k > 0) // cat timp inca mai avem ture pe tabla
    {
        buna = false; // deocamdata tura nu sta bine acolo
        // cat timp pozitia curenta nu e buna si tura
        // mai poate fi dusa cu o linie mai sus
        while (!buna && x[k] < n)
        {
            // mut tura mai sus cu un rand/o linie
            x[k]++;
            // testez conditiile de continuare k->k+1
            if (ConditiiContinuare(k)) buna = true;

        }
        if (buna) // daca varianta pentru tura k este buna...
            if (k == n) // daca am ajuns la ultima tura...
                ScrieSolutia(); // atunci afisam solutia
            else // daca nu am ajuns la ultima, 
            {
                k++; // trecem la urmatoarea tura
                x[k] = 0; // si o asezam sub tabla
            }
        else
            k--; // daca nu (mai) gasim o varianta buna
        // atunci ne intoarcem la tura anterioara
    }
    cout << "Numarul total de solutii:" << nsol << endl;
}