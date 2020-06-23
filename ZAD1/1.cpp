#include <iostream>
#include <chrono>
#include <cmath>

using namespace std;
using namespace std::chrono;

    void function()
    {   // funkcja wykonuje jakies bezsensowne, ale obciazajace obliczenia
        double number{ 0. };
    #pragma omp parallel for reduction(+:number) num_threads(4)
        for (long long i = 0; i != 200000000; ++i)
        {
            number += sin(static_cast<double>(i) / (i + 1));
        }
    }

int main()
{
	int i=0;
	for (i; i<=3; i++)
{
	    auto start = std::chrono::high_resolution_clock::now();
    // odczytaj czas poczatkowy
    function();
    // After function call 
    auto stop = std::chrono::high_resolution_clock::now();
    // odczytaj czas koncowy

    // floating-point duration: no duration_cast needed
    std::chrono::duration<double, std::milli> fp_ms = stop - start;

    auto int_ms = std::chrono::duration_cast<std::chrono::seconds>(stop - start);
   /* auto duration = 0;*/ // w miejsce 0 wpisz odpowiednie wyrazenie z duration przeliczajacym na minuty

    std::cout << "f() czas w milisekundach " << fp_ms.count() << " ms, "
        << "or " << int_ms.count() << " czas w sekundach " << std::endl;
}
    return 0;

}
