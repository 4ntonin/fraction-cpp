#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>


class Fraction
{
public:
    Fraction(int numerateur, int denominateur);
    Fraction(int numerateur);
    Fraction();
    void affiche(std::ostream &flux) const;
    Fraction& operator+=(Fraction const &autre);
    Fraction& operator*=(Fraction const& autre);
    bool superieur(const Fraction &b) const;
    bool egal(const Fraction &autre) const;

private:
    int m_numerateur;
    int m_denominateur;
};

int pgcd(int a, int b);
Fraction operator+(Fraction const& a, Fraction const& b);
Fraction operator*(const Fraction &a, const Fraction &b);
bool operator>(const Fraction &a, const Fraction &b);
bool operator<(const Fraction &a, const Fraction &b);
bool operator==(const Fraction &a, const Fraction &b);
std::ostream& operator<<(std::ostream& flux, Fraction const& fraction);


#endif // FRACTION_H