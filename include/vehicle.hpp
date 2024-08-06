#ifndef VEHICLE_HPP
#define VEHICLE_HPP
#include <string>
#include <vector>
#include <iostream>

struct Musteri {
    string ad;
    string soyad;
    string telefon;
};
struct Satis {
    string tarih;
    int fiyat;
    Musteri musteri;
};
struct Bakim {
    string tarih;
    string islem;
    int km;
};
struct Arac {
    int id;
    string marka;
    string model;
    int yil;
    string renk;
    int km;
    int motor_hacmi;
    string yakit_turu;
    string vites_tipi;
    Satis satis;
    vector<Bakim> bakim_gecmisi;
};
int vehicle_database();
#endif // VEHICLE_HPP