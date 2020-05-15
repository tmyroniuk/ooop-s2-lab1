#include "generator.h"
#include <QString>
#include <QDebug>

template <typename T>
std::random_device Generator<T>::rd;

template<>
IPv4 Generator<IPv4>::rand_val() {
    std::uniform_int_distribution<int> dist(0, 255);
    std::string res = std::to_string(dist(rd));
    for (int i = 0; i < 3; i++) res += '.' + std::to_string(dist(rd));
    return IPv4(res);
}

template<>
MAC Generator<MAC>::rand_val() {
    Parser parser;
    std::uniform_int_distribution<int> dist(0, 255);
    std::string res = parser.intToHex(dist(rd));
    for (int i = 0; i < 5; i++) res += ':' + parser.intToHex(dist(rd));
    return MAC(res);
}

template<>
IPv6 Generator<IPv6>::rand_val() {
    Parser parser;
    std::uniform_int_distribution<uint16_t> dist(0, 65535);
    std::string res = parser.intToHex(dist(rd));
    for (int i = 0; i < 7; i++) res += ':' + parser.intToHex(dist(rd));
    return IPv6(res);
}

template<>
int Generator<int>::rand_val() {
    std::uniform_int_distribution<int> dist(-255, 255);
    return dist(rd);
}

template<>
double Generator<double>::rand_val() {
    std::uniform_int_distribution<int> dist(1, 255);
    return double(dist(rd))/double(dist(rd));
}

template<>
std::string Generator<std::string>::rand_val() {
    std::string res;
    std::uniform_int_distribution<int> len(1, 10);
    std::uniform_int_distribution<int> dist(int('a'), int('z'));
    for(int i = 0; i<len(rd); i++) res += char(dist(rd));
    return res;
}

template<>
int Generator<int>::concrete_val(const std::string& str) {qDebug()<< QString::fromStdString(str); return std::stoi(str); }

template<>
double Generator<double>::concrete_val(const std::string& str) { return std::stod(str); }

template<>
std::string Generator<std::string>::concrete_val(const std::string& str) { return str; }

template<>
IPv4 Generator<IPv4>::concrete_val(const std::string& str) { return IPv4(str); }

template<>
IPv6 Generator<IPv6>::concrete_val(const std::string& str) { return IPv6(str); }

template<>
MAC Generator<MAC>::concrete_val(const std::string& str) { return MAC(str); }

template <>
QString Generator<int>::to_qstring(const int &val) { return QString::number(val); }

template <>
QString Generator<double>::to_qstring(const double &val) { return QString::number(val); }

template <>
QString Generator<std::string>::to_qstring(const std::string &val) { return QString::fromStdString(val); }

template <>
QString Generator<IPv4>::to_qstring(const IPv4 &val) { return QString::fromStdString(val.asString()); }

template <>
QString Generator<MAC>::to_qstring(const MAC &val) { return QString::fromStdString(val.asString()); }

template <>
QString Generator<IPv6>::to_qstring(const IPv6 &val) { return QString::fromStdString(val.asString()); }
