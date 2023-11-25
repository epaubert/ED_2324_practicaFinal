#ifndef _RUTA_H_
#define _RUTA_H_

#include<iostream>
#include<string>
#include<../include/Punto.h>
#include<list>

using namespace std;

class Ruta{
    private:
        list<Punto> puntos;
        string code;

    public:

        Ruta();
        void Insertar(const Punto &n) ;
        void Borrar(const Punto &n) ;
        
        string getCode() const ;
        void setCode(const string &code) ;

        bool operator==(const Ruta &R) const ;
        bool operator<(const Ruta &R) const ;

        class iterator{
            private:
                list<Punto>:: iterator p;
            public:
                Punto &operator*();
                iterator operator++();
                bool operator==(const iterator &it) const;
                bool operator!=(const iterator &it) const;
        } ;

        class const_iterator{
            private:
                list<Punto>::const_iterator p;
            public:
                const Punto &operator*() const;
                const_iterator operator++();
                bool operator==(const iterator &it) const;
                bool operator!=(const iterator &it) const;
        };

        iterator begin() ;
        const_iterator begin() const;

        iterator end() ;
        const_iterator end() const ;

        iterator find(const Punto &P) ;

        friend istream &operator>>(istream &is, Ruta &R) ;
        friend ostream &operator<<(ostream &os, Ruta &R) ;
 };

#endif