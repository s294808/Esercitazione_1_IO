#include <iostream>
#include <fstream>
#include <iomanip>

double mappatura(double N)
{
    //ridimensiona i valori da [1, 5] a [0, 1]
    double Nrid = (N-1.0)/(5.0-1.0);

    //mappa il valore ridemensionato a [-1, 2]
    double Nmappato = Nrid * (2.0 - (-1.0)) + (-1.0);

    return Nmappato;
}

int main()
{
    //APRE IL FILE E CONTROLLA SE CI SONO ERRORI

    std::string fileName = "data.csv";
    std::ifstream ifstr(fileName);

    if(ifstr.fail())
    {
        std::cerr << "Errore nell'apertura del file" <<std::endl;
        return 1;
    }

    //CREAZIONE DEL FILE result.csv E CONTROLLO DI ERRORI NELLA CREAZIONE

    std::string nomeFile = "result.csv";
    std::ofstream outFile(nomeFile);
    outFile << "N mean" << std::endl; //scrittura dell'header del file

    if(outFile.fail())
    {
        std::cerr << "Errore nella creazione del file" <<std::endl;
        return 1;
    }


    double val = 0; //valori dentro il file data.csv
    double valMappato = 0; //valori mappati tramite la funzione mappatura
    unsigned int countVal = 1; //contatore dei valori dentro il file
    double sum = 0; //somma dei valori mappati al variare di i
    double mean = 0; //media dei valori mappati al variare di i


    while (ifstr >> val)
    {
        valMappato = mappatura(val);
        sum += valMappato;
        mean = sum/countVal;
        countVal++;
        outFile << std::scientific << std::setprecision(17) << mean << std::endl; //scrittura nel file dei valori della media al variare di i
    }

    outFile.close(); //chiusura del file

    std::cout << "Il file è stato creato correttamente" << std::endl;

    return 0;
}

