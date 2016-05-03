/* stringtokenizer.cpp; reference implementation for stringtokenizer.h
 * Copyright (C) 2016  Aayush Agarwal
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdexcept>
#include "stringtokenizer.h"

namespace stringtokenizer {

/* WARNING: tokenize is currently only tested to work with standard strings
 * where each character fits in a byte. Using unicode or any other multi-byte
 * encodings may result in unexpected behaviour.
 */
std::vector<std::string> tokenize(std::string source, char delimiter) {

    //to ensure the last word is correctly parsed
    if(source.back() != delimiter) source += delimiter;
    std::vector<std::string> stringtokens(0);
    std::string currtoken = "";
    for(const auto& i: source) {
        if(i == delimiter) {
            if(currtoken != "") {
                stringtokens.push_back(currtoken);
                currtoken = "";
            }
            else currtoken = "";
        }
        else currtoken += i;
    }
    return stringtokens;
}

/* WARNING: It is your responsibility to ensure that the values in the
 * strings sent to these functions are not out of range.
 *
 * These functions will not add any values that are out of range to the vector.
 * These functions can handle mixed input using the same rules as the
 * std::sto<type> functions.
 */

/* functions that take string and delimiter as input */
std::vector<int> sttoiv(std::string source, char delimiter) {

    std::vector<std::string> tokens = tokenize(source, delimiter);
    return sttoiv(tokens);
}
std::vector<long> sttolv(std::string source, char delimiter) {

    std::vector<std::string> tokens = tokenize(source, delimiter);
    return sttolv(tokens);
}
std::vector<long long> sttollv(std::string source, char delimiter) {

    std::vector<std::string> tokens = tokenize(source, delimiter);
    return sttollv(tokens);
}

std::vector<unsigned long> sttoulv(std::string source, char delimiter) {

    std::vector<std::string> tokens = tokenize(source, delimiter);
    return sttoulv(tokens);
}
std::vector<unsigned long long> sttoullv(std::string source, char delimiter) {

    std::vector<std::string> tokens = tokenize(source, delimiter);
    return sttoullv(tokens);
}

std::vector<float> sttofv(std::string source, char delimiter) {

    std::vector<std::string> tokens = tokenize(source, delimiter);
    return sttofv(tokens);
}
std::vector<double> sttodv(std::string source, char delimiter) {

    std::vector<std::string> tokens = tokenize(source, delimiter);
    return sttodv(tokens);
}
std::vector<long double> sttoldv(std::string source, char delimiter) {

    std::vector<std::string> tokens = tokenize(source, delimiter);
    return sttoldv(tokens);
}

/* functions that take string vectors as input */
std::vector<int> sttoiv(std::vector<std::string> tokens) {

    std::vector<int> int_tokens(0);
    for(const auto& i: tokens) {
        try { int_tokens.push_back(std::stoi(i)); }
        catch(std::invalid_argument) { continue; }
        catch(std::out_of_range) { continue; }
    }
    return int_tokens;
}
std::vector<long> sttolv(std::vector<std::string> tokens) {

    std::vector<long> long_tokens(0);
    for(const auto& i: tokens) {
        try { long_tokens.push_back(std::stol(i)); }
        catch(std::invalid_argument) { continue; }
        catch(std::out_of_range) { continue; }
    }
    return long_tokens;
}
std::vector<long long> sttollv(std::vector<std::string> tokens) {

    std::vector<long long> long_long_tokens(0);
    for(const auto& i: tokens) {
        try { long_long_tokens.push_back(std::stoll(i)); }
        catch(std::invalid_argument) { continue; }
        catch(std::out_of_range) { continue; }
    }
    return long_long_tokens;
}

std::vector<unsigned long> sttoulv(std::vector<std::string> tokens) {

    std::vector<unsigned long> unsigned_long_tokens(0);
    for(const auto& i: tokens) {
        try { unsigned_long_tokens.push_back(std::stoul(i)); }
        catch(std::invalid_argument) { continue; }
        catch(std::out_of_range) { continue; }
    }
    return unsigned_long_tokens;
}
std::vector<unsigned long long> sttoullv(std::vector<std::string> tokens) {

    std::vector<unsigned long long> unsigned_long_long_tokens(0);
    for(const auto& i: tokens) {
        try { unsigned_long_long_tokens.push_back(std::stoull(i)); }
        catch(std::invalid_argument) { continue; }
        catch(std::out_of_range) { continue; }
    }
    return unsigned_long_long_tokens;
}

std::vector<float> sttofv(std::vector<std::string> tokens) {

    std::vector<float> float_tokens(0);
    for(const auto& i: tokens) {
        try { float_tokens.push_back(std::stof(i)); }
        catch(std::invalid_argument& iarg) { continue; }
        catch(std::out_of_range& oor) { continue; }
    }
    return float_tokens;
}
std::vector<double> sttodv(std::vector<std::string> tokens) {

    std::vector<double> double_tokens(0);
    for(const auto& i: tokens) {
        try { double_tokens.push_back(std::stod(i)); }
        catch(std::invalid_argument) { continue; }
        catch(std::out_of_range) { continue; }
    }
    return double_tokens;
}
std::vector<long double> sttoldv(std::vector<std::string> tokens) {

    std::vector<long double> long_double_tokens(0);
    for(const auto& i: tokens) {
        try { long_double_tokens.push_back(std::stold(i)); }
        catch(std::invalid_argument) { continue; }
        catch(std::out_of_range) { continue; }
    }
    return long_double_tokens;
}
}
