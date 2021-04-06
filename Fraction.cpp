#include "Fraction.h"
using namespace std;


Fraction::Fraction(int numerateur, int denominateur) : m_numerateur(numerateur), m_denominateur(denominateur) {
    int diviseur(pgcd(numerateur, denominateur));
    m_numerateur /= diviseur;
    m_denominateur /= diviseur;
}

Fraction::Fraction(int numerateur) : m_numerateur(numerateur), m_denominateur(1) {}

Fraction::Fraction() : m_numerateur(0), m_denominateur(1){}

void Fraction::affiche(ostream &flux) const {
    if(m_denominateur == 1) {
        flux << m_numerateur;
    }
    else {
        flux << m_numerateur << "/" << m_denominateur;
    }
}

bool Fraction::superieur(const Fraction &autre) const {
    if(m_numerateur * autre.m_denominateur > m_denominateur * autre.m_numerateur)
        return true;
    else
        return false;
}

bool Fraction::egal(const Fraction &autre) const {
    if(m_numerateur == autre.m_numerateur && m_denominateur == autre.m_denominateur)
        return true;
    else
        return false;
}


int pgcd(int a, int b) {
    while (b != 0)
    {
        const int t = b;
        b = a%b;
        a=t;
    }
    return a;
}


Fraction operator+(const Fraction &a, const Fraction &b) {
    Fraction copie(a);
    copie += b;
    return copie;
}

Fraction operator*(const Fraction &a, const Fraction &b) {
    Fraction copie(a);
    copie *= b;
    return copie;
}

bool operator>(const Fraction &a, const Fraction &b) {
    if(a.superieur(b))
        return true;
    else
        return false;
}

bool operator<(const Fraction &a, const Fraction &b) {
    if(b.superieur(a))
        return true;
    else
        return false;
}

bool operator==(const Fraction &a, const Fraction &b) {
    if(a.egal(b))
        return true;
    else
        return false;
}

Fraction& Fraction::operator+=(Fraction const& autre) {
    m_numerateur = autre.m_denominateur * m_numerateur + m_denominateur * autre.m_numerateur;
    m_denominateur = m_denominateur * autre.m_denominateur;
    return *this;
}

Fraction& Fraction::operator*=(Fraction const& autre) {
    m_numerateur *= autre.m_numerateur;
    m_denominateur *= autre.m_denominateur;
    return *this;
}

ostream& operator<<(ostream& flux, Fraction const& fraction) {
    fraction.affiche(flux);
    return flux;
}

