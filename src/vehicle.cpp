#include "vehicle.hpp"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "include/json.hpp"

using namespace std;
using json = nlohmann::json;

vector<Arac> arac_list;

int vehicle_database() {
    const char *dosyaAdi = "examp.json";
    ifstream i(dosyaAdi);

    json j;
    i >> j;

    auto &aracContains = j["araclar"];

    Arac arac;

    for (const auto &item : aracContains.items()) {
        for (const auto &val : item.value().items()) {
            if (val.key() == "id") {
                if (val.value() == "")
                    arac.id = 0;
                else
                    arac.id = val.value();
                cout << arac.id << endl;
            }

            if (val.key() == "marka") {
                if (val.value() == "")
                    arac.marka = "0";
                else
                    arac.marka = val.value();
                cout << arac.marka << endl;
            }

            if (val.key() == "model") {
                if (val.value() == "")
                    arac.model = "0";
                else
                    arac.model = val.value();
                cout << arac.model << endl;
            }

            if (val.key() == "yil") {
                if (val.value() == "")
                    arac.yil = 0;
                else
                    arac.yil = val.value();
                cout << arac.yil << endl;
            }

            if (val.key() == "renk") {
                if (val.value() == "")
                    arac.renk = "0";
                else
                    arac.renk = val.value();
                cout << arac.renk << endl;
            }

            if (val.key() == "km") {
                if (val.value() == "")
                    arac.km = 0;
                else
                    arac.km = val.value();
                cout << arac.km << endl;
            }

            if (val.key() == "motor_hacmi") {
                if (val.value() == "")
                    arac.motor_hacmi = 0;
                else
                    arac.motor_hacmi = val.value();
                cout << arac.motor_hacmi << endl;
            }

            if (val.key() == "yakit_turu") {
                if (val.value() == "")
                    arac.yakit_turu = "0";
                else
                    arac.yakit_turu = val.value();
                cout << arac.yakit_turu << endl;
            }

            if (val.key() == "vites_tipi") {
                if (val.value() == "")
                    arac.vites_tipi = "0";
                else
                    arac.vites_tipi = val.value();
                cout << arac.vites_tipi << endl;
            }

            if (val.key() == "satis") {
                auto satis = val.value();
                if (satis["tarih"] == "")
                    arac.satis.tarih = "0";
                else
                    arac.satis.tarih = satis["tarih"];
                cout << arac.satis.tarih << endl;

                if (satis["fiyat"] == "")
                    arac.satis.fiyat = 0;
                else
                    arac.satis.fiyat = satis["fiyat"];
                cout << arac.satis.fiyat << endl;

                if (satis["musteri"]["ad"] == "")
                    arac.satis.musteri.ad = "0";
                else
                    arac.satis.musteri.ad = satis["musteri"]["ad"];
                cout << arac.satis.musteri.ad << endl;

                if (satis["musteri"]["soyad"] == "")
                    arac.satis.musteri.soyad = "0";
                else
                    arac.satis.musteri.soyad = satis["musteri"]["soyad"];
                cout << arac.satis.musteri.soyad << endl;

                if (satis["musteri"]["telefon"] == "")
                    arac.satis.musteri.telefon = "0";
                else
                    arac.satis.musteri.telefon = satis["musteri"]["telefon"];
                cout << arac.satis.musteri.telefon << endl;
            }

            if (val.key() == "bakim_gecmisi") {
                for (const auto &bakim : val.value()) {
                    Bakim b;
                    if (bakim["tarih"] == "")
                        b.tarih = "0";
                    else
                        b.tarih = bakim["tarih"];
                    cout << b.tarih << endl;

                    if (bakim["islem"] == "")
                        b.islem = "0";
                    else
                        b.islem = bakim["islem"];
                    cout << b.islem << endl;

                    if (bakim["km"] == "")
                        b.km = 0;
                    else
                        b.km = bakim["km"];
                    cout << b.km << endl;

                    arac.bakim_gecmisi.push_back(b);
                }
            }
        }
        arac_list.push_back(arac);
    }

    ofstream File("src/arac_database.txt");

    stringstream ss;

    for (int i = 0; i < arac_list.size(); i++) {
        ss << "Arac ID: " << arac_list[i].id << "\n";
        ss << "Marka: " << arac_list[i].marka << "\n";
        ss << "Model: " << arac_list[i].model << "\n";
        ss << "Yil: " << arac_list[i].yil << "\n";
        ss << "Renk: " << arac_list[i].renk << "\n";
        ss << "KM: " << arac_list[i].km << "\n";
        ss << "Motor Hacmi: " << arac_list[i].motor_hacmi << "\n";
        ss << "Yakit Turu: " << arac_list[i].yakit_turu << "\n";
        ss << "Vites Tipi: " << arac_list[i].vites_tipi << "\n";
        ss << "Satis Tarihi: " << arac_list[i].satis.tarih << "\n";
        ss << "Fiyat: " << arac_list[i].satis.fiyat << "\n";
        ss << "Musteri Adi: " << arac_list[i].satis.musteri.ad << "\n";
        ss << "Musteri Soyadi: " << arac_list[i].satis.musteri.soyad << "\n";
        ss << "Musteri Telefon: " << arac_list[i].satis.musteri.telefon << "\n";

        ss << "Bakim Gecmisi:\n";
        for (const auto &bakim : arac_list[i].bakim_gecmisi) {
            ss << "  Tarih: " << bakim.tarih << ", Islem: " << bakim.islem << ", KM: " << bakim.km << "\n";
        }
        ss << "---------------------\n";
    }

    File << ss.str();
    File.close();

    return 0;
}
