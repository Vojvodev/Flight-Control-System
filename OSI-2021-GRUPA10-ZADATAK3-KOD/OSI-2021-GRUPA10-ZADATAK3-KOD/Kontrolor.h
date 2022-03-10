#pragma once
#include <exception>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <filesystem>

#include "Let.h"
#include "Datum.h"
#include "Radnik.h"

class Let;
namespace fs = std::filesystem;
#define RASPORED_FILEPATH "./LETOVI/RASPORED.txt"
#define SORTIRANI_FILEPATH "./LETOVI/SORTIRANI_RASPORED"


class Kontrolor :virtual public Radnik
{
private:
public:
    Kontrolor(std::string name, std::string pass) : Radnik(name, pass, "Kontrolor") {}
    void kreiraj_let();
    bool promjenaStatusa();

    void promjenaStatusaNovica();

    void pregledInformacijaOLetovima() const;
    void otkazivanjeLeta();

private:
    bool postojiLiLet(int ime) const;
    void promijeniOperatera(std::string id) const;
    void izbrisiIzRasporeda(std::string id);
    void azurirajAktivneLetove(std::string id);
    void sortiranjeRasporeda(std::string);
    void prepisiLetove(std::string);
    bool daLiJeLetAktivan(std::string);
};
